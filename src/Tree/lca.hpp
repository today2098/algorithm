#ifndef ALGORITHM_LCA_HPP
#define ALGORITHM_LCA_HPP 1

#include <algorithm>  // for fill().
#include <cassert>
#include <utility>  // for swap().
#include <vector>

namespace algorithm {

// 最近共通祖先 (LCA:Lowest Common Ancestor)．
class LCA {
    int vn, h, rt;                       // vn:=(ノード数), h:=ceiling(log2(vn)), rt:=(根番号).
    std::vector<std::vector<int> > g;    // g[v][]:=(ノードvの隣接リスト).
    std::vector<std::vector<int> > par;  // par[v][k]:=(ノードvから2^k回辿って到達する親ノード番号). 親がいない場合は-1．
    std::vector<int> depth;              // depth[v]:=(ノードvの深さ). 根に連結していない場合は-1．
    bool update;

    void dfs(int v, int p, int d) {
        par[v][0] = p, depth[v] = d;
        for(int u : g[v]) {
            if(u != p) dfs(u, v, d + 1);
        }
    }
    void build() {  // 祖先木を構築する．O(|V|*log|V|).
        for(int i = 0; i < vn; ++i) std::fill(par[i].begin(), par[i].end(), -1);
        std::fill(depth.begin(), depth.end(), -1);
        dfs(rt, -1, 0);
        for(int k = 1; k < h; ++k)
            for(int v = 0; v < vn; ++v) {
                if(par[v][k - 1] != -1) par[v][k] = par[par[v][k - 1]][k - 1];
            }
        update = false;
    }

public:
    // constructor. O(log|V|).
    LCA() : LCA(0) {}
    explicit LCA(size_t vn_, int rt_ = 0) : vn(vn_), h(1), rt(rt_), g(vn_), depth(vn_, -1), update(true) {
        while((1 << h) < vn) h++;
        par.assign(vn, std::vector<int>(h, -1));
    }

    int size() const { return vn; }  // ノード数を返す．
    int root(int rt_ = -1) {         // 根番号にアクセスする．
        if(rt_ != -1) {
            assert(0 <= rt_ and rt_ < vn);
            rt = rt_, update = true;
        }
        return rt;
    }
    void add_edge(int u, int v) {  // ノードuとvに辺を繋げる．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        g[u].push_back(v);
        g[v].push_back(u);
        update = true;
    }
    int lca(int u, int v) {  // ノードuとvの最も近い共通の先祖を求める．O(log|V|).
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        if(update) build();
        if(depth[u] == -1 or depth[v] == -1) return -1;  // 非連結．
        if(depth[u] > depth[v]) std::swap(u, v);
        for(int k = 0; k < h; ++k) {
            if((depth[v] - depth[u]) & (1 << k)) v = par[v][k];  // 同じ深さに合わせる．
        }
        if(u == v) return u;
        for(int k = h - 1; k >= 0; --k) {
            if(par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];  // 異なったら根に近づける．
        }
        return par[u][0];
    }
    int get_depth(int v) {  // ノードvの深さを返す．
        assert(0 <= v and v < vn);
        if(update) build();
        return depth[v];
    }
    int distance(int u, int v) {  // ノードuとvの距離を求める．O(log|V|).
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        if(update) build();
        if(depth[u] == -1 or depth[v] == -1) return -1;  // 非連結．
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_LCA_HPP
