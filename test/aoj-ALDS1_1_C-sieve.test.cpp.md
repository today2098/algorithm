---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/NumberTheory/sieve.hpp
    title: "Sieve of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
      \u7BE9\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj-ALDS1_1_C-sieve.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\n\n#include\
    \ <iostream>\n\n#line 1 \"src/Math/NumberTheory/sieve.hpp\"\n/**\n * @brief Sieve\
    \ of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\uFF09\
    \n * @docs docs/Math/NumberTheory/sieve.md\n */\n\n#ifndef ALGORITHM_SIEVE_HPP\n\
    #define ALGORITHM_SIEVE_HPP 1\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <cmath>\n#include <map>\n#include <numeric>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Sieve of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\
    \u30B9\u306E\u7BE9\uFF09.\nclass Sieve {\n    int m_mx;                // m_mx:=(\u7BE9\
    \u306B\u304B\u3051\u308B\u6700\u5927\u306E\u81EA\u7136\u6570).\n    std::vector<int>\
    \ m_lpf;  // m_lpf[n]:=(\u81EA\u7136\u6570n\u306E\u6700\u5C0F\u306E\u7D20\u56E0\
    \u6570). Least prime factor. m_lpf[n]==n \u306E\u3068\u304D\uFF0Cn\u306F\u7D20\
    \u6570\uFF0E\n\npublic:\n    // constructor. n\u4EE5\u4E0B\u306E\u81EA\u7136\u6570\
    \u3092\u7BE9\u306B\u304B\u3051\u308B\uFF0EO(N*loglogN).\n    Sieve() : Sieve(51e4)\
    \ {}\n    explicit Sieve(int n) : m_mx(n), m_lpf(n + 1, -1) {\n        assert(n\
    \ >= 0);\n        std::iota(m_lpf.begin() + 2, m_lpf.end(), 2);\n        for(int\
    \ p = 2; p * p <= m_mx; ++p) {\n            if(m_lpf[p] != p) continue;\n    \
    \        for(int q = p * p; q <= m_mx; q += p) {\n                if(m_lpf[q]\
    \ == q) m_lpf[q] = p;\n            }\n        }\n    }\n\n    // \u7D20\u6570\u5224\
    \u5B9A\uFF0EO(1).\n    bool is_prime(int n) const {\n        assert(0 <= n and\
    \ n <= m_mx);\n        return m_lpf[n] == n;\n    }\n    // \u81EA\u7136\u6570\
    n\u306E\u6700\u5C0F\u306E\u7D20\u56E0\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n   \
    \ int lpf(int n) const {\n        assert(0 <= n and n <= m_mx);\n        return\
    \ m_lpf[n];\n    }\n    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(logN).\n\
    \    std::map<int, int> prime_factorize(int n) const {\n        assert(1 <= n\
    \ and n <= m_mx);\n        std::map<int, int> res;\n        while(n > 1) {\n \
    \           res[m_lpf[n]]++;\n            n /= m_lpf[n];\n        }\n        return\
    \ res;\n    }\n    // \u9AD8\u901F\u7D04\u6570\u5217\u6319\uFF0E\n    std::vector<int>\
    \ divisors(int n) const {\n        assert(1 <= n and n <= m_mx);\n        std::vector<int>\
    \ res({1});\n        const std::map<int, int> &&pf = prime_factorize(n);\n   \
    \     for(const auto &[p, cnt] : pf) {\n            const int sz = res.size();\n\
    \            int b = 1;\n            for(int i = 0; i < cnt; ++i) {\n        \
    \        b *= p;\n                for(int j = 0; j < sz; ++j) res.push_back(res[j]\
    \ * b);\n            }\n        }\n        std::sort(res.begin(), res.end());\n\
    \        return res;\n    }\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\
    \u30A4\u95A2\u6570\uFF0En\u4EE5\u4E0B\u3067n\u3068\u4E92\u3044\u306B\u7D20\u306A\
    \u81EA\u7136\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\uFF0E\n    int totient(int\
    \ n) const {\n        assert(1 <= n and n <= m_mx);\n        const std::map<int,\
    \ int> &&pf = prime_factorize(n);\n        int res = n;\n        for(const auto\
    \ &[p, cnt] : pf) res = res / p * (p - 1);\n        return res;\n    }\n    //\
    \ \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\uFF0EO(N*loglogN).\n    std::vector<int>\
    \ mobius() const {\n        std::vector<int> res(m_mx + 1, 1);  // res[n]:=\u03BC\
    (n).\n        for(int p = 2; p <= m_mx; ++p) {\n            if(m_lpf[p] != p)\
    \ continue;\n            res[p] = -1;\n            for(int q = 2 * p; q <= m_mx;\
    \ q += p) {\n                if((q / p) % p == 0) res[q] = 0;  // n\u304C\u3042\
    \u308B\u7D20\u6570p\u30672\u56DE\u4EE5\u4E0A\u5272\u308A\u5207\u308C\u308B\u3068\
    \u304D\uFF0C\u03BC(n)=0.\n                else res[q] = -res[q];            //\
    \ n\u304Ck\u500B\u306E\u76F8\u7570\u306A\u308B\u7D20\u56E0\u6570\u3067\u5206\u89E3\
    \u3067\u304D\u308B\u3068\u304D\uFF0C\u03BC(n)=(-1)^k.\n            }\n       \
    \ }\n        return res;\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n#line\
    \ 6 \"test/aoj-ALDS1_1_C-sieve.test.cpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n\n    algorithm::Sieve sieve((int)1e8);\n\n    int ans = 0;\n    for(int\
    \ i = 0; i < n; ++i) {\n        int a;\n        std::cin >> a;\n\n        if(sieve.is_prime(n))\
    \ ans++;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#include <iostream>\n\n#include \"../src/Math/NumberTheory/sieve.hpp\"\n\n\
    int main() {\n    int n;\n    std::cin >> n;\n\n    algorithm::Sieve sieve((int)1e8);\n\
    \n    int ans = 0;\n    for(int i = 0; i < n; ++i) {\n        int a;\n       \
    \ std::cin >> a;\n\n        if(sieve.is_prime(n)) ans++;\n    }\n\n    std::cout\
    \ << ans << std::endl;\n}\n"
  dependsOn:
  - src/Math/NumberTheory/sieve.hpp
  isVerificationFile: true
  path: test/aoj-ALDS1_1_C-sieve.test.cpp
  requiredBy: []
  timestamp: '2023-09-11 18:10:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj-ALDS1_1_C-sieve.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ALDS1_1_C-sieve.test.cpp
- /verify/test/aoj-ALDS1_1_C-sieve.test.cpp.html
title: test/aoj-ALDS1_1_C-sieve.test.cpp
---
