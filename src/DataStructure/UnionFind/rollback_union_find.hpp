#ifndef ALGORITHM_ROLLBACK_UNION_FIND_HPP
#define ALGORITHM_ROLLBACK_UNION_FIND_HPP 1

/**
 * @brief Rollback付きUnion-Find
 * @docs docs/DataStructure/UnionFind/rollback_union_find.md
 */

#include <algorithm>
#include <cassert>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

namespace algorithm {

class RollbackUnionFind {
    int m_vn;  // m_vn:=(要素数).
    int m_gn;  // m_gn:=(グループ数).
    // m_par[x]:=(要素xの親番号). 0未満の場合，xは根であり，値の絶対値は属するグループのサイズを表す．
    std::vector<int> m_par;
    // m_history[]:=(1つ手前の状態). tuple of (x, m_par[x], y, m_par[y]).
    std::stack<std::tuple<int, int, int, int> > m_history;

public:
    RollbackUnionFind() : RollbackUnionFind(0) {}
    explicit RollbackUnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn, -1) {}

    // 現在のインデックスを返す．O(1).
    int index() const { return m_history.size(); }
    // 要素の総数を返す．
    int vn() const { return m_vn; };
    // グループ数を返す．
    int gn() const { return m_gn; };
    // 要素xが属するグループ（根付き木）の根番号を返す．O(logN).
    int root(int x) const {
        assert(0 <= x and x < vn());
        if(m_par[x] < 0) return x;
        return root(m_par[x]);
    }
    // 要素xが属するグループのサイズを返す．O(logN).
    int size(int x) const {
        assert(0 <= x and x < vn());
        return -m_par[root(x)];
    }
    // 要素x, yが同じグループに属するか判定する．O(logN).
    bool is_same(int x, int y) const {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        return root(x) == root(y);
    }
    // 要素xが属するグループと要素yが属するグループとを併合する．O(logN).
    bool unite(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        x = root(x), y = root(y);
        if(x == y) return false;  // Do nothing.
        m_history.emplace(x, m_par[x], y, m_par[y]);
        if(size(x) < size(y)) std::swap(x, y);  // Merge technique (union by size).
        m_par[x] += m_par[y];
        m_par[y] = x;
        m_gn--;
        return true;
    }
    // 1つ手前の状態に戻る．O(1).
    int rollback() {
        assert(!m_history.empty());
        m_par[std::get<0>(m_history.top())] = std::get<1>(m_history.top());
        m_par[std::get<2>(m_history.top())] = std::get<3>(m_history.top());
        m_history.pop();
        return index();
    }
    void reset() {
        m_gn = vn();
        std::fill(m_par.begin(), m_par.end(), -1);
        std::stack<std::tuple<int, int, int, int> >().swap(m_history);
    }
};

}  // namespace algorithm

#endif
