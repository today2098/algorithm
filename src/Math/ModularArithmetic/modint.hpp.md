---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Math/ModularArithmetic/modint.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <iostream>\n\nnamespace algorithm {\n\ntemplate <int mod>\n\
    class Modint {\n    long long val;\n\npublic:\n    Modint() : Modint(0) {}\n \
    \   Modint(long long val_) : val(val_) {\n        static_assert(mod >= 1);\n \
    \       if(!(0 <= val and val < mod)) {\n            val %= mod;\n           \
    \ if(val < 0) val += mod;\n        }\n    }\n\n    Modint operator+() const {\
    \ return Modint(*this); }\n    Modint operator-() const { return Modint(0) - (*this);\
    \ }\n    Modint &operator++() {\n        val++;\n        if(val == mod) val =\
    \ 0;\n        return *this;\n    }\n    Modint &operator--() {\n        if(val\
    \ == 0) val = mod;\n        val--;\n        return *this;\n    }\n    Modint operator++(int)\
    \ {\n        Modint res = *this;\n        ++(*this);\n        return res;\n  \
    \  }\n    Modint operator--(int) {\n        Modint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    Modint &operator+=(const Modint &a) {\n     \
    \   val += a.val;\n        if(val >= mod) val -= mod;\n        return *this;\n\
    \    }\n    Modint &operator-=(const Modint &a) {\n        val -= a.val;\n   \
    \     if(val < 0) val += mod;\n        return *this;\n    }\n    Modint &operator*=(const\
    \ Modint &a) {\n        val = val * a.val % mod;\n        return *this;\n    }\n\
    \    Modint &operator/=(const Modint &a) { return (*this) *= a.inv(); }\n\n  \
    \  friend Modint operator+(const Modint &x, const Modint &y) { return Modint(x)\
    \ += y; }\n    friend Modint operator-(const Modint &x, const Modint &y) { return\
    \ Modint(x) -= y; }\n    friend Modint operator*(const Modint &x, const Modint\
    \ &y) { return Modint(x) *= y; }\n    friend Modint operator/(const Modint &x,\
    \ const Modint &y) { return Modint(x) /= y; }\n    friend bool operator==(const\
    \ Modint &x, const Modint &y) { return x.val == y.val; }\n    friend bool operator!=(const\
    \ Modint &x, const Modint &y) { return x.val != y.val; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Modint &x) {\n        is >> x.val;\n        if(!(0\
    \ <= x.val and x.val < mod)) {\n            x.val %= mod;\n            if(x.val\
    \ < 0) x.val += mod;\n        }\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Modint &x) { return os << x.val; }\n\n \
    \   static constexpr int modulus() { return mod; }\n    long long value() const\
    \ { return val; }\n    Modint inv() const {\n        long long a = val, b = mod,\
    \ u = 1, v = 0;\n        while(b) {\n            long long t = a / b;\n      \
    \      a -= t * b, u -= t * v;\n            std::swap(a, b), std::swap(u, v);\n\
    \        }\n        return Modint(u);\n    }\n\n    friend Modint mod_pow(const\
    \ Modint &x, long long k) {\n        if(k < 0) return mod_pow(x.inv(), -k);\n\
    \        Modint res = 1, tmp = x;\n        while(k > 0) {\n            if(k &\
    \ 1LL) res *= tmp;\n            tmp = tmp * tmp;\n            k >>= 1;\n     \
    \   }\n        return res;\n    }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    \n"
  code: "#ifndef ALGORITHM_MODINT_HPP\n#define ALGORITHM_MODINT_HPP 1\n\n#include\
    \ <cassert>\n#include <iostream>\n\nnamespace algorithm {\n\ntemplate <int mod>\n\
    class Modint {\n    long long val;\n\npublic:\n    Modint() : Modint(0) {}\n \
    \   Modint(long long val_) : val(val_) {\n        static_assert(mod >= 1);\n \
    \       if(!(0 <= val and val < mod)) {\n            val %= mod;\n           \
    \ if(val < 0) val += mod;\n        }\n    }\n\n    Modint operator+() const {\
    \ return Modint(*this); }\n    Modint operator-() const { return Modint(0) - (*this);\
    \ }\n    Modint &operator++() {\n        val++;\n        if(val == mod) val =\
    \ 0;\n        return *this;\n    }\n    Modint &operator--() {\n        if(val\
    \ == 0) val = mod;\n        val--;\n        return *this;\n    }\n    Modint operator++(int)\
    \ {\n        Modint res = *this;\n        ++(*this);\n        return res;\n  \
    \  }\n    Modint operator--(int) {\n        Modint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    Modint &operator+=(const Modint &a) {\n     \
    \   val += a.val;\n        if(val >= mod) val -= mod;\n        return *this;\n\
    \    }\n    Modint &operator-=(const Modint &a) {\n        val -= a.val;\n   \
    \     if(val < 0) val += mod;\n        return *this;\n    }\n    Modint &operator*=(const\
    \ Modint &a) {\n        val = val * a.val % mod;\n        return *this;\n    }\n\
    \    Modint &operator/=(const Modint &a) { return (*this) *= a.inv(); }\n\n  \
    \  friend Modint operator+(const Modint &x, const Modint &y) { return Modint(x)\
    \ += y; }\n    friend Modint operator-(const Modint &x, const Modint &y) { return\
    \ Modint(x) -= y; }\n    friend Modint operator*(const Modint &x, const Modint\
    \ &y) { return Modint(x) *= y; }\n    friend Modint operator/(const Modint &x,\
    \ const Modint &y) { return Modint(x) /= y; }\n    friend bool operator==(const\
    \ Modint &x, const Modint &y) { return x.val == y.val; }\n    friend bool operator!=(const\
    \ Modint &x, const Modint &y) { return x.val != y.val; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Modint &x) {\n        is >> x.val;\n        if(!(0\
    \ <= x.val and x.val < mod)) {\n            x.val %= mod;\n            if(x.val\
    \ < 0) x.val += mod;\n        }\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Modint &x) { return os << x.val; }\n\n \
    \   static constexpr int modulus() { return mod; }\n    long long value() const\
    \ { return val; }\n    Modint inv() const {\n        long long a = val, b = mod,\
    \ u = 1, v = 0;\n        while(b) {\n            long long t = a / b;\n      \
    \      a -= t * b, u -= t * v;\n            std::swap(a, b), std::swap(u, v);\n\
    \        }\n        return Modint(u);\n    }\n\n    friend Modint mod_pow(const\
    \ Modint &x, long long k) {\n        if(k < 0) return mod_pow(x.inv(), -k);\n\
    \        Modint res = 1, tmp = x;\n        while(k > 0) {\n            if(k &\
    \ 1LL) res *= tmp;\n            tmp = tmp * tmp;\n            k >>= 1;\n     \
    \   }\n        return res;\n    }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/ModularArithmetic/modint.hpp
  requiredBy: []
  timestamp: '2023-08-30 11:28:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/ModularArithmetic/modint.hpp
layout: document
redirect_from:
- /library/src/Math/ModularArithmetic/modint.hpp
- /library/src/Math/ModularArithmetic/modint.hpp.html
title: src/Math/ModularArithmetic/modint.hpp
---
