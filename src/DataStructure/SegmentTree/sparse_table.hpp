#ifndef ALGORITHM_SPARSE_TABLE_HPP
#define ALGORITHM_SPARSE_TABLE_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// 結合則 ((A•B)•C=A•(B•C)) と冪等性 (A•A=A) が成り立つ演算（min, max, orなど）による区間クエリを求める．
template <typename S>
class SparseTable {
    using F = std::function<S(const S &, const S &)>;

    F m_op;                                // S m_op(S,S):=(二項演算関数).
    int m_sz;                              // m_sz:=(要素数).
    std::vector<int> m_log;                // m_log[x]:=(2^k<=x となる最大の整数k).
    std::vector<std::vector<S> > m_table;  // m_table[k][i]:=(長さが2^kで，左端がiである区間のクエリ).

public:
    // constructor. O(N*logN).
    SparseTable() {}
    explicit SparseTable(const F &op, const std::vector<S> &v) : m_op(op), m_sz(v.size()), m_log(v.size() + 1, 0) {
        for(int i = 2; i <= size(); ++i) m_log[i] = m_log[i >> 1] + 1;
        m_table.assign(m_log[size()] + 1, std::vector<S>(size()));
        std::copy(v.begin(), v.end(), m_table[0].begin());
        for(int i = 1; i <= m_log[size()]; ++i) {
            for(int j = 0; j <= size() - (1 << i) + 1; ++j) m_table[i][j] = m_op(m_table[i - 1][j], m_table[i - 1][j + (1 << (i - 1))]);
        }
    }

    // 要素数を返す．
    int size() const { return m_sz; }
    // 区間[l,r)のクエリを返す．O(1).
    S query(int l, int r) const {
        assert(0 <= l and l < r and r <= size());
        int length = r - l;
        return m_op(m_table[m_log[length]][l], m_table[m_log[length]][r - (1 << m_log[length])]);
    }
};

}  // namespace algorithm

#endif
