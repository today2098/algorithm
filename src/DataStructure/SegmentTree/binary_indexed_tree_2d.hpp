/**
 * @brief 二次元BIT
 */

#ifndef ALGORITHM_BINARY_INDEXED_TREE_2D_HPP
#define ALGORITHM_BINARY_INDEXED_TREE_2D_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// 二次元BIT．
template <typename T>
class BIT2D {
    int m_h, m_w;
    std::vector<std::vector<T> > m_dat;  // 1-based index.

    void build() {
        for(int i = 1; i <= height(); ++i)
            for(int j = 1; j <= width(); ++j) {
                int ni = i + (i & -i), nj = j + (j & -j);
                bool flag1 = (ni <= height()), flag2 = (nj <= width());
                if(flag1) m_dat[ni][j] += m_dat[i][j];
                if(flag2) m_dat[i][nj] += m_dat[i][j];
                if(flag1 and flag2) m_dat[ni][nj] -= m_dat[i][j];
            }
    }

public:
    // constructor. O(H*W).
    BIT2D() : BIT2D(0, 0) {}
    explicit BIT2D(size_t h, size_t w, T a = 0) : m_h(h), m_w(w), m_dat(h + 1, std::vector<T>(w + 1, a)) {
        if(a != 0) build();
    }
    explicit BIT2D(const std::vector<std::vector<T> > &dat)
        : m_h(dat.size()), m_w(dat[0].size()), m_dat(dat.size() + 1, std::vector<T>(dat[0].size() + 1)) {
        for(int i = 0; i < height(); ++i) std::copy(dat[i].begin(), dat[i].end(), m_dat[i + 1].begin() + 1);
        build();
    }

    int height() const { return m_h; }
    int width() const { return m_w; }
    // 要素(x,y)にaを加算する．O((logH)*logW).
    void add(int y, int x, T a) {
        assert(1 <= y and y <= height());
        assert(1 <= x and x <= width());
        for(int i = y; i <= height(); i += i & -i) {
            for(int j = x; j <= width(); j += j & -j) m_dat[i][j] += a;
        }
    }
    // 区間[1,y]かつ[1,x]の総和を求める．O((logH)*logW).
    T sum(int y, int x) const {
        assert(0 <= y and y <= height());
        assert(0 <= x and x <= width());
        T res = 0;
        for(int i = y; i > 0; i -= i & -i) {
            for(int j = x; j > 0; j -= j & -j) res += m_dat[i][j];
        }
        return res;
    }
    // 区間[y,yy]かつ[x,xx]の総和を求める．
    T sum(int y, int x, int yy, int xx) const {
        assert(1 <= y and y <= yy and yy <= height());
        assert(1 <= x and x <= xx and xx <= width());
        return sum(yy, xx) - sum(yy, x - 1) - sum(y - 1, xx) + sum(y - 1, x - 1);
    }
    // 全要素をaで埋める．O(H*W).
    void fill(T a = 0) {
        for(int i = 1; i <= height(); ++i) std::fill(m_dat[i].begin() + 1, m_dat[i].end(), a);
        if(a != 0) build();
    }
};

}  // namespace algorithm

#endif
