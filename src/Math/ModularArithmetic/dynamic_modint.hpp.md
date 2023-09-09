---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u52D5\u7684Modint"
    links: []
  bundledCode: "#line 1 \"src/Math/ModularArithmetic/dynamic_modint.hpp\"\n/**\n *\
    \ @brief \u52D5\u7684Modint\n */\n\n#ifndef ALGORITHM_DYNAMIC_MODINT_HPP\n#define\
    \ ALGORITHM_DYNAMIC_MODINT_HPP 1\n\n#include <cassert>\n#include <iostream>\n\
    #include <utility>\n\nnamespace algorithm {\n\ntemplate <int id>\nclass DynamicModint\
    \ {\n    static int mod;\n    long long val;\n\n    void build() {\n        if(!(-mod\
    \ <= val and val < mod)) val %= mod;\n        if(val < 0) val += mod;\n    }\n\
    \npublic:\n    DynamicModint() : DynamicModint(0) {}\n    DynamicModint(long long\
    \ val_) : val(val_) {\n        assert(mod >= 1);\n        build();\n    }\n\n\
    \    DynamicModint operator+() const { return DynamicModint(*this); }\n    DynamicModint\
    \ operator-() const { return (val == 0 ? DynamicModint(0) : DynamicModint(mod\
    \ - val)); }\n    DynamicModint &operator++() {\n        val++;\n        if(val\
    \ == mod) val = 0;\n        return *this;\n    }\n    DynamicModint &operator--()\
    \ {\n        if(val == 0) val = mod;\n        val--;\n        return *this;\n\
    \    }\n    DynamicModint operator++(int) {\n        DynamicModint res = *this;\n\
    \        ++(*this);\n        return res;\n    }\n    DynamicModint operator--(int)\
    \ {\n        DynamicModint res = *this;\n        --(*this);\n        return res;\n\
    \    }\n    DynamicModint &operator+=(const DynamicModint &rhs) {\n        val\
    \ += rhs.val;\n        if(val >= mod) val -= mod;\n        return *this;\n   \
    \ }\n    DynamicModint &operator-=(const DynamicModint &rhs) {\n        val -=\
    \ rhs.val;\n        if(val < 0) val += mod;\n        return *this;\n    }\n  \
    \  DynamicModint &operator*=(const DynamicModint &rhs) {\n        val = val *\
    \ rhs.val % mod;\n        return *this;\n    }\n    DynamicModint &operator/=(const\
    \ DynamicModint &rhs) { return *this *= rhs.inv(); }\n\n    friend DynamicModint\
    \ operator+(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ += rhs; }\n    friend DynamicModint operator-(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) -= rhs; }\n    friend DynamicModint\
    \ operator*(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ *= rhs; }\n    friend DynamicModint operator/(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ DynamicModint &lhs, const DynamicModint &rhs) { return lhs.val == rhs.val; }\n\
    \    friend bool operator!=(const DynamicModint &lhs, const DynamicModint &rhs)\
    \ { return lhs.val != rhs.val; }\n    friend std::istream &operator>>(std::istream\
    \ &is, DynamicModint &rhs) {\n        is >> rhs.val;\n        rhs.build();\n \
    \       return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const DynamicModint &rhs) { return os << rhs.val; }\n\n    static constexpr\
    \ int get_id() { return id; }\n    static void set_modulus(int mod_) {\n     \
    \   assert(mod_ >= 1);\n        mod = mod_;\n    }\n    static int modulus() {\
    \ return mod; }\n    long long value() const { return val; }\n    DynamicModint\
    \ inv() const {\n        long long a = val, b = mod, u = 1, v = 0;\n        while(b)\
    \ {\n            long long t = a / b;\n            a -= b * t, u -= v * t;\n \
    \           std::swap(a, b), std::swap(u, v);\n        }\n        return DynamicModint(u);\n\
    \    }\n    DynamicModint pow(long long k) const {\n        if(k < 0) return inv().pow(-k);\n\
    \        DynamicModint res = 1, mul = *this;\n        while(k > 0) {\n       \
    \     if(k & 1LL) res *= mul;\n            mul *= mul;\n            k >>= 1;\n\
    \        }\n        return res;\n    }\n\n    friend DynamicModint mod_inv(const\
    \ DynamicModint &a) { return a.inv(); }\n    friend DynamicModint mod_pow(const\
    \ DynamicModint &a, long long k) { return a.pow(k); }\n};\n\ntemplate <int id>\n\
    int DynamicModint<id>::mod = 1'000'000'007;\n\n}  // namespace algorithm\n\n#endif\n"
  code: "/**\n * @brief \u52D5\u7684Modint\n */\n\n#ifndef ALGORITHM_DYNAMIC_MODINT_HPP\n\
    #define ALGORITHM_DYNAMIC_MODINT_HPP 1\n\n#include <cassert>\n#include <iostream>\n\
    #include <utility>\n\nnamespace algorithm {\n\ntemplate <int id>\nclass DynamicModint\
    \ {\n    static int mod;\n    long long val;\n\n    void build() {\n        if(!(-mod\
    \ <= val and val < mod)) val %= mod;\n        if(val < 0) val += mod;\n    }\n\
    \npublic:\n    DynamicModint() : DynamicModint(0) {}\n    DynamicModint(long long\
    \ val_) : val(val_) {\n        assert(mod >= 1);\n        build();\n    }\n\n\
    \    DynamicModint operator+() const { return DynamicModint(*this); }\n    DynamicModint\
    \ operator-() const { return (val == 0 ? DynamicModint(0) : DynamicModint(mod\
    \ - val)); }\n    DynamicModint &operator++() {\n        val++;\n        if(val\
    \ == mod) val = 0;\n        return *this;\n    }\n    DynamicModint &operator--()\
    \ {\n        if(val == 0) val = mod;\n        val--;\n        return *this;\n\
    \    }\n    DynamicModint operator++(int) {\n        DynamicModint res = *this;\n\
    \        ++(*this);\n        return res;\n    }\n    DynamicModint operator--(int)\
    \ {\n        DynamicModint res = *this;\n        --(*this);\n        return res;\n\
    \    }\n    DynamicModint &operator+=(const DynamicModint &rhs) {\n        val\
    \ += rhs.val;\n        if(val >= mod) val -= mod;\n        return *this;\n   \
    \ }\n    DynamicModint &operator-=(const DynamicModint &rhs) {\n        val -=\
    \ rhs.val;\n        if(val < 0) val += mod;\n        return *this;\n    }\n  \
    \  DynamicModint &operator*=(const DynamicModint &rhs) {\n        val = val *\
    \ rhs.val % mod;\n        return *this;\n    }\n    DynamicModint &operator/=(const\
    \ DynamicModint &rhs) { return *this *= rhs.inv(); }\n\n    friend DynamicModint\
    \ operator+(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ += rhs; }\n    friend DynamicModint operator-(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) -= rhs; }\n    friend DynamicModint\
    \ operator*(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ *= rhs; }\n    friend DynamicModint operator/(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ DynamicModint &lhs, const DynamicModint &rhs) { return lhs.val == rhs.val; }\n\
    \    friend bool operator!=(const DynamicModint &lhs, const DynamicModint &rhs)\
    \ { return lhs.val != rhs.val; }\n    friend std::istream &operator>>(std::istream\
    \ &is, DynamicModint &rhs) {\n        is >> rhs.val;\n        rhs.build();\n \
    \       return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const DynamicModint &rhs) { return os << rhs.val; }\n\n    static constexpr\
    \ int get_id() { return id; }\n    static void set_modulus(int mod_) {\n     \
    \   assert(mod_ >= 1);\n        mod = mod_;\n    }\n    static int modulus() {\
    \ return mod; }\n    long long value() const { return val; }\n    DynamicModint\
    \ inv() const {\n        long long a = val, b = mod, u = 1, v = 0;\n        while(b)\
    \ {\n            long long t = a / b;\n            a -= b * t, u -= v * t;\n \
    \           std::swap(a, b), std::swap(u, v);\n        }\n        return DynamicModint(u);\n\
    \    }\n    DynamicModint pow(long long k) const {\n        if(k < 0) return inv().pow(-k);\n\
    \        DynamicModint res = 1, mul = *this;\n        while(k > 0) {\n       \
    \     if(k & 1LL) res *= mul;\n            mul *= mul;\n            k >>= 1;\n\
    \        }\n        return res;\n    }\n\n    friend DynamicModint mod_inv(const\
    \ DynamicModint &a) { return a.inv(); }\n    friend DynamicModint mod_pow(const\
    \ DynamicModint &a, long long k) { return a.pow(k); }\n};\n\ntemplate <int id>\n\
    int DynamicModint<id>::mod = 1'000'000'007;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/ModularArithmetic/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2023-09-09 16:07:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/ModularArithmetic/dynamic_modint.hpp
layout: document
redirect_from:
- /library/src/Math/ModularArithmetic/dynamic_modint.hpp
- /library/src/Math/ModularArithmetic/dynamic_modint.hpp.html
title: "\u52D5\u7684Modint"
---
