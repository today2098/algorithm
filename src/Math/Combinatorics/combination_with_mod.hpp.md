---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/Combinatorics/combination_with_mod.md
    document_title: "\u7D44\u5408\u305B\uFF08mod\u4ED8\u304D\uFF09"
    links: []
  bundledCode: "#line 1 \"src/Math/Combinatorics/combination_with_mod.hpp\"\n\n\n\n\
    /**\n * @brief \u7D44\u5408\u305B\uFF08mod\u4ED8\u304D\uFF09\n * @docs docs/Math/Combinatorics/combination_with_mod.md\n\
    \ */\n\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u7D44\
    \u5408\u305B\uFF08mod\u4ED8\u304D\uFF09\uFF0E\ntemplate <int mod>\nclass Combination\
    \ {\n    int m_mx;                       // m_mx:=(\u5F15\u6570n\u306E\u6700\u5927\
    \u5024). \u5236\u7D04\u306F m_mx<mod\uFF0E\n    std::vector<long long> m_fact;\
    \  // m_fact[n]:=(n\u306E\u968E\u4E57).\n    std::vector<long long> m_inv;   //\
    \ m_inv[n]:=(n\u306E\u9006\u5143).\n    std::vector<long long> m_finv;  // m_finv[n]:=(n\u306E\
    \u968E\u4E57\u306E\u9006\u5143).\n\npublic:\n    // constructor. O(N).\n    Combination()\
    \ : Combination(51e4) {}\n    explicit Combination(int mx) : m_mx(mx), m_fact(mx\
    \ + 1), m_inv(mx + 1), m_finv(mx + 1) {\n        static_assert(mod >= 1);\n  \
    \      assert(1 <= m_mx and m_mx < mod);\n        m_fact[0] = m_fact[1] = 1;\n\
    \        m_inv[1] = 1;\n        m_finv[0] = m_finv[1] = 1;\n        for(int n\
    \ = 2; n <= m_mx; ++n) {\n            m_fact[n] = m_fact[n - 1] * n % mod;\n \
    \           m_inv[n] = mod - m_inv[mod % n] * (mod / n) % mod;\n            m_finv[n]\
    \ = m_finv[n - 1] * m_inv[n] % mod;\n        }\n    }\n\n    static constexpr\
    \ int modulus() { return mod; }\n    // \u968E\u4E57\uFF0EO(1).\n    long long\
    \ factorial(int n) const {\n        assert(0 <= n and n <= m_mx);\n        return\
    \ m_fact[n];\n    }\n    // \u9006\u5143\uFF0EO(1).\n    long long inverse(int\
    \ n) const {\n        assert(1 <= n and n <= m_mx);\n        return m_inv[n];\n\
    \    }\n    // \u968E\u4E57\u306E\u9006\u5143\uFF0EO(1).\n    long long inverse_fact(int\
    \ n) const {\n        assert(0 <= n and n <= m_mx);\n        return m_finv[n];\n\
    \    }\n    // \u9806\u5217\uFF0EO(1).\n    long long nPk(int n, int k) const\
    \ {\n        assert(0 <= k and k <= n and n <= m_mx);\n        return m_fact[n]\
    \ * m_finv[n - k] % mod;\n    }\n    // \u7D44\u5408\u305B\uFF0EO(1).\n    long\
    \ long nCk(int n, int k) const {\n        assert(0 <= k and k <= n and n <= m_mx);\n\
    \        return m_fact[n] * m_finv[n - k] % mod * m_finv[k] % mod;\n    }\n  \
    \  // \u7D44\u5408\u305B\uFF0EO(K).\n    long long big_nCk(long long n, int k)\
    \ const {\n        assert(0 <= k and k <= m_mx and k <= n);\n        long long\
    \ res = 1;\n        for(int i = 0; i < k; ++i) res = res * ((n - i) % mod) % mod;\n\
    \        res = res * m_finv[k] % mod;\n        return res;\n    }\n    // \u91CD\
    \u8907\u7D44\u5408\u305B\uFF0EO(1).\n    long long nHk(int n, int k) const { return\
    \ nCk(k + n - 1, n - 1); }\n};\n\nusing Combination998244353 = Combination<998'244'353>;\n\
    using Combination1000000007 = Combination<1'000'000'007>;\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_COMBINATION_WITH_MOD_HPP\n#define ALGORITHM_COMBINATION_WITH_MOD_HPP\
    \ 1\n\n/**\n * @brief \u7D44\u5408\u305B\uFF08mod\u4ED8\u304D\uFF09\n * @docs\
    \ docs/Math/Combinatorics/combination_with_mod.md\n */\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u7D44\u5408\u305B\uFF08mod\u4ED8\
    \u304D\uFF09\uFF0E\ntemplate <int mod>\nclass Combination {\n    int m_mx;   \
    \                    // m_mx:=(\u5F15\u6570n\u306E\u6700\u5927\u5024). \u5236\u7D04\
    \u306F m_mx<mod\uFF0E\n    std::vector<long long> m_fact;  // m_fact[n]:=(n\u306E\
    \u968E\u4E57).\n    std::vector<long long> m_inv;   // m_inv[n]:=(n\u306E\u9006\
    \u5143).\n    std::vector<long long> m_finv;  // m_finv[n]:=(n\u306E\u968E\u4E57\
    \u306E\u9006\u5143).\n\npublic:\n    // constructor. O(N).\n    Combination()\
    \ : Combination(51e4) {}\n    explicit Combination(int mx) : m_mx(mx), m_fact(mx\
    \ + 1), m_inv(mx + 1), m_finv(mx + 1) {\n        static_assert(mod >= 1);\n  \
    \      assert(1 <= m_mx and m_mx < mod);\n        m_fact[0] = m_fact[1] = 1;\n\
    \        m_inv[1] = 1;\n        m_finv[0] = m_finv[1] = 1;\n        for(int n\
    \ = 2; n <= m_mx; ++n) {\n            m_fact[n] = m_fact[n - 1] * n % mod;\n \
    \           m_inv[n] = mod - m_inv[mod % n] * (mod / n) % mod;\n            m_finv[n]\
    \ = m_finv[n - 1] * m_inv[n] % mod;\n        }\n    }\n\n    static constexpr\
    \ int modulus() { return mod; }\n    // \u968E\u4E57\uFF0EO(1).\n    long long\
    \ factorial(int n) const {\n        assert(0 <= n and n <= m_mx);\n        return\
    \ m_fact[n];\n    }\n    // \u9006\u5143\uFF0EO(1).\n    long long inverse(int\
    \ n) const {\n        assert(1 <= n and n <= m_mx);\n        return m_inv[n];\n\
    \    }\n    // \u968E\u4E57\u306E\u9006\u5143\uFF0EO(1).\n    long long inverse_fact(int\
    \ n) const {\n        assert(0 <= n and n <= m_mx);\n        return m_finv[n];\n\
    \    }\n    // \u9806\u5217\uFF0EO(1).\n    long long nPk(int n, int k) const\
    \ {\n        assert(0 <= k and k <= n and n <= m_mx);\n        return m_fact[n]\
    \ * m_finv[n - k] % mod;\n    }\n    // \u7D44\u5408\u305B\uFF0EO(1).\n    long\
    \ long nCk(int n, int k) const {\n        assert(0 <= k and k <= n and n <= m_mx);\n\
    \        return m_fact[n] * m_finv[n - k] % mod * m_finv[k] % mod;\n    }\n  \
    \  // \u7D44\u5408\u305B\uFF0EO(K).\n    long long big_nCk(long long n, int k)\
    \ const {\n        assert(0 <= k and k <= m_mx and k <= n);\n        long long\
    \ res = 1;\n        for(int i = 0; i < k; ++i) res = res * ((n - i) % mod) % mod;\n\
    \        res = res * m_finv[k] % mod;\n        return res;\n    }\n    // \u91CD\
    \u8907\u7D44\u5408\u305B\uFF0EO(1).\n    long long nHk(int n, int k) const { return\
    \ nCk(k + n - 1, n - 1); }\n};\n\nusing Combination998244353 = Combination<998'244'353>;\n\
    using Combination1000000007 = Combination<1'000'000'007>;\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Combinatorics/combination_with_mod.hpp
  requiredBy: []
  timestamp: '2024-05-30 00:04:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/Combinatorics/combination_with_mod.hpp
layout: document
redirect_from:
- /library/src/Math/Combinatorics/combination_with_mod.hpp
- /library/src/Math/Combinatorics/combination_with_mod.hpp.html
title: "\u7D44\u5408\u305B\uFF08mod\u4ED8\u304D\uFF09"
---
