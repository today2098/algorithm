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
  bundledCode: "#line 1 \"src/Utils/table.hpp\"\n\n\n\n#include <vector>\n\nnamespace\
    \ algorithm {\n\ntemplate <typename Type>\ninline std::vector<Type> table(size_t\
    \ n, const Type &val) { return std::vector<Type>(n, val); }\n\ntemplate <typename...\
    \ Args>\nauto table(size_t n, const Args &...args) {\n    auto val = table(args...);\n\
    \    return std::vector<decltype(val)>(n, std::move(val));\n}\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_TABLE_HPP\n#define ALGORITHM_TABLE_HPP 1\n\n#include <vector>\n\
    \nnamespace algorithm {\n\ntemplate <typename Type>\ninline std::vector<Type>\
    \ table(size_t n, const Type &val) { return std::vector<Type>(n, val); }\n\ntemplate\
    \ <typename... Args>\nauto table(size_t n, const Args &...args) {\n    auto val\
    \ = table(args...);\n    return std::vector<decltype(val)>(n, std::move(val));\n\
    }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Utils/table.hpp
  requiredBy: []
  timestamp: '2023-08-19 16:18:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Utils/table.hpp
layout: document
redirect_from:
- /library/src/Utils/table.hpp
- /library/src/Utils/table.hpp.html
title: src/Utils/table.hpp
---
