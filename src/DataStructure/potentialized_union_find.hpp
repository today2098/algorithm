#ifndef ALGORITHM_POTENTIALIZED_UNION_FIND_HPP
#define ALGORITHM_POTENTIALIZED_UNION_FIND_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

// 重み付きUnion-Find Tree．
template <typename T>
class PotentializedUnionFind {
    int vn, gn;            // vn:=(ノード数), gn:=(グループ数).
    std::vector<int> par;  // par[v]:=(ノードvの親番号). 0未満の場合，vが親で，絶対値がグループサイズを表す．
    std::vector<T> p;      // p[v]:=(ノードvのポテンシャル).

public:
    // constructor.
    PotentializedUnionFind() : PotentializedUnionFind(0) {}
    explicit PotentializedUnionFind(std::size_t vn_) : vn(vn_), gn(vn_), par(vn_, -1), p(vn_, 0) {}

    int get_vn() const { return vn; };  // ノード数を返す．
    int get_gn() const { return gn; };  // グループ数を返す．
    int root(int v) {                   // ノードvの親番号を返す．
        assert(0 <= v and v < vn);
        if(par[v] < 0) return v;
        int res = root(par[v]);  // recrusion.
        p[v] += p[par[v]];
        return par[v] = res;
    }
    int size(int v) {  // ノードvが属するグループのサイズを返す．
        assert(0 <= v and v < vn);
        return -par[root(v)];
    }
    T potential(int v) {  // ノードvのポテンシャルを返す．
        assert(0 <= v and v < vn);
        root(v);
        return p[v];
    }
    bool same(int u, int v) {  // ノードuとvが同じグループか判定する．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        return root(u) == root(v);
    }
    T diff(int u, int v) {  // ノードuに対するvの相対ポテンシャルを返す．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        return potential(v) - potential(u);
    }
    bool unite(int u, int v, T d) {  // diff(u,v)=dとなるようにノードuとvの親ノードを結合する．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        d = d + potential(u) - potential(v);
        u = root(u), v = root(v);
        if(u == v) return false;                   // Do nothing.
        if(size(u) < size(v)) swap(u, v), d = -d;  // Merge technique.
        par[u] += par[v];
        par[v] = u, p[v] = d;
        gn--;
        return true;
    }
    void reset() {
        gn = vn;
        std::fill(par.begin(), par.end(), -1);
        std::fill(p.begin(), p.end(), 0);
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_POTENTIALIZED_UNION_FIND_HPP
