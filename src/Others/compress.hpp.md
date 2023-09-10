---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DSL_4_A.test.cpp
    title: test/aoj-DSL_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 1 \"src/Others/compress.hpp\"\n/**\n * @brief \u5EA7\u6A19\u5727\
    \u7E2E\n */\n\n#ifndef ALGORITHM_COMPRESS_HPP\n#define ALGORITHM_COMPRESS_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n//\
    \ \u5EA7\u6A19\u5727\u7E2E\uFF0E\ntemplate <typename Type>\nstd::vector<Type>\
    \ compress(std::vector<Type> &v) {\n    const int n = v.size();\n    std::vector<Type>\
    \ key = v;\n    std::sort(key.begin(), key.end());\n    key.erase(std::unique(key.begin(),\
    \ key.end()), key.end());\n    for(int i = 0; i < n; ++i) v[i] = std::lower_bound(key.begin(),\
    \ key.end(), v[i]) - key.begin();\n    return key;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  code: "/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n */\n\n#ifndef ALGORITHM_COMPRESS_HPP\n\
    #define ALGORITHM_COMPRESS_HPP 1\n\n#include <algorithm>\n#include <vector>\n\n\
    namespace algorithm {\n\n// \u5EA7\u6A19\u5727\u7E2E\uFF0E\ntemplate <typename\
    \ Type>\nstd::vector<Type> compress(std::vector<Type> &v) {\n    const int n =\
    \ v.size();\n    std::vector<Type> key = v;\n    std::sort(key.begin(), key.end());\n\
    \    key.erase(std::unique(key.begin(), key.end()), key.end());\n    for(int i\
    \ = 0; i < n; ++i) v[i] = std::lower_bound(key.begin(), key.end(), v[i]) - key.begin();\n\
    \    return key;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Others/compress.hpp
  requiredBy: []
  timestamp: '2023-09-10 09:58:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-DSL_4_A.test.cpp
documentation_of: src/Others/compress.hpp
layout: document
redirect_from:
- /library/src/Others/compress.hpp
- /library/src/Others/compress.hpp.html
title: "\u5EA7\u6A19\u5727\u7E2E"
---
