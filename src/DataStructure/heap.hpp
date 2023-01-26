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

    F comp;               // bool comp(T&,T&):=(比較演算関数).
    int sz;               // sz:=(要素数).
    std::vector<T> tree;  // tree[]:=(二分木). 1-based index.

    int shift_up(int k) {
        assert(1 <= k and k <= sz);
        if(k == 1) return 1;
        int par = k / 2;
        if(comp(tree[par], tree[k])) return k;
        std::swap(tree[par], tree[k]);
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
        assert(1 <= k and k <= sz);
        if(k > sz / 2) return k;
        int l = 2 * k, r = 2 * k + 1;
        if(r > sz or comp(tree[l], tree[r])) {
            if(comp(tree[k], tree[l])) return k;
            std::swap(tree[k], tree[l]);
            return l;
        } else {
            if(comp(tree[k], tree[r])) return k;
            std::swap(tree[k], tree[r]);
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
        int k = sz / 2;
        for(int i = k; i >= 1; --i) all_shift_down(i);
    }

public:
    // constructor. O(N*logN).
    Heap() : Heap([](const T &a, const T &b) -> bool { return a > b; }, std::vector<T>(0)) {}
    explicit Heap(const F &comp_) : Heap(comp_, std::vector<T>(0)) {}
    explicit Heap(const std::vector<T> &v) : Heap([](const T &a, const T &b) -> bool { return a > b; }, v) {}
    explicit Heap(const F &comp_, const std::vector<T> &v) : comp(comp_), sz(v.size()), tree(v.size() + 1) {
        if(sz > 0) {
            std::copy(v.begin(), v.end(), tree.begin() + 1);
            heap_sort();
        }
    }
    ~Heap() {
        std::vector<T>().swap(tree);
    }

    bool empty() const { return sz == 0; }
    int size() const { return sz; }
    // 要素参照．O(1).
    T top() const {
        assert(!empty());
        return tree[1];
    }
    // 要素追加．O(logN).
    void push(const T &a) {
        tree.push_back(a);
        sz++;
        all_shift_up(sz);
    }
    // 要素削除．O(logN).
    T pop() {
        assert(!empty());
        T res = tree[1];
        tree[1] = tree[sz];
        tree.pop_back();
        sz--;
        if(sz > 0) all_shift_down(1);
        return res;
    }
    // ヒープソート．O(N*logN).
    void heap_sort(const F &comp_) {
        comp = comp_;
        heap_sort();
    }
};

}  // namespace algorithm

#endif
