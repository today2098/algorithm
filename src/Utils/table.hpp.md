---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-3110.test.cpp
    title: test/aoj-3110.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Utils/table.md
    links: []
  bundledCode: "#line 1 \"src/Utils/table.hpp\"\n/**\n * @docs docs/Utils/table.md\n\
    \ */\n\n#ifndef ALGORITHM_TABLE_HPP\n#define ALGORITHM_TABLE_HPP 1\n\n#include\
    \ <vector>\n\nnamespace algorithm {\n\ntemplate <typename Type>\ninline std::vector<Type>\
    \ table(size_t n, const Type &val) { return std::vector<Type>(n, val); }\n\ntemplate\
    \ <typename... Args>\ninline auto table(size_t n, const Args &...args) { return\
    \ std::vector(n, table(args...)); }\n\n}  // namespace algorithm\n\n#endif\n"
  code: "/**\n * @docs docs/Utils/table.md\n */\n\n#ifndef ALGORITHM_TABLE_HPP\n#define\
    \ ALGORITHM_TABLE_HPP 1\n\n#include <vector>\n\nnamespace algorithm {\n\ntemplate\
    \ <typename Type>\ninline std::vector<Type> table(size_t n, const Type &val) {\
    \ return std::vector<Type>(n, val); }\n\ntemplate <typename... Args>\ninline auto\
    \ table(size_t n, const Args &...args) { return std::vector(n, table(args...));\
    \ }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Utils/table.hpp
  requiredBy: []
  timestamp: '2023-09-25 15:35:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-3110.test.cpp
documentation_of: src/Utils/table.hpp
layout: document
redirect_from:
- /library/src/Utils/table.hpp
- /library/src/Utils/table.hpp.html
title: src/Utils/table.hpp
---
## 概要

`std::vector` による多次元配列を作成する．
