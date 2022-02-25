#ifndef ALGORITHM_LIS_HPP
#define ALGORITHM_LIS_HPP

#include <algorithm>
#include <vector>

namespace algorithm {

// 最長増加部分列 (LIS:Longest Increasing Subsequence) の長さを求める．O(|A|*log|A|).
template <class Class>
int lis(const Class &a, bool is_strong = true) {
    Class sub({a[0]});  // sub[]:=(配列aのLIS).
    for(int i = 1; i < a.size(); ++i) {
        if(is_strong) {  // 狭義単調増加．
            if(sub[sub.size() - 1] < a[i])
                sub.push_back(a[i]);
            else
                *lower_bound(sub.begin(), sub.end(), a[i]) = a[i];
        } else {  // 広義単調増加．
            if(sub[sub.size() - 1] <= a[i])
                sub.push_back(a[i]);
            else
                *upper_bound(sub.begin(), sub.end(), a[i]) = a[i];
        }
    }
    return sub.size();
}

}  // namespace algorithm

#endif  // ALGORITHM_LIS_HPP
