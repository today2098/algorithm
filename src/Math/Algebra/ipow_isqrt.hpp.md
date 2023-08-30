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
  bundledCode: "#line 1 \"src/Math/Algebra/ipow_isqrt.hpp\"\n\n\n\n#include <cassert>\n\
    #include <cmath>\n\nnamespace algorithm {\n\n// \u7E70\u8FD4\u3057\u4E8C\u4E57\
    \u6CD5\uFF0EO(logK).\nlong long ipow(long long n, long long k) {\n    assert(k\
    \ >= 0);\n    if(k == 0) return 1;\n    long long &&res = ipow(n * n, k >> 1);\n\
    \    if(k & 1LL) res *= n;\n    return res;\n}\n\n// \u5E73\u65B9\u6839\uFF08\u30CB\
    \u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\uFF0E\ndouble isqrt(double x, const double\
    \ eps = 1e-10) {\n    assert(x >= 0.0);\n    double res = 5.0;\n    while(1) {\n\
    \        double tmp = (x / res + res) / 2;\n        if(std::abs(tmp - res) < eps)\
    \ break;\n        res = tmp;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_IPOW_ISQRT_HPP\n#define ALGORITHM_IPOW_ISQRT_HPP 1\n\n\
    #include <cassert>\n#include <cmath>\n\nnamespace algorithm {\n\n// \u7E70\u8FD4\
    \u3057\u4E8C\u4E57\u6CD5\uFF0EO(logK).\nlong long ipow(long long n, long long\
    \ k) {\n    assert(k >= 0);\n    if(k == 0) return 1;\n    long long &&res = ipow(n\
    \ * n, k >> 1);\n    if(k & 1LL) res *= n;\n    return res;\n}\n\n// \u5E73\u65B9\
    \u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\uFF0E\ndouble isqrt(double\
    \ x, const double eps = 1e-10) {\n    assert(x >= 0.0);\n    double res = 5.0;\n\
    \    while(1) {\n        double tmp = (x / res + res) / 2;\n        if(std::abs(tmp\
    \ - res) < eps) break;\n        res = tmp;\n    }\n    return res;\n}\n\n}  //\
    \ namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Algebra/ipow_isqrt.hpp
  requiredBy: []
  timestamp: '2023-08-30 11:28:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/Algebra/ipow_isqrt.hpp
layout: document
redirect_from:
- /library/src/Math/Algebra/ipow_isqrt.hpp
- /library/src/Math/Algebra/ipow_isqrt.hpp.html
title: src/Math/Algebra/ipow_isqrt.hpp
---
