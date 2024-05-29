---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/Combinatorics/combination.md
    document_title: "\u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\
      \u305B"
    links: []
  bundledCode: "#line 1 \"src/Math/Combinatorics/combination.hpp\"\n\n\n\n/**\n *\
    \ @brief \u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\u305B\
    \n * @docs docs/Math/Combinatorics/combination.md\n */\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// \u9806\u5217\uFF0EO(K).\nlong long nPk(long long\
    \ n, int k) {\n    assert(0 <= k and k <= n);\n    long long res = 1;\n    for(int\
    \ i = 0; i < k; ++i) res = res * (n - i);\n    return res;\n}\n\n// \u7D44\u5408\
    \u305B\uFF0EO(K).\nlong long nCk(long long n, int k) {\n    assert(0 <= k and\
    \ k <= n);\n    long long res = 1;\n    for(int i = 0; i < k; ++i) res = res *\
    \ (n - i) / (i + 1);\n    return res;\n}\n\n// \u91CD\u8907\u7D44\u5408\u305B\uFF0E\
    O(N).\nlong long nHk(int n, long long k) { return nCk(k + n - 1, n - 1); }\n\n\
    }  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_COMBINATION_HPP\n#define ALGORITHM_COMBINATION_HPP 1\n\n\
    /**\n * @brief \u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\
    \u305B\n * @docs docs/Math/Combinatorics/combination.md\n */\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// \u9806\u5217\uFF0EO(K).\nlong long nPk(long long\
    \ n, int k) {\n    assert(0 <= k and k <= n);\n    long long res = 1;\n    for(int\
    \ i = 0; i < k; ++i) res = res * (n - i);\n    return res;\n}\n\n// \u7D44\u5408\
    \u305B\uFF0EO(K).\nlong long nCk(long long n, int k) {\n    assert(0 <= k and\
    \ k <= n);\n    long long res = 1;\n    for(int i = 0; i < k; ++i) res = res *\
    \ (n - i) / (i + 1);\n    return res;\n}\n\n// \u91CD\u8907\u7D44\u5408\u305B\uFF0E\
    O(N).\nlong long nHk(int n, long long k) { return nCk(k + n - 1, n - 1); }\n\n\
    }  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Combinatorics/combination.hpp
  requiredBy: []
  timestamp: '2024-05-27 09:52:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/Combinatorics/combination.hpp
layout: document
redirect_from:
- /library/src/Math/Combinatorics/combination.hpp
- /library/src/Math/Combinatorics/combination.hpp.html
title: "\u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\u305B"
---
