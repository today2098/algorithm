#ifndef ALGORITHM_LCS_HPP
#define ALGORITHM_LCS_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// 最長共通部分列 (LCS: Longest Common Subsequence)．
// 引数はSTLのシーケンスコンテナ．O(|A|*|B|).
template <class Sequence>
Sequence lcs(const Sequence &a, const Sequence &b) {
    const int n = a.size(), m = b.size();
    // dp[i][j]:=(a[:i]とb[:j]のLCSの長さ).
    std::vector<std::vector<int> > dp(n + 1, std::vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    Sequence sub(dp[n][m], a[0]);  // sub[]:=(配列a, bのLCS).
    int i = n, j = m, k = dp[n][m];
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

#endif
