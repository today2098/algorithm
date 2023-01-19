#ifndef ALGORITHM_POTENTIALIZED_UNION_FIND_HPP
#define ALGORITHM_POTENTIALIZED_UNION_FIND_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// 重み付きUnion-Find Tree．
template <typename T>
class PotentializedUnionFind {
    int m_vn;                // m_vn:=(ノード数).
    int m_gn;                // m_gn:=(グループ数).
    std::vector<int> m_par;  // m_par[v]:=(ノードvの親番号). 0未満の場合，vは親となり，値の絶対値はグループサイズを表す．
    std::vector<T> m_p;      // m_p[v]:=(ノードvのポテンシャル).

public:
    PotentializedUnionFind() : PotentializedUnionFind(0) {}
    explicit PotentializedUnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn, -1), m_p(vn, 0) {}

    // ノード数を返す．
    int vn() const { return m_vn; };
    // グループ数を返す．
    int gn() const { return m_gn; };
    // ノードvの親番号を返す．
    int root(int v) {
        assert(0 <= v and v < vn());
        if(m_par[v] < 0) return v;
        auto res = root(m_par[v]);  // recrusion.
        m_p[v] += m_p[m_par[v]];
        return m_par[v] = res;
    }
    // ノードvが属するグループのサイズを返す．
    int size(int v) {
        assert(0 <= v and v < vn());
        return -m_par[root(v)];
    }
    // ノードvのポテンシャルを返す．
    T potential(int v) {
        assert(0 <= v and v < vn());
        root(v);
        return m_p[v];
    }
    // ノードuとvが同じグループか判定する．
    bool same(int u, int v) {
        assert(0 <= u and u < vn());
        assert(0 <= v and v < vn());
        return root(u) == root(v);
    }
    // ノードuに対するvの相対ポテンシャルを返す．
    T difference(int u, int v) {
        assert(0 <= u and u < vn());
        assert(0 <= v and v < vn());
        return potential(v) - potential(u);
    }
    // difference(u,v)=dとなるようにノードuとvの親ノードを結合する．
    bool unite(int u, int v, T d) {
        assert(0 <= u and u < vn());
        assert(0 <= v and v < vn());
        d = d + potential(u) - potential(v);
        u = root(u), v = root(v);
        if(u == v) return false;  // Do nothing.
        if(size(u) < size(v)) {   // Merge technique.
            std::swap(u, v);
            d = -d;
        }
        m_par[u] += m_par[v];
        m_par[v] = u;
        m_p[v] = d;
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
