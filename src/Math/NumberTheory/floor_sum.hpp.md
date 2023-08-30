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
    - "https://atcoder.jp/contests/practice2/editorial/579\uFF08\u53C2\u71672022.9.17\uFF09\
      \uFF0E"
    - "https://qiita.com/HNJ/items/564f15316719209df73c\uFF08\u53C2\u71672022.9.17\uFF09\
      \uFF0E"
    - "https://rsk0315.hatenablog.com/entry/2020/12/13/231307\uFF08\u53C2\u71672022.9.17\uFF09\
      \uFF0E"
    - "https://twitter.com/kyopro_friends/status/1304063876019793921\uFF08\u53C2\u7167\
      2023.2.15\uFF09\uFF0E"
  bundledCode: "#line 1 \"src/Math/NumberTheory/floor_sum.hpp\"\n\n\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// sum_{x=0}^{n-1} floor((a*x+b)/m)\u3092\u6C42\u3081\
    \u308B\uFF0EO(logA+logM).\nlong long floor_sum(long long n, long long m, long\
    \ long a, long long b) {\n    assert(0 <= n and n < (1LL << 32));\n    assert(1\
    \ <= m and m < (1LL << 32));\n    long long res = 0;\n    if(a < 0) {\n      \
    \  long long a2 = (a % m + m) % m;\n        res -= n * (n - 1) / 2 * ((a2 - a)\
    \ / m);\n        a = a2;\n    }\n    if(b < 0) {\n        long long b2 = (b %\
    \ m + m) % m;\n        res -= n * ((b2 - b) / m);\n        b = b2;\n    }\n  \
    \  if(a >= m) {\n        res += n * (n - 1) / 2 * (a / m);\n        a %= m;\n\
    \    }\n    if(b >= m) {\n        res += n * (b / m);\n        b %= m;\n    }\n\
    \    long long y_max = a * n + b;\n    if(y_max >= m) res += floor_sum(y_max /\
    \ m, a, m, y_max % m);\n    return res;\n}\n\n}  // namespace algorithm\n\n\n\n\
    /*\n\u53C2\u8003\u6587\u732E\n- HNJ\uFF0CFloor Sum (ACL Practice Contest C)\uFF0C\
    Qiita, https://qiita.com/HNJ/items/564f15316719209df73c\uFF08\u53C2\u71672022.9.17\uFF09\
    \uFF0E\n- rsk0315\uFF0Csum of floor of liner \u306E\u89E3\u8AAC\u3092\u3059\u308B\
    \u3088\uFF0CHatena Blog, https://rsk0315.hatenablog.com/entry/2020/12/13/231307\uFF08\
    \u53C2\u71672022.9.17\uFF09\uFF0E\n- yosupo\uFF0CC - Floor Sum \u89E3\u8AAC\uFF0C\
    AtCoder, https://atcoder.jp/contests/practice2/editorial/579\uFF08\u53C2\u7167\
    2022.9.17\uFF09\uFF0E\n- kyopro_friends, Twitter, https://twitter.com/kyopro_friends/status/1304063876019793921\uFF08\
    \u53C2\u71672023.2.15\uFF09\uFF0E\n*/\n"
  code: "#ifndef ALGORITHM_FLOOR_SUM_HPP\n#define ALGORITHM_FLOOR_SUM_HPP 1\n\n#include\
    \ <cassert>\n\nnamespace algorithm {\n\n// sum_{x=0}^{n-1} floor((a*x+b)/m)\u3092\
    \u6C42\u3081\u308B\uFF0EO(logA+logM).\nlong long floor_sum(long long n, long long\
    \ m, long long a, long long b) {\n    assert(0 <= n and n < (1LL << 32));\n  \
    \  assert(1 <= m and m < (1LL << 32));\n    long long res = 0;\n    if(a < 0)\
    \ {\n        long long a2 = (a % m + m) % m;\n        res -= n * (n - 1) / 2 *\
    \ ((a2 - a) / m);\n        a = a2;\n    }\n    if(b < 0) {\n        long long\
    \ b2 = (b % m + m) % m;\n        res -= n * ((b2 - b) / m);\n        b = b2;\n\
    \    }\n    if(a >= m) {\n        res += n * (n - 1) / 2 * (a / m);\n        a\
    \ %= m;\n    }\n    if(b >= m) {\n        res += n * (b / m);\n        b %= m;\n\
    \    }\n    long long y_max = a * n + b;\n    if(y_max >= m) res += floor_sum(y_max\
    \ / m, a, m, y_max % m);\n    return res;\n}\n\n}  // namespace algorithm\n\n\
    #endif\n\n/*\n\u53C2\u8003\u6587\u732E\n- HNJ\uFF0CFloor Sum (ACL Practice Contest\
    \ C)\uFF0CQiita, https://qiita.com/HNJ/items/564f15316719209df73c\uFF08\u53C2\u7167\
    2022.9.17\uFF09\uFF0E\n- rsk0315\uFF0Csum of floor of liner \u306E\u89E3\u8AAC\
    \u3092\u3059\u308B\u3088\uFF0CHatena Blog, https://rsk0315.hatenablog.com/entry/2020/12/13/231307\uFF08\
    \u53C2\u71672022.9.17\uFF09\uFF0E\n- yosupo\uFF0CC - Floor Sum \u89E3\u8AAC\uFF0C\
    AtCoder, https://atcoder.jp/contests/practice2/editorial/579\uFF08\u53C2\u7167\
    2022.9.17\uFF09\uFF0E\n- kyopro_friends, Twitter, https://twitter.com/kyopro_friends/status/1304063876019793921\uFF08\
    \u53C2\u71672023.2.15\uFF09\uFF0E\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/floor_sum.hpp
  requiredBy: []
  timestamp: '2023-08-30 11:28:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/NumberTheory/floor_sum.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/floor_sum.hpp
- /library/src/Math/NumberTheory/floor_sum.hpp.html
title: src/Math/NumberTheory/floor_sum.hpp
---
