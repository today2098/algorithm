---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D20\u6570\u5224\u5B9A"
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/is_prime.hpp\"\n/**\n * @brief \u7D20\
    \u6570\u5224\u5B9A\n */\n\n#ifndef ALGORITHM_IS_PRIME_HPP\n#define ALGORITHM_IS_PRIME_HPP\
    \ 1\n\n#include <cassert>\n\nnamespace algorithm {\n\n// \u7D20\u6570\u5224\u5B9A\
    \uFF0EO(\u221AN).\ntemplate <typename Type>\nbool is_prime(Type n) {\n    assert(n\
    \ >= 0);\n    if(n < 2) return false;\n    for(Type p = 2; p * p <= n; ++p) {\n\
    \        if(n % p == 0) return false;\n    }\n    return true;\n}\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  code: "/**\n * @brief \u7D20\u6570\u5224\u5B9A\n */\n\n#ifndef ALGORITHM_IS_PRIME_HPP\n\
    #define ALGORITHM_IS_PRIME_HPP 1\n\n#include <cassert>\n\nnamespace algorithm\
    \ {\n\n// \u7D20\u6570\u5224\u5B9A\uFF0EO(\u221AN).\ntemplate <typename Type>\n\
    bool is_prime(Type n) {\n    assert(n >= 0);\n    if(n < 2) return false;\n  \
    \  for(Type p = 2; p * p <= n; ++p) {\n        if(n % p == 0) return false;\n\
    \    }\n    return true;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/is_prime.hpp
  requiredBy: []
  timestamp: '2023-08-30 11:28:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/NumberTheory/is_prime.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/is_prime.hpp
- /library/src/Math/NumberTheory/is_prime.hpp.html
title: "\u7D20\u6570\u5224\u5B9A"
---
