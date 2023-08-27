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
    - "https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\uFF08\u53C2\u7167"
  bundledCode: "#line 1 \"src/MathNumberTheory/segment_sieve.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cmath>\n#include <map>\n#include\
    \ <numeric>\n#include <vector>\n\nnamespace algorithm {\n\n// \u533A\u9593\u7BE9\
    \uFF0E\nclass SegmentSieve {\n    long long l, r;\n    long long sr;         \
    \                         // sr:=\u221Ar.\n    std::vector<long long> small; \
    \                 // small[n]:=(\u533A\u9593[2,\u221Ar)\u306E\u81EA\u7136\u6570\
    n\u306E\u6700\u5C0F\u306E\u7D20\u56E0\u6570).\n    std::vector<std::map<long long,\
    \ int> > large;  // large[n-l][]:=(\u533A\u9593[l,r)\u306E\u81EA\u7136\u6570n\u306E\
    \u533A\u9593[2,\u221Ar)\u306B\u304A\u3051\u308B\u3044\u304F\u3064\u304B\u306E\u7D20\
    \u56E0\u6570).\n    std::vector<long long> aux;                    // aux[n-l]:=(large[n-l][]\u306E\
    \u7A4D).\n\n    void build() {\n        sr = std::sqrt(r) + 5;\n        small.assign(sr,\
    \ -1);\n        std::iota(small.begin() + 2, small.end(), 2);\n        large.resize(r\
    \ - l);\n        aux.assign(r - l, 1);\n        for(long long p = 2; p * p < r;\
    \ ++p) {\n            if(small[p] == p) {\n                for(long long n = p\
    \ * p; n < sr; n += p) small[n] = p;\n                for(long long n = std::max<long\
    \ long>(2, (l + p - 1) / p) * p; n < r; n += p) {\n                    long long\
    \ tmp = n;\n                    while(tmp % p == 0 and aux[n - l] * aux[n - l]\
    \ <= r) {\n                        large[n - l][p]++;\n                      \
    \  aux[n - l] *= p;\n                        tmp /= p;\n                    }\n\
    \                }\n            }\n        }\n    }\n\npublic:\n    // constructor.\
    \ \u533A\u9593[l,r)\u306E\u81EA\u7136\u6570\u3092\u7BE9\u306B\u304B\u3051\u308B\
    \uFF0E\u5236\u7D04\u306E\u76EE\u5B89\u306F\u304A\u304A\u3088\u305D 2<=l<r<=1e12,\
    \ r-l<=1e6\uFF0E\n    SegmentSieve() : SegmentSieve(2, 3) {}\n    explicit SegmentSieve(long\
    \ long l_, long long r_) : l(l_), r(r_) {\n        assert(2 <= l and l < r);\n\
    \        build();\n    }\n\n    // \u7D20\u6570\u5224\u5B9A\uFF0EO(1).\n    bool\
    \ is_prime(long long n) const {\n        assert(l <= n and n < r);\n        return\
    \ large[n - l].size() == 0;\n    }\n    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\
    \u89E3\uFF0E\n    std::map<long long, int> prime_factorize(long long n) const\
    \ {\n        assert(l <= n and n < r);\n        auto res = large[n - l];\n   \
    \     n /= aux[n - l];\n        if(n >= sr) {\n            res[n]++;\n       \
    \     return res;\n        }\n        while(n > 1) {\n            res[small[n]]++;\n\
    \            n /= small[n];\n        }\n        return res;\n    }\n    // \u9AD8\
    \u901F\u7D04\u6570\u5217\u6319\uFF0E\n    std::vector<long long> divisors(long\
    \ long n) const {\n        assert(l <= n and n < r);\n        std::vector<long\
    \ long> res({1});\n        const auto &&pf = prime_factorize(n);\n        int\
    \ capacity = 1;\n        for(const auto &[_, cnt] : pf) capacity *= (cnt + 1);\n\
    \        res.reserve(capacity);\n        for(const auto &[p, cnt] : pf) {\n  \
    \          const int sz = res.size();\n            long long b = 1;\n        \
    \    for(int i = 0; i < cnt; ++i) {\n                b *= p;\n               \
    \ for(int j = 0; j < sz; ++j) res.push_back(res[j] * b);\n            }\n    \
    \    }\n        std::sort(res.begin(), res.end());\n        return res;\n    }\n\
    };\n\n}  // namespace algorithm\n\n\n\n/*\n\u53C2\u8003\u6587\u732E\n- rsk0315_h4x\uFF0C\
    \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306B\u57FA\u3065\u304F\
    \u9AD8\u901F\u306A\u7D20\u56E0\u6570\u5206\u89E3\uFF0CQiita\uFF0Chttps://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\uFF08\
    \u53C2\u7167 2022.9.10\uFF09\uFF0E\n*/\n"
  code: "#ifndef ALGORITHM_SEGMENT_SIEVE_HPP\n#define ALGORITHM_SEGMENT_SIEVE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <map>\n\
    #include <numeric>\n#include <vector>\n\nnamespace algorithm {\n\n// \u533A\u9593\
    \u7BE9\uFF0E\nclass SegmentSieve {\n    long long l, r;\n    long long sr;   \
    \                               // sr:=\u221Ar.\n    std::vector<long long> small;\
    \                  // small[n]:=(\u533A\u9593[2,\u221Ar)\u306E\u81EA\u7136\u6570\
    n\u306E\u6700\u5C0F\u306E\u7D20\u56E0\u6570).\n    std::vector<std::map<long long,\
    \ int> > large;  // large[n-l][]:=(\u533A\u9593[l,r)\u306E\u81EA\u7136\u6570n\u306E\
    \u533A\u9593[2,\u221Ar)\u306B\u304A\u3051\u308B\u3044\u304F\u3064\u304B\u306E\u7D20\
    \u56E0\u6570).\n    std::vector<long long> aux;                    // aux[n-l]:=(large[n-l][]\u306E\
    \u7A4D).\n\n    void build() {\n        sr = std::sqrt(r) + 5;\n        small.assign(sr,\
    \ -1);\n        std::iota(small.begin() + 2, small.end(), 2);\n        large.resize(r\
    \ - l);\n        aux.assign(r - l, 1);\n        for(long long p = 2; p * p < r;\
    \ ++p) {\n            if(small[p] == p) {\n                for(long long n = p\
    \ * p; n < sr; n += p) small[n] = p;\n                for(long long n = std::max<long\
    \ long>(2, (l + p - 1) / p) * p; n < r; n += p) {\n                    long long\
    \ tmp = n;\n                    while(tmp % p == 0 and aux[n - l] * aux[n - l]\
    \ <= r) {\n                        large[n - l][p]++;\n                      \
    \  aux[n - l] *= p;\n                        tmp /= p;\n                    }\n\
    \                }\n            }\n        }\n    }\n\npublic:\n    // constructor.\
    \ \u533A\u9593[l,r)\u306E\u81EA\u7136\u6570\u3092\u7BE9\u306B\u304B\u3051\u308B\
    \uFF0E\u5236\u7D04\u306E\u76EE\u5B89\u306F\u304A\u304A\u3088\u305D 2<=l<r<=1e12,\
    \ r-l<=1e6\uFF0E\n    SegmentSieve() : SegmentSieve(2, 3) {}\n    explicit SegmentSieve(long\
    \ long l_, long long r_) : l(l_), r(r_) {\n        assert(2 <= l and l < r);\n\
    \        build();\n    }\n\n    // \u7D20\u6570\u5224\u5B9A\uFF0EO(1).\n    bool\
    \ is_prime(long long n) const {\n        assert(l <= n and n < r);\n        return\
    \ large[n - l].size() == 0;\n    }\n    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\
    \u89E3\uFF0E\n    std::map<long long, int> prime_factorize(long long n) const\
    \ {\n        assert(l <= n and n < r);\n        auto res = large[n - l];\n   \
    \     n /= aux[n - l];\n        if(n >= sr) {\n            res[n]++;\n       \
    \     return res;\n        }\n        while(n > 1) {\n            res[small[n]]++;\n\
    \            n /= small[n];\n        }\n        return res;\n    }\n    // \u9AD8\
    \u901F\u7D04\u6570\u5217\u6319\uFF0E\n    std::vector<long long> divisors(long\
    \ long n) const {\n        assert(l <= n and n < r);\n        std::vector<long\
    \ long> res({1});\n        const auto &&pf = prime_factorize(n);\n        int\
    \ capacity = 1;\n        for(const auto &[_, cnt] : pf) capacity *= (cnt + 1);\n\
    \        res.reserve(capacity);\n        for(const auto &[p, cnt] : pf) {\n  \
    \          const int sz = res.size();\n            long long b = 1;\n        \
    \    for(int i = 0; i < cnt; ++i) {\n                b *= p;\n               \
    \ for(int j = 0; j < sz; ++j) res.push_back(res[j] * b);\n            }\n    \
    \    }\n        std::sort(res.begin(), res.end());\n        return res;\n    }\n\
    };\n\n}  // namespace algorithm\n\n#endif\n\n/*\n\u53C2\u8003\u6587\u732E\n- rsk0315_h4x\uFF0C\
    \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306B\u57FA\u3065\u304F\
    \u9AD8\u901F\u306A\u7D20\u56E0\u6570\u5206\u89E3\uFF0CQiita\uFF0Chttps://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\uFF08\
    \u53C2\u7167 2022.9.10\uFF09\uFF0E\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/MathNumberTheory/segment_sieve.hpp
  requiredBy: []
  timestamp: '2023-04-05 18:41:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/MathNumberTheory/segment_sieve.hpp
layout: document
redirect_from:
- /library/src/MathNumberTheory/segment_sieve.hpp
- /library/src/MathNumberTheory/segment_sieve.hpp.html
title: src/MathNumberTheory/segment_sieve.hpp
---
