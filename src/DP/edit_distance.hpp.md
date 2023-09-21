---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DPL_1_E.test.cpp
    title: test/aoj-DPL_1_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DP/edit_distance.md
    document_title: "Edit Distance\uFF08\u7DE8\u96C6\u8DDD\u96E2\uFF09"
    links: []
  bundledCode: "#line 1 \"src/DP/edit_distance.hpp\"\n\n\n\n/**\n * @brief Edit Distance\uFF08\
    \u7DE8\u96C6\u8DDD\u96E2\uFF09\n * @docs docs/DP/edit_distance.md\n */\n\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n// Edit Distance\uFF08\
    \u7DE8\u96C6\u8DDD\u96E2\uFF09.\n// \u5F15\u6570\u306FSTL\u306E\u30B7\u30FC\u30B1\
    \u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\u3067\u3042\u308B\u3053\u3068\uFF0EO(|S|*|T|).\n\
    template <class Sequence>\nstd::vector<std::vector<int> > edit_distance(const\
    \ Sequence &s, const Sequence &t) {\n    const int n = s.size(), m = t.size();\n\
    \    // dp[i][j]:=(s[:i]\u3068t[:j]\u306E\u7DE8\u96C6\u8DDD\u96E2).\n    std::vector<std::vector<int>\
    \ > dp(n + 1, std::vector<int>(m + 1, 0));\n    for(int i = 1; i <= n; ++i) dp[i][0]\
    \ = i;\n    for(int j = 1; j <= m; ++j) dp[0][j] = j;\n    for(int i = 1; i <=\
    \ n; ++i) {\n        for(int j = 1; j <= m; ++j) {\n            dp[i][j] = std::min({dp[i\
    \ - 1][j] + 1,\n                                 dp[i][j - 1] + 1,\n         \
    \                        dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1)});\n\
    \        }\n    }\n    return dp;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_EDIT_DISTANCE_HPP\n#define ALGORITHM_EDIT_DISTANCE_HPP\
    \ 1\n\n/**\n * @brief Edit Distance\uFF08\u7DE8\u96C6\u8DDD\u96E2\uFF09\n * @docs\
    \ docs/DP/edit_distance.md\n */\n\n#include <algorithm>\n#include <vector>\n\n\
    namespace algorithm {\n\n// Edit Distance\uFF08\u7DE8\u96C6\u8DDD\u96E2\uFF09\
    .\n// \u5F15\u6570\u306FSTL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\
    \u30CA\u3067\u3042\u308B\u3053\u3068\uFF0EO(|S|*|T|).\ntemplate <class Sequence>\n\
    std::vector<std::vector<int> > edit_distance(const Sequence &s, const Sequence\
    \ &t) {\n    const int n = s.size(), m = t.size();\n    // dp[i][j]:=(s[:i]\u3068\
    t[:j]\u306E\u7DE8\u96C6\u8DDD\u96E2).\n    std::vector<std::vector<int> > dp(n\
    \ + 1, std::vector<int>(m + 1, 0));\n    for(int i = 1; i <= n; ++i) dp[i][0]\
    \ = i;\n    for(int j = 1; j <= m; ++j) dp[0][j] = j;\n    for(int i = 1; i <=\
    \ n; ++i) {\n        for(int j = 1; j <= m; ++j) {\n            dp[i][j] = std::min({dp[i\
    \ - 1][j] + 1,\n                                 dp[i][j - 1] + 1,\n         \
    \                        dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1)});\n\
    \        }\n    }\n    return dp;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DP/edit_distance.hpp
  requiredBy: []
  timestamp: '2023-09-20 16:42:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-DPL_1_E.test.cpp
documentation_of: src/DP/edit_distance.hpp
layout: document
redirect_from:
- /library/src/DP/edit_distance.hpp
- /library/src/DP/edit_distance.hpp.html
title: "Edit Distance\uFF08\u7DE8\u96C6\u8DDD\u96E2\uFF09"
---
## 概要

配列 $S, T$ に対して，2つの編集距離を求める．

計算量は $\mathcal{O}(\lvert S \rvert \lvert T \rvert)$ ．


## 参考文献

1. "レーベンシュタイン距離". Wikipedia. <https://ja.wikipedia.org/wiki/レーベンシュタイン距離>.
