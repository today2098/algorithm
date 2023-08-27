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
  bundledCode: "#line 1 \"src/DP/lcs.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u6700\u9577\u5171\u901A\u90E8\
    \u5206\u5217 (LCS: Longest Common Subsequence)\uFF0E\n// \u5F15\u6570\u306FSTL\u306E\
    \u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\uFF0EO(|A|*|B|).\ntemplate\
    \ <class Sequence>\nSequence lcs(const Sequence &a, const Sequence &b) {\n   \
    \ const int n = a.size(), m = b.size();\n    // dp[i][j]:=(a[:i]\u3068b[:j]\u306E\
    LCS\u306E\u9577\u3055).\n    std::vector<std::vector<int> > dp(n + 1, std::vector<int>(m\
    \ + 1, 0));\n    for(int i = 1; i <= n; ++i) {\n        for(int j = 1; j <= m;\
    \ ++j) {\n            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;\n\
    \            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);\n        }\n\
    \    }\n    Sequence sub(dp[n][m], a[0]);  // sub[]:=(\u914D\u5217a, b\u306ELCS).\n\
    \    int i = n, j = m, k = dp[n][m];\n    while(k > 0) {\n        if(a[i - 1]\
    \ == b[j - 1]) {\n            sub[k - 1] = a[i - 1];\n            i--, j--, k--;\n\
    \        } else if(dp[i][j] == dp[i - 1][j]) {\n            i--;\n        } else\
    \ {\n            j--;\n        }\n    }\n    return sub;\n}\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LCS_HPP\n#define ALGORITHM_LCS_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u6700\u9577\
    \u5171\u901A\u90E8\u5206\u5217 (LCS: Longest Common Subsequence)\uFF0E\n// \u5F15\
    \u6570\u306FSTL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\uFF0E\
    O(|A|*|B|).\ntemplate <class Sequence>\nSequence lcs(const Sequence &a, const\
    \ Sequence &b) {\n    const int n = a.size(), m = b.size();\n    // dp[i][j]:=(a[:i]\u3068\
    b[:j]\u306ELCS\u306E\u9577\u3055).\n    std::vector<std::vector<int> > dp(n +\
    \ 1, std::vector<int>(m + 1, 0));\n    for(int i = 1; i <= n; ++i) {\n       \
    \ for(int j = 1; j <= m; ++j) {\n            if(a[i - 1] == b[j - 1]) dp[i][j]\
    \ = dp[i - 1][j - 1] + 1;\n            else dp[i][j] = std::max(dp[i - 1][j],\
    \ dp[i][j - 1]);\n        }\n    }\n    Sequence sub(dp[n][m], a[0]);  // sub[]:=(\u914D\
    \u5217a, b\u306ELCS).\n    int i = n, j = m, k = dp[n][m];\n    while(k > 0) {\n\
    \        if(a[i - 1] == b[j - 1]) {\n            sub[k - 1] = a[i - 1];\n    \
    \        i--, j--, k--;\n        } else if(dp[i][j] == dp[i - 1][j]) {\n     \
    \       i--;\n        } else {\n            j--;\n        }\n    }\n    return\
    \ sub;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DP/lcs.hpp
  requiredBy: []
  timestamp: '2023-08-17 15:26:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DP/lcs.hpp
layout: document
redirect_from:
- /library/src/DP/lcs.hpp
- /library/src/DP/lcs.hpp.html
title: src/DP/lcs.hpp
---
