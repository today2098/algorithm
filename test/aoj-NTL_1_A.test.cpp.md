---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A
  bundledCode: "#line 1 \"test/aoj-NTL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A\"\
    \n\n#include <iostream>\n\n#line 1 \"src/Math/NumberTheory/prime_factorization.hpp\"\
    \n/**\n * @brief \u7D20\u56E0\u6570\u5206\u89E3\n */\n\n#ifndef ALGORITHM_PRIME_FACTORIZATION_HPP\n\
    #define ALGORITHM_PRIME_FACTORIZATION_HPP 1\n\n#include <cassert>\n#include <map>\n\
    \nnamespace algorithm {\n\n// \u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\n\
    template <typename Type>\nstd::map<Type, int> prime_factorization(Type n) {\n\
    \    assert(n >= 2);\n    std::map<Type, int> res;  // res[p]:=(\u81EA\u7136\u6570\
    n\u306B\u542B\u307E\u308C\u308B\u7D20\u56E0\u6570p\u306E\u500B\u6570).\n    for(Type\
    \ p = 2; p * p <= n; ++p) {\n        if(n % p != 0) continue;\n        while(n\
    \ % p == 0) res[p]++, n /= p;\n    }\n    if(n != 1) res[n]++;\n    return res;\n\
    }\n\n}  // namespace algorithm\n\n#endif\n#line 6 \"test/aoj-NTL_1_A.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    auto &&mp = algorithm::prime_factorization(n);\n\
    \n    std::cout << n << \":\";\n    for(const auto &[p, cnt] : mp) {\n       \
    \ for(int i = 0; i < cnt; ++i) std::cout << \" \" << p;\n    }\n    std::cout\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A\"\
    \n\n#include <iostream>\n\n#include \"../src/Math/NumberTheory/prime_factorization.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    auto &&mp = algorithm::prime_factorization(n);\n\
    \n    std::cout << n << \":\";\n    for(const auto &[p, cnt] : mp) {\n       \
    \ for(int i = 0; i < cnt; ++i) std::cout << \" \" << p;\n    }\n    std::cout\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/Math/NumberTheory/prime_factorization.hpp
  isVerificationFile: true
  path: test/aoj-NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 12:30:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-NTL_1_A.test.cpp
- /verify/test/aoj-NTL_1_A.test.cpp.html
title: test/aoj-NTL_1_A.test.cpp
---
