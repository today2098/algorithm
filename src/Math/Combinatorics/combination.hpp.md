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
  bundledCode: "#line 1 \"src/Math/Combinatorics/combination.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u4E8C\u9805\u4FC2\
    \u6570\uFF08mod\u4ED8\u304D\uFF09\uFF0E\ntemplate <int mod>\nclass Combination\
    \ {\n    int m_sz;                       // m_sz:=(\u8981\u7D20\u6570). \u5236\
    \u7D04\u306F m_sz<=mod\uFF0E\n    std::vector<long long> m_fact;  // m_fact[n]:=(n\u306E\
    \u968E\u4E57).\n    std::vector<long long> m_inv;   // m_inv[n]:=(n\u306E\u9006\
    \u5143).\n    std::vector<long long> m_finv;  // m_finv[n]:=(n\u306E\u968E\u4E57\
    \u306E\u9006\u5143).\n\npublic:\n    // constructor. O(N).\n    Combination()\
    \ : Combination(51e4) {}\n    explicit Combination(size_t sz) : m_sz(sz), m_fact(sz),\
    \ m_inv(sz), m_finv(sz) {\n        static_assert(mod >= 1);\n        assert(2\
    \ <= m_sz and m_sz <= mod);\n        m_fact[0] = m_fact[1] = 1;\n        m_inv[1]\
    \ = 1;\n        m_finv[0] = m_finv[1] = 1;\n        for(int n = 2; n < m_sz; ++n)\
    \ {\n            m_fact[n] = m_fact[n - 1] * n % mod;\n            m_inv[n] =\
    \ mod - m_inv[mod % n] * (mod / n) % mod;\n            m_finv[n] = m_finv[n -\
    \ 1] * m_inv[n] % mod;\n        }\n    }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    // \u968E\u4E57\uFF0E\n    long long factorial(int n) const\
    \ {\n        assert(0 <= n and n < m_sz);\n        return m_fact[n];\n    }\n\
    \    // \u9006\u5143\uFF0E\n    long long inverse(int n) const {\n        assert(1\
    \ <= n and n < m_sz);\n        return m_inv[n];\n    }\n    // \u968E\u4E57\u306E\
    \u9006\u5143\uFF0E\n    long long inverse_fact(int n) const {\n        assert(0\
    \ <= n and n < m_sz);\n        return m_finv[n];\n    }\n    // \u9806\u5217\uFF0E\
    \n    long long nPk(int n, int k) const {\n        assert(0 <= k and k <= n and\
    \ n < m_sz);\n        return m_fact[n] * m_finv[n - k] % mod;\n    }\n    // \u7D44\
    \u5408\u305B\uFF0E\n    long long nCk(int n, int k) const {\n        assert(0\
    \ <= k and k <= n and n < m_sz);\n        return m_fact[n] * m_finv[n - k] % mod\
    \ * m_finv[k] % mod;\n    }\n    // \u91CD\u8907\u7D44\u5408\u305B\uFF0E\n   \
    \ long long nHk(int n, int k) const { return nCk(k + n - 1, n - 1); }\n};\n\n\
    using Combination998244353 = Combination<998'244'353>;\nusing Combination1000000007\
    \ = Combination<1'000'000'007>;\n\n// \u9806\u5217\uFF0E\ninline long long nPk(long\
    \ long n, int k) {\n    assert(0 <= k and k <= n);\n    long long res = 1;\n \
    \   for(int i = 0; i < k; ++i) res = res * (n - i);\n    return res;\n}\n\n//\
    \ \u7D44\u5408\u305B\uFF0E\ninline long long nCk(long long n, int k) {\n    assert(0\
    \ <= k and k <= n);\n    long long res = 1;\n    for(int i = 0; i < k; ++i) res\
    \ = res * (n - i) / (i + 1);\n    return res;\n}\n\n// \u91CD\u8907\u7D44\u5408\
    \u305B\uFF0E\ninline long long nHk(int n, long long k) { return nCk(k + n - 1,\
    \ n - 1); }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_COMBINATION_HPP\n#define ALGORITHM_COMBINATION_HPP 1\n\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u4E8C\u9805\
    \u4FC2\u6570\uFF08mod\u4ED8\u304D\uFF09\uFF0E\ntemplate <int mod>\nclass Combination\
    \ {\n    int m_sz;                       // m_sz:=(\u8981\u7D20\u6570). \u5236\
    \u7D04\u306F m_sz<=mod\uFF0E\n    std::vector<long long> m_fact;  // m_fact[n]:=(n\u306E\
    \u968E\u4E57).\n    std::vector<long long> m_inv;   // m_inv[n]:=(n\u306E\u9006\
    \u5143).\n    std::vector<long long> m_finv;  // m_finv[n]:=(n\u306E\u968E\u4E57\
    \u306E\u9006\u5143).\n\npublic:\n    // constructor. O(N).\n    Combination()\
    \ : Combination(51e4) {}\n    explicit Combination(size_t sz) : m_sz(sz), m_fact(sz),\
    \ m_inv(sz), m_finv(sz) {\n        static_assert(mod >= 1);\n        assert(2\
    \ <= m_sz and m_sz <= mod);\n        m_fact[0] = m_fact[1] = 1;\n        m_inv[1]\
    \ = 1;\n        m_finv[0] = m_finv[1] = 1;\n        for(int n = 2; n < m_sz; ++n)\
    \ {\n            m_fact[n] = m_fact[n - 1] * n % mod;\n            m_inv[n] =\
    \ mod - m_inv[mod % n] * (mod / n) % mod;\n            m_finv[n] = m_finv[n -\
    \ 1] * m_inv[n] % mod;\n        }\n    }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    // \u968E\u4E57\uFF0E\n    long long factorial(int n) const\
    \ {\n        assert(0 <= n and n < m_sz);\n        return m_fact[n];\n    }\n\
    \    // \u9006\u5143\uFF0E\n    long long inverse(int n) const {\n        assert(1\
    \ <= n and n < m_sz);\n        return m_inv[n];\n    }\n    // \u968E\u4E57\u306E\
    \u9006\u5143\uFF0E\n    long long inverse_fact(int n) const {\n        assert(0\
    \ <= n and n < m_sz);\n        return m_finv[n];\n    }\n    // \u9806\u5217\uFF0E\
    \n    long long nPk(int n, int k) const {\n        assert(0 <= k and k <= n and\
    \ n < m_sz);\n        return m_fact[n] * m_finv[n - k] % mod;\n    }\n    // \u7D44\
    \u5408\u305B\uFF0E\n    long long nCk(int n, int k) const {\n        assert(0\
    \ <= k and k <= n and n < m_sz);\n        return m_fact[n] * m_finv[n - k] % mod\
    \ * m_finv[k] % mod;\n    }\n    // \u91CD\u8907\u7D44\u5408\u305B\uFF0E\n   \
    \ long long nHk(int n, int k) const { return nCk(k + n - 1, n - 1); }\n};\n\n\
    using Combination998244353 = Combination<998'244'353>;\nusing Combination1000000007\
    \ = Combination<1'000'000'007>;\n\n// \u9806\u5217\uFF0E\ninline long long nPk(long\
    \ long n, int k) {\n    assert(0 <= k and k <= n);\n    long long res = 1;\n \
    \   for(int i = 0; i < k; ++i) res = res * (n - i);\n    return res;\n}\n\n//\
    \ \u7D44\u5408\u305B\uFF0E\ninline long long nCk(long long n, int k) {\n    assert(0\
    \ <= k and k <= n);\n    long long res = 1;\n    for(int i = 0; i < k; ++i) res\
    \ = res * (n - i) / (i + 1);\n    return res;\n}\n\n// \u91CD\u8907\u7D44\u5408\
    \u305B\uFF0E\ninline long long nHk(int n, long long k) { return nCk(k + n - 1,\
    \ n - 1); }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Combinatorics/combination.hpp
  requiredBy: []
  timestamp: '2023-08-30 11:28:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/Combinatorics/combination.hpp
layout: document
redirect_from:
- /library/src/Math/Combinatorics/combination.hpp
- /library/src/Math/Combinatorics/combination.hpp.html
title: src/Math/Combinatorics/combination.hpp
---
