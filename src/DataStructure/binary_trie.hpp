#ifndef ALGORITHM_BINARY_TRIE_HPP
#define ALGORITHM_BINARY_TRIE_HPP 1

/**
 * @brief Binary Trie木
 * @docs docs/DataStructure/binary_trie.md
 */

#include <bitset>
#include <cassert>
#include <cstdint>

namespace algorithm {

// 非負整数を要素値とする多重集合．
template <size_t B = 32>  // B:ビット長.
class BinaryTrie {
public:
    using size_type = uint64_t;

private:
    struct Node {
        size_type cnt;  // cnt:=(自身を根とする部分木に含まれる要素数).
        Node *ch[2];    // ch[]:=(子のポインタ).
        Node() : cnt(0) {
            ch[0] = ch[1] = nullptr;
        }
    };

    Node *m_root;           // m_root:=(根のポインタ).
    std::bitset<B> m_bias;  // m_bias:=(xorの操作を行う値).

    Node *find(const std::bitset<B> &x) const {
        if(m_root == nullptr) return nullptr;
        Node *p = m_root;
        for(int i = B - 1; i >= 0; --i) {
            p = p->ch[x[i] ^ m_bias[i]];
            if(p == nullptr) return nullptr;
        }
        return p;
    }
    Node *add(Node *p, const std::bitset<B> &x, size_type cnt, int shift = B - 1) {  // Top down.
        if(p == nullptr) p = new Node;
        p->cnt += cnt;
        if(shift >= 0) {
            bool bit = x[shift] ^ m_bias[shift];
            p->ch[bit] = add(p->ch[bit], x, cnt, shift - 1);
        }
        return p;
    }
    Node *sub(Node *p, const std::bitset<B> &x, size_type cnt, int shift = B - 1) {  // Bottom up.
        assert(p and p->cnt >= cnt);
        if(shift >= 0) {
            bool bit = x[shift] ^ m_bias[shift];
            p->ch[bit] = sub(p->ch[bit], x, cnt, shift - 1);
        }
        p->cnt -= cnt;
        if(p->cnt == 0) {
            delete p;
            p = nullptr;
        }
        return p;
    }
    std::bitset<B> get(Node *p, size_type k, int shift = B - 1) const {
        assert(p);
        if(shift < 0) return 0;
        bool bit = m_bias[shift];
        size_type m = (p->ch[bit] ? p->ch[bit]->cnt : 0);
        if(k < m) return get(p->ch[bit], k, shift - 1);
        return std::bitset<B>(0).set(shift) | get(p->ch[!bit], k - m, shift - 1);
    }
    size_type get_lower(Node *p, const std::bitset<B> &x, int shift = B - 1) const {
        if(p == nullptr or shift < 0) return 0;
        bool bit = x[shift] ^ m_bias[shift];
        return (x[shift] and p->ch[!bit] ? p->ch[!bit]->cnt : 0) + get_lower(p->ch[bit], x, shift - 1);
    }
    size_type get_upper(Node *p, const std::bitset<B> &x, int shift = B - 1) const {
        if(p == nullptr) return 0;
        if(shift < 0) return p->cnt;
        bool bit = x[shift] ^ m_bias[shift];
        return (x[shift] and p->ch[!bit] ? p->ch[!bit]->cnt : 0) + get_upper(p->ch[bit], x, shift - 1);
    }
    Node *dfs_clear(Node *p) {
        if(p == nullptr) return nullptr;
        for(bool bit : {0, 1}) p->ch[bit] = dfs_clear(p->ch[bit]);
        delete p;
        return p = nullptr;
    }
    void dfs_print(std::ostream &os, Node *p, std::bitset<B> &x, int &cnt, int shift = B - 1) const {
        if(shift < 0) {
            os << (cnt == 0 ? "" : "\n ") << "{" << x << " (" << x.to_ullong() << "), " << p->cnt << "}";
            cnt++;
            return;
        }
        for(bool bit : {0, 1}) {
            x[shift] = bit;
            bit ^= m_bias[shift];
            if(p->ch[bit]) dfs_print(os, p->ch[bit], x, cnt, shift - 1);
        }
    }

public:
    BinaryTrie() : m_root(nullptr), m_bias(0) {}
    ~BinaryTrie() {
        clear();
    }

    std::bitset<B> operator[](size_type k) const { return kth_element(k); }

    // 要素が空かどうか判定する．O(1).
    bool empty() const { return m_root == nullptr; }
    // 全要素数を返す．O(1).
    size_type size() const { return (m_root ? m_root->cnt : 0); }
    // 値xの要素が多重集合に含まれるか判定する．O(B).
    bool exist(const std::bitset<B> &x) const { return find(x); }
    // 値xの要素数を返す．O(B).
    size_type count(const std::bitset<B> &x) const {
        Node *p = find(x);
        return (p ? p->cnt : 0);
    }
    // 多重集合に値xの要素を追加する．O(B).
    void insert(const std::bitset<B> &x, size_type cnt = 1) {
        if(cnt == 0) return;
        m_root = add(m_root, x, cnt);
    }
    // 多重集合から値xの要素を削除する．O(B).
    void erase(const std::bitset<B> &x, size_type cnt = 1) {
        assert(count(x) >= cnt);
        if(cnt == 0) return;
        m_root = sub(m_root, x, cnt);
    }
    // 多重集合内で最小の要素値を取得する．O(B).
    std::bitset<B> min_element() const { return kth_element(0); }
    // 多重集合内で最大の要素値を取得する．O(B).
    std::bitset<B> max_element() const { return kth_element(size() - 1); }
    // 多重集合内でk番目に小さい要素値を取得する．0-based index. O(B).
    std::bitset<B> kth_element(size_type k) const {
        assert(0 <= k and k < size());
        return get(m_root, k);
    }
    // 集合内で値x以上である最小の要素番号を取得する．O(B).
    size_type lower_bound(const std::bitset<B> &x) const { return get_lower(m_root, x); }
    // 集合内で値xより大きい最小の要素番号を取得する．O(B).
    size_type upper_bound(const std::bitset<B> &x) const { return get_upper(m_root, x); }
    // 全要素値にxorの操作を行う．O(1).
    void operator_xor(const std::bitset<B> &x) { m_bias ^= x; }
    // xorの操作をする値を返す．O(1).
    std::bitset<B> xor_value() const { return m_bias; }
    // 全要素を削除する．
    void clear() { m_root = dfs_clear(m_root); }

    friend std::ostream &operator<<(std::ostream &os, const BinaryTrie &ob) {
        std::bitset<B> x(0);
        int cnt = 0;
        os << "[";
        if(ob.m_root) ob.dfs_print(os, ob.m_root, x, cnt);
        os << "]";
        return os;
    }
};

}  // namespace algorithm

#endif
