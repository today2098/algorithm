#ifndef ALGORITHM_DYNAMIC_SEGMENT_TREE_HPP
#define ALGORITHM_DYNAMIC_SEGMENT_TREE_HPP 1

/**
 * @brief Dynamic Segment Tree（動的セグメント木）
 * @docs docs/DataStructure/SegmentTree/dynamic_segment_tree.md
 */

#include <cassert>
#include <functional>
#include <iostream>
#include <memory>
#include <utility>

namespace algorithm {

// Dynamic Segment Tree（動的セグメント木）.
template <typename S>
class DynamicSegTree {
public:
    using value_type = S;
    using size_type = size_t;

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        size_type index;
        S value;
        S product;
        node_ptr left, right;
        explicit Node(size_type index_, const S &value_)
            : index(index_), value(value_), product(value_), left(nullptr), right(nullptr) {}
    };

    using Op = std::function<S(const S &, const S &)>;

    Op m_op;          // S m_op(S,S):=(二項演算関数).
    S m_e;            // m_e:=(単位元).
    size_type m_sz;   // m_sz:=(要素数).
    node_ptr m_root;  // m_root:=(根のポインタ).

    void update(const node_ptr &p) const {
        assert(p);
        const S &lhs = (p->left ? p->left->product : identity());
        const S &rhs = (p->right ? p->right->product : identity());
        p->product = m_op(m_op(lhs, p->value), rhs);
    }
    void set(node_ptr &p, size_type l, size_type r, size_type k, S a) {
        assert(0 <= l and l <= k and k < r and r <= size());
        if(!p) {
            p = std::make_unique<Node>(k, a);
            return;
        }
        if(p->index == k) {
            p->value = a;
            update(p);
            return;
        }
        size_type mid = (l + r) / 2;
        if(k < mid) {
            if(p->index < k) std::swap(p->index, k), std::swap(p->value, a);
            set(p->left, l, mid, k, a);
        } else {
            if(k < p->index) std::swap(k, p->index), std::swap(a, p->value);
            set(p->right, mid, r, k, a);
        }
        update(p);
    }
    S get(const node_ptr &p, size_type l, size_type r, size_type k) const {
        assert(0 <= l and l <= r and r <= size());
        if(!p) return identity();
        if(p->index == k) return p->value;
        size_type mid = (l + r) / 2;
        if(l < mid) return get(p->left, l, mid, k);
        return get(p->left, mid, r, k);
    }
    S prod(const node_ptr &p, size_type l, size_type r, size_type nl, size_type nr) const {
        assert(0 <= l and l <= r and r <= size());
        assert(0 <= nl and nl <= nr and nr <= size());
        if(!p or nr <= l or r <= nl) return identity();
        if(nl <= l and r <= nr) return p->product;
        size_type mid = (l + r) / 2;
        S &&res = prod(p->left, l, mid, nl, nr);
        if(nl <= p->index and p->index < nr) res = m_op(res, p->value);
        res = m_op(res, prod(p->right, mid, r, nl, nr));
        return res;
    }
    template <class Func>
    size_type most_right(const node_ptr &p, size_type l, size_type r, const Func &jud, size_type nl, S &product) const {
        assert(0 <= l and l <= r and r <= size());
        assert(0 <= nl and nl <= size());
        if(!p or r <= nl) return r;
        if(nl <= l and jud(m_op(product, p->product))) {
            product = m_op(product, p->product);
            return r;
        }
        size_type mid = (l + r) / 2;
        size_type res = most_right(p->left, l, mid, jud, nl, product);
        if(res != mid) return res;
        if(nl <= p->index) {
            product = m_op(product, p->value);
            if(!jud(product)) return p->index;
        }
        return most_right(p->right, mid, r, jud, nl, product);
    }
    template <class Func>
    size_type most_left(const node_ptr &p, size_type l, size_type r, const Func &jud, size_type nr, S &product) const {
        assert(0 <= l and l <= r and r <= size());
        assert(0 <= nr and nr <= size());
        if(!p or nr <= l) return l;
        if(r <= nr and jud(m_op(p->product, product))) {
            product = m_op(p->product, product);
            return l;
        }
        size_type mid = (l + r) / 2;
        size_type res = most_left(p->right, mid, r, jud, nr, product);
        if(res != mid) return res;
        if(p->index < nr) {
            product = m_op(p->value, product);
            if(!jud(product)) return p->index + 1;
        }
        return most_left(p->left, l, mid, jud, nr, product);
    }
    void reset(node_ptr &p, size_type l, size_type r, size_type nl, size_type nr) {
        assert(0 <= l and l <= r and r <= size());
        assert(0 <= nl and nl <= nr and nr <= size());
        if(!p or nr <= l or r <= nl) return;
        if(nl <= l and r <= nr) {
            p.reset();
            return;
        }
        size_type mid = (l + r) / 2;
        reset(p->left, l, mid, nl, nr);
        reset(p->right, mid, r, nl, nr);
        if(nl <= p->index and p->index < nr) p->value = identity();
        if(!p->left and !p->right and p->value == identity()) {
            p.reset();
            return;
        }
        update(p);
    }

public:
    // constructor. O(N).
    DynamicSegTree(){};
    explicit DynamicSegTree(const Op &op, const S &e, size_type n)
        : m_op(op), m_e(e), m_sz(n), m_root(nullptr) {}

    // 要素数を返す．
    size_type size() const { return m_sz; }
    // 単位元を返す．
    S identity() const { return m_e; }
    // k番目の要素をaに置き換える．O(logN).
    void set(size_type k, const S &a) {
        assert(0 <= k and k < size());
        set(m_root, 0, size(), k, a);
    }
    // k番目の要素を返す．O(logN).
    S prod(size_type k) const {
        assert(0 <= k and k < size());
        return get(m_root, 0, size(), k);
    }
    // 区間[l,r)の要素の総積 v[l]•v[l+1]•...•v[r-1] を求める．O(logN).
    S prod(size_type l, size_type r) const {
        assert(0 <= l and l <= r and r <= size());
        return prod(m_root, 0, size(), l, r);
    }
    // 区間全体の要素の総積を返す．O(1).
    S prod_all() const { return (m_root ? m_root->product : identity()); }
    // jud(prod(l,-))==true となる区間の最右位値を二分探索する．
    // ただし，要素列には単調性があり，また jud(e)==true であること．O(logN).
    template <class Func = std::function<bool(const S &)> >
    size_type most_right(const Func &jud, int l) const {
        assert(jud(identity()));
        assert(0 <= l and l <= size());
        S product = identity();
        return most_right(m_root, 0, size(), jud, l, product);
    }
    // jud(prod(-,r))==true となる区間の最左位値を二分探索する．
    // ただし，要素列には単調性があり，また jud(e)==true であること．O(logN).
    template <class Func = std::function<bool(const S &)> >
    size_type most_left(const Func &jud, int r) const {
        assert(jud(identity()));
        assert(0 <= r and r <= size());
        S product = identity();
        return most_left(m_root, 0, size(), jud, r, product);
    }
    void reset() { m_root.reset(); }
    void reset(size_type l, size_type r) {
        assert(0 <= l and l <= r and r <= size());
        reset(m_root, 0, size(), l, r);
    }

    friend std::ostream &operator<<(std::ostream &os, const DynamicSegTree &segtree) {
        os << "[";
        bool first = true;
        auto dfs = [&](auto self, const node_ptr &p) -> void {
            if(!p) return;
            self(self, p->left);
            os << (first ? "" : " ") << "{" << p->index << ", " << p->value << "}";
            first = false;
            self(self, p->right);
        };
        dfs(dfs, segtree.m_root);
        os << "]";
        return os;
    }
};

}  // namespace algorithm

#endif
