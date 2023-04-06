#ifndef ALGORITHM_MANACHER_HPP
#define ALGORITHM_MANACHER_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// 最長回文 (Longest Palindromic Substring)．
template <class Sequence>
class Manacher {
    int m_sz;  // m_sz:=(配列サイズ).
    // m_radius[2*k]:=(k文字目を中心とする奇数長の最長回文の半径),
    // m_radius[2*k-1]:=(k-1文字目とk文字目の間を中心とする偶数長の最長回文の半径).
    std::vector<int> m_radius;

public:
    // constructor. 引数はSTLのシーケンスコンテナ．O(|S|).
    Manacher() : Manacher(Sequence()) {}
    explicit Manacher(const Sequence &s) : m_sz(s.size()), m_radius(2 * s.size()) {
        Sequence t(2 * size(), 0);
        for(int i = 0; i < size(); ++i) t[2 * i] = s[i];
        int i = 0, j = 0;
        while(i < 2 * size() - 1) {
            while(0 <= i - j and i + j < 2 * size() - 1 and t[i - j] == t[i + j]) j++;
            m_radius[i] = j;
            int k = 1;
            while(i - k >= 0 and m_radius[i - k] + k < j) {
                m_radius[i + k] = m_radius[i - k];
                k++;
            }
            i += k, j -= k;
        }
    }

    int size() const { return m_sz; }
    // k文字目を中心とする奇数長の最長回文の半径を返す．
    int get_odd(int k) const {
        assert(0 <= k and k < size());
        return (m_radius[2 * k] + 1) / 2;
    }
    // k-1文字目とk文字目の間を中心とする偶数長の最長回文の半径を返す．
    int get_even(int k) const {
        assert(1 <= k and k < size());
        return m_radius[2 * k - 1] / 2;
    }
    // 部分列s[l:r]が回文か判定する．
    bool is_palindrome(int l, int r) const {
        assert(0 <= l and l < r and r <= size());
        int mid = (l + r) / 2;
        return ((r - l) & 1 ? get_odd(mid) >= (r - l + 1) / 2 : get_even(mid) >= (r - l) / 2);
    }
};

}  // namespace algorithm

#endif
