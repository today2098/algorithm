---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/Tree/double_sweep.hpp
    title: "Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
  bundledCode: "#line 1 \"test/aoj-GRL_5_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#line 1 \"src/Graph/Tree/double_sweep.hpp\"\
    \n\n\n\n/**\n * @brief Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09\n * @docs\
    \ docs/Graph/Tree/double_sweep.md\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <queue>\n#include <tuple>\n#line 15 \"src/Graph/Tree/double_sweep.hpp\"\
    \n\nnamespace algorithm {\n\n// \u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\
    \uFF0EO(|V|).\nstd::tuple<int, int, int> double_sweep(const std::vector<std::vector<int>\
    \ > &g, int rt = 0) {\n    const int vn = g.size();\n    assert(vn == 0 or (0\
    \ <= rt and rt < vn));\n    if(vn == 0) return {-1, -1, -1};\n    int furthest_node;\n\
    \    std::vector<int> d(vn);\n    std::queue<int> que;\n    auto bfs = [&](int\
    \ s) -> void {\n        furthest_node = s;\n        std::fill(d.begin(), d.end(),\
    \ -1);\n        d[s] = 0;\n        que.push(s);\n        while(!que.empty()) {\n\
    \            int u = que.front();\n            que.pop();\n            furthest_node\
    \ = u;\n            for(int v : g[u]) {\n                assert(0 <= v and v <\
    \ vn);\n                if(d[v] != -1) continue;\n                d[v] = d[u]\
    \ + 1;\n                que.push(v);\n            }\n        }\n    };\n    bfs(rt);\n\
    \    rt = furthest_node;\n    bfs(rt);\n    return {d[furthest_node], rt, furthest_node};\
    \  // tuple of (diameter, endpoint1, endpoint2).\n}\n\n// \u91CD\u307F\u4ED8\u304D\
    \u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\uFF0EO(|V|).\ntemplate <typename\
    \ Type>\nstd::tuple<Type, int, int> double_sweep(const std::vector<std::vector<std::pair<int,\
    \ Type> > > &g, int rt = 0) {\n    const int vn = g.size();\n    assert(vn ==\
    \ 0 or (0 <= rt and rt < vn));\n    if(vn == 0) return {-1, -1, -1};\n    int\
    \ furthest_node;\n    std::vector<Type> d(vn);\n    std::queue<int> que;\n   \
    \ std::vector<bool> seen(vn);\n    auto bfs = [&](int s) -> void {\n        furthest_node\
    \ = s;\n        d[s] = 0;\n        que.push(s);\n        std::fill(seen.begin(),\
    \ seen.end(), false);\n        while(!que.empty()) {\n            int u = que.front();\n\
    \            que.pop();\n            seen[u] = true;\n            if(d[u] > d[furthest_node])\
    \ furthest_node = u;\n            for(const auto &[v, cost] : g[u]) {\n      \
    \          assert(0 <= v and v < vn);\n                if(seen[v]) continue;\n\
    \                d[v] = d[u] + cost;\n                que.emplace(v);\n      \
    \      }\n        }\n    };\n    bfs(rt);\n    rt = furthest_node;\n    bfs(rt);\n\
    \    return {d[furthest_node], rt, furthest_node};  // tuple of (diameter, endpoint1,\
    \ endpoint2).\n}\n\n}  // namespace algorithm\n\n\n#line 8 \"test/aoj-GRL_5_A.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::vector<std::vector<std::pair<int,\
    \ int> > > g(n);\n    for(int i = 0; i < n - 1; ++i) {\n        int s, t;\n  \
    \      int w;\n        std::cin >> s >> t >> w;\n\n        g[s].emplace_back(t,\
    \ w);\n        g[t].emplace_back(s, w);\n    }\n\n    auto &&[ans, _, __] = algorithm::double_sweep(g);\n\
    \    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"\
    ../src/Graph/Tree/double_sweep.hpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n\n    std::vector<std::vector<std::pair<int, int> > > g(n);\n    for(int\
    \ i = 0; i < n - 1; ++i) {\n        int s, t;\n        int w;\n        std::cin\
    \ >> s >> t >> w;\n\n        g[s].emplace_back(t, w);\n        g[t].emplace_back(s,\
    \ w);\n    }\n\n    auto &&[ans, _, __] = algorithm::double_sweep(g);\n    std::cout\
    \ << ans << std::endl;\n}\n"
  dependsOn:
  - src/Graph/Tree/double_sweep.hpp
  isVerificationFile: true
  path: test/aoj-GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2024-05-08 10:38:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-GRL_5_A.test.cpp
- /verify/test/aoj-GRL_5_A.test.cpp.html
title: test/aoj-GRL_5_A.test.cpp
---
