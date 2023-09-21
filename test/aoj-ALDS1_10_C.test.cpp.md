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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_C
  bundledCode: "#line 1 \"test/aoj-ALDS1_10_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 1 \"src/DP/longest_common_subsequence.hpp\"\
    \n\n\n\n/**\n * @brief Longest Common Subsequence\uFF08\u6700\u9577\u5171\u901A\
    \u90E8\u5206\u5217\uFF09\n * @docs docs/DP/longest_common_subsequence.md\n */\n\
    \n#include <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n// Longest\
    \ Common Subsequence\uFF08\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\uFF09.\n\
    // \u5F15\u6570\u306FSTL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\
    \u30CA\uFF0EO(|A|*|B|).\ntemplate <class Sequence>\nSequence lcs(const Sequence\
    \ &a, const Sequence &b) {\n    const int n = a.size(), m = b.size();\n    //\
    \ dp[i][j]:=(a[:i]\u3068b[:j]\u306ELCS\u306E\u9577\u3055).\n    std::vector<std::vector<int>\
    \ > dp(n + 1, std::vector<int>(m + 1, 0));\n    for(int i = 1; i <= n; ++i) {\n\
    \        for(int j = 1; j <= m; ++j) {\n            dp[i][j] = (a[i - 1] == b[j\
    \ - 1] ? dp[i - 1][j - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]));\n     \
    \   }\n    }\n    Sequence sub(dp[n][m], 0);  // sub[]:=(\u914D\u5217a, b\u306E\
    LCS).\n    int i = n, j = m, k = dp[n][m];\n    while(k > 0) {\n        if(a[i\
    \ - 1] == b[j - 1]) {\n            sub[k - 1] = a[i - 1];\n            i--, j--,\
    \ k--;\n        } else if(dp[i][j] == dp[i - 1][j]) {\n            i--;\n    \
    \    } else {\n            j--;\n        }\n    }\n    return sub;\n}\n\n}  //\
    \ namespace algorithm\n\n\n#line 7 \"test/aoj-ALDS1_10_C.test.cpp\"\n\nint main()\
    \ {\n    int q;\n    std::cin >> q;\n\n    while(q--) {\n        std::string x,\
    \ y;\n        std::cin >> x >> y;\n\n        std::cout << algorithm::lcs(x, y).size()\
    \ << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../src/DP/longest_common_subsequence.hpp\"\
    \n\nint main() {\n    int q;\n    std::cin >> q;\n\n    while(q--) {\n       \
    \ std::string x, y;\n        std::cin >> x >> y;\n\n        std::cout << algorithm::lcs(x,\
    \ y).size() << std::endl;\n    }\n}\n"
  dependsOn:
  - src/DP/longest_common_subsequence.hpp
  isVerificationFile: true
  path: test/aoj-ALDS1_10_C.test.cpp
  requiredBy: []
  timestamp: '2023-09-20 16:42:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ALDS1_10_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ALDS1_10_C.test.cpp
- /verify/test/aoj-ALDS1_10_C.test.cpp.html
title: test/aoj-ALDS1_10_C.test.cpp
---
