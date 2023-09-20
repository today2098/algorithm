#ifndef ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP
#define ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP 1

/**
 * @brief Longest Increasing Subsequence（最長増加部分列）
 * @docs docs/DP/longest_increasing_subsequence.md
 */

#include <algorithm>
#include <functional>
#include <vector>

namespace algorithm {

// 最長増加部分列 (LIS: Longest Increasing Subsequence) の長さを求める．O(N*logN).
template <typename Type, typename Func = std::function<bool(const Type &, const Type &)> >
std::vector<int> lis(
    const std::vector<Type> &v,
    const Func &comp = [](const Type &a, const Type &b) -> bool { return a < b; }) {
    const int n = v.size();
    std::vector<int> res(n + 1, 0);  // res[i]:=(v[:i]における最長増加部分列の長さ).
    std::vector<Type> sub;
    sub.reserve(n);
    for(int i = 0; i < n; ++i) {
        auto itr = std::lower_bound(sub.begin(), sub.end(), v[i], comp);
        if(itr == sub.end()) sub.push_back(v[i]);
        else *itr = v[i];
        res[i + 1] = sub.size();
    }
    return res;
}

}  // namespace algorithm

#endif
