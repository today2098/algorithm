#ifndef ALGORITHM_LIS_HPP
#define ALGORITHM_LIS_HPP

#include <algorithm>  // lower_bound() and upper_bound().
#include <vector>

namespace algorithm {

// 最長増加部分列 (LIS:Longest Increasing Subsequence) の長さを求める．引数はSTLのシーケンスコンテナ．O(|A|*log|A|).
template <class Class>
int lis(const Class &a, bool is_strong = true) {
    Class tmp({a[0]});
    for(int i = 1; i < a.size(); ++i) {
        if(is_strong) {  // 狭義単調増加．
            if(tmp[tmp.size() - 1] < a[i])
                tmp.push_back(a[i]);
            else
                *lower_bound(tmp.begin(), tmp.end(), a[i]) = a[i];
        } else {  // 広義単調増加．
            if(tmp[tmp.size() - 1] <= a[i])
                tmp.push_back(a[i]);
            else
                *upper_bound(tmp.begin(), tmp.end(), a[i]) = a[i];
        }
    }
    return tmp.size();
}

}  // namespace algorithm

#endif  // ALGORITHM_LIS_HPP
