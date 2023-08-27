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
  bundledCode: "#line 1 \"src/String/run_length_encode.hpp\"\n\n\n\n#include <string>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u30E9\u30F3\
    \u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\uFF08\u9023\u9577\u5727\u7E2E\uFF09\uFF0E\
    \nstd::vector<std::pair<char, int> > run_length_encoding(const std::string &s)\
    \ {\n    std::vector<std::pair<char, int> > res;\n    const int n = s.size();\n\
    \    if(n == 0) return res;\n    int cnt = 1;\n    for(int i = 1; i < n; ++i)\
    \ {\n        if(s[i] != s[i - 1]) {\n            res.emplace_back(s[i - 1], cnt);\n\
    \            cnt = 0;\n        }\n        cnt++;\n    }\n    res.emplace_back(s[n\
    \ - 1], cnt);\n    return res;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_RUN_LENGTH_ENCODING_HPP\n#define ALGORITHM_RUN_LENGTH_ENCODING_HPP\
    \ 1\n\n#include <string>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\uFF08\u9023\u9577\u5727\
    \u7E2E\uFF09\uFF0E\nstd::vector<std::pair<char, int> > run_length_encoding(const\
    \ std::string &s) {\n    std::vector<std::pair<char, int> > res;\n    const int\
    \ n = s.size();\n    if(n == 0) return res;\n    int cnt = 1;\n    for(int i =\
    \ 1; i < n; ++i) {\n        if(s[i] != s[i - 1]) {\n            res.emplace_back(s[i\
    \ - 1], cnt);\n            cnt = 0;\n        }\n        cnt++;\n    }\n    res.emplace_back(s[n\
    \ - 1], cnt);\n    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/String/run_length_encode.hpp
  requiredBy: []
  timestamp: '2023-08-23 17:12:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/String/run_length_encode.hpp
layout: document
redirect_from:
- /library/src/String/run_length_encode.hpp
- /library/src/String/run_length_encode.hpp.html
title: src/String/run_length_encode.hpp
---
