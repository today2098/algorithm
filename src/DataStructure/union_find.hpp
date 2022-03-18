#ifndef ALGORITHM_UNION_FIND_HPP
#define ALGORITHM_UNION_FIND_HPP 1

#include <algorithm>  // for fill().
#include <cassert>
#include <utility>  // for swap().
#include <vector>

namespace algorithm {

// 素集合データ構造.
class UnionFind {
    int vn, gn;            // vn:=(ノード数), gn:=(グループ数).
    std::vector<int> par;  // par[v]:=(ノードvの親番号). 0未満の場合，vが親で，絶対値がグループサイズを表す．

public:
    // constructor.
    UnionFind() : UnionFind(0) {}
    explicit UnionFind(size_t vn_) : vn(vn_), gn(vn_), par(vn_, -1) {}

    int get_vn() const { return vn; };  // ノード数を返す．
    int get_gn() const { return gn; };  // グループ数を返す．
    int root(int v) {                   // ノードvの親番号を返す．
        assert(0 <= v and v < vn);
        if(par[v] < 0) return v;
        return par[v] = root(par[v]);
    }
    int size(int v) {  // ノードvが属するグループのサイズを返す．
        assert(0 <= v and v < vn);
        return -par[root(v)];
    }
    bool same(int u, int v) {  // ノードuとvが同じグループか判定する．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        return root(u) == root(v);
    }
    bool unite(int u, int v) {  // ノードu, vが属するそれぞれのグループを結合する．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        u = root(u), v = root(v);
        if(u == v) return false;                // Do nothing.
        if(size(u) < size(v)) std::swap(u, v);  // Merge technique.
        par[u] += par[v];
        par[v] = u;
        gn--;
        return true;
    }
    void reset() {
        gn = vn;
        std::fill(par.begin(), par.end(), -1);
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_UNION_FIND_HPP
