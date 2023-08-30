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
  bundledCode: "#line 1 \"src/Math/NumberTheory/divisor.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u6700\u5927\
    \u516C\u7D04\u6570 (GCD: Greatest Common Divisor)\uFF0EO(logN).\ntemplate <typename\
    \ Type>\nType igcd(Type a, Type b) { return (b == 0) ? a : igcd(b, a % b); }\n\
    \n// \u6700\u5C0F\u516C\u500D\u6570 (LCM: Least Common Multiple)\uFF0EO(logN).\n\
    template <typename Type>\nType ilcm(Type a, Type b) { return a / igcd(a, b) *\
    \ b; }\n\n// \u7D04\u6570\u5217\u6319\uFF0EO(\u221AN).\ntemplate <typename Type>\n\
    std::vector<Type> divisors(Type n) {\n    assert(n >= 0);\n    std::vector<Type>\
    \ res;  // res[]:=(\u81EA\u7136\u6570n\u306E\u7D04\u6570\u306E\u96C6\u5408).\n\
    \    for(Type p = 1; p * p <= n; ++p) {\n        if(n % p == 0) {\n          \
    \  res.push_back(p);\n            Type q = n / p;\n            if(q != p) res.push_back(q);\n\
    \        }\n    }\n    std::sort(res.begin(), res.end());\n    return res;\n}\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DIVISOR_HPP\n#define ALGORITHM_DIVISOR_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\
    \n// \u6700\u5927\u516C\u7D04\u6570 (GCD: Greatest Common Divisor)\uFF0EO(logN).\n\
    template <typename Type>\nType igcd(Type a, Type b) { return (b == 0) ? a : igcd(b,\
    \ a % b); }\n\n// \u6700\u5C0F\u516C\u500D\u6570 (LCM: Least Common Multiple)\uFF0E\
    O(logN).\ntemplate <typename Type>\nType ilcm(Type a, Type b) { return a / igcd(a,\
    \ b) * b; }\n\n// \u7D04\u6570\u5217\u6319\uFF0EO(\u221AN).\ntemplate <typename\
    \ Type>\nstd::vector<Type> divisors(Type n) {\n    assert(n >= 0);\n    std::vector<Type>\
    \ res;  // res[]:=(\u81EA\u7136\u6570n\u306E\u7D04\u6570\u306E\u96C6\u5408).\n\
    \    for(Type p = 1; p * p <= n; ++p) {\n        if(n % p == 0) {\n          \
    \  res.push_back(p);\n            Type q = n / p;\n            if(q != p) res.push_back(q);\n\
    \        }\n    }\n    std::sort(res.begin(), res.end());\n    return res;\n}\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/divisor.hpp
  requiredBy: []
  timestamp: '2023-08-30 11:28:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/NumberTheory/divisor.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/divisor.hpp
- /library/src/Math/NumberTheory/divisor.hpp.html
title: src/Math/NumberTheory/divisor.hpp
---
