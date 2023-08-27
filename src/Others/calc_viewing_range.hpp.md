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
  bundledCode: "#line 1 \"src/Others/calc_viewing_range.hpp\"\n\n\n\n#include <functional>\n\
    #include <stack>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// \u898B\u6674\u3089\u3057\u7BC4\u56F2\uFF0E\n// H[] within [left[i],\
    \ right[i]) <= H[i] (left[i] <= i < right[i]) \u3068\u306A\u308Bleft[], right[]\u3092\
    \u6C42\u3081\u308B\uFF0EO(N).\ntemplate <typename Type, typename Func = std::function<bool(Type,\
    \ Type)> >\nstd::pair<std::vector<int>, std::vector<int> > calc_viewing_range(\n\
    \    const std::vector<Type> &h,\n    const Func &comp = [](const Type &a, const\
    \ Type &b) -> bool { return a <= b; }) {\n    const int n = h.size();\n    std::vector<int>\
    \ left(n, 0), right(n, n);\n    // left side.\n    std::stack<std::pair<Type,\
    \ int> > stack_left;\n    for(int i = 0; i < n; ++i) {\n        while(!stack_left.empty()\
    \ and comp(stack_left.top().first, h[i])) stack_left.pop();\n        if(!stack_left.empty())\
    \ left[i] = stack_left.top().second + 1;\n        stack_left.push({h[i], i});\n\
    \    }\n    // right side.\n    std::stack<std::pair<Type, int> > stack_right;\n\
    \    for(int i = n - 1; i >= 0; --i) {\n        while(!stack_right.empty() and\
    \ comp(stack_right.top().first, h[i])) stack_right.pop();\n        if(!stack_right.empty())\
    \ right[i] = stack_right.top().second;\n        stack_right.push({h[i], i});\n\
    \    }\n    return {left, right};\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_CALC_VIEWING_RANGE_HPP\n#define ALGORITHM_CALC_VIEWING_RANGE_HPP\
    \ 1\n\n#include <functional>\n#include <stack>\n#include <utility>\n#include <vector>\n\
    \nnamespace algorithm {\n\n// \u898B\u6674\u3089\u3057\u7BC4\u56F2\uFF0E\n// H[]\
    \ within [left[i], right[i]) <= H[i] (left[i] <= i < right[i]) \u3068\u306A\u308B\
    left[], right[]\u3092\u6C42\u3081\u308B\uFF0EO(N).\ntemplate <typename Type, typename\
    \ Func = std::function<bool(Type, Type)> >\nstd::pair<std::vector<int>, std::vector<int>\
    \ > calc_viewing_range(\n    const std::vector<Type> &h,\n    const Func &comp\
    \ = [](const Type &a, const Type &b) -> bool { return a <= b; }) {\n    const\
    \ int n = h.size();\n    std::vector<int> left(n, 0), right(n, n);\n    // left\
    \ side.\n    std::stack<std::pair<Type, int> > stack_left;\n    for(int i = 0;\
    \ i < n; ++i) {\n        while(!stack_left.empty() and comp(stack_left.top().first,\
    \ h[i])) stack_left.pop();\n        if(!stack_left.empty()) left[i] = stack_left.top().second\
    \ + 1;\n        stack_left.push({h[i], i});\n    }\n    // right side.\n    std::stack<std::pair<Type,\
    \ int> > stack_right;\n    for(int i = n - 1; i >= 0; --i) {\n        while(!stack_right.empty()\
    \ and comp(stack_right.top().first, h[i])) stack_right.pop();\n        if(!stack_right.empty())\
    \ right[i] = stack_right.top().second;\n        stack_right.push({h[i], i});\n\
    \    }\n    return {left, right};\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Others/calc_viewing_range.hpp
  requiredBy: []
  timestamp: '2023-07-26 16:38:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Others/calc_viewing_range.hpp
layout: document
redirect_from:
- /library/src/Others/calc_viewing_range.hpp
- /library/src/Others/calc_viewing_range.hpp.html
title: src/Others/calc_viewing_range.hpp
---
