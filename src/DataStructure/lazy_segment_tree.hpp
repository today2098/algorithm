#ifndef ALGORITHM_LAZY_SEGMENT_TREE_HPP
#define ALGORITHM_LAZY_SEGMENT_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

namespace algorithm {

// 遅延評価セグメント木．
template <class Monoid, class Action>
class LazySegTree {
    using FM = std::function<Monoid(Monoid, Monoid)>;
    using FA = std::function<void(Monoid &, Action)>;
    using FC = std::function<void(Action &, Action)>;

    FM m_op;                     // Monoid m_op(Monoid,Monoid):=(二項演算関数). M•M.
    FA m_action;                 // void m_action(Monoid&,Action):=(作用素によるモノイド元への作用). M×A.
    FC m_composition;            // void m_composition(Action&,Action):=(作用素の合成). A•A.
    Monoid m_e;                  // m_e:=(単位元).
    Action m_id;                 // m_id:=(作用素の単位元).
    int m_sz;                    // m_sz:=(要素数).
    int m_n;                     // m_n:=(二分木の葉数).
    int m_depth;                 // m_depth:=(二分木の深さ).
    std::vector<Monoid> m_tree;  // m_tree(2n)[]:=(完全二分木). 1-based index.
    std::vector<Action> m_lazy;  // m_lazy(n)[k]:=(m_tree[k]の子 (m_tree[2k], m_tree[2k+1]) に対する遅延評価).

    void apply0(int k, const Action &d) {
        assert(1 <= k and k < 2 * m_n);
        m_action(m_tree[k], d);
        if(k < m_n) m_composition(m_lazy[k], d);
    }
    void push(int k) {
        assert(1 <= k and k < m_n);
        apply0(k << 1, m_lazy[k]);
        apply0(k << 1 | 1, m_lazy[k]);
        m_lazy[k] = action_identity();
    }
    void update(int k) {
        assert(1 <= k and k < m_n);
        m_tree[k] = m_op(m_tree[k << 1], m_tree[k << 1 | 1]);
    }

public:
    // constructor. O(N).
    LazySegTree() {}
    explicit LazySegTree(const FM &op, const FA &action, const FC &composition, const Monoid &e, const Action &id, size_t n)
        : m_op(op), m_action(action), m_composition(composition), m_e(e), m_id(id), m_sz(n), m_n(1), m_depth(0) {
        while(m_n < size()) m_n <<= 1, m_depth++;
        m_tree.assign(2 * m_n, identity());
        m_lazy.assign(m_n, action_identity());
    }
    explicit LazySegTree(const FM &op, const FA &action, const FC &composition, const Monoid &e, const Action &id, const std::vector<Monoid> &v)
        : LazySegTree(op, action, composition, e, id, v.size()) {
        std::copy(v.begin(), v.end(), m_tree.begin() + m_n);
        for(int i = m_n - 1; i >= 1; --i) update(i);
    }

    // 要素数を返す．
    int size() const { return m_sz; }
    // モノイドの単位元を返す．
    Monoid identity() const { return m_e; }
    // 作用素の単位元を返す．
    Action action_identity() const { return m_id; }
    // k番目の要素をaに置き換える．O(logN).
    void set(int k, const Monoid &a) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = a;
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // 区間[l,-)の要素をv[]に置き換える．O(N).
    void set(int l, const std::vector<Monoid> &v) {
        int r = l + v.size();
        assert(0 <= l and r <= size());
        if(l == r) return;
        l += m_n, r += m_n;
        for(int i = m_depth; i >= 1; --i) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }
        std::copy(v.begin(), v.end(), m_tree.begin() + l);
        for(int i = 1; i <= m_depth; ++i) {
            int l2 = (l >> i), r2 = ((r - 1) >> i);
            for(int j = l2; j <= r2; ++j) update(j);
        }
    }
    // k番目の要素を作用素dを用いて更新する．O(logN).
    void apply(int k, const Action &d) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_action(m_tree[k], d);
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // 区間[l,r)を作用素dを用いて更新する．O(logN).
    void apply(int l, int r, const Action &d) {
        assert(0 <= l and l <= r and r <= size());
        if(l == r) return;
        l += m_n, r += m_n;
        for(int i = m_depth; i >= 1; --i) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }
        for(int l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {
            if(l2 & 1) apply0(l2++, d);
            if(r2 & 1) apply0(--r2, d);
        }
        for(int i = 1; i <= m_depth; ++i) {
            if(((l >> i) << i) != l) update(l >> i);
            if(((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
    // 一点取得．O(logN).
    Monoid prod(int k) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        return m_tree[k];
    }
    // 区間[l,r)の総積 (v[l]•v[l+1]•....•v[r-1]) を求める．O(logN).
    Monoid prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if(l == r) return identity();
        l += m_n, r += m_n;
        for(int i = m_depth; i >= 1; --i) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }
        Monoid val_l = identity(), val_r = identity();
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) val_l = m_op(val_l, m_tree[l++]);
            if(r & 1) val_r = m_op(m_tree[--r], val_r);
        }
        return m_op(val_l, val_r);
    }
    // 区間全体の総積を返す．O(1).
    Monoid prod_all() const { return m_tree[1]; }
    // jud(prod(l,-))=true となる区間の最右位値を二分探索する．
    // ただし要素列には単調性があり，また jud(e)=true であること．O(logN).
    int most_right(const std::function<bool(Monoid)> &jud, int l) const {
        assert(jud(identity()));
        assert(0 <= l and l <= size());
        if(l == size()) return size();
        l += m_n;
        for(int i = m_depth; i >= 1; --i) push(l >> i);
        Monoid val = identity();
        do {
            while(!(l & 1)) l >>= 1;
            Monoid &&tmp = m_op(val, m_tree[l]);
            if(!jud(tmp)) {
                while(l < m_n) {
                    push(l);
                    l *= 2;
                    Monoid &&tmp2 = m_op(val, m_tree[l]);
                    if(jud(tmp2)) val = tmp2, l++;
                }
                return l - m_n;
            }
            val = tmp, l++;
        } while((l & -l) != l);  // (x&-x)==x のとき，xは2の階乗数．
        return size();
    }
    // jud(prod(-,r))=true となる区間の最左位値を二分探索する．
    // ただし要素列には単調性があり，また jud(e)=true であること．O(logN).
    int most_left(const std::function<bool(Monoid)> &jud, int r) const {
        assert(jud(identity()));
        assert(0 <= r and r <= size());
        if(r == 0) return 0;
        r += m_n;
        for(int i = m_depth; i >= 1; --i) push((r - 1) >> i);
        Monoid val = identity();
        do {
            r--;
            while(r > 1 and r & 1) r >>= 1;
            Monoid &&tmp = m_op(m_tree[r], val);
            if(!jud(tmp)) {
                while(r < m_n) {
                    push(r);
                    r = 2 * r + 1;
                    Monoid &&tmp2 = m_op(m_tree[r], val);
                    if(jud(tmp2)) val = tmp2, r--;
                }
                return r - m_n + 1;
            }
            val = tmp;
        } while((r & -r) != r);  // (x&-x)==x のとき，xは2の階乗数．
        return 0;
    }
    void reset() {
        std::fill(m_tree.begin(), m_tree.end(), identity());
        std::fill(m_lazy.begin(), m_lazy.end(), action_identity());
    }
};

}  // namespace algorithm

#endif
