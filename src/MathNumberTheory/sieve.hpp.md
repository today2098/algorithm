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
    - "https://qiita.com/drken/items/3beb679e54266f20ab63\uFF08\u53C2\u71672023.6.8\uFF09\
      ."
  bundledCode: "#line 1 \"src/MathNumberTheory/sieve.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <map>\n#include <numeric>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\
    \u30B9\u306E\u7BE9\uFF0E\nclass Sieve {\n    int m_mx;                // m_mx:=(\u7BE9\
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
    \ res({1});\n        const auto &&pf = prime_factorize(n);\n        for(const\
    \ auto &[p, cnt] : pf) {\n            const int sz = res.size();\n           \
    \ int b = 1;\n            for(int i = 0; i < cnt; ++i) {\n                b *=\
    \ p;\n                for(int j = 0; j < sz; ++j) res.push_back(res[j] * b);\n\
    \            }\n        }\n        std::sort(res.begin(), res.end());\n      \
    \  return res;\n    }\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\
    \u95A2\u6570\uFF0En\u4EE5\u4E0B\u3067n\u3068\u4E92\u3044\u306B\u7D20\u306A\u81EA\
    \u7136\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\uFF0E\n    int totient(int\
    \ n) const {\n        assert(1 <= n and n <= m_mx);\n        const auto &&pf =\
    \ prime_factorize(n);\n        int res = 1;\n        for(const auto &[p, cnt]\
    \ : pf) res *= std::pow(p, cnt - 1) * (p - 1);\n        return res;\n    }\n \
    \   // \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\uFF0EO(N*loglogN).\n    std::vector<int>\
    \ mebius() const {\n        std::vector<int> res(m_mx + 1, 1);  // res[i]:=\u03BC\
    (i).\n        for(int p = 2; p <= m_mx; ++p) {\n            if(m_lpf[p] != p)\
    \ continue;\n            res[p] = -1;\n            for(int q = 2 * p; q <= m_mx;\
    \ q += p) {\n                if((q / p) % p == 0) res[q] = 0;\n              \
    \  else res[q] = -res[q];\n            }\n        }\n        return res;\n   \
    \ }\n};\n\n}  // namespace algorithm\n\n\n\n/*\n\u53C2\u8003\u6587\u732E\n- drken,\
    \ \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306E\u6D3B\u7528\u6CD5\
    \u3092\u7DCF\u7279\u96C6\uFF01 \u301C \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\
    \u30FB\u30E1\u30D3\u30A6\u30B9\u306E\u53CD\u8EE2\u516C\u5F0F \u301C, Qiita, https://qiita.com/drken/items/3beb679e54266f20ab63\uFF08\
    \u53C2\u71672023.6.8\uFF09.\n*/\n"
  code: "#ifndef ALGORITHM_SIEVE_HPP\n#define ALGORITHM_SIEVE_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <map>\n#include <numeric>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\
    \u30B9\u306E\u7BE9\uFF0E\nclass Sieve {\n    int m_mx;                // m_mx:=(\u7BE9\
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
    \ res({1});\n        const auto &&pf = prime_factorize(n);\n        for(const\
    \ auto &[p, cnt] : pf) {\n            const int sz = res.size();\n           \
    \ int b = 1;\n            for(int i = 0; i < cnt; ++i) {\n                b *=\
    \ p;\n                for(int j = 0; j < sz; ++j) res.push_back(res[j] * b);\n\
    \            }\n        }\n        std::sort(res.begin(), res.end());\n      \
    \  return res;\n    }\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\
    \u95A2\u6570\uFF0En\u4EE5\u4E0B\u3067n\u3068\u4E92\u3044\u306B\u7D20\u306A\u81EA\
    \u7136\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\uFF0E\n    int totient(int\
    \ n) const {\n        assert(1 <= n and n <= m_mx);\n        const auto &&pf =\
    \ prime_factorize(n);\n        int res = 1;\n        for(const auto &[p, cnt]\
    \ : pf) res *= std::pow(p, cnt - 1) * (p - 1);\n        return res;\n    }\n \
    \   // \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\uFF0EO(N*loglogN).\n    std::vector<int>\
    \ mebius() const {\n        std::vector<int> res(m_mx + 1, 1);  // res[i]:=\u03BC\
    (i).\n        for(int p = 2; p <= m_mx; ++p) {\n            if(m_lpf[p] != p)\
    \ continue;\n            res[p] = -1;\n            for(int q = 2 * p; q <= m_mx;\
    \ q += p) {\n                if((q / p) % p == 0) res[q] = 0;\n              \
    \  else res[q] = -res[q];\n            }\n        }\n        return res;\n   \
    \ }\n};\n\n}  // namespace algorithm\n\n#endif\n\n/*\n\u53C2\u8003\u6587\u732E\
    \n- drken, \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306E\u6D3B\u7528\
    \u6CD5\u3092\u7DCF\u7279\u96C6\uFF01 \u301C \u9AD8\u901F\u7D20\u56E0\u6570\u5206\
    \u89E3\u30FB\u30E1\u30D3\u30A6\u30B9\u306E\u53CD\u8EE2\u516C\u5F0F \u301C, Qiita,\
    \ https://qiita.com/drken/items/3beb679e54266f20ab63\uFF08\u53C2\u71672023.6.8\uFF09\
    .\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/MathNumberTheory/sieve.hpp
  requiredBy: []
  timestamp: '2023-06-08 14:17:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/MathNumberTheory/sieve.hpp
layout: document
redirect_from:
- /library/src/MathNumberTheory/sieve.hpp
- /library/src/MathNumberTheory/sieve.hpp.html
title: src/MathNumberTheory/sieve.hpp
---
