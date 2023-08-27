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
  bundledCode: "#line 1 \"src/DP/edit_distance.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u7DE8\u96C6\u8DDD\u96E2 (edit\
    \ distance)\uFF0E\u5F15\u6570\u306FSTL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\
    \u30F3\u30C6\u30CA\uFF0EO(|S|*|T|).\ntemplate <class Sequence>\nint edit_distance(const\
    \ Sequence &s, const Sequence &t) {\n    const int m = s.size(), n = t.size();\n\
    \    std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1));  // dp[i][j]:=(s[:i]\u3068\
    t[:j]\u306E\u7DE8\u96C6\u8DDD\u96E2).\n    dp[0][0] = 0;\n    for(int i = 1; i\
    \ <= m; ++i) dp[i][0] = i;\n    for(int j = 1; j <= n; ++j) dp[0][j] = j;\n  \
    \  for(int i = 1; i <= m; ++i) {\n        for(int j = 1; j <= n; ++j) {\n    \
    \        dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j\
    \ - 1] + (s[i - 1] == t[j - 1] ? 0 : 1)});\n        }\n    }\n    return dp[m][n];\n\
    }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_EDIT_DISTANCE_HPP\n#define ALGORITHM_EDIT_DISTANCE_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n//\
    \ \u7DE8\u96C6\u8DDD\u96E2 (edit distance)\uFF0E\u5F15\u6570\u306FSTL\u306E\u30B7\
    \u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\uFF0EO(|S|*|T|).\ntemplate <class\
    \ Sequence>\nint edit_distance(const Sequence &s, const Sequence &t) {\n    const\
    \ int m = s.size(), n = t.size();\n    std::vector<std::vector<int> > dp(m + 1,\
    \ std::vector<int>(n + 1));  // dp[i][j]:=(s[:i]\u3068t[:j]\u306E\u7DE8\u96C6\u8DDD\
    \u96E2).\n    dp[0][0] = 0;\n    for(int i = 1; i <= m; ++i) dp[i][0] = i;\n \
    \   for(int j = 1; j <= n; ++j) dp[0][j] = j;\n    for(int i = 1; i <= m; ++i)\
    \ {\n        for(int j = 1; j <= n; ++j) {\n            dp[i][j] = std::min({dp[i\
    \ - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0\
    \ : 1)});\n        }\n    }\n    return dp[m][n];\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DP/edit_distance.hpp
  requiredBy: []
  timestamp: '2023-04-06 11:39:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DP/edit_distance.hpp
layout: document
redirect_from:
- /library/src/DP/edit_distance.hpp
- /library/src/DP/edit_distance.hpp.html
title: src/DP/edit_distance.hpp
---
