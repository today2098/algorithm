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
  bundledCode: "#line 1 \"src/Math/Combinatorics/montmort.hpp\"\n\n#define ALGORTIHM_MONTMORT_HPP\
    \ 1\n\n#include <cassert>\n#include <cmath>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// \u5B8C\u5168\u9806\u5217\uFF08mod\u4ED8\u304D\uFF09\uFF0E\ntemplate\
    \ <int mod>\nclass Montmort {\n    int m_sz;\n    std::vector<long long> m_montmort;\
    \  // m_montmort[k]:=(k\u756A\u76EE\u306E\u30E2\u30F3\u30E2\u30FC\u30EB\u6570\
    ).\n\npublic:\n    Montmort() : Montmort(51e4) {}\n    explicit Montmort(size_t\
    \ sz) : m_sz(sz), m_montmort(sz) {\n        static_assert(mod >= 1);\n       \
    \ assert(m_sz >= 2);\n        m_montmort[0] = 1, m_montmort[1] = 0;\n        for(int\
    \ i = 2; i < m_sz; ++i) m_montmort[i] = (i - 1) * ((m_montmort[i - 2] + m_montmort[i\
    \ - 1]) % mod) % mod;  // \u96A3\u63A5\u4E09\u9805\u9593\u306E\u6F38\u5316\u5F0F\
    \uFF0E\n        // for(int i = 2; i < m_sz; ++i) m_montmort[i] = (i * m_montmort[i\
    \ - 1] % mod + (i & 1 ? -1 : 1) + mod) % mod;  // \u96A3\u63A5\u4E8C\u9805\u9593\
    \u306E\u6F38\u5316\u5F0F\uFF0E\n    }\n\n    static constexpr int modulus() {\
    \ return mod; }\n    // k\u500B\u306E\u8981\u7D20\u3092\u4E26\u3073\u66FF\u3048\
    \u305F\u3068\u304D\u306B\u5B8C\u5168\u9806\u5217\u3068\u306A\u308B\u901A\u308A\
    \u6570\uFF0E\n    long long montmort(int k) const {\n        assert(1 <= k and\
    \ k < m_sz);\n        return m_montmort[k];\n    }\n    // \u7121\u9650\u500B\u306E\
    \u8981\u7D20\u3092\u4E26\u3073\u66FF\u3048\u305F\u3068\u304D\u306B\u5B8C\u5168\
    \u9806\u5217\u3068\u306A\u308B\u78BA\u7387\uFF0E\n    static constexpr double\
    \ converged_probability() { return 1.0 / std::exp(1.0); }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  code: "#ifndef ALGORITHM_MONTMORT_HPP\n#define ALGORTIHM_MONTMORT_HPP 1\n\n#include\
    \ <cassert>\n#include <cmath>\n#include <vector>\n\nnamespace algorithm {\n\n\
    // \u5B8C\u5168\u9806\u5217\uFF08mod\u4ED8\u304D\uFF09\uFF0E\ntemplate <int mod>\n\
    class Montmort {\n    int m_sz;\n    std::vector<long long> m_montmort;  // m_montmort[k]:=(k\u756A\
    \u76EE\u306E\u30E2\u30F3\u30E2\u30FC\u30EB\u6570).\n\npublic:\n    Montmort()\
    \ : Montmort(51e4) {}\n    explicit Montmort(size_t sz) : m_sz(sz), m_montmort(sz)\
    \ {\n        static_assert(mod >= 1);\n        assert(m_sz >= 2);\n        m_montmort[0]\
    \ = 1, m_montmort[1] = 0;\n        for(int i = 2; i < m_sz; ++i) m_montmort[i]\
    \ = (i - 1) * ((m_montmort[i - 2] + m_montmort[i - 1]) % mod) % mod;  // \u96A3\
    \u63A5\u4E09\u9805\u9593\u306E\u6F38\u5316\u5F0F\uFF0E\n        // for(int i =\
    \ 2; i < m_sz; ++i) m_montmort[i] = (i * m_montmort[i - 1] % mod + (i & 1 ? -1\
    \ : 1) + mod) % mod;  // \u96A3\u63A5\u4E8C\u9805\u9593\u306E\u6F38\u5316\u5F0F\
    \uFF0E\n    }\n\n    static constexpr int modulus() { return mod; }\n    // k\u500B\
    \u306E\u8981\u7D20\u3092\u4E26\u3073\u66FF\u3048\u305F\u3068\u304D\u306B\u5B8C\
    \u5168\u9806\u5217\u3068\u306A\u308B\u901A\u308A\u6570\uFF0E\n    long long montmort(int\
    \ k) const {\n        assert(1 <= k and k < m_sz);\n        return m_montmort[k];\n\
    \    }\n    // \u7121\u9650\u500B\u306E\u8981\u7D20\u3092\u4E26\u3073\u66FF\u3048\
    \u305F\u3068\u304D\u306B\u5B8C\u5168\u9806\u5217\u3068\u306A\u308B\u78BA\u7387\
    \uFF0E\n    static constexpr double converged_probability() { return 1.0 / std::exp(1.0);\
    \ }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Combinatorics/montmort.hpp
  requiredBy: []
  timestamp: '2023-08-30 11:28:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/Combinatorics/montmort.hpp
layout: document
redirect_from:
- /library/src/Math/Combinatorics/montmort.hpp
- /library/src/Math/Combinatorics/montmort.hpp.html
title: src/Math/Combinatorics/montmort.hpp
---