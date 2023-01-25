#ifndef ALGORITHM_BINARY_TRIE_HPP
#define ALGORITHM_BINARY_TRIE_HPP 1

#include <bitset>
#include <cassert>
#include <vector>

namespace algorithm {

// 非負整数値を扱うTrie木．
template <typename T = unsigned, int B = 32, typename U = size_t>  // T:非負整数値の型, B:ビット長, U:サイズの型.
class BinaryTrie {
    struct Node {
        U cnt;        // cnt:=(自身を根とする部分木に含まれる要素数).
        Node *ch[2];  // ch[]:=(子のポインタ). 二分木．
        Node() : cnt(0), ch({nullptr, nullptr}) {}
    };

    Node *root;  // root:=(根のポインタ).

    void delete_subtree(Node *rt) {
        if(rt == nullptr) return;
        for(bool bit : {0, 1}) {
            delete_subtree(rt->ch[bit]);
            rt->ch[bit] = nullptr;
        }
        delete rt;
        rt = nullptr;
    }
    Node *add(Node *p, T x, U cnt, int shift = B - 1) {  // Top down.
        if(p == nullptr) p = new Node;
        p->cnt += cnt;
        if(shift < 0) return p;
        bool bit = (x >> shift) & (T)1;
        p->ch[bit] = add(p->ch[bit], x, cnt, shift - 1);
        return p;
    }
    Node *sub(Node *p, T x, U cnt, int shift = B - 1) {  // Top down.
        assert(p != nullptr and p->cnt >= cnt);
        p->cnt -= cnt;
        if(p->cnt == 0) {
            delete_subtree(p);
            return p = nullptr;
        }
        if(shift < 0) return p;
        bool bit = (x >> shift) & (T)1;
        p->ch[bit] = sub(p->ch[bit], x, cnt, shift - 1);
        return p;
    }
    T get_min(Node *p, T bias = 0, int shift = B - 1) const {
        assert(p != nullptr);
        if(shift < 0) return 0;
        bool bit = (bias >> shift) & (T)1;
        if(p->ch[bit] == nullptr) bit = !bit;
        return get_min(p->ch[bit], bias, shift - 1) | ((T)bit << shift);
    }
    T get(Node *p, U k, T bias = 0, int shift = B - 1) const {
        assert(p != nullptr);
        if(shift < 0) return 0;
        bool bit = (bias >> shift) & (T)1;
        U m = (p->ch[bit] == nullptr ? 0 : p->ch[bit]->cnt);
        if(k < m) {
            return get(p->ch[bit], k, bias, shift - 1) | ((T)bit << shift);
        } else {
            bit = !bit;
            return get(p->ch[bit], k - m, bias, shift - 1) | ((T)bit << shift);
        }
    }
    U get_lower(Node *p, T x, int shift = B - 1) const {
        if(p == nullptr or shift < 0) return 0;
        bool bit = (x >> shift) & (T)1;
        return ((bit and p->ch[0] != nullptr) ? p->ch[0]->cnt : 0) + get_lower(p->ch[bit], x, shift - 1);
    }
    void dfs(std::ostream &os, Node *p, std::bitset<B> &bits, int shift = B - 1) const {
        if(shift < 0) {
            os << "[" << bits << "] (num: " << (T)bits.to_ullong() << ", cnt: " << p->cnt << ")\n";
            return;
        }
        for(bool bit : {0, 1}) {
            if(p->ch[bit] != nullptr) {
                bits.set(shift, bit);
                dfs(os, p->ch[bit], bits, shift - 1);
            }
        }
    }

public:
    BinaryTrie() : root(nullptr) {
        static_assert(B >= 1);
    }
    ~BinaryTrie() {
        clear();
    }

    // 集合内でk番目に小さい値を取得する．O(B).
    T operator[](U k) const {
        assert(0 <= k and k < size());
        return get(root, k);
    }

    // 要素が空かどうか判定する．O(1).
    bool empty() const { return root == nullptr; }
    // 要素数を返す．O(1).
    U size() const { return (root == nullptr ? 0 : root->cnt); }
    // 値xの要素数を返す．O(B).
    U count(T x) const {
        if(root == nullptr) return 0;
        Node *p = root;
        for(int i = B - 1; i >= 0; --i) {
            p = p->ch[(x >> i) & (T)1];
            if(p == nullptr) return 0;
        }
        return p->cnt;
    }
    // 集合に値xを追加する．O(B).
    void insert(T x, U cnt = 1) { root = add(root, x, cnt); }
    // 集合から値xを削除する．O(B).
    void erase(T x, U cnt = 1) {
        assert(count(x) >= cnt);
        root = sub(root, x, cnt);
    }
    // 集合内で値xとXORしたときに最小となる値を取得する．O(B).
    T min_element(T x = 0) const { return get_min(root, x); }
    // 集合内で値xとXORしたときに最大となる値を取得する．O(B).
    T max_element(T x = 0) const { return get_min(root, ~x); }
    // 集合内で値xとXORしたときにk番目に小さい値を取得する．O(B).
    T kth_element(U k, T x = 0) const {
        assert(0 <= k and k < size());
        return get(root, k, x);
    }
    // 集合内で値x以上の最小の要素番号を取得する．O(B).
    U lower_bound(T x) const { return get_lower(root, x); }
    // 集合内で値xより大きい最小の要素番号を取得する．O(B).
    U upper_bound(T x) const { return get_lower(root, x + 1); }
    // 全要素を削除する．
    void clear() {
        delete_subtree(root);
        root = nullptr;
    }

    friend std::ostream &operator<<(std::ostream &os, const BinaryTrie &ob) {
        if(ob.empty()) return os;
        std::bitset<B> bits(0);
        ob.dfs(os, ob.root, bits);
    }
};

}  // namespace algorithm

#endif

/*
参考文献
- kazuma，非負整数値を扱うTrieについて，Hatena Blog, https://kazuma8128.hatenablog.com/entry/2018/05/06/022654（参照2022.9.11）．
*/
