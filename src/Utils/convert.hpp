#ifndef ALGORITHM_CONVERT_HPP
#define ALGORITHM_CONVERT_HPP 1

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

namespace algorithm {

template <typename Type>
inline bool chmax(Type &a, const Type &b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename Type>
inline bool chmin(Type &a, const Type &b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

inline bool chtoupper(char &c) {
    if('a' <= c && c <= 'z') {
        c -= 0x20;
        return true;
    }
    return false;
}

inline bool chtolower(char &c) {
    if('A' <= c && c <= 'Z') {
        c += 0x20;
        return true;
    }
    return false;
}

std::vector<int> stov(const std::string &s) {
    const int n = s.size();
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i) v[i] = s[i];
    return v;
}

std::string vtos(const std::vector<int> &v) {
    const int n = v.size();
    std::string s(n, 0);
    for(int i = 0; i < n; ++i) {
        assert(0 <= v[i] and v[i] < 128);
        s[i] = v[i];
    }
    return s;
}

// 座標圧縮．
template <typename Type>
std::vector<Type> compress(std::vector<Type> &v) {
    const int n = v.size();
    std::vector<Type> res = v;
    std::sort(res.begin(), res.end());
    res.erase(std::unique(res.begin(), res.end()), res.end());
    for(int i = 0; i < n; ++i) v[i] = std::lower_bound(res.begin(), res.end(), v[i]) - res.begin();
    return res;
}

// 2次元配列を時計回り90度回転させる．
template <typename Type>
std::vector<std::vector<Type> > rotate(const std::vector<std::vector<Type> > &v) {
    assert(v.size() > 0);
    const int h = v.size();
    const int w = v[0].size();
    std::vector<std::vector<Type> > res(w, std::vector<Type>(h));
    for(int i = 0; i < w; ++i) {
        for(int j = 0; j < h; ++j) res[i][j] = v[h - 1 - j][i];
    }
    return res;
}

}  // namespace algorithm

#endif
