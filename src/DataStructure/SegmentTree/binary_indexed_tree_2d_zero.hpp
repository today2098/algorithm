/**
 * @brief 2次元BIT (0-based index)
 */

#ifndef ALGORITHM_BINARY_INDEXED_TREE_2D_ZERO_HPP
#define ALGORITHM_BINARY_INDEXED_TREE_2D_ZERO_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// 2次元BIT (0-based index)．
template <typename T>
class BIT2D0 {
    int m_h, m_w;
    std::vector<std::vector<T> > m_dat;  // 0-based index.

    void build() {
        for(int i = 0; i < height(); ++i) {
            for(int j = 0; j < width(); ++j) {
                int ni = i | i + 1, nj = j | j + 1;
                bool flag1 = (ni < height()), flag2 = (nj < width());
                if(flag1) m_dat[ni][j] += m_dat[i][j];
                if(flag2) m_dat[i][nj] += m_dat[i][j];
                if(flag1 and flag2) m_dat[ni][nj] -= m_dat[i][j];
            }
        }
    }

public:
    // constructor. O(H*W).
    BIT2D0() : BIT2D0(0, 0) {}
    explicit BIT2D0(size_t h, size_t w, T a = 0) : m_h(h), m_w(w), m_dat(h, std::vector<T>(w, a)) {
        if(a != 0) build();
    }
    explicit BIT2D0(const std::vector<std::vector<T> > &dat) : m_h(dat.size()), m_w(dat[0].size()), m_dat(dat) {
        build();
    }

    int height() const { return m_h; }
    int width() const { return m_w; }
    // 座標(x,y)にaを加算する．O((logH)*logW).
    void add(int y, int x, T a) {
        assert(0 <= y and y < height());
        assert(0 <= x and x < width());
        for(int i = y; i < height(); i |= i + 1) {
            for(int j = x; j < width(); j |= j + 1) m_dat[i][j] += a;
        }
    }
    // 区間[0,y)かつ[0,x)の総和を求める．O((logH)*logW).
    T sum(int y, int x) const {
        assert(0 <= y and y <= height());
        assert(0 <= x and x <= width());
        T res = 0;
        for(int i = y - 1; i >= 0; i = (i & i + 1) - 1) {
            for(int j = x - 1; j >= 0; j = (j & j + 1) - 1) res += m_dat[i][j];
        }
        return res;
    }
    // 区間[y,yy)かつ[x,xx)の総和を求める．
    T sum(int y, int x, int yy, int xx) const {
        assert(0 <= y and y <= yy and yy <= height());
        assert(0 <= x and x <= xx and xx <= width());
        return sum(yy, xx) - sum(yy, x) - sum(y, xx) + sum(y, x);
    }
    // 全要素をaで埋める．O(H*W).
    void fill(T a = 0) {
        for(int i = 0; i < height(); ++i) std::fill(m_dat[i].begin(), m_dat[i].end(), a);
        if(a != 0) build();
    }
};

}  // namespace algorithm

#endif
