---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/totient.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
  bundledCode: "#line 1 \"test/aoj-NTL_1_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D\"\
    \n\n#include <iostream>\n\n#line 1 \"src/Math/NumberTheory/totient.hpp\"\n/**\n\
    \ * @brief \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570\n * @docs\
    \ docs/Math/NumberTheory/totient.md\n */\n\n#ifndef ALGORITHM_TOTIENT_HPP\n#define\
    \ ALGORITHM_TOTIENT_HPP 1\n\n#include <cassert>\n\nnamespace algorithm {\n\n//\
    \ \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570\uFF0E\n// n\u4EE5\
    \u4E0B\u3067n\u3068\u4E92\u3044\u306B\u7D20\u306A\u81EA\u7136\u6570\u306E\u500B\
    \u6570\u3092\u6C42\u3081\u308B\uFF0EO(\u221AN).\ntemplate <typename Type>\nType\
    \ totient(Type n) {\n    assert(n >= 1);\n    Type res = n;\n    for(Type p =\
    \ 2; p * p <= n; ++p) {\n        if(n % p != 0) continue;\n        res -= res\
    \ / p;\n        while(n % p == 0) n /= p;\n    }\n    if(n > 1) res -= res / n;\n\
    \    return res;\n}\n\n};  // namespace algorithm\n\n#endif\n#line 6 \"test/aoj-NTL_1_D.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::cout << algorithm::totient(n)\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D\"\n\n\
    #include <iostream>\n\n#include \"../src/Math/NumberTheory/totient.hpp\"\n\nint\
    \ main() {\n    int n;\n    std::cin >> n;\n\n    std::cout << algorithm::totient(n)\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/Math/NumberTheory/totient.hpp
  isVerificationFile: true
  path: test/aoj-NTL_1_D.test.cpp
  requiredBy: []
  timestamp: '2023-09-11 21:21:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-NTL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-NTL_1_D.test.cpp
- /verify/test/aoj-NTL_1_D.test.cpp.html
title: test/aoj-NTL_1_D.test.cpp
---
