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
  bundledCode: "#line 1 \"src/Utils/convert.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <string>\n#include <vector>\n\nnamespace algorithm {\n\n\
    template <typename Type>\ninline bool chmin(Type &a, const Type &b) {\n    if(a\
    \ > b) {\n        a = b;\n        return true;\n    }\n    return false;\n}\n\n\
    template <typename Type>\ninline bool chmax(Type &a, const Type &b) {\n    if(a\
    \ < b) {\n        a = b;\n        return true;\n    }\n    return false;\n}\n\n\
    inline bool chtoupper(char &c) {\n    if('a' <= c && c <= 'z') {\n        c -=\
    \ 0x20;\n        return true;\n    }\n    return false;\n}\n\ninline bool chtolower(char\
    \ &c) {\n    if('A' <= c && c <= 'Z') {\n        c += 0x20;\n        return true;\n\
    \    }\n    return false;\n}\n\nstd::vector<int> stov(const std::string &s) {\n\
    \    const int n = s.size();\n    std::vector<int> v(n);\n    for(int i = 0; i\
    \ < n; ++i) v[i] = s[i];\n    return v;\n}\n\nstd::string vtos(const std::vector<int>\
    \ &v) {\n    const int n = v.size();\n    std::string s(n, 0);\n    for(int i\
    \ = 0; i < n; ++i) {\n        assert(0 <= v[i] and v[i] < 128);\n        s[i]\
    \ = v[i];\n    }\n    return s;\n}\n\n// \u5EA7\u6A19\u5727\u7E2E\uFF0E\ntemplate\
    \ <typename Type>\nstd::vector<Type> compress(std::vector<Type> &v) {\n    const\
    \ int n = v.size();\n    std::vector<Type> res = v;\n    std::sort(res.begin(),\
    \ res.end());\n    res.erase(std::unique(res.begin(), res.end()), res.end());\n\
    \    for(int i = 0; i < n; ++i) v[i] = std::lower_bound(res.begin(), res.end(),\
    \ v[i]) - res.begin();\n    return res;\n}\n\n// 2\u6B21\u5143\u914D\u5217\u3092\
    \u6642\u8A08\u56DE\u308A90\u5EA6\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\ntemplate\
    \ <typename Type>\nstd::vector<std::vector<Type> > rotate(const std::vector<std::vector<Type>\
    \ > &v) {\n    assert(v.size() > 0);\n    const int h = v.size();\n    const int\
    \ w = v[0].size();\n    std::vector<std::vector<Type> > res(w, std::vector<Type>(h));\n\
    \    for(int i = 0; i < w; ++i) {\n        for(int j = 0; j < h; ++j) res[i][j]\
    \ = v[h - 1 - j][i];\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_CONVERT_HPP\n#define ALGORITHM_CONVERT_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <string>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\ntemplate <typename Type>\ninline bool chmin(Type &a, const Type\
    \ &b) {\n    if(a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\n\ntemplate <typename Type>\ninline bool chmax(Type &a, const Type\
    \ &b) {\n    if(a < b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\n\ninline bool chtoupper(char &c) {\n    if('a' <= c && c <= 'z')\
    \ {\n        c -= 0x20;\n        return true;\n    }\n    return false;\n}\n\n\
    inline bool chtolower(char &c) {\n    if('A' <= c && c <= 'Z') {\n        c +=\
    \ 0x20;\n        return true;\n    }\n    return false;\n}\n\nstd::vector<int>\
    \ stov(const std::string &s) {\n    const int n = s.size();\n    std::vector<int>\
    \ v(n);\n    for(int i = 0; i < n; ++i) v[i] = s[i];\n    return v;\n}\n\nstd::string\
    \ vtos(const std::vector<int> &v) {\n    const int n = v.size();\n    std::string\
    \ s(n, 0);\n    for(int i = 0; i < n; ++i) {\n        assert(0 <= v[i] and v[i]\
    \ < 128);\n        s[i] = v[i];\n    }\n    return s;\n}\n\n// \u5EA7\u6A19\u5727\
    \u7E2E\uFF0E\ntemplate <typename Type>\nstd::vector<Type> compress(std::vector<Type>\
    \ &v) {\n    const int n = v.size();\n    std::vector<Type> res = v;\n    std::sort(res.begin(),\
    \ res.end());\n    res.erase(std::unique(res.begin(), res.end()), res.end());\n\
    \    for(int i = 0; i < n; ++i) v[i] = std::lower_bound(res.begin(), res.end(),\
    \ v[i]) - res.begin();\n    return res;\n}\n\n// 2\u6B21\u5143\u914D\u5217\u3092\
    \u6642\u8A08\u56DE\u308A90\u5EA6\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\ntemplate\
    \ <typename Type>\nstd::vector<std::vector<Type> > rotate(const std::vector<std::vector<Type>\
    \ > &v) {\n    assert(v.size() > 0);\n    const int h = v.size();\n    const int\
    \ w = v[0].size();\n    std::vector<std::vector<Type> > res(w, std::vector<Type>(h));\n\
    \    for(int i = 0; i < w; ++i) {\n        for(int j = 0; j < h; ++j) res[i][j]\
    \ = v[h - 1 - j][i];\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Utils/convert.hpp
  requiredBy: []
  timestamp: '2023-06-09 09:36:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Utils/convert.hpp
layout: document
redirect_from:
- /library/src/Utils/convert.hpp
- /library/src/Utils/convert.hpp.html
title: src/Utils/convert.hpp
---
