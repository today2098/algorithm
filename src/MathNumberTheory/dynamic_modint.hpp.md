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
  bundledCode: "#line 1 \"src/MathNumberTheory/dynamic_modint.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <iostream>\n\nnamespace algorithm {\n\ntemplate <int id>\n\
    class DynamicModint {\n    static int mod;\n    long long val;\n\npublic:\n  \
    \  DynamicModint() : DynamicModint(0) {}\n    DynamicModint(long long val_) :\
    \ val(val_) {\n        assert(mod >= 1);\n        val %= mod;\n        if(val\
    \ < 0) val += mod;\n    }\n\n    DynamicModint operator+() const { return DynamicModint(*this);\
    \ }\n    DynamicModint operator-() const { return DynamicModint(0) - (*this);\
    \ }\n    DynamicModint &operator++() {\n        val++;\n        if(val == mod)\
    \ val = 0;\n        return *this;\n    }\n    DynamicModint &operator--() {\n\
    \        if(val == 0) val = mod;\n        val--;\n        return *this;\n    }\n\
    \    DynamicModint operator++(int) {\n        DynamicModint res = *this;\n   \
    \     ++(*this);\n        return res;\n    }\n    DynamicModint operator--(int)\
    \ {\n        DynamicModint res = *this;\n        --(*this);\n        return res;\n\
    \    }\n    DynamicModint &operator+=(const DynamicModint &a) {\n        val +=\
    \ a.val;\n        if(val >= mod) val -= mod;\n        return *this;\n    }\n \
    \   DynamicModint &operator-=(const DynamicModint &a) {\n        val -= a.val;\n\
    \        if(val < 0) val += mod;\n        return *this;\n    }\n    DynamicModint\
    \ &operator*=(const DynamicModint &a) {\n        val = val * a.val % mod;\n  \
    \      return *this;\n    }\n    DynamicModint &operator/=(const DynamicModint\
    \ &a) { return (*this) *= a.inv(); }\n\n    friend DynamicModint operator+(const\
    \ DynamicModint &x, const DynamicModint &y) { return DynamicModint(x) += y; }\n\
    \    friend DynamicModint operator-(const DynamicModint &x, const DynamicModint\
    \ &y) { return DynamicModint(x) -= y; }\n    friend DynamicModint operator*(const\
    \ DynamicModint &x, const DynamicModint &y) { return DynamicModint(x) *= y; }\n\
    \    friend DynamicModint operator/(const DynamicModint &x, const DynamicModint\
    \ &y) { return DynamicModint(x) /= y; }\n    friend bool operator==(const DynamicModint\
    \ &x, const DynamicModint &y) { return x.val == y.val; }\n    friend bool operator!=(const\
    \ DynamicModint &x, const DynamicModint &y) { return x.val != y.val; }\n    friend\
    \ std::istream &operator>>(std::istream &is, DynamicModint &x) {\n        is >>\
    \ x.val;\n        x.val %= mod;\n        if(x.val < 0) x.val += mod;\n       \
    \ return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ DynamicModint &x) { return os << x.val; }\n\n    static constexpr int get_id()\
    \ { return id; }\n    static void set_modulus(int mod_) {\n        assert(mod_\
    \ >= 1);\n        mod = mod_;\n    }\n    static int modulus() { return mod; }\n\
    \    long long value() const { return val; }\n    DynamicModint inv() const {\n\
    \        long long a = val, b = mod, u = 1, v = 0;\n        while(b) {\n     \
    \       long long t = a / b;\n            a -= t * b, u -= t * v;\n          \
    \  std::swap(a, b), std::swap(u, v);\n        }\n        return DynamicModint(u);\n\
    \    }\n\n    friend DynamicModint mod_pow(const DynamicModint &x, long long k)\
    \ {\n        if(k < 0) return mod_pow(x.inv(), -k);\n        DynamicModint res\
    \ = 1, tmp = x;\n        while(k > 0) {\n            if(k & 1LL) res *= tmp;\n\
    \            tmp = tmp * tmp;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n};\n\ntemplate <int id>\nint DynamicModint<id>::mod = 1'000'000'007;\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DYNAMIC_MODINT_HPP\n#define ALGORITHM_DYNAMIC_MODINT_HPP\
    \ 1\n\n#include <cassert>\n#include <iostream>\n\nnamespace algorithm {\n\ntemplate\
    \ <int id>\nclass DynamicModint {\n    static int mod;\n    long long val;\n\n\
    public:\n    DynamicModint() : DynamicModint(0) {}\n    DynamicModint(long long\
    \ val_) : val(val_) {\n        assert(mod >= 1);\n        val %= mod;\n      \
    \  if(val < 0) val += mod;\n    }\n\n    DynamicModint operator+() const { return\
    \ DynamicModint(*this); }\n    DynamicModint operator-() const { return DynamicModint(0)\
    \ - (*this); }\n    DynamicModint &operator++() {\n        val++;\n        if(val\
    \ == mod) val = 0;\n        return *this;\n    }\n    DynamicModint &operator--()\
    \ {\n        if(val == 0) val = mod;\n        val--;\n        return *this;\n\
    \    }\n    DynamicModint operator++(int) {\n        DynamicModint res = *this;\n\
    \        ++(*this);\n        return res;\n    }\n    DynamicModint operator--(int)\
    \ {\n        DynamicModint res = *this;\n        --(*this);\n        return res;\n\
    \    }\n    DynamicModint &operator+=(const DynamicModint &a) {\n        val +=\
    \ a.val;\n        if(val >= mod) val -= mod;\n        return *this;\n    }\n \
    \   DynamicModint &operator-=(const DynamicModint &a) {\n        val -= a.val;\n\
    \        if(val < 0) val += mod;\n        return *this;\n    }\n    DynamicModint\
    \ &operator*=(const DynamicModint &a) {\n        val = val * a.val % mod;\n  \
    \      return *this;\n    }\n    DynamicModint &operator/=(const DynamicModint\
    \ &a) { return (*this) *= a.inv(); }\n\n    friend DynamicModint operator+(const\
    \ DynamicModint &x, const DynamicModint &y) { return DynamicModint(x) += y; }\n\
    \    friend DynamicModint operator-(const DynamicModint &x, const DynamicModint\
    \ &y) { return DynamicModint(x) -= y; }\n    friend DynamicModint operator*(const\
    \ DynamicModint &x, const DynamicModint &y) { return DynamicModint(x) *= y; }\n\
    \    friend DynamicModint operator/(const DynamicModint &x, const DynamicModint\
    \ &y) { return DynamicModint(x) /= y; }\n    friend bool operator==(const DynamicModint\
    \ &x, const DynamicModint &y) { return x.val == y.val; }\n    friend bool operator!=(const\
    \ DynamicModint &x, const DynamicModint &y) { return x.val != y.val; }\n    friend\
    \ std::istream &operator>>(std::istream &is, DynamicModint &x) {\n        is >>\
    \ x.val;\n        x.val %= mod;\n        if(x.val < 0) x.val += mod;\n       \
    \ return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ DynamicModint &x) { return os << x.val; }\n\n    static constexpr int get_id()\
    \ { return id; }\n    static void set_modulus(int mod_) {\n        assert(mod_\
    \ >= 1);\n        mod = mod_;\n    }\n    static int modulus() { return mod; }\n\
    \    long long value() const { return val; }\n    DynamicModint inv() const {\n\
    \        long long a = val, b = mod, u = 1, v = 0;\n        while(b) {\n     \
    \       long long t = a / b;\n            a -= t * b, u -= t * v;\n          \
    \  std::swap(a, b), std::swap(u, v);\n        }\n        return DynamicModint(u);\n\
    \    }\n\n    friend DynamicModint mod_pow(const DynamicModint &x, long long k)\
    \ {\n        if(k < 0) return mod_pow(x.inv(), -k);\n        DynamicModint res\
    \ = 1, tmp = x;\n        while(k > 0) {\n            if(k & 1LL) res *= tmp;\n\
    \            tmp = tmp * tmp;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n};\n\ntemplate <int id>\nint DynamicModint<id>::mod = 1'000'000'007;\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/MathNumberTheory/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2022-11-27 15:49:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/MathNumberTheory/dynamic_modint.hpp
layout: document
redirect_from:
- /library/src/MathNumberTheory/dynamic_modint.hpp
- /library/src/MathNumberTheory/dynamic_modint.hpp.html
title: src/MathNumberTheory/dynamic_modint.hpp
---
