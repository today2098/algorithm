---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DP/longest_increasing_subsequence.hpp
    title: "Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\u90E8\u5206\
      \u5217\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D
  bundledCode: "#line 1 \"test/aoj-DPL_1_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"src/DP/longest_increasing_subsequence.hpp\"\
    \n/**\n * @brief Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\uFF09\n */\n\n#ifndef ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP\n\
    #define ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP 1\n\n#include <algorithm>\n\
    #include <functional>\n#line 11 \"src/DP/longest_increasing_subsequence.hpp\"\n\
    \nnamespace algorithm {\n\n// Longest Increasing Subsequence\uFF08\u6700\u9577\
    \u5897\u52A0\u90E8\u5206\u5217\uFF09\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\
    \uFF0EO(N*logN).\ntemplate <typename Type, typename Func = std::function<bool(const\
    \ Type &, const Type &)> >\nstd::vector<int> lis(\n    const std::vector<Type>\
    \ &v,\n    const Func &comp = [](const Type &a, const Type &b) -> bool { return\
    \ a < b; }) {\n    const int n = v.size();\n    std::vector<int> res(n + 1, 0);\
    \  // res[i]:=(v[:i]\u306B\u304A\u3051\u308B\u6700\u9577\u5897\u52A0\u90E8\u5206\
    \u5217\u306E\u9577\u3055).\n    std::vector<Type> sub;\n    sub.reserve(n);\n\
    \    for(int i = 0; i < n; ++i) {\n        auto itr = std::lower_bound(sub.begin(),\
    \ sub.end(), v[i], comp);\n        if(itr == sub.end()) sub.push_back(v[i]);\n\
    \        else *itr = v[i];\n        res[i + 1] = sub.size();\n    }\n    return\
    \ res;\n}\n\n}  // namespace algorithm\n\n#endif\n#line 7 \"test/aoj-DPL_1_D.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::vector<int> a(n);\n\
    \    for(auto &in : a) std::cin >> in;\n\n    auto &&lis = algorithm::lis(a);\n\
    \    std::cout << lis[n] << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../src/DP/longest_increasing_subsequence.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::vector<int> a(n);\n\
    \    for(auto &in : a) std::cin >> in;\n\n    auto &&lis = algorithm::lis(a);\n\
    \    std::cout << lis[n] << std::endl;\n}\n"
  dependsOn:
  - src/DP/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: test/aoj-DPL_1_D.test.cpp
  requiredBy: []
  timestamp: '2023-09-04 20:37:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DPL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DPL_1_D.test.cpp
- /verify/test/aoj-DPL_1_D.test.cpp.html
title: test/aoj-DPL_1_D.test.cpp
---
