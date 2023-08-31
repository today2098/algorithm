/**
 * @brief 重み付きUnion-Find木
 * @docs docs/DataStructure/UnionFind/potentialized_union_find.md
 */

#ifndef ALGORITHM_POTENTIALIZED_UNION_FIND_HPP
#define ALGORITHM_POTENTIALIZED_UNION_FIND_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

// 重み付きUnion-Find木．
template <typename T>  // T:Type of potential.
class PotentializedUnionFind {
    int m_vn;                // m_vn:=(要素数).
    int m_gn;                // m_gn:=(グループ数).
    std::vector<int> m_par;  // m_par[x]:=(ノードxの親番号). 0未満の場合，xは根であり，値の絶対値は属するグループのサイズを表す．
    std::vector<T> m_p;      // m_p[x]:=(要素xのポテンシャル).

public:
    PotentializedUnionFind() : PotentializedUnionFind(0) {}
    explicit PotentializedUnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn, -1), m_p(vn, 0) {}

    // 要素の総数を返す．
    int vn() const { return m_vn; };
    // グループ数を返す．
    int gn() const { return m_gn; };
    // 要素xが属するグループ（根付き木）の根番号を返す．O(α(N)).
    int root(int x) {
        assert(0 <= x and x < vn());
        if(m_par[x] < 0) return x;
        int res = root(m_par[x]);  // 座標圧縮．
        m_p[x] += m_p[m_par[x]];
        return m_par[x] = res;
    }
    // 要素xが属するグループのサイズを返す．
    int size(int x) {
        assert(0 <= x and x < vn());
        return -m_par[root(x)];
    }
    // 要素xのポテンシャルを返す．
    T potential(int x) {
        assert(0 <= x and x < vn());
        root(x);
        return m_p[x];
    }
    // 要素x, yが同じグループに属するか判定する．
    bool is_same(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        return root(x) == root(y);
    }
    // 要素xに対するyの相対ポテンシャルを返す．
    T difference(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        return potential(y) - potential(x);
    }
    // difference(x,y)==dとなるように，要素xが属するグループと要素yが属するグループとを併合する．
    bool unite(int x, int y, T d) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        d = d + potential(x) - potential(y);
        x = root(x), y = root(y);
        if(x == y) return false;  // Do nothing.
        if(size(x) < size(y)) {   // Merge technique (union by size).
            std::swap(x, y);
            d = -d;
        }
        m_par[x] += m_par[y];
        m_par[y] = x;
        m_p[y] = d;
        m_gn--;
        return true;
    }
    void reset() {
        m_gn = vn();
        std::fill(m_par.begin(), m_par.end(), -1);
        std::fill(m_p.begin(), m_p.end(), 0);
    }
};

}  // namespace algorithm

#endif
