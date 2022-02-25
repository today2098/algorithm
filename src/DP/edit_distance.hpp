#ifndef ALGORITHM_EDIT_DISTANCE_HPP
#define ALGORITHM_EDIT_DISTANCE_HPP 1

#include <algorithm>
#include <vector>

namespace algorithm {

// 編集距離 (edit distance)．O(|A|*|B|).
template <class Class>
int edit_distance(const Class &a, const Class &b) {
    int an = a.size(), bn = b.size();
    std::vector<std::vector<int> > dp(an + 1, std::vector<int>(bn + 1));  // dp[i][j]:=(a[:i]とb[:j]の編集距離).
    dp[0][0] = 0;
    for(int i = 1; i <= an; ++i) dp[i][0] = i;
    for(int j = 1; j <= bn; ++j) dp[0][j] = j;
    for(int i = 1; i <= an; ++i)
        for(int j = 1; j <= bn; ++j) {
            dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)});
        }
    return dp[an][bn];
}

}  // namespace algorithm

#endif  // ALGORITHM_EDIT_DISTANCE_HPP
