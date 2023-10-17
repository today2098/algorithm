---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/Math/Convolution/number_theoretic_transform.hpp
    title: "Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09"
  - icon: ':x:'
    path: src/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684modint"
  - icon: ':x:'
    path: src/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj-3110.test.cpp
    title: test/aoj-3110.test.cpp
  - icon: ':x:'
    path: test/yosupo-convolution_mod.test.cpp
    title: test/yosupo-convolution_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo-range_affine_range_sum.test.cpp
    title: test/yosupo-range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n#include\
    \ <type_traits>\n\nnamespace algorithm {\n\nclass ModintBase {};\n\ntemplate <class\
    \ T>\nusing is_modint = std::is_base_of<ModintBase, T>;\n\ntemplate <class T>\n\
    inline constexpr bool is_modint_v = is_modint<T>::value;\n\ntemplate <int mod>\n\
    class Modint : ModintBase {\n    long long val;\n\n    void normalize() {\n  \
    \      if(!(-mod <= val and val < mod)) val %= mod;\n        if(val < 0) val +=\
    \ mod;\n    }\n\npublic:\n    Modint() : Modint(0) {}\n    Modint(long long val_)\
    \ : val(val_) {\n        static_assert(mod >= 1);\n        normalize();\n    }\n\
    \n    Modint operator+() const { return Modint(*this); }\n    Modint operator-()\
    \ const { return (val == 0 ? Modint(*this) : Modint(mod - val)); }\n    Modint\
    \ &operator++() {\n        val++;\n        if(val == mod) val = 0;\n        return\
    \ *this;\n    }\n    Modint &operator--() {\n        if(val == 0) val = mod;\n\
    \        val--;\n        return *this;\n    }\n    Modint operator++(int) {\n\
    \        Modint res = *this;\n        ++(*this);\n        return res;\n    }\n\
    \    Modint operator--(int) {\n        Modint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    Modint &operator+=(const Modint &rhs) {\n   \
    \     val += rhs.val;\n        if(val >= mod) val -= mod;\n        return *this;\n\
    \    }\n    Modint &operator-=(const Modint &rhs) {\n        val -= rhs.val;\n\
    \        if(val < 0) val += mod;\n        return *this;\n    }\n    Modint &operator*=(const\
    \ Modint &rhs) {\n        val = val * rhs.val % mod;\n        return *this;\n\
    \    }\n    Modint &operator/=(const Modint &rhs) { return *this *= rhs.inv();\
    \ }\n\n    friend Modint operator+(const Modint &lhs, const Modint &rhs) { return\
    \ Modint(lhs) += rhs; }\n    friend Modint operator-(const Modint &lhs, const\
    \ Modint &rhs) { return Modint(lhs) -= rhs; }\n    friend Modint operator*(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }\n    friend Modint\
    \ operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs) /= rhs;\
    \ }\n    friend bool operator==(const Modint &lhs, const Modint &rhs) { return\
    \ lhs.val == rhs.val; }\n    friend bool operator!=(const Modint &lhs, const Modint\
    \ &rhs) { return lhs.val != rhs.val; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Modint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n    \
    \    return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    long long value() const { return val; }\n    Modint inv()\
    \ const {\n        long long a = val, b = mod, u = 1, v = 0;\n        while(b\
    \ != 0) {\n            long long t = a / b;\n            a -= b * t, u -= v *\
    \ t;\n            std::swap(a, b), std::swap(u, v);\n        }\n        return\
    \ Modint(u);\n    }\n    Modint pow(long long k) const {\n        if(k < 0) return\
    \ inv().pow(-k);\n        Modint res = 1, mul = *this;\n        while(k > 0) {\n\
    \            if(k & 1LL) res *= mul;\n            mul *= mul;\n            k >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    friend Modint mod_inv(const\
    \ Modint &a) { return a.inv(); }\n    friend Modint mod_pow(const Modint &a, long\
    \ long k) { return a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    \n"
  code: "#ifndef ALGORITHM_MODINT_BASE_HPP\n#define ALGORITHM_MODINT_BASE_HPP 1\n\n\
    #include <type_traits>\n\nnamespace algorithm {\n\nclass ModintBase {};\n\ntemplate\
    \ <class T>\nusing is_modint = std::is_base_of<ModintBase, T>;\n\ntemplate <class\
    \ T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\ntemplate <int\
    \ mod>\nclass Modint : ModintBase {\n    long long val;\n\n    void normalize()\
    \ {\n        if(!(-mod <= val and val < mod)) val %= mod;\n        if(val < 0)\
    \ val += mod;\n    }\n\npublic:\n    Modint() : Modint(0) {}\n    Modint(long\
    \ long val_) : val(val_) {\n        static_assert(mod >= 1);\n        normalize();\n\
    \    }\n\n    Modint operator+() const { return Modint(*this); }\n    Modint operator-()\
    \ const { return (val == 0 ? Modint(*this) : Modint(mod - val)); }\n    Modint\
    \ &operator++() {\n        val++;\n        if(val == mod) val = 0;\n        return\
    \ *this;\n    }\n    Modint &operator--() {\n        if(val == 0) val = mod;\n\
    \        val--;\n        return *this;\n    }\n    Modint operator++(int) {\n\
    \        Modint res = *this;\n        ++(*this);\n        return res;\n    }\n\
    \    Modint operator--(int) {\n        Modint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    Modint &operator+=(const Modint &rhs) {\n   \
    \     val += rhs.val;\n        if(val >= mod) val -= mod;\n        return *this;\n\
    \    }\n    Modint &operator-=(const Modint &rhs) {\n        val -= rhs.val;\n\
    \        if(val < 0) val += mod;\n        return *this;\n    }\n    Modint &operator*=(const\
    \ Modint &rhs) {\n        val = val * rhs.val % mod;\n        return *this;\n\
    \    }\n    Modint &operator/=(const Modint &rhs) { return *this *= rhs.inv();\
    \ }\n\n    friend Modint operator+(const Modint &lhs, const Modint &rhs) { return\
    \ Modint(lhs) += rhs; }\n    friend Modint operator-(const Modint &lhs, const\
    \ Modint &rhs) { return Modint(lhs) -= rhs; }\n    friend Modint operator*(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }\n    friend Modint\
    \ operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs) /= rhs;\
    \ }\n    friend bool operator==(const Modint &lhs, const Modint &rhs) { return\
    \ lhs.val == rhs.val; }\n    friend bool operator!=(const Modint &lhs, const Modint\
    \ &rhs) { return lhs.val != rhs.val; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Modint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n    \
    \    return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    long long value() const { return val; }\n    Modint inv()\
    \ const {\n        long long a = val, b = mod, u = 1, v = 0;\n        while(b\
    \ != 0) {\n            long long t = a / b;\n            a -= b * t, u -= v *\
    \ t;\n            std::swap(a, b), std::swap(u, v);\n        }\n        return\
    \ Modint(u);\n    }\n    Modint pow(long long k) const {\n        if(k < 0) return\
    \ inv().pow(-k);\n        Modint res = 1, mul = *this;\n        while(k > 0) {\n\
    \            if(k & 1LL) res *= mul;\n            mul *= mul;\n            k >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    friend Modint mod_inv(const\
    \ Modint &a) { return a.inv(); }\n    friend Modint mod_pow(const Modint &a, long\
    \ long k) { return a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/ModularArithmetic/modint_base.hpp
  requiredBy:
  - src/Math/Convolution/number_theoretic_transform.hpp
  - src/Math/ModularArithmetic/modint.hpp
  - src/Math/ModularArithmetic/dynamic_modint.hpp
  timestamp: '2023-10-18 00:58:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-range_affine_range_sum.test.cpp
  - test/yosupo-convolution_mod.test.cpp
  - test/aoj-3110.test.cpp
documentation_of: src/Math/ModularArithmetic/modint_base.hpp
layout: document
redirect_from:
- /library/src/Math/ModularArithmetic/modint_base.hpp
- /library/src/Math/ModularArithmetic/modint_base.hpp.html
title: src/Math/ModularArithmetic/modint_base.hpp
---
