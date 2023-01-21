#ifndef ALGORITHM_EDIT_DISTANCE_HPP
#define ALGORITHM_EDIT_DISTANCE_HPP 1

#include <algorithm>
#include <vector>

namespace algorithm {

// 編集距離 (edit distance)．引数はSTLのシーケンスコンテナ．O(|A|*|B|).
template <class Class>
int edit_distance(const Class &s, const Class &t) {
    const int m = s.size(), n = t.size();
    std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1));  // dp[i][j]:=(s[:i]とt[:j]の編集距離).
    dp[0][0] = 0;
    for(int i = 1; i <= m; ++i) dp[i][0] = i;
    for(int j = 1; j <= n; ++j) dp[0][j] = j;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j) dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1)});
    return dp[m][n];
}

}  // namespace algorithm

#endif
