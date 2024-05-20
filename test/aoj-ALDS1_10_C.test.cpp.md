---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DP/longest_common_subsequence.hpp
    title: "Longest Common Subsequence\uFF08\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\
      \uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C
  bundledCode: "#line 1 \"test/aoj-ALDS1_10_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 1 \"src/DP/longest_common_subsequence.hpp\"\
    \n\n\n\n/**\n * @brief Longest Common Subsequence\uFF08\u6700\u9577\u5171\u901A\
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
    \    }\n    return sub;\n}\n\n}  // namespace algorithm\n\n\n#line 7 \"test/aoj-ALDS1_10_C.test.cpp\"\
    \n\nint main() {\n    int q;\n    std::cin >> q;\n\n    while(q--) {\n       \
    \ std::string x, y;\n        std::cin >> x >> y;\n\n        std::cout << algorithm::lcs(x,\
    \ y).size() << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../src/DP/longest_common_subsequence.hpp\"\
    \n\nint main() {\n    int q;\n    std::cin >> q;\n\n    while(q--) {\n       \
    \ std::string x, y;\n        std::cin >> x >> y;\n\n        std::cout << algorithm::lcs(x,\
    \ y).size() << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/DP/longest_common_subsequence.hpp
  isVerificationFile: true
  path: test/aoj-ALDS1_10_C.test.cpp
  requiredBy: []
  timestamp: '2024-05-20 01:51:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ALDS1_10_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ALDS1_10_C.test.cpp
- /verify/test/aoj-ALDS1_10_C.test.cpp.html
title: test/aoj-ALDS1_10_C.test.cpp
---
