---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - "https://qiita.com/drken/items/ae02240cd1f8edfc86fd\uFF08\u53C2\u71672022.9.16\uFF09\
      \uFF0E"
    - "https://qiita.com/drken/items/b97ff231e43bce50199a\uFF08\u53C2\u71672023.2.2\uFF09\
      \uFF0E"
  bundledCode: "#line 1 \"src/Math/NumberTheory/extgcd.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\
    \u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\uFF0E\n// ax+by=GCD(a,b) \u3092\u6E80\
    \u305F\u3059\u6574\u6570\u306E\u7D44(x,y)\u3092\u6C42\u3081\uFF0CGCD(a,b)\u3092\
    \u8FD4\u3059\uFF0EO(logN).\ntemplate <typename Type>\nType extgcd(Type a, Type\
    \ b, Type &x, Type &y) {\n    if(b == 0) {\n        x = 1, y = 0;\n        return\
    \ a;\n    }\n    Type d = extgcd(b, a % b, y, x);\n    y -= a / b * x;\n    return\
    \ d;\n}\n\n// \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese Remainder Theorem)\uFF0E\
    \n// x\u2261b1 (mod. m1) \u304B\u3064 x\u2261b2 (mod. m2) \u3092\u6E80\u305F\u3059\
    \u6574\u6570x(0\u2266x\uFF1Clcm(m1,m2))\u3092\u6C42\u3081\u308B\uFF0E\n// \u8FD4\
    \u308A\u5024\u306F x\u2261r (mod. m) \u3068\u306A\u308B\u7D44(r,m)\uFF0E\u89E3\
    \u306A\u3057\u306E\u5834\u5408\uFF0C(0,-1)\u3092\u8FD4\u3059\uFF0E\nstd::pair<long\
    \ long, long long> crt(long long b1, long long m1, long long b2, long long m2)\
    \ {\n    long long p, q;\n    long long d = extgcd(m1, m2, p, q);  // p is inv\
    \ of m1/d (mod. m2/d)\n    if((b2 - b1) % d != 0) return {0, -1};\n    long long\
    \ m = m1 / d * m2;  // lcm of (m1,m2)\n    long long tmp = (b2 - b1) / d * p %\
    \ (m2 / d);\n    long long r = ((b1 + m1 * tmp) % m + m) % m;\n    return {r,\
    \ m};\n}\n\n// \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese Remainder Theorem)\uFF0E\
    \n// \u5404i\u306B\u3064\u3044\u3066\uFF0Cx\u2261b[i] (mod. m[i]) \u3092\u6E80\
    \u305F\u3059\u6574\u6570x(0\u2266x\uFF1Clcm(m[i]))\u3092\u6C42\u3081\u308B\uFF0E\
    \n// \u8FD4\u308A\u5024\u306F x\u2261r (mod. m) \u3068\u306A\u308B\u7D44(r,m)\uFF0E\
    \u89E3\u306A\u3057\u306E\u5834\u5408\uFF0C(0,-1)\u3092\u8FD4\u3059\uFF0E\nstd::pair<long\
    \ long, long long> crt(const std::vector<long long> &bs, const std::vector<long\
    \ long> &ms) {\n    assert(bs.size() == ms.size());\n    const int sz = bs.size();\n\
    \    long long r = 0, m = 1;\n    for(int i = 0; i < sz; ++i) {\n        auto\
    \ &&[rr, mm] = crt(r, m, bs[i], ms[i]);\n        if(rr == 0 and mm == -1) return\
    \ {0, -1};\n        r = rr, m = mm;\n    }\n    return {r, m};\n}\n\n}  // namespace\
    \ algorithm\n\n\n\n/*\n\u53C2\u8003\u6587\u732E\n- drken, \u62E1\u5F35\u30E6\u30FC\
    \u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5 \u301C \u4E00\u6B21\u4E0D\u5B9A\
    \u65B9\u7A0B\u5F0F ax + by = c \u306E\u89E3\u304D\u65B9 \u301C\uFF0CQiita, https://qiita.com/drken/items/b97ff231e43bce50199a\uFF08\
    \u53C2\u71672023.2.2\uFF09\uFF0E\n- drken\uFF0C\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\
    \ (CRT) \u306E\u89E3\u8AAC\u3068\u305D\u308C\u3092\u7528\u3044\u308B\u554F\u984C\
    \u306E\u307E\u3068\u3081\uFF0CQiita, https://qiita.com/drken/items/ae02240cd1f8edfc86fd\uFF08\
    \u53C2\u71672022.9.16\uFF09\uFF0E\n*/\n"
  code: "#ifndef ALGORITHM_EXTGCD_HPP\n#define ALGORITHM_EXTGCD_HPP 1\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u62E1\u5F35\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\uFF0E\n// ax+by=GCD(a,b)\
    \ \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44(x,y)\u3092\u6C42\u3081\uFF0C\
    GCD(a,b)\u3092\u8FD4\u3059\uFF0EO(logN).\ntemplate <typename Type>\nType extgcd(Type\
    \ a, Type b, Type &x, Type &y) {\n    if(b == 0) {\n        x = 1, y = 0;\n  \
    \      return a;\n    }\n    Type d = extgcd(b, a % b, y, x);\n    y -= a / b\
    \ * x;\n    return d;\n}\n\n// \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese Remainder\
    \ Theorem)\uFF0E\n// x\u2261b1 (mod. m1) \u304B\u3064 x\u2261b2 (mod. m2) \u3092\
    \u6E80\u305F\u3059\u6574\u6570x(0\u2266x\uFF1Clcm(m1,m2))\u3092\u6C42\u3081\u308B\
    \uFF0E\n// \u8FD4\u308A\u5024\u306F x\u2261r (mod. m) \u3068\u306A\u308B\u7D44\
    (r,m)\uFF0E\u89E3\u306A\u3057\u306E\u5834\u5408\uFF0C(0,-1)\u3092\u8FD4\u3059\uFF0E\
    \nstd::pair<long long, long long> crt(long long b1, long long m1, long long b2,\
    \ long long m2) {\n    long long p, q;\n    long long d = extgcd(m1, m2, p, q);\
    \  // p is inv of m1/d (mod. m2/d)\n    if((b2 - b1) % d != 0) return {0, -1};\n\
    \    long long m = m1 / d * m2;  // lcm of (m1,m2)\n    long long tmp = (b2 -\
    \ b1) / d * p % (m2 / d);\n    long long r = ((b1 + m1 * tmp) % m + m) % m;\n\
    \    return {r, m};\n}\n\n// \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese Remainder\
    \ Theorem)\uFF0E\n// \u5404i\u306B\u3064\u3044\u3066\uFF0Cx\u2261b[i] (mod. m[i])\
    \ \u3092\u6E80\u305F\u3059\u6574\u6570x(0\u2266x\uFF1Clcm(m[i]))\u3092\u6C42\u3081\
    \u308B\uFF0E\n// \u8FD4\u308A\u5024\u306F x\u2261r (mod. m) \u3068\u306A\u308B\
    \u7D44(r,m)\uFF0E\u89E3\u306A\u3057\u306E\u5834\u5408\uFF0C(0,-1)\u3092\u8FD4\u3059\
    \uFF0E\nstd::pair<long long, long long> crt(const std::vector<long long> &bs,\
    \ const std::vector<long long> &ms) {\n    assert(bs.size() == ms.size());\n \
    \   const int sz = bs.size();\n    long long r = 0, m = 1;\n    for(int i = 0;\
    \ i < sz; ++i) {\n        auto &&[rr, mm] = crt(r, m, bs[i], ms[i]);\n       \
    \ if(rr == 0 and mm == -1) return {0, -1};\n        r = rr, m = mm;\n    }\n \
    \   return {r, m};\n}\n\n}  // namespace algorithm\n\n#endif\n\n/*\n\u53C2\u8003\
    \u6587\u732E\n- drken, \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5 \u301C \u4E00\u6B21\u4E0D\u5B9A\u65B9\u7A0B\u5F0F ax + by = c \u306E\
    \u89E3\u304D\u65B9 \u301C\uFF0CQiita, https://qiita.com/drken/items/b97ff231e43bce50199a\uFF08\
    \u53C2\u71672023.2.2\uFF09\uFF0E\n- drken\uFF0C\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\
    \ (CRT) \u306E\u89E3\u8AAC\u3068\u305D\u308C\u3092\u7528\u3044\u308B\u554F\u984C\
    \u306E\u307E\u3068\u3081\uFF0CQiita, https://qiita.com/drken/items/ae02240cd1f8edfc86fd\uFF08\
    \u53C2\u71672022.9.16\uFF09\uFF0E\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/extgcd.hpp
  requiredBy: []
  timestamp: '2023-08-30 11:28:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/NumberTheory/extgcd.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/extgcd.hpp
- /library/src/Math/NumberTheory/extgcd.hpp.html
title: src/Math/NumberTheory/extgcd.hpp
---
