---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj-3110.test.cpp
    title: test/aoj-3110.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Modint
    links: []
  bundledCode: "#line 1 \"src/Math/ModularArithmetic/modint.hpp\"\n/**\n * @brief\
    \ Modint\n */\n\n#ifndef ALGORITHM_MODINT_HPP\n#define ALGORITHM_MODINT_HPP 1\n\
    \n#include <cassert>\n#include <iostream>\n#include <utility>\n\nnamespace algorithm\
    \ {\n\ntemplate <int mod>\nclass Modint {\n    long long val;\n\n    void convert(long\
    \ long &val_) {\n        if(!(-mod <= val_ and val_ < mod)) val_ %= mod;\n   \
    \     if(val_ < 0) val_ += mod;\n    }\n\npublic:\n    Modint() : Modint(0) {}\n\
    \    Modint(long long val_) : val(val_) {\n        static_assert(mod >= 1);\n\
    \        convert(val);\n    }\n\n    Modint operator+() const { return Modint(*this);\
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
    \   convert(rhs.val);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
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
  code: "/**\n * @brief Modint\n */\n\n#ifndef ALGORITHM_MODINT_HPP\n#define ALGORITHM_MODINT_HPP\
    \ 1\n\n#include <cassert>\n#include <iostream>\n#include <utility>\n\nnamespace\
    \ algorithm {\n\ntemplate <int mod>\nclass Modint {\n    long long val;\n\n  \
    \  void convert(long long &val_) {\n        if(!(-mod <= val_ and val_ < mod))\
    \ val_ %= mod;\n        if(val_ < 0) val_ += mod;\n    }\n\npublic:\n    Modint()\
    \ : Modint(0) {}\n    Modint(long long val_) : val(val_) {\n        static_assert(mod\
    \ >= 1);\n        convert(val);\n    }\n\n    Modint operator+() const { return\
    \ Modint(*this); }\n    Modint operator-() const { return (val == 0 ? Modint(0)\
    \ : Modint(mod - val)); }\n    Modint &operator++() {\n        val++;\n      \
    \  if(val == mod) val = 0;\n        return *this;\n    }\n    Modint &operator--()\
    \ {\n        if(val == 0) val = mod;\n        val--;\n        return *this;\n\
    \    }\n    Modint operator++(int) {\n        Modint res = *this;\n        ++(*this);\n\
    \        return res;\n    }\n    Modint operator--(int) {\n        Modint res\
    \ = *this;\n        --(*this);\n        return res;\n    }\n    Modint &operator+=(const\
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
    \   convert(rhs.val);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
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
  timestamp: '2023-09-04 14:28:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj-3110.test.cpp
documentation_of: src/Math/ModularArithmetic/modint.hpp
layout: document
redirect_from:
- /library/src/Math/ModularArithmetic/modint.hpp
- /library/src/Math/ModularArithmetic/modint.hpp.html
title: Modint
---
