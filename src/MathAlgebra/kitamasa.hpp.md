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
  bundledCode: "#line 1 \"src/MathAlgebra/kitamasa.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u304D\u305F\u307E\u3055\u6CD5\
    \uFF0E\u7DDA\u5F62\u6F38\u5316\u5F0F a[n]=d[0]*a[n-k]+d[1]*a[n-k+1]+....+d[k-1]*a[n-1]\
    \ \u3092\u6C42\u3081\u308B\uFF0EO((K^2)*logN).\ntemplate <typename T = long long>\n\
    class Kitamasa {\n    int k;             // k:=(\u968E\u6570).\n    std::vector<T>\
    \ a;  // a[]:=(\u521D\u9805\u884C\u5217).\n    std::vector<T> d;  // d[]:=(\u4FC2\
    \u6570\u884C\u5217).\n\n    // f(n)->f(n+1). O(K).\n    std::vector<T> add(const\
    \ std::vector<T> &x) const {\n        std::vector<T> y(k);\n        y[0] = x[k\
    \ - 1] * d[0];\n        for(int i = 1; i < k; ++i) y[i] = x[i - 1] + x[k - 1]\
    \ * d[i];\n        return y;\n    }\n    // f(n)->f(2*n). O(K^2).\n    std::vector<T>\
    \ mul(const std::vector<T> &x) const {\n        std::vector<T> y(k, 0);\n    \
    \    auto t = x;\n        for(int i = 0; i < k; ++i) {\n            for(int j\
    \ = 0; j < k; ++j) y[j] += x[i] * t[j];\n            if(i < k - 1) t = add(t);\n\
    \        }\n        return y;\n    }\n    // f(n)\u3092\u8FD4\u3059\uFF0EO((K^2)*logN).\n\
    \    std::vector<T> f(long long n) const {\n        if(n == 0) {\n           \
    \ std::vector<T> x(k, 0);\n            x[0] = 1;\n            return x;  // f(0).\n\
    \        }\n        auto &&x = mul(f(n / 2));\n        if(n & 1LL) x = add(x);\n\
    \        return x;\n    }\n\npublic:\n    Kitamasa() : Kitamasa(std::vector<T>({0,\
    \ 1}), std::vector<T>({1, 1})) {}  // \u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u6570\
    \u5217\uFF0E\n    explicit Kitamasa(const std::vector<T> &a_, const std::vector<T>\
    \ &d_) : k(a_.size()), a(a_), d(d_) {\n        assert(k >= 1 and a.size() == d.size());\n\
    \    }\n\n    T operator[](long long n) const { return calc(n); }\n\n    // a[n]\u3092\
    \u8FD4\u3059\uFF0EO((K^2)*logN).\n    T calc(long long n) const {\n        assert(n\
    \ >= 0);\n        const auto &&x = f(n);\n        T res = 0;\n        for(int\
    \ i = 0; i < k; ++i) res += x[i] * a[i];\n        return res;\n    }\n};\n\n}\
    \  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_KITAMASA_HPP\n#define ALGORITHM_KITAMASA_HPP 1\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u304D\u305F\u307E\
    \u3055\u6CD5\uFF0E\u7DDA\u5F62\u6F38\u5316\u5F0F a[n]=d[0]*a[n-k]+d[1]*a[n-k+1]+....+d[k-1]*a[n-1]\
    \ \u3092\u6C42\u3081\u308B\uFF0EO((K^2)*logN).\ntemplate <typename T = long long>\n\
    class Kitamasa {\n    int k;             // k:=(\u968E\u6570).\n    std::vector<T>\
    \ a;  // a[]:=(\u521D\u9805\u884C\u5217).\n    std::vector<T> d;  // d[]:=(\u4FC2\
    \u6570\u884C\u5217).\n\n    // f(n)->f(n+1). O(K).\n    std::vector<T> add(const\
    \ std::vector<T> &x) const {\n        std::vector<T> y(k);\n        y[0] = x[k\
    \ - 1] * d[0];\n        for(int i = 1; i < k; ++i) y[i] = x[i - 1] + x[k - 1]\
    \ * d[i];\n        return y;\n    }\n    // f(n)->f(2*n). O(K^2).\n    std::vector<T>\
    \ mul(const std::vector<T> &x) const {\n        std::vector<T> y(k, 0);\n    \
    \    auto t = x;\n        for(int i = 0; i < k; ++i) {\n            for(int j\
    \ = 0; j < k; ++j) y[j] += x[i] * t[j];\n            if(i < k - 1) t = add(t);\n\
    \        }\n        return y;\n    }\n    // f(n)\u3092\u8FD4\u3059\uFF0EO((K^2)*logN).\n\
    \    std::vector<T> f(long long n) const {\n        if(n == 0) {\n           \
    \ std::vector<T> x(k, 0);\n            x[0] = 1;\n            return x;  // f(0).\n\
    \        }\n        auto &&x = mul(f(n / 2));\n        if(n & 1LL) x = add(x);\n\
    \        return x;\n    }\n\npublic:\n    Kitamasa() : Kitamasa(std::vector<T>({0,\
    \ 1}), std::vector<T>({1, 1})) {}  // \u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u6570\
    \u5217\uFF0E\n    explicit Kitamasa(const std::vector<T> &a_, const std::vector<T>\
    \ &d_) : k(a_.size()), a(a_), d(d_) {\n        assert(k >= 1 and a.size() == d.size());\n\
    \    }\n\n    T operator[](long long n) const { return calc(n); }\n\n    // a[n]\u3092\
    \u8FD4\u3059\uFF0EO((K^2)*logN).\n    T calc(long long n) const {\n        assert(n\
    \ >= 0);\n        const auto &&x = f(n);\n        T res = 0;\n        for(int\
    \ i = 0; i < k; ++i) res += x[i] * a[i];\n        return res;\n    }\n};\n\n}\
    \  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/MathAlgebra/kitamasa.hpp
  requiredBy: []
  timestamp: '2023-04-06 08:46:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/MathAlgebra/kitamasa.hpp
layout: document
redirect_from:
- /library/src/MathAlgebra/kitamasa.hpp
- /library/src/MathAlgebra/kitamasa.hpp.html
title: src/MathAlgebra/kitamasa.hpp
---
