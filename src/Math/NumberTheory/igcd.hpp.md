---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/ilcm.hpp
    title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-NTL_1_C.test.cpp
    title: test/aoj-NTL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/igcd.hpp\"\n/**\n * @brief Greatest\
    \ Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09\n */\n\n#ifndef ALGORITHM_IGCD_HPP\n\
    #define ALGORITHM_IGCD_HPP 1\n\nnamespace algorithm {\n\n// Greatest Common Divisor\uFF08\
    \u6700\u5927\u516C\u7D04\u6570\uFF09. O(logN).\ntemplate <typename Type>\nType\
    \ igcd(Type a, Type b) { return (b == 0) ? a : igcd(b, a % b); }\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  code: "/**\n * @brief Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\
    \uFF09\n */\n\n#ifndef ALGORITHM_IGCD_HPP\n#define ALGORITHM_IGCD_HPP 1\n\nnamespace\
    \ algorithm {\n\n// Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\
    \uFF09. O(logN).\ntemplate <typename Type>\nType igcd(Type a, Type b) { return\
    \ (b == 0) ? a : igcd(b, a % b); }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/igcd.hpp
  requiredBy:
  - src/Math/NumberTheory/ilcm.hpp
  timestamp: '2023-09-13 00:11:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-NTL_1_C.test.cpp
documentation_of: src/Math/NumberTheory/igcd.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/igcd.hpp
- /library/src/Math/NumberTheory/igcd.hpp.html
title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
---
