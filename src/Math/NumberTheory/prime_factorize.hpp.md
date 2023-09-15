---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-NTL_1_A.test.cpp
    title: test/aoj-NTL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D20\u56E0\u6570\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/prime_factorize.hpp\"\n/**\n * @brief\
    \ \u7D20\u56E0\u6570\u5206\u89E3\n */\n\n#ifndef ALGORITHM_PRIME_FACTORIZE_HPP\n\
    #define ALGORITHM_PRIME_FACTORIZE_HPP 1\n\n#include <cassert>\n#include <map>\n\
    \nnamespace algorithm {\n\n// \u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\n\
    template <typename Type>\nstd::map<Type, int> prime_factorize(Type n) {\n    assert(n\
    \ >= 0);\n    std::map<Type, int> res;  // res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\
    \u307E\u308C\u308B\u7D20\u56E0\u6570p\u306E\u500B\u6570).\n    for(Type p = 2;\
    \ p * p <= n; ++p) {\n        while(n % p == 0) res[p]++, n /= p;\n    }\n   \
    \ if(n > 1) res[n] = 1;\n    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  code: "/**\n * @brief \u7D20\u56E0\u6570\u5206\u89E3\n */\n\n#ifndef ALGORITHM_PRIME_FACTORIZE_HPP\n\
    #define ALGORITHM_PRIME_FACTORIZE_HPP 1\n\n#include <cassert>\n#include <map>\n\
    \nnamespace algorithm {\n\n// \u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\n\
    template <typename Type>\nstd::map<Type, int> prime_factorize(Type n) {\n    assert(n\
    \ >= 0);\n    std::map<Type, int> res;  // res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\
    \u307E\u308C\u308B\u7D20\u56E0\u6570p\u306E\u500B\u6570).\n    for(Type p = 2;\
    \ p * p <= n; ++p) {\n        while(n % p == 0) res[p]++, n /= p;\n    }\n   \
    \ if(n > 1) res[n] = 1;\n    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/prime_factorize.hpp
  requiredBy: []
  timestamp: '2023-09-13 00:24:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-NTL_1_A.test.cpp
documentation_of: src/Math/NumberTheory/prime_factorize.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/prime_factorize.hpp
- /library/src/Math/NumberTheory/prime_factorize.hpp.html
title: "\u7D20\u56E0\u6570\u5206\u89E3"
---
