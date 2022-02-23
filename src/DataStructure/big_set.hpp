#ifndef ALGORITHM_BIG_SET_HPP
#define ALGORITHM_BIG_SET_HPP 1

#include <cassert>
#include <iostream>
#include <iterator>
#include <set>
#include <utility>

namespace algorithm {

// 連続した整数列の集合を管理するデータ構造．
template <typename T>
class BigSet {
    std::set<std::pair<T, T> > st;  // st:=(整数の集合). 連続する整数列[l,r)をpair(l,r)で表現する．
    T inf;

public:
    // constructor.
    explicit BigSet(T inf_ = 1e9) : inf(inf_) {
        st.emplace(-inf, -inf + 1);  // 番兵．
        st.emplace(inf, inf + 1);    // 〃
    }

    T infinity() const { return inf; }
    bool insert(T x) { return insert(x, x + 1); }  // 整数xを挿入する．
    bool insert(T l, T r) {                        // 整数列[l,r)を挿入する．O(logN).
        assert(-inf < l and l < r and r <= inf);
        auto itr1 = std::prev(st.lower_bound(std::pair<T, T>(l + 1, l + 2)));
        auto [l1, r1] = *itr1;
        if(r <= r1) return false;  // 集合に完全に含まれている場合．
        auto itr3 = st.lower_bound(std::pair<T, T>(r, r + 1));
        auto itr2 = std::prev(itr3);
        auto [l2, r2] = *itr2;
        auto [l3, r3] = *itr3;
        if(l <= r1)
            l = l1;
        else
            itr1++;
        if(l3 <= r) {
            st.erase(itr1, ++itr3);
            st.emplace(l, r3);
        } else {
            st.erase(itr1, itr3);
            if(r <= r2)
                st.emplace(l, r2);
            else
                st.emplace(l, r);
        }
        return true;
    }
    bool erase(T x) { return erase(x, x + 1); }  // 整数xを削除する．
    bool erase(T l, T r) {                       // 範囲[l,r)の整数列を削除する．O(logN).
        assert(-inf < l and l < r and r <= inf);
        auto itr1 = std::prev(st.lower_bound(std::pair<T, T>(l + 1, l + 2)));
        auto itr3 = st.lower_bound(std::pair<T, T>(r, r + 1));
        auto itr2 = std::prev(itr3);
        auto [l1, r1] = *itr1;
        auto [l2, r2] = *itr2;
        if(l < r1) {
            st.erase(itr1, itr3);
            if(l1 < l) st.emplace(l1, l);
        } else {
            if(itr1 == itr2) return false;  // 集合に全く含まれていない場合．
            st.erase(++itr1, itr3);
        }
        if(r < r2) st.emplace(r, r2);
        return true;
    }
    bool contains(T x) const { return contains(x, x + 1); }  // 整数xが集合に含まれるか判定する．
    bool contains(T l, T r) const {                          // 整数列[l,r)が集合に完全に含まれるか判定する．(logN).
        assert(-inf < l and l < r and r <= inf);
        const auto &[ignore, pr] = *std::prev(st.lower_bound(std::pair<T, T>(l + 1, l + 2)));
        return r <= pr;
    }
    T mex(T x) const {  // 集合に含まれないx以上の整数の中で最小の値 (MEX:Minimum EXcluded value) を求める．O(logN).
        assert(-inf < x and x < inf);
        const auto &[ignore, r] = *std::prev(st.lower_bound(std::pair<T, T>(x + 1, x + 2)));
        return (x < r ? r : x);
    }

    friend std::ostream &operator<<(std::ostream &os, const BigSet<T> &ob) {
        for(const auto &[l, r] : ob.st) os << "[" << l << ", " << r << ") ";
        os << std::endl;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_BIG_SET_HPP
