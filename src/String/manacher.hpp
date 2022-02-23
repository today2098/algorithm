#ifndef ALGORITHM_MANACHER_HPP
#define ALGORITHM_MANACHER_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// 最長回文 (Longest Palindromic Substring)．
template <class C>
class Manacher {
    int n;  // n:=(配列サイズ).
    // len[2*k]:=(k文字目を中心とする最長回文の半径), len[2*k-1]:=(k-1文字目とk文字目の間を中心とする最長回文の半径).
    std::vector<int> len;

    void manacher(const C &t) {
        int i = 0, j = 0;
        while(i < 2 * n - 1) {
            while(0 <= i - j and i + j < 2 * n - 1 and t[i - j] == t[i + j]) j++;
            len[i] = j;
            int k = 1;
            while(i - k >= 0 and len[i - k] + k < j) {
                len[i + k] = len[i - k];
                k++;
            }
            i += k, j -= k;
        }
    }

public:
    // constructor. 引数はstringやvectorなど，STLの配列クラス．O(|S|).
    Manacher() : Manacher(C()) {}
    explicit Manacher(const C &s) : n(s.size()), len(2 * s.size()) {
        C t(2 * n, 0);
        for(int i = 0; i < n; ++i) t[2 * i] = s[i];
        manacher(t);
    }

    int get_odd(int k) const {  // k文字目を中心とする最長奇数長回文の半径を返す．
        assert(0 <= k and k < n);
        return (len[2 * k] + 1) / 2;
    }
    int get_even(int k) const {  // k-1文字目とk文字目の間を中心とする最長偶数長回文の半径を返す．
        assert(1 <= k and k < n);
        return len[2 * k - 1] / 2;
    }
    bool is_palindrome(int l, int r) const {  // 部分列s[l:r]が回文か判定する．
        assert(0 <= l and l < r and r <= n);
        int mid = (l + r) / 2;
        if((r - l) & 1)
            return get_odd(mid) == (r - l + 1) / 2;
        else
            return get_even(mid) == (r - l) / 2;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_MANACHER_HPP
