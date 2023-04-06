#ifndef ALGORITHM_HEAP_HPP
#define ALGORITHM_HEAP_HPP 1

#include <cassert>
#include <functional>
#include <vector>

namespace algorithm {

// 二分ヒープ．
template <typename T>
class Heap {
    using F = std::function<bool(T &, T &)>;

    F m_comp;               // bool m_comp(T&,T&):=(比較演算関数).
    int m_sz;               // m_sz:=(要素数).
    std::vector<T> m_tree;  // m_tree[]:=(二分木). 1-based index.

    int shift_up(int k) {
        assert(1 <= k and k <= size());
        if(k == 1) return 1;
        int par = k / 2;
        if(m_comp(m_tree[par], m_tree[k])) return k;
        std::swap(m_tree[par], m_tree[k]);
        return par;
    }
    void all_shift_up(int k) {
        while(1) {
            int next = shift_up(k);
            if(next == k) return;
            k = next;
        }
    }
    int shift_down(int k) {
        assert(1 <= k and k <= size());
        if(k > size() / 2) return k;
        int l = 2 * k, r = 2 * k + 1;
        if(r > size() or m_comp(m_tree[l], m_tree[r])) {
            if(m_comp(m_tree[k], m_tree[l])) return k;
            std::swap(m_tree[k], m_tree[l]);
            return l;
        } else {
            if(m_comp(m_tree[k], m_tree[r])) return k;
            std::swap(m_tree[k], m_tree[r]);
            return r;
        }
    }
    void all_shift_down(int k) {
        while(1) {
            int next = shift_down(k);
            if(next == k) return;
            k = next;
        }
    }
    void heap_sort() {
        int k = size() / 2;
        for(int i = k; i >= 1; --i) all_shift_down(i);
    }

public:
    // constructor. O(N*logN).
    Heap() : Heap([](const T &a, const T &b) -> bool { return a > b; }, std::vector<T>(0)) {}
    explicit Heap(const F &comp) : Heap(comp, std::vector<T>(0)) {}
    explicit Heap(const std::vector<T> &v) : Heap([](const T &a, const T &b) -> bool { return a > b; }, v) {}
    explicit Heap(const F &comp, const std::vector<T> &v) : m_comp(comp), m_sz(v.size()), m_tree(v.size() + 1) {
        if(size() > 0) {
            std::copy(v.begin(), v.end(), m_tree.begin() + 1);
            heap_sort();
        }
    }
    ~Heap() {
        std::vector<T>().swap(m_tree);
    }

    bool empty() const { return size() == 0; }
    int size() const { return m_sz; }
    // 要素参照．O(1).
    T top() const {
        assert(!empty());
        return m_tree[1];
    }
    // 要素追加．O(logN).
    void push(const T &a) {
        m_tree.push_back(a);
        m_sz++;
        all_shift_up(size());
    }
    // 要素削除．O(logN).
    T pop() {
        assert(!empty());
        T res = m_tree[1];
        m_tree[1] = m_tree[size()];
        m_tree.pop_back();
        m_sz--;
        if(size() > 0) all_shift_down(1);
        return res;
    }
    // ヒープソート．O(N*logN).
    void heap_sort(const F &comp) {
        m_comp = comp;
        heap_sort();
    }
};

}  // namespace algorithm

#endif
