---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/floor_sum.hpp
    title: Floor Sum
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/yosupo-sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#include <iostream>\n\
    \n#line 1 \"src/Math/NumberTheory/floor_sum.hpp\"\n\n\n\n/**\n * @brief Floor\
    \ Sum\n * @docs docs/Math/NumberTheory/floor_sum.md\n */\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// sum_{x=0}^{n-1} floor((a*x+b)/m) \u3092\u6C42\u3081\
    \u308B\uFF0EO(log m).\nlong long floor_sum(long long n, long long m, long long\
    \ a, long long b) {\n    assert(0 <= n and n < 1LL << 32);\n    assert(1 <= m\
    \ and m < 1LL << 32);\n    long long res = 0;\n    if(a >= m) {\n        res +=\
    \ a / m * (n * (n - 1) / 2);\n        a %= m;\n    } else if(a < 0) {\n      \
    \  long long na = (a % m + m) % m;\n        res -= (na - a) / m * (n * (n - 1)\
    \ / 2);\n        a = na;\n    }\n    if(b >= m) {\n        res += b / m * n;\n\
    \        b %= m;\n    } else if(b < 0) {\n        long long nb = (b % m + m) %\
    \ m;\n        res -= (nb - b) / m * n;\n        b = nb;\n    }\n    long long\
    \ y_max = a * n + b;\n    if(y_max >= m) res += floor_sum(y_max / m, a, m, y_max\
    \ % m);\n    return res;\n}\n\n}  // namespace algorithm\n\n\n#line 6 \"test/yosupo-sum_of_floor_of_linear.test.cpp\"\
    \n\nint main() {\n    int t;\n    std::cin >> t;\n\n    while(t--) {\n       \
    \ int n, m, a, b;\n        std::cin >> n >> m >> a >> b;\n\n        std::cout\
    \ << algorithm::floor_sum(n, m, a, b) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <iostream>\n\n#include \"../src/Math/NumberTheory/floor_sum.hpp\"\
    \n\nint main() {\n    int t;\n    std::cin >> t;\n\n    while(t--) {\n       \
    \ int n, m, a, b;\n        std::cin >> n >> m >> a >> b;\n\n        std::cout\
    \ << algorithm::floor_sum(n, m, a, b) << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/Math/NumberTheory/floor_sum.hpp
  isVerificationFile: true
  path: test/yosupo-sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2023-09-25 15:34:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-sum_of_floor_of_linear.test.cpp
- /verify/test/yosupo-sum_of_floor_of_linear.test.cpp.html
title: test/yosupo-sum_of_floor_of_linear.test.cpp
---
