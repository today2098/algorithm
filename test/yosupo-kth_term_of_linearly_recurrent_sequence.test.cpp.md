---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/Algebra/kitamasa.hpp
    title: "\u304D\u305F\u307E\u3055\u6CD5"
  - icon: ':question:'
    path: src/Math/ModularArithmetic/modint.hpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/yosupo-kth_term_of_linearly_recurrent_sequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"src/Math/Algebra/kitamasa.hpp\"\
    \n\n\n\n/**\n * @brief \u304D\u305F\u307E\u3055\u6CD5\n * @docs docs/Math/Algebra/kitamasa.md\n\
    \ */\n\n#include <cassert>\n#include <cstdint>\n#line 12 \"src/Math/Algebra/kitamasa.hpp\"\
    \n\nnamespace algorithm {\n\n// \u304D\u305F\u307E\u3055\u6CD5\uFF0E\n// \u7DDA\
    \u5F62\u6F38\u5316\u5F0F a[n]=d[0]*a[n-k]+d[1]*a[n-(k-1)]+....+d[k-1]*a[n-1] \u3092\
    \u6C42\u3081\u308B\uFF0EO((K^2)*logN).\ntemplate <typename T = long long>\nclass\
    \ Kitamasa {\npublic:\n    using size_type = uint64_t;\n\nprivate:\n    size_type\
    \ m_k;       // m_k:=(\u968E\u6570).\n    std::vector<T> m_a;  // m_a[]:=(\u521D\
    \u9805\u884C\u5217).\n    std::vector<T> m_d;  // m_d[]:=(\u4FC2\u6570\u884C\u5217\
    ).\n\n    // f(n)->f(n+1). O(K).\n    std::vector<T> add(const std::vector<T>\
    \ &x) const {\n        std::vector<T> y(m_k);\n        y[0] = x[m_k - 1] * m_d[0];\n\
    \        for(size_type i = 1; i < m_k; ++i) y[i] = x[i - 1] + x[m_k - 1] * m_d[i];\n\
    \        return y;\n    }\n    // f(n)->f(2*n). O(K^2).\n    std::vector<T> mul(const\
    \ std::vector<T> &x) const {\n        std::vector<T> y(m_k, 0);\n        std::vector<T>\
    \ t = x;\n        for(size_type i = 0; i < m_k; ++i) {\n            for(size_type\
    \ j = 0; j < m_k; ++j) y[j] += x[i] * t[j];\n            if(i < m_k - 1) t = add(t);\n\
    \        }\n        return y;\n    }\n    // f(n)\u3092\u8FD4\u3059\uFF0EO((K^2)*logN).\n\
    \    std::vector<T> f(size_type n) const {\n        if(n == 0) {\n           \
    \ std::vector<T> x(m_k, 0);\n            x[0] = 1;\n            return x;  //\
    \ f(0).\n        }\n        std::vector<T> &&x = mul(f(n / 2));\n        if(n\
    \ & 1ULL) x = add(x);\n        return x;\n    }\n\npublic:\n    Kitamasa() : Kitamasa(std::vector<T>({0,\
    \ 1}), std::vector<T>({1, 1})) {}  // \u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u6570\
    \u5217\uFF0E\n    explicit Kitamasa(const std::vector<T> &a, const std::vector<T>\
    \ &d) : m_k(a.size()), m_a(a), m_d(d) {\n        assert(a.size() >= 1);\n    \
    \    assert(a.size() == d.size());\n    }\n\n    T operator[](size_type n) const\
    \ { return calc(n); }\n\n    // a[n]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*logN).\n\
    \    T calc(size_type n) const {\n        const std::vector<T> &&x = f(n);\n \
    \       T res = 0;\n        for(size_type i = 0; i < m_k; ++i) res += x[i] * m_a[i];\n\
    \        return res;\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 1 \"src/Math/ModularArithmetic/modint.hpp\"\
    \n/**\n * @brief Modint\n */\n\n#ifndef ALGORITHM_MODINT_HPP\n#define ALGORITHM_MODINT_HPP\
    \ 1\n\n#line 10 \"src/Math/ModularArithmetic/modint.hpp\"\n#include <utility>\n\
    \nnamespace algorithm {\n\ntemplate <int mod>\nclass Modint {\n    long long val;\n\
    \n    void build() {\n        if(!(-mod <= val and val < mod)) val %= mod;\n \
    \       if(val < 0) val += mod;\n    }\n\npublic:\n    Modint() : Modint(0) {}\n\
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
    #endif\n#line 8 \"test/yosupo-kth_term_of_linearly_recurrent_sequence.test.cpp\"\
    \n\nint main() {\n    int d;\n    long long k;\n    std::cin >> d >> k;\n\n  \
    \  std::vector<algorithm::mint998244353> a(d), c(d);\n    for(auto &in : a) std::cin\
    \ >> in;\n    for(auto &in : c) std::cin >> in;\n\n    algorithm::Kitamasa<algorithm::mint998244353>\
    \ kitamasa(a, c);\n\n    std::cout << kitamasa[k] << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../src/Math/Algebra/kitamasa.hpp\"\
    \n#include \"../src/Math/ModularArithmetic/modint.hpp\"\n\nint main() {\n    int\
    \ d;\n    long long k;\n    std::cin >> d >> k;\n\n    std::vector<algorithm::mint998244353>\
    \ a(d), c(d);\n    for(auto &in : a) std::cin >> in;\n    for(auto &in : c) std::cin\
    \ >> in;\n\n    algorithm::Kitamasa<algorithm::mint998244353> kitamasa(a, c);\n\
    \n    std::cout << kitamasa[k] << std::endl;\n}\n"
  dependsOn:
  - src/Math/Algebra/kitamasa.hpp
  - src/Math/ModularArithmetic/modint.hpp
  isVerificationFile: true
  path: test/yosupo-kth_term_of_linearly_recurrent_sequence.test.cpp
  requiredBy: []
  timestamp: '2023-09-23 04:49:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-kth_term_of_linearly_recurrent_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-kth_term_of_linearly_recurrent_sequence.test.cpp
- /verify/test/yosupo-kth_term_of_linearly_recurrent_sequence.test.cpp.html
title: test/yosupo-kth_term_of_linearly_recurrent_sequence.test.cpp
---
