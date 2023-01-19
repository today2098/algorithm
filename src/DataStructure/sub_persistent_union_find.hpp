#ifndef ALGORITHM_SUB_PERSISTENT_UNION_FIND_HPP
#define ALGORITHM_SUB_PERSISTENT_UNION_FIND_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// 部分永続Union-Find Tree．
class SubPersistentUnionFind {
    using pii = std::pair<int, int>;

    int m_now;  // m_now:=(時刻).
    int m_vn;   // m_vn:=(ノード数).
    int m_gn;   // m_gn:=(グループ数).
    // m_par[v][](t,id):=(時刻tにおけるノードvの親番号id). 値idが0未満の場合，vは親となり，値idの絶対値はグループサイズを表す．
    std::vector<std::vector<pii> > m_par;

    static constexpr int infinity() { return 1e9; }

public:
    SubPersistentUnionFind() : SubPersistentUnionFind(0) {}
    explicit SubPersistentUnionFind(size_t vn) : m_now(1), m_vn(vn), m_gn(vn), m_par(vn, std::vector<pii>(1, pii(0, -1))) {
        assert((int)vn < infinity());
    }

    // 現在の時刻を返す．
    int now() const { return m_now; }
    // ノード数を返す．
    int vn() const { return m_vn; };
    // グループ数を返す．
    int gn() const { return m_gn; };
    // 現在におけるノードvの親番号を返す．O(logN).
    int root(int v) const {
        assert(0 <= v and v < vn());
        auto itr = m_par[v].rbegin();
        if(itr->second < 0) return v;
        return root(itr->second);
    }
    // 時刻tにおけるノードvの親番号を返す．O(logN).
    int root(int v, int t) const {
        assert(0 <= v and v < vn());
        assert(0 <= t and t < now());
        auto itr = std::lower_bound(m_par[v].begin(), m_par[v].end(), pii(t, -infinity()));
        if(itr == m_par[v].end() or itr->first > t) itr--;
        if(itr->second < 0) return v;
        return (itr->first == t ? itr->second : root(itr->second, t));
    }
    // 現在におけるノードvが属するグループのサイズを返す．O(logN).
    int size(int v) const {
        assert(0 <= v and v < vn());
        return -m_par[root(v)].rbegin()->second;
    }
    // 時刻tにおけるノードvが属するグループのサイズを返す．O(logN).
    int size(int v, int t) const {
        assert(0 <= v and v < vn());
        assert(0 <= t and t < now());
        int par = root(v, t);
        auto itr = std::lower_bound(m_par[par].begin(), m_par[par].end(), pii(t, -infinity()));
        if(itr == m_par[par].end() or itr->first > t) itr--;
        return -itr->second;
    }
    // 現在においてノードuとvが同じグループか判定する．O(logN).
    bool same(int u, int v) const {
        assert(0 <= u and u < vn());
        assert(0 <= v and v < vn());
        return root(u) == root(v);
    }
    // 時刻tにおいてノードuとvが同じグループか判定する．O(logN).
    bool same(int u, int v, int t) const {
        assert(0 <= u and u < vn());
        assert(0 <= v and v < vn());
        assert(0 <= t and t < now());
        return root(u, t) == root(v, t);
    }
    // ノードu, vが属するそれぞれのグループを結合する．O(logN).
    bool unite(int u, int v) {
        assert(0 <= u and u < vn());
        assert(0 <= v and v < vn());
        u = root(u), v = root(v);
        if(u == v) {
            m_now++;
            return false;  // Already united.
        }
        int sz_u = -m_par[u].rbegin()->second;
        int sz_v = -m_par[v].rbegin()->second;
        if(sz_u < sz_v) std::swap(u, v), std::swap(sz_u, sz_v);  // Merge technique.
        m_par[u].emplace_back(now(), -sz_u - sz_v);
        m_par[v].emplace_back(now(), u);
        m_gn--;
        m_now++;
        return true;
    }
    void reset() {
        m_now = 1;
        m_gn = vn();
        for(auto &history : m_par) history.resize(1);
    }
};

}  // namespace algorithm

#endif
