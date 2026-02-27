---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modulo.hpp
    title: "\u30E2\u30B8\u30E5\u30ED\u6F14\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/no_1681_2.test.cpp
    title: verify/yukicoder/no_1681_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/dynamic_modint.hpp\"\n\n\
    \n\n#include <cassert>\n#include <concepts>\n#include <cstdint>\n#include <functional>\n\
    #include <iostream>\n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\n\n\n#line 7 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n#include <utility>\n\
    \n#line 1 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\n\n\n\n#line 6 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// Returns x mod m.\ntemplate\
    \ <std::unsigned_integral Type>\nconstexpr std::uint32_t modulo(Type x, std::uint32_t\
    \ m) { return x % m; }\n\n// Returns x mod m.\ntemplate <std::unsigned_integral\
    \ Type>\nconstexpr std::uint32_t modulo(Type x, std::int32_t m) { return x % static_cast<std::uint32_t>(m);\
    \ }\n\n// Returns x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t\
    \ modulo(Type x, std::uint32_t m) {\n    x %= static_cast<std::int64_t>(m);\n\
    \    if(x < 0) x += static_cast<std::int64_t>(m);\n    return x;\n}\n\n// Returns\
    \ x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t modulo(Type\
    \ x, std::int32_t m) {\n    x %= m;\n    if(x < 0) x += m;\n    return x;\n}\n\
    \n}  // namespace internal\n\n}  // namespace algorithm\n\n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// Returns pair of (x, g)\
    \ s.t. g=gcd(a,m), ax=g (mod m), 0<=x<m/g\uFF0EO(log(min(a,m))).\nconstexpr std::pair<std::uint32_t,\
    \ std::uint32_t> mod_inv(std::uint32_t a, std::uint32_t m) {\n    if(a == 0) return\
    \ {0, m};\n    std::uint32_t s = m, t = a;\n    std::uint32_t u = 0, v = 1;\n\
    \    while(true) {\n        std::uint32_t q = s / t;\n        s -= t * q, u -=\
    \ v * q;\n        if(s == 0) return {v, t};\n        q = t / s;\n        t -=\
    \ s * q, v -= u * q;\n        if(t == 0) return {u + m / s, s};  // u will be\
    \ negative.\n    }\n}\n\n}  // namespace internal\n\n// \u30E2\u30B8\u30E5\u30E9\
    \u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09\uFF0E\n// a^(-1) mod m \u3092\
    \u6C42\u3081\u308B\uFF0E\u89E3\u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\
    \u5206\u6761\u4EF6\u306F\uFF0Ca\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(log(min(a,m))).\ntemplate <std::integral Type>\nconstexpr\
    \ std::int64_t mod_inv(Type a, std::int32_t m) {\n    assert(m >= 1);\n    auto\
    \ [x, g] = internal::mod_inv(internal::modulo(a, m), m);\n    assert(g == 1);\n\
    \    return x;\n}\n\n}  // namespace algorithm\n\n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\
    \n\n\n\n#line 7 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n#line 10 \"\
    algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\nnamespace algorithm {\n\nnamespace\
    \ internal {\n\n// Returns n^k mod m.\nconstexpr std::uint32_t mod_pow(std::uint64_t\
    \ n, unsigned long long k, std::uint32_t m) {\n    std::uint64_t res = 1;\n  \
    \  for(; k > 0; k >>= 1) {\n        if(k & 1ULL) res = res * n % m;\n        n\
    \ = n * n % m;\n    }\n    return res;\n}\n\n}  // namespace internal\n\n// \u7E70\
    \u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0E\n// n^k\
    \ mod m \u3092\u6C42\u3081\u308B\uFF0EO(log k).\ntemplate <std::integral Type>\n\
    constexpr std::int64_t mod_pow(Type n, long long k, std::int32_t m) {\n    assert(m\
    \ >= 1);\n    if(k >= 0) return internal::mod_pow(internal::modulo(n, m), k, m);\n\
    \    auto [x, g] = internal::mod_inv(internal::modulo(n, m), m);\n    assert(g\
    \ == 1);\n    return internal::mod_pow(x, -k, m);\n}\n\n}  // namespace algorithm\n\
    \n\n#line 1 \"algorithm/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n#include\
    \ <type_traits>\n\nnamespace algorithm {\n\nclass ModintBase {};\n\ntemplate <typename\
    \ T>\nusing is_modint = std::is_base_of<ModintBase, T>;\n\ntemplate <typename\
    \ T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\ntemplate <typename\
    \ T>\nconcept modint = is_modint_v<T>;\n\n}  // namespace algorithm\n\n\n#line\
    \ 14 \"algorithm/Math/ModularArithmetic/dynamic_modint.hpp\"\n\nnamespace algorithm\
    \ {\n\ntemplate <int id>\nclass DynamicModint : public ModintBase {\n    static\
    \ std::uint32_t mod;\n    std::uint32_t val;\n\npublic:\n    DynamicModint() :\
    \ val(0) {}\n    template <std::integral Type>\n    DynamicModint(Type val) :\
    \ val(internal::modulo(val, mod)) {}\n\n    DynamicModint operator+() const {\
    \ return DynamicModint(*this); }\n    DynamicModint operator-() const {\n    \
    \    if(val == 0) DynamicModint();\n        return raw(mod - val);\n    }\n  \
    \  DynamicModint &operator++() {\n        ++val;\n        if(val == mod) val =\
    \ 0;\n        return *this;\n    }\n    DynamicModint &operator--() {\n      \
    \  if(val == 0) val = mod;\n        --val;\n        return *this;\n    }\n   \
    \ DynamicModint operator++(int) {\n        DynamicModint res = *this;\n      \
    \  ++(*this);\n        return res;\n    }\n    DynamicModint operator--(int) {\n\
    \        DynamicModint res = *this;\n        --(*this);\n        return res;\n\
    \    }\n    DynamicModint &operator+=(const DynamicModint &rhs) {\n        if(rhs.val\
    \ >= mod - val) val -= mod;\n        val += rhs.val;\n        return *this;\n\
    \    }\n    DynamicModint &operator-=(const DynamicModint &rhs) {\n        if(rhs.val\
    \ > val) val += mod;\n        val -= rhs.val;\n        return *this;\n    }\n\
    \    DynamicModint &operator*=(const DynamicModint &rhs) {\n        val = static_cast<std::uint64_t>(val)\
    \ * rhs.val % mod;\n        return *this;\n    }\n    DynamicModint &operator/=(const\
    \ DynamicModint &rhs) { return *this *= rhs.inv(); }\n\n    friend bool operator==(const\
    \ DynamicModint &lhs, const DynamicModint &rhs) { return lhs.val == rhs.val; }\n\
    \    friend DynamicModint operator+(const DynamicModint &lhs, const DynamicModint\
    \ &rhs) { return DynamicModint(lhs) += rhs; }\n    friend DynamicModint operator-(const\
    \ DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) -=\
    \ rhs; }\n    friend DynamicModint operator*(const DynamicModint &lhs, const DynamicModint\
    \ &rhs) { return DynamicModint(lhs) *= rhs; }\n    friend DynamicModint operator/(const\
    \ DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) /=\
    \ rhs; }\n    friend std::istream &operator>>(std::istream &is, DynamicModint\
    \ &rhs) {\n        std::int64_t val;\n        is >> val;\n        rhs.val = internal::modulo(val,\
    \ mod);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const DynamicModint &rhs) { return os << rhs.val; }\n\n    static constexpr\
    \ int get_id() { return id; }\n    static std::int32_t modulus() { return mod;\
    \ }\n    static void set_modulus(std::int32_t mod) {\n        assert(mod >= 1);\n\
    \        DynamicModint::mod = mod;\n    }\n    static DynamicModint raw(std::uint32_t\
    \ val) {\n        DynamicModint res;\n        res.val = val;\n        return res;\n\
    \    }\n\n    std::int64_t value() const { return val; }\n    DynamicModint inv()\
    \ const {\n        auto [x, g] = internal::mod_inv(val, mod);\n        assert(g\
    \ == 1);\n        return raw(x);\n    }\n    DynamicModint pow(long long k) const\
    \ {\n        if(k < 0) return raw(internal::mod_pow(val, -k, mod)).inv();\n  \
    \      return raw(internal::mod_pow(val, k, mod));\n    }\n\n    friend DynamicModint\
    \ mod_inv(const DynamicModint &a) { return a.inv(); }\n    friend DynamicModint\
    \ mod_pow(const DynamicModint &a, long long k) { return a.pow(k); }\n};\n\ntemplate\
    \ <int id>\nstd::uint32_t DynamicModint<id>::mod = 1'000'000'007;\n\n}  // namespace\
    \ algorithm\n\ntemplate <int id>\nstruct std::hash<algorithm::DynamicModint<id>>\
    \ {\n    std::size_t operator()(const algorithm::DynamicModint<id> &ob) const\
    \ { return ob.value(); }\n};\n\n\n"
  code: "#ifndef ALGORITHM_DYNAMIC_MODINT_HPP\n#define ALGORITHM_DYNAMIC_MODINT_HPP\
    \ 1\n\n#include <cassert>\n#include <concepts>\n#include <cstdint>\n#include <functional>\n\
    #include <iostream>\n\n#include \"mod_inv.hpp\"\n#include \"mod_pow.hpp\"\n#include\
    \ \"modint_base.hpp\"\n#include \"modulo.hpp\"\n\nnamespace algorithm {\n\ntemplate\
    \ <int id>\nclass DynamicModint : public ModintBase {\n    static std::uint32_t\
    \ mod;\n    std::uint32_t val;\n\npublic:\n    DynamicModint() : val(0) {}\n \
    \   template <std::integral Type>\n    DynamicModint(Type val) : val(internal::modulo(val,\
    \ mod)) {}\n\n    DynamicModint operator+() const { return DynamicModint(*this);\
    \ }\n    DynamicModint operator-() const {\n        if(val == 0) DynamicModint();\n\
    \        return raw(mod - val);\n    }\n    DynamicModint &operator++() {\n  \
    \      ++val;\n        if(val == mod) val = 0;\n        return *this;\n    }\n\
    \    DynamicModint &operator--() {\n        if(val == 0) val = mod;\n        --val;\n\
    \        return *this;\n    }\n    DynamicModint operator++(int) {\n        DynamicModint\
    \ res = *this;\n        ++(*this);\n        return res;\n    }\n    DynamicModint\
    \ operator--(int) {\n        DynamicModint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    DynamicModint &operator+=(const DynamicModint\
    \ &rhs) {\n        if(rhs.val >= mod - val) val -= mod;\n        val += rhs.val;\n\
    \        return *this;\n    }\n    DynamicModint &operator-=(const DynamicModint\
    \ &rhs) {\n        if(rhs.val > val) val += mod;\n        val -= rhs.val;\n  \
    \      return *this;\n    }\n    DynamicModint &operator*=(const DynamicModint\
    \ &rhs) {\n        val = static_cast<std::uint64_t>(val) * rhs.val % mod;\n  \
    \      return *this;\n    }\n    DynamicModint &operator/=(const DynamicModint\
    \ &rhs) { return *this *= rhs.inv(); }\n\n    friend bool operator==(const DynamicModint\
    \ &lhs, const DynamicModint &rhs) { return lhs.val == rhs.val; }\n    friend DynamicModint\
    \ operator+(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ += rhs; }\n    friend DynamicModint operator-(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) -= rhs; }\n    friend DynamicModint\
    \ operator*(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ *= rhs; }\n    friend DynamicModint operator/(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) /= rhs; }\n    friend std::istream\
    \ &operator>>(std::istream &is, DynamicModint &rhs) {\n        std::int64_t val;\n\
    \        is >> val;\n        rhs.val = internal::modulo(val, mod);\n        return\
    \ is;\n    }\n    friend std::ostream &operator<<(std::ostream &os, const DynamicModint\
    \ &rhs) { return os << rhs.val; }\n\n    static constexpr int get_id() { return\
    \ id; }\n    static std::int32_t modulus() { return mod; }\n    static void set_modulus(std::int32_t\
    \ mod) {\n        assert(mod >= 1);\n        DynamicModint::mod = mod;\n    }\n\
    \    static DynamicModint raw(std::uint32_t val) {\n        DynamicModint res;\n\
    \        res.val = val;\n        return res;\n    }\n\n    std::int64_t value()\
    \ const { return val; }\n    DynamicModint inv() const {\n        auto [x, g]\
    \ = internal::mod_inv(val, mod);\n        assert(g == 1);\n        return raw(x);\n\
    \    }\n    DynamicModint pow(long long k) const {\n        if(k < 0) return raw(internal::mod_pow(val,\
    \ -k, mod)).inv();\n        return raw(internal::mod_pow(val, k, mod));\n    }\n\
    \n    friend DynamicModint mod_inv(const DynamicModint &a) { return a.inv(); }\n\
    \    friend DynamicModint mod_pow(const DynamicModint &a, long long k) { return\
    \ a.pow(k); }\n};\n\ntemplate <int id>\nstd::uint32_t DynamicModint<id>::mod =\
    \ 1'000'000'007;\n\n}  // namespace algorithm\n\ntemplate <int id>\nstruct std::hash<algorithm::DynamicModint<id>>\
    \ {\n    std::size_t operator()(const algorithm::DynamicModint<id> &ob) const\
    \ { return ob.value(); }\n};\n\n#endif\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  - algorithm/Math/ModularArithmetic/modulo.hpp
  - algorithm/Math/ModularArithmetic/mod_pow.hpp
  - algorithm/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2026-02-27 06:07:42+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/no_1681_2.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
layout: document
title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
---


## 概要

実行時に法が決まる Modint 構造体．

インスタンスを生成する前に法とする自然数を設定する．

```cpp
DynamicModint<0>::set_modulus(5);
DynamicModint<0> a = 13;
DynamicModint<0> b = 17;
cout << a << " " << b << endl;  // 3 2

DynamicModint<1>::set_modulus(17);
DynamicModint<1> c = 13;
DynamicModint<1> d = 17;
cout << c << " " << d << endl;  // 13 0
```
