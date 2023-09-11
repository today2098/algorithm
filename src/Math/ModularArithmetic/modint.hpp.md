---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-3110.test.cpp
    title: test/aoj-3110.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-range_affine_range_sum.test.cpp
    title: test/yosupo-range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Modint
    links: []
  bundledCode: "#line 1 \"src/Math/ModularArithmetic/modint.hpp\"\n/**\n * @brief\
    \ Modint\n */\n\n#ifndef ALGORITHM_MODINT_HPP\n#define ALGORITHM_MODINT_HPP 1\n\
    \n#include <cassert>\n#include <iostream>\n#include <utility>\n\nnamespace algorithm\
    \ {\n\ntemplate <int mod>\nclass Modint {\n    long long val;\n\n    void build()\
    \ {\n        if(!(-mod <= val and val < mod)) val %= mod;\n        if(val < 0)\
    \ val += mod;\n    }\n\npublic:\n    Modint() : Modint(0) {}\n    Modint(long\
    \ long val_) : val(val_) {\n        static_assert(mod >= 1);\n        build();\n\
    \    }\n\n    Modint operator+() const { return Modint(*this); }\n    Modint operator-()\
    \ const { return (val == 0 ? Modint(0) : Modint(mod - val)); }\n    Modint &operator++()\
    \ {\n        val++;\n        if(val == mod) val = 0;\n        return *this;\n\
    \    }\n    Modint &operator--() {\n        if(val == 0) val = mod;\n        val--;\n\
    \        return *this;\n    }\n    Modint operator++(int) {\n        Modint res\
    \ = *this;\n        ++(*this);\n        return res;\n    }\n    Modint operator--(int)\
    \ {\n        Modint res = *this;\n        --(*this);\n        return res;\n  \
    \  }\n    Modint &operator+=(const Modint &rhs) {\n        val += rhs.val;\n \
    \       if(val >= mod) val -= mod;\n        return *this;\n    }\n    Modint &operator-=(const\
    \ Modint &rhs) {\n        val -= rhs.val;\n        if(val < 0) val += mod;\n \
    \       return *this;\n    }\n    Modint &operator*=(const Modint &rhs) {\n  \
    \      val = val * rhs.val % mod;\n        return *this;\n    }\n    Modint &operator/=(const\
    \ Modint &rhs) { return *this *= rhs.inv(); }\n\n    friend Modint operator+(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) += rhs; }\n    friend Modint\
    \ operator-(const Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs;\
    \ }\n    friend Modint operator*(const Modint &lhs, const Modint &rhs) { return\
    \ Modint(lhs) *= rhs; }\n    friend Modint operator/(const Modint &lhs, const\
    \ Modint &rhs) { return Modint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ Modint &lhs, const Modint &rhs) { return lhs.val == rhs.val; }\n    friend bool\
    \ operator!=(const Modint &lhs, const Modint &rhs) { return lhs.val != rhs.val;\
    \ }\n    friend std::istream &operator>>(std::istream &is, Modint &rhs) {\n  \
    \      is >> rhs.val;\n        rhs.build();\n        return is;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Modint &rhs) { return os <<\
    \ rhs.val; }\n\n    static constexpr int modulus() { return mod; }\n    long long\
    \ value() const { return val; }\n    Modint inv() const {\n        long long a\
    \ = val, b = mod, u = 1, v = 0;\n        while(b != 0) {\n            long long\
    \ t = a / b;\n            a -= b * t, u -= v * t;\n            std::swap(a, b),\
    \ std::swap(u, v);\n        }\n        return Modint(u);\n    }\n    Modint pow(long\
    \ long k) const {\n        if(k < 0) return inv().pow(-k);\n        Modint res\
    \ = 1, mul = *this;\n        while(k > 0) {\n            if(k & 1LL) res *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n\n    friend Modint mod_inv(const Modint &a) { return a.inv(); }\n   \
    \ friend Modint mod_pow(const Modint &a, long long k) { return a.pow(k); }\n};\n\
    \nusing mint998244353 = Modint<998'244'353>;\nusing mint1000000007 = Modint<1'000'000'007>;\n\
    \n}  // namespace algorithm\n\n#endif\n"
  code: "/**\n * @brief Modint\n */\n\n#ifndef ALGORITHM_MODINT_HPP\n#define ALGORITHM_MODINT_HPP\
    \ 1\n\n#include <cassert>\n#include <iostream>\n#include <utility>\n\nnamespace\
    \ algorithm {\n\ntemplate <int mod>\nclass Modint {\n    long long val;\n\n  \
    \  void build() {\n        if(!(-mod <= val and val < mod)) val %= mod;\n    \
    \    if(val < 0) val += mod;\n    }\n\npublic:\n    Modint() : Modint(0) {}\n\
    \    Modint(long long val_) : val(val_) {\n        static_assert(mod >= 1);\n\
    \        build();\n    }\n\n    Modint operator+() const { return Modint(*this);\
    \ }\n    Modint operator-() const { return (val == 0 ? Modint(0) : Modint(mod\
    \ - val)); }\n    Modint &operator++() {\n        val++;\n        if(val == mod)\
    \ val = 0;\n        return *this;\n    }\n    Modint &operator--() {\n       \
    \ if(val == 0) val = mod;\n        val--;\n        return *this;\n    }\n    Modint\
    \ operator++(int) {\n        Modint res = *this;\n        ++(*this);\n       \
    \ return res;\n    }\n    Modint operator--(int) {\n        Modint res = *this;\n\
    \        --(*this);\n        return res;\n    }\n    Modint &operator+=(const\
    \ Modint &rhs) {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n\
    \        return *this;\n    }\n    Modint &operator-=(const Modint &rhs) {\n \
    \       val -= rhs.val;\n        if(val < 0) val += mod;\n        return *this;\n\
    \    }\n    Modint &operator*=(const Modint &rhs) {\n        val = val * rhs.val\
    \ % mod;\n        return *this;\n    }\n    Modint &operator/=(const Modint &rhs)\
    \ { return *this *= rhs.inv(); }\n\n    friend Modint operator+(const Modint &lhs,\
    \ const Modint &rhs) { return Modint(lhs) += rhs; }\n    friend Modint operator-(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }\n    friend Modint\
    \ operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs;\
    \ }\n    friend Modint operator/(const Modint &lhs, const Modint &rhs) { return\
    \ Modint(lhs) /= rhs; }\n    friend bool operator==(const Modint &lhs, const Modint\
    \ &rhs) { return lhs.val == rhs.val; }\n    friend bool operator!=(const Modint\
    \ &lhs, const Modint &rhs) { return lhs.val != rhs.val; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Modint &rhs) {\n        is >> rhs.val;\n     \
    \   rhs.build();\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int\
    \ modulus() { return mod; }\n    long long value() const { return val; }\n   \
    \ Modint inv() const {\n        long long a = val, b = mod, u = 1, v = 0;\n  \
    \      while(b != 0) {\n            long long t = a / b;\n            a -= b *\
    \ t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n        }\n \
    \       return Modint(u);\n    }\n    Modint pow(long long k) const {\n      \
    \  if(k < 0) return inv().pow(-k);\n        Modint res = 1, mul = *this;\n   \
    \     while(k > 0) {\n            if(k & 1LL) res *= mul;\n            mul *=\
    \ mul;\n            k >>= 1;\n        }\n        return res;\n    }\n\n    friend\
    \ Modint mod_inv(const Modint &a) { return a.inv(); }\n    friend Modint mod_pow(const\
    \ Modint &a, long long k) { return a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/ModularArithmetic/modint.hpp
  requiredBy: []
  timestamp: '2023-09-09 16:07:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-range_affine_range_sum.test.cpp
  - test/aoj-3110.test.cpp
documentation_of: src/Math/ModularArithmetic/modint.hpp
layout: document
redirect_from:
- /library/src/Math/ModularArithmetic/modint.hpp
- /library/src/Math/ModularArithmetic/modint.hpp.html
title: Modint
---