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
  bundledCode: "#line 1 \"src/DP/lis.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
    #include <functional>\n#include <vector>\n\nnamespace algorithm {\n\n// \u6700\
    \u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS: Longest Increasing Subsequence) \u306E\
    \u9577\u3055\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\ntemplate <typename Type,\
    \ typename Func = std::function<bool(const Type &, const Type &)> >\nstd::vector<int>\
    \ lis(\n    const std::vector<Type> &v,\n    const Func &comp = [](const Type\
    \ &a, const Type &b) -> bool { return a < b; }) {\n    const int n = v.size();\n\
    \    std::vector<int> res(n);  // res[i]:=(v[:i+1]\u306E\u6700\u9577\u5897\u52A0\
    \u90E8\u5206\u5217\u306E\u9577\u3055).\n    std::vector<Type> dp;\n    dp.reserve(n);\n\
    \    for(int i = 0; i < n; ++i) {\n        auto itr = std::lower_bound(dp.begin(),\
    \ dp.end(), v[i], comp);\n        if(itr == dp.end()) dp.push_back(v[i]);\n  \
    \      else *itr = v[i];\n        res[i] = dp.size();\n    }\n    return res;\n\
    }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LIS_HPP\n#define ALGORITHM_LIS_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS: Longest Increasing\
    \ Subsequence) \u306E\u9577\u3055\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\ntemplate\
    \ <typename Type, typename Func = std::function<bool(const Type &, const Type\
    \ &)> >\nstd::vector<int> lis(\n    const std::vector<Type> &v,\n    const Func\
    \ &comp = [](const Type &a, const Type &b) -> bool { return a < b; }) {\n    const\
    \ int n = v.size();\n    std::vector<int> res(n);  // res[i]:=(v[:i+1]\u306E\u6700\
    \u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055).\n    std::vector<Type>\
    \ dp;\n    dp.reserve(n);\n    for(int i = 0; i < n; ++i) {\n        auto itr\
    \ = std::lower_bound(dp.begin(), dp.end(), v[i], comp);\n        if(itr == dp.end())\
    \ dp.push_back(v[i]);\n        else *itr = v[i];\n        res[i] = dp.size();\n\
    \    }\n    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DP/lis.hpp
  requiredBy: []
  timestamp: '2023-08-17 14:58:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DP/lis.hpp
layout: document
redirect_from:
- /library/src/DP/lis.hpp
- /library/src/DP/lis.hpp.html
title: src/DP/lis.hpp
---
