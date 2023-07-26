#ifndef ALGORITHM_CALC_VIEWING_RANGE_HPP
#define ALGORITHM_CALC_VIEWING_RANGE_HPP 1

#include <functional>
#include <stack>
#include <utility>
#include <vector>

namespace algorithm {

// 見晴らし範囲．
// H[] within [left[i], right[i]) <= H[i] (left[i] <= i < right[i]) となるleft[], right[]を求める．O(N).
template <typename Type, typename Func = std::function<bool(Type, Type)> >
std::pair<std::vector<int>, std::vector<int> > calc_viewing_range(
    const std::vector<Type> &h,
    const Func &comp = [](const Type &a, const Type &b) -> bool { return a <= b; }) {
    const int n = h.size();
    std::vector<int> left(n, 0), right(n, n);
    // left side.
    std::stack<std::pair<Type, int> > stack_left;
    for(int i = 0; i < n; ++i) {
        while(!stack_left.empty() and comp(stack_left.top().first, h[i])) stack_left.pop();
        if(!stack_left.empty()) left[i] = stack_left.top().second + 1;
        stack_left.push({h[i], i});
    }
    // right side.
    std::stack<std::pair<Type, int> > stack_right;
    for(int i = n - 1; i >= 0; --i) {
        while(!stack_right.empty() and comp(stack_right.top().first, h[i])) stack_right.pop();
        if(!stack_right.empty()) right[i] = stack_right.top().second;
        stack_right.push({h[i], i});
    }
    return {left, right};
}

}  // namespace algorithm

#endif
