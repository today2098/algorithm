/**
 * @brief 座標圧縮
 */

#ifndef ALGORITHM_COMPRESS_HPP
#define ALGORITHM_COMPRESS_HPP 1

#include <algorithm>
#include <vector>

namespace algorithm {

// 座標圧縮．
template <typename Type>
std::vector<Type> compress(std::vector<Type> &v) {
    const int n = v.size();
    std::vector<Type> key = v;
    std::sort(key.begin(), key.end());
    key.erase(std::unique(key.begin(), key.end()), key.end());
    for(int i = 0; i < n; ++i) v[i] = std::lower_bound(key.begin(), key.end(), v[i]) - key.begin();
    return key;
}

}  // namespace algorithm

#endif
