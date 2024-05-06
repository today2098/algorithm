---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-ITP1_3_D.test.cpp
    title: test/aoj-ITP1_3_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D04\u6570\u5217\u6319"
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/divisors.hpp\"\n/**\n * @brief \u7D04\
    \u6570\u5217\u6319\n */\n\n#ifndef ALGORITHM_DIVISORS_HPP\n#define ALGORITHM_DIVISORS_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u7D04\u6570\u5217\u6319\uFF0EO(\u221AN).\ntemplate <typename\
    \ Type>\nstd::vector<Type> divisors(Type n) {\n    assert(n >= 1);\n    std::vector<Type>\
    \ res;  // res[]:=(\u81EA\u7136\u6570n\u306E\u7D04\u6570\u306E\u96C6\u5408).\n\
    \    for(Type p = 1; p * p <= n; ++p) {\n        if(n % p == 0) {\n          \
    \  res.push_back(p);\n            Type q = n / p;\n            if(q != p) res.push_back(q);\n\
    \        }\n    }\n    std::sort(res.begin(), res.end());\n    return res;\n}\n\
    \n}  // namespace algorithm\n\n#endif\n"
  code: "/**\n * @brief \u7D04\u6570\u5217\u6319\n */\n\n#ifndef ALGORITHM_DIVISORS_HPP\n\
    #define ALGORITHM_DIVISORS_HPP 1\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u7D04\u6570\u5217\u6319\uFF0E\
    O(\u221AN).\ntemplate <typename Type>\nstd::vector<Type> divisors(Type n) {\n\
    \    assert(n >= 1);\n    std::vector<Type> res;  // res[]:=(\u81EA\u7136\u6570\
    n\u306E\u7D04\u6570\u306E\u96C6\u5408).\n    for(Type p = 1; p * p <= n; ++p)\
    \ {\n        if(n % p == 0) {\n            res.push_back(p);\n            Type\
    \ q = n / p;\n            if(q != p) res.push_back(q);\n        }\n    }\n   \
    \ std::sort(res.begin(), res.end());\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/divisors.hpp
  requiredBy: []
  timestamp: '2023-09-13 00:11:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-ITP1_3_D.test.cpp
documentation_of: src/Math/NumberTheory/divisors.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/divisors.hpp
- /library/src/Math/NumberTheory/divisors.hpp.html
title: "\u7D04\u6570\u5217\u6319"
---