#ifndef ALGORITHM_LIS_HPP
#define ALGORITHM_LIS_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

namespace algorithm {

// 最長増加部分列 (LIS: Longest Increasing Subsequence) の長さを求める．O(N*logN).
template <typename Type, typename Func = std::function<bool(const Type &, const Type &)> >
std::vector<int> lis(
    const std::vector<Type> &v,
    const Func &comp = [](const Type &a, const Type &b) -> bool { return a < b; }) {
    const int n = v.size();
    std::vector<int> res(n);  // res[i]:=(v[:i+1]の最長増加部分列の長さ).
    std::vector<Type> dp;
    dp.reserve(n);
    for(int i = 0; i < n; ++i) {
        auto itr = std::lower_bound(dp.begin(), dp.end(), v[i], comp);
        if(itr == dp.end()) dp.push_back(v[i]);
        else *itr = v[i];
        res[i] = dp.size();
    }
    return res;
}

}  // namespace algorithm

#endif
