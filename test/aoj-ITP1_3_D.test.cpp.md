---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/divisors.hpp
    title: "\u7D04\u6570\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D
  bundledCode: "#line 1 \"test/aoj-ITP1_3_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D\"\
    \n\n#include <algorithm>\n#include <iostream>\n\n#line 1 \"src/Math/NumberTheory/divisors.hpp\"\
    \n/**\n * @brief \u7D04\u6570\u5217\u6319\n */\n\n#ifndef ALGORITHM_DIVISORS_HPP\n\
    #define ALGORITHM_DIVISORS_HPP 1\n\n#line 9 \"src/Math/NumberTheory/divisors.hpp\"\
    \n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u7D04\u6570\
    \u5217\u6319\uFF0EO(\u221AN).\ntemplate <typename Type>\nstd::vector<Type> divisors(Type\
    \ n) {\n    assert(n >= 1);\n    std::vector<Type> res;  // res[]:=(\u81EA\u7136\
    \u6570n\u306E\u7D04\u6570\u306E\u96C6\u5408).\n    for(Type p = 1; p * p <= n;\
    \ ++p) {\n        if(n % p == 0) {\n            res.push_back(p);\n          \
    \  Type q = n / p;\n            if(q != p) res.push_back(q);\n        }\n    }\n\
    \    std::sort(res.begin(), res.end());\n    return res;\n}\n\n}  // namespace\
    \ algorithm\n\n#endif\n#line 7 \"test/aoj-ITP1_3_D.test.cpp\"\n\nint main() {\n\
    \    int a, b, c;\n    std::cin >> a >> b >> c;\n\n    const auto &&divs = algorithm::divisors(c);\n\
    \    std::cout << std::upper_bound(divs.begin(), divs.end(), b) - std::lower_bound(divs.begin(),\
    \ divs.end(), a) << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D\"\n\n\
    #include <algorithm>\n#include <iostream>\n\n#include \"../src/Math/NumberTheory/divisors.hpp\"\
    \n\nint main() {\n    int a, b, c;\n    std::cin >> a >> b >> c;\n\n    const\
    \ auto &&divs = algorithm::divisors(c);\n    std::cout << std::upper_bound(divs.begin(),\
    \ divs.end(), b) - std::lower_bound(divs.begin(), divs.end(), a) << std::endl;\n\
    }\n"
  dependsOn:
  - src/Math/NumberTheory/divisors.hpp
  isVerificationFile: true
  path: test/aoj-ITP1_3_D.test.cpp
  requiredBy: []
  timestamp: '2023-09-13 00:40:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ITP1_3_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ITP1_3_D.test.cpp
- /verify/test/aoj-ITP1_3_D.test.cpp.html
title: test/aoj-ITP1_3_D.test.cpp
---
