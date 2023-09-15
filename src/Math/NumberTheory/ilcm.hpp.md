---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/igcd.hpp
    title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-NTL_1_C.test.cpp
    title: test/aoj-NTL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/NumberTheory/ilcm.hpp: line 8: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09\
    \n */\n\n#ifndef ALGORITHM_ILCM_HPP\n#define ALGORITHM_ILCM_HPP 1\n\n#include\
    \ \"igcd.hpp\"\n\nnamespace algorithm {\n\n// Least Common Multiple\uFF08\u6700\
    \u5C0F\u516C\u500D\u6570\uFF09. O(logN).\ntemplate <typename Type>\nType ilcm(Type\
    \ a, Type b) { return a / igcd(a, b) * b; }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - src/Math/NumberTheory/igcd.hpp
  isVerificationFile: false
  path: src/Math/NumberTheory/ilcm.hpp
  requiredBy: []
  timestamp: '2023-09-13 00:11:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-NTL_1_C.test.cpp
documentation_of: src/Math/NumberTheory/ilcm.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/ilcm.hpp
- /library/src/Math/NumberTheory/ilcm.hpp.html
title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
---
