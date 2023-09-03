---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\u90E8\
      \u5206\u5217\uFF09"
    links: []
  bundledCode: "#line 1 \"src/DP/longest_increasing_subsequence.hpp\"\n/**\n * @brief\
    \ Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\
    \uFF09\n */\n\n#ifndef ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP\n#define ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP\
    \ 1\n\n#include <algorithm>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\
    \u90E8\u5206\u5217\uFF09\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\n\
    template <typename Type, typename Func = std::function<bool(const Type &, const\
    \ Type &)> >\nstd::vector<int> lis(\n    const std::vector<Type> &v,\n    const\
    \ Func &comp = [](const Type &a, const Type &b) -> bool { return a < b; }) {\n\
    \    const int n = v.size();\n    std::vector<int> res(n + 1, 0);  // res[i]:=(v[:i]\u306B\
    \u304A\u3051\u308B\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055\
    ).\n    std::vector<Type> sub;\n    sub.reserve(n);\n    for(int i = 0; i < n;\
    \ ++i) {\n        auto itr = std::lower_bound(sub.begin(), sub.end(), v[i], comp);\n\
    \        if(itr == sub.end()) sub.push_back(v[i]);\n        else *itr = v[i];\n\
    \        res[i + 1] = sub.size();\n    }\n    return res;\n}\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  code: "/**\n * @brief Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\
    \u90E8\u5206\u5217\uFF09\n */\n\n#ifndef ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP\n\
    #define ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP 1\n\n#include <algorithm>\n\
    #include <functional>\n#include <vector>\n\nnamespace algorithm {\n\n// Longest\
    \ Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\uFF09\
    \u306E\u9577\u3055\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\ntemplate <typename\
    \ Type, typename Func = std::function<bool(const Type &, const Type &)> >\nstd::vector<int>\
    \ lis(\n    const std::vector<Type> &v,\n    const Func &comp = [](const Type\
    \ &a, const Type &b) -> bool { return a < b; }) {\n    const int n = v.size();\n\
    \    std::vector<int> res(n + 1, 0);  // res[i]:=(v[:i]\u306B\u304A\u3051\u308B\
    \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055).\n    std::vector<Type>\
    \ sub;\n    sub.reserve(n);\n    for(int i = 0; i < n; ++i) {\n        auto itr\
    \ = std::lower_bound(sub.begin(), sub.end(), v[i], comp);\n        if(itr == sub.end())\
    \ sub.push_back(v[i]);\n        else *itr = v[i];\n        res[i + 1] = sub.size();\n\
    \    }\n    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DP/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2023-09-03 18:32:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DP/longest_increasing_subsequence.hpp
layout: document
redirect_from:
- /library/src/DP/longest_increasing_subsequence.hpp
- /library/src/DP/longest_increasing_subsequence.hpp.html
title: "Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\
  \uFF09"
---
