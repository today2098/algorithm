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
  bundledCode: "#line 1 \"src/MathNumberTheory/prime.hpp\"\n\n\n\n#include <cassert>\n\
    #include <map>\n#include <type_traits>\n\nnamespace algorithm {\n\n// \u7D20\u6570\
    \u5224\u5B9A\uFF0EO(\u221AN).\ntemplate <typename Type>\nbool is_prime(Type n)\
    \ {\n    assert(n >= 0);\n    if(n < 2) return false;\n    for(Type p = 2; p *\
    \ p <= n; ++p) {\n        if(n % p == 0) return false;\n    }\n    return true;\n\
    }\n\n// \u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\ntemplate <typename Type>\n\
    std::map<Type, int> prime_factorize(Type n) {\n    assert(n >= 2);\n    std::map<Type,\
    \ int> res;  // res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\u307E\u308C\u308B\u7D20\
    \u56E0\u6570p\u306E\u500B\u6570).\n    for(Type p = 2; p * p <= n; ++p) {\n  \
    \      if(n % p != 0) continue;\n        while(n % p == 0) res[p]++, n /= p;\n\
    \    }\n    if(n != 1) res[n]++;\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_PRIME_HPP\n#define ALGORITHM_PRIME_HPP 1\n\n#include <cassert>\n\
    #include <map>\n#include <type_traits>\n\nnamespace algorithm {\n\n// \u7D20\u6570\
    \u5224\u5B9A\uFF0EO(\u221AN).\ntemplate <typename Type>\nbool is_prime(Type n)\
    \ {\n    assert(n >= 0);\n    if(n < 2) return false;\n    for(Type p = 2; p *\
    \ p <= n; ++p) {\n        if(n % p == 0) return false;\n    }\n    return true;\n\
    }\n\n// \u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\ntemplate <typename Type>\n\
    std::map<Type, int> prime_factorize(Type n) {\n    assert(n >= 2);\n    std::map<Type,\
    \ int> res;  // res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\u307E\u308C\u308B\u7D20\
    \u56E0\u6570p\u306E\u500B\u6570).\n    for(Type p = 2; p * p <= n; ++p) {\n  \
    \      if(n % p != 0) continue;\n        while(n % p == 0) res[p]++, n /= p;\n\
    \    }\n    if(n != 1) res[n]++;\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/MathNumberTheory/prime.hpp
  requiredBy: []
  timestamp: '2023-04-05 19:20:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/MathNumberTheory/prime.hpp
layout: document
redirect_from:
- /library/src/MathNumberTheory/prime.hpp
- /library/src/MathNumberTheory/prime.hpp.html
title: src/MathNumberTheory/prime.hpp
---
