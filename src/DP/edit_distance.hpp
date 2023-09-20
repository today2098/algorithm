#ifndef ALGORITHM_EDIT_DISTANCE_HPP
#define ALGORITHM_EDIT_DISTANCE_HPP 1

/**
 * @brief Edit Distance（編集距離）
 * @docs docs/DP/edit_distance.md
 */

#include <algorithm>
#include <vector>

namespace algorithm {

// Edit Distance（編集距離）.
// 引数はSTLのシーケンスコンテナであること．O(|S|*|T|).
template <class Sequence>
std::vector<std::vector<int> > edit_distance(const Sequence &s, const Sequence &t) {
    const int n = s.size(), m = t.size();
    // dp[i][j]:=(s[:i]とt[:j]の編集距離).
    std::vector<std::vector<int> > dp(n + 1, std::vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i) dp[i][0] = i;
    for(int j = 1; j <= m; ++j) dp[0][j] = j;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j] = std::min({dp[i - 1][j] + 1,
                                 dp[i][j - 1] + 1,
                                 dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1)});
        }
    }
    return dp;
}

}  // namespace algorithm

#endif
