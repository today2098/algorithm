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
  bundledCode: "#line 1 \"src/Math/NumberTheory/prime_factorization.hpp\"\n/**\n *\
    \ @brief \u7D20\u56E0\u6570\u5206\u89E3\n */\n\n#ifndef ALGORITHM_PRIME_FACTORIZATION_HPP\n\
    #define ALGORITHM_PRIME_FACTORIZATION_HPP 1\n\n#include <cassert>\n#include <map>\n\
    \nnamespace algorithm {\n\n// \u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\n\
    template <typename Type>\nstd::map<Type, int> prime_factorization(Type n) {\n\
    \    assert(n >= 2);\n    std::map<Type, int> res;  // res[p]:=(\u81EA\u7136\u6570\
    n\u306B\u542B\u307E\u308C\u308B\u7D20\u56E0\u6570p\u306E\u500B\u6570).\n    for(Type\
    \ p = 2; p * p <= n; ++p) {\n        if(n % p != 0) continue;\n        while(n\
    \ % p == 0) res[p]++, n /= p;\n    }\n    if(n != 1) res[n]++;\n    return res;\n\
    }\n\n}  // namespace algorithm\n\n#endif\n"
  code: "/**\n * @brief \u7D20\u56E0\u6570\u5206\u89E3\n */\n\n#ifndef ALGORITHM_PRIME_FACTORIZATION_HPP\n\
    #define ALGORITHM_PRIME_FACTORIZATION_HPP 1\n\n#include <cassert>\n#include <map>\n\
    \nnamespace algorithm {\n\n// \u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\n\
    template <typename Type>\nstd::map<Type, int> prime_factorization(Type n) {\n\
    \    assert(n >= 2);\n    std::map<Type, int> res;  // res[p]:=(\u81EA\u7136\u6570\
    n\u306B\u542B\u307E\u308C\u308B\u7D20\u56E0\u6570p\u306E\u500B\u6570).\n    for(Type\
    \ p = 2; p * p <= n; ++p) {\n        if(n % p != 0) continue;\n        while(n\
    \ % p == 0) res[p]++, n /= p;\n    }\n    if(n != 1) res[n]++;\n    return res;\n\
    }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/prime_factorization.hpp
  requiredBy: []
  timestamp: '2023-08-30 11:28:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-NTL_1_A.test.cpp
documentation_of: src/Math/NumberTheory/prime_factorization.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/prime_factorization.hpp
- /library/src/Math/NumberTheory/prime_factorization.hpp.html
title: "\u7D20\u56E0\u6570\u5206\u89E3"
---
