---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-ALDS1_10_C.test.cpp
    title: test/aoj-ALDS1_10_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DP/longest_common_subsequence.md
    document_title: "Longest Common Subsequence\uFF08\u6700\u9577\u5171\u901A\u90E8\
      \u5206\u5217\uFF09"
    links: []
  bundledCode: "#line 1 \"src/DP/longest_common_subsequence.hpp\"\n\n\n\n/**\n * @brief\
    \ Longest Common Subsequence\uFF08\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\uFF09\
    \n * @docs docs/DP/longest_common_subsequence.md\n */\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// 2\u3064\u306E\u914D\u5217\u306B\
    \u5BFE\u3057\u3066\uFF0C\u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (LCS: Longest\
    \ Common Subsequence) \u3092\u6C42\u3081\u308B\uFF0E\n// \u5F15\u6570\u306FSTL\u306E\
    \u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\u3067\u3042\u308B\u3053\
    \u3068\uFF0EO(|S|*|T|).\ntemplate <class Sequence>\nSequence lcs(const Sequence\
    \ &s, const Sequence &t) {\n    const int n = s.size(), m = t.size();\n    //\
    \ dp[i][j]:=(s[:i]\u3068t[:j]\u306ELCS\u306E\u9577\u3055).\n    std::vector<std::vector<int>\
    \ > dp(n + 1, std::vector<int>(m + 1, 0));\n    for(int i = 1; i <= n; ++i) {\n\
    \        for(int j = 1; j <= m; ++j) {\n            dp[i][j] = (s[i - 1] == t[j\
    \ - 1] ? dp[i - 1][j - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]));\n     \
    \   }\n    }\n    Sequence sub(dp[n][m], 0);  // sub[]:=(\u914D\u5217s, t\u306E\
    LCS).\n    int i = n, j = m, k = dp[n][m];\n    while(k > 0) {\n        if(s[i\
    \ - 1] == t[j - 1]) {\n            sub[k - 1] = s[i - 1];\n            i--, j--,\
    \ k--;\n        } else if(dp[i][j] == dp[i - 1][j]) {\n            i--;\n    \
    \    } else {\n            j--;\n        }\n    }\n    return sub;\n}\n\n}  //\
    \ namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LONGEST_COMMON_SUBSEQUENCE_HPP\n#define ALGORITHM_LONGEST_COMMON_SUBSEQUENCE_HPP\
    \ 1\n\n/**\n * @brief Longest Common Subsequence\uFF08\u6700\u9577\u5171\u901A\
    \u90E8\u5206\u5217\uFF09\n * @docs docs/DP/longest_common_subsequence.md\n */\n\
    \n#include <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n// 2\u3064\
    \u306E\u914D\u5217\u306B\u5BFE\u3057\u3066\uFF0C\u6700\u9577\u5171\u901A\u90E8\
    \u5206\u5217 (LCS: Longest Common Subsequence) \u3092\u6C42\u3081\u308B\uFF0E\n\
    // \u5F15\u6570\u306FSTL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\
    \u30CA\u3067\u3042\u308B\u3053\u3068\uFF0EO(|S|*|T|).\ntemplate <class Sequence>\n\
    Sequence lcs(const Sequence &s, const Sequence &t) {\n    const int n = s.size(),\
    \ m = t.size();\n    // dp[i][j]:=(s[:i]\u3068t[:j]\u306ELCS\u306E\u9577\u3055\
    ).\n    std::vector<std::vector<int> > dp(n + 1, std::vector<int>(m + 1, 0));\n\
    \    for(int i = 1; i <= n; ++i) {\n        for(int j = 1; j <= m; ++j) {\n  \
    \          dp[i][j] = (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] + 1 : std::max(dp[i\
    \ - 1][j], dp[i][j - 1]));\n        }\n    }\n    Sequence sub(dp[n][m], 0); \
    \ // sub[]:=(\u914D\u5217s, t\u306ELCS).\n    int i = n, j = m, k = dp[n][m];\n\
    \    while(k > 0) {\n        if(s[i - 1] == t[j - 1]) {\n            sub[k - 1]\
    \ = s[i - 1];\n            i--, j--, k--;\n        } else if(dp[i][j] == dp[i\
    \ - 1][j]) {\n            i--;\n        } else {\n            j--;\n        }\n\
    \    }\n    return sub;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DP/longest_common_subsequence.hpp
  requiredBy: []
  timestamp: '2024-05-20 01:51:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-ALDS1_10_C.test.cpp
documentation_of: src/DP/longest_common_subsequence.hpp
layout: document
redirect_from:
- /library/src/DP/longest_common_subsequence.hpp
- /library/src/DP/longest_common_subsequence.hpp.html
title: "Longest Common Subsequence\uFF08\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\
  \uFF09"
---
## 概要

配列 $S, T$ に対して，最長共通部分列 (LCS: Longest Common Subsequence) を求める．
最長共通部分列とは，2つの配列において，双方に現れる部分列の中で最長のものを指す．

アルゴリズムの計算量は $\mathcal{O}(\lvert S \rvert \lvert T \rvert)$ ．


## 参考文献

1. 秋葉拓哉ほか. "2-3 値を覚えて再利用 '動的計画法'". プログラミングコンテストチャレンジブック. 第2版, マイナビ出版, 2012, p.56-57.


## 問題

- "F - LCS". Educational DP Contest / DP まとめコンテスト. AtCoder. <https://atcoder.jp/contests/dp/tasks/dp_f>.