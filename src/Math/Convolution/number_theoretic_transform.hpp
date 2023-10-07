#ifndef ALGORITHM_NUMBER_THEORETIC_TRANSFORM_HPP
#define ALGORITHM_NUMBER_THEORETIC_TRANSFORM_HPP 1

/**
 * @brief Number Theoretic Transform（数論変換）
 * @docs docs/Math/Convolution/number_theoretic_transform.md
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <utility>
#include <vector>

#include "../ModularArithmetic/dynamic_modint.hpp"
#include "../ModularArithmetic/modint.hpp"

namespace algorithm {

namespace ntt {

constexpr int MOD = 998'244'353;   // 998'244'353 = 2^23 * 7 * 17 + 1.
constexpr int MOD1 = 167'772'161;  // 167'772'161 = 2^25 * 5 + 1.
constexpr int MOD2 = 469'762'049;  // 469'762'049 = 2^26 * 7 + 1.
constexpr int MOD3 = 754'974'721;  // 754'974'721 = 2^24 * 3^2 * 5 + 1.
// constexpr int MOD4 = 1'107'296'257;  // 1'107'296'257 = 2^25 * 3 * 11 + 1.
// constexpr int MOD5 = 1'224'736'769;  // 1'224'736'769 = 2^24 * 73 + 1.
// constexpr int MOD6 = 1'711'276'033;  // 1'224'736'769 = 2^25 * 3 * 17 + 1.
// constexpr int MOD7 = 1'811'939'329;  // 1'224'736'769 = 2^26 * 3^3 + 1.

// 繰り返し二乗法（mod付き）．
// a^k (mod m) を求める．O(logK).
long long mod_pow(long long a, long long k, int m) {
    assert(k >= 0);
    assert(m >= 1);
    long long res = 1;
    a %= m;
    while(k > 0) {
        if(k & 1LL) res = res * a % m;
        a = a * a % m;
        k >>= 1;
    }
    return res;
}

// 素数mを法とする最小の原始根を求める．
constexpr int primitive_root(int m) {
    assert(m >= 2);
    if(m == 2) return 1;
    if(m == 998'244'353) return 3;
    if(m == 167'772'161) return 3;
    if(m == 469'762'049) return 3;
    if(m == 754'974'721) return 11;
    std::array<int, 20> divs({2});  // divs[]:=(m-1の素因数).
    int cnt = 1;
    int n = (m - 1) / 2;
    while(n % 2 == 0) n /= 2;
    for(int p = 3; p * p <= n; p += 2) {
        if(n % p == 0) {
            divs[cnt++] = p;
            while(n % p == 0) n /= p;
        }
    }
    if(n > 1) divs[cnt++] = n;
    for(int g = 2;; ++g) {
        bool ok = true;
        for(int i = 0; i < cnt; ++i) {
            if(mod_pow(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if(ok) return g;
    }
}

// Number Theoretic Transform（数論変換）.
// 引数の数列の長さは2のべき乗であること．O(N*logN).
template <class mint>
void transform(std::vector<mint> &a, bool inv = false) {
    if(a.empty()) return;
    static bool first = true;
    static std::array<mint, 30> ws({}), iws({});  // ws[k]:=(2^k乗根), iws[k]:=(2^k乗根の逆元).
    if(first) {
        mint pr = primitive_root(mint::modulus());
        int rank = 0;
        while(!((mint::modulus() - 1) & 1 << rank)) rank++;
        ws[rank] = pr.pow((mint::modulus() - 1) >> rank);
        iws[rank] = ws[rank].inv();
        for(int k = rank - 1; k >= 0; --k) {
            ws[k] = ws[k + 1] * ws[k + 1];
            iws[k] = iws[k + 1] * iws[k + 1];
        }
        first = false;
    }
    const int n = a.size();
    assert((mint::modulus() - 1) % n == 0);
    int h = 0;  // h:=log2(n).
    while(1 << h < n) h++;
    assert(n == 1 << h);
    for(int i = 0; i < n; ++i) {
        int j = 0;
        for(int k = 0; k < h; ++k) j |= (i >> k & 1) << (h - 1 - k);
        if(i < j) std::swap(a[i], a[j]);
    }
    for(int b = 1, k = 1; b < n; b <<= 1, ++k) {
        mint w = 1;
        for(int i = 0; i < b; ++i) {
            for(int j = 0; j < n; j += b << 1) {
                mint tmp = a[i + j + b] * w;
                a[i + j + b] = a[i + j] - tmp;
                a[i + j] = a[i + j] + tmp;
            }
            w *= (inv ? iws[k] : ws[k]);
        }
    }
    if(inv) {
        mint tmp = mint(n).inv();
        for(int i = 0; i < n; ++i) a[i] *= tmp;
    }
}

// 畳み込み．
// 数列a, bに対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列cを求める．O(N^2).
template <typename Type>
std::vector<Type> convolve_naive(const std::vector<Type> &a, const std::vector<Type> &b) {
    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();
    const int n = a.size(), m = b.size();
    std::vector<Type> res(n + m - 1, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) res[i + j] += a[i] * b[j];
    }
    return res;
}

// 畳み込み．
// 数列a, bに対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列cを求める．O(N*logN).
template <class mint>
std::vector<mint> convolve(std::vector<mint> a, std::vector<mint> b) {
    if(a.size() == 0 or b.size() == 0) return std::vector<mint>();
    const int n = a.size() + b.size() - 1;
    int m = 1;
    while(m < n) m <<= 1;
    a.resize(m, 0), b.resize(m, 0);
    transform(a), transform(b);
    for(int i = 0; i < m; ++i) a[i] *= b[i];
    transform(a, true);
    a.resize(n);
    return a;
}

}  // namespace ntt

}  // namespace algorithm

#endif
