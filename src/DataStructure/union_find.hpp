#ifndef ALGORITHM_UNION_FIND_HPP
#define ALGORITHM_UNION_FIND_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// 素集合データ構造．
class UnionFind {
    int m_vn;                // m_vn:=(ノード数).
    int m_gn;                // m_gn:=(連結成分数).
    std::vector<int> m_par;  // m_par[v]:=(ノードvの親番号). 0未満の場合，vは根であり，値の絶対値は連結成分のサイズを表す．

public:
    UnionFind() : UnionFind(0) {}
    explicit UnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn, -1) {}

    // ノードの総数を返す．
    int vn() const { return m_vn; };
    // 連結成分の数を返す．
    int gn() const { return m_gn; };
    // ノードvが属する連結成分の根番号を返す．
    int root(int v) {
        assert(0 <= v and v < vn());
        if(m_par[v] < 0) return v;
        return m_par[v] = root(m_par[v]);
    }
    // ノードvが属する連結成分のサイズを返す．
    int size(int v) {
        assert(0 <= v and v < vn());
        return -m_par[root(v)];
    }
    // ノードuとvが連結しているか判定する．
    bool is_same(int u, int v) {
        assert(0 <= u and u < vn());
        assert(0 <= v and v < vn());
        return root(u) == root(v);
    }
    // ノードuとvの属する連結成分を繋げる．
    bool unite(int u, int v) {
        assert(0 <= u and u < vn());
        assert(0 <= v and v < vn());
        u = root(u), v = root(v);
        if(u == v) return false;                // Do nothing.
        if(size(u) < size(v)) std::swap(u, v);  // Merge technique.
        m_par[u] += m_par[v];
        m_par[v] = u;
        m_gn--;
        return true;
    }
    void reset() {
        m_gn = vn();
        std::fill(m_par.begin(), m_par.end(), -1);
    }
};

}  // namespace algorithm

#endif
