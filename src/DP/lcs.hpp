#ifndef ALGORITHM_LCS_HPP
#define ALGORITHM_LCS_HPP 1

#include <algorithm>
#include <vector>

namespace algorithm {

// 最長共通部分列 (LCS:Longest Common Subsequence)．O(|A|*|B|).
template <class Class>
Class lcs(const Class &a, const Class &b) {
    int an = a.size(), bn = b.size();
    std::vector<std::vector<int> > dp(an + 1, std::vector<int>(bn + 1, 0));  // dp[i][j]:=(a[:i]とb[:j]のLCSの長さ).
    for(int i = 1; i <= an; ++i)
        for(int j = 1; j <= bn; ++j) {
            if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    Class sub(dp[an][bn]);  // sub[]:=(配列a, bのLCS).
    int i = an, j = bn, k = dp[an][bn];
    while(k > 0) {
        if(a[i - 1] == b[j - 1]) {
            sub[k - 1] = a[i - 1];
            i--, j--, k--;
        } else if(dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }
    return sub;
}

}  // namespace algorithm

#endif  // ALGORITHM_LCS_HPP
