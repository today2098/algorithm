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
  bundledCode: "#line 1 \"src/Graph/ford_fulkerson.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\ntemplate <typename T>  // T:\u5BB9\u91CF\u306E\u578B.\nclass FordFulkerson\
    \ {\n    struct Edge {\n        int to;   // to:=(\u884C\u304D\u5148\u30CE\u30FC\
    \u30C9).\n        T cap;    // cap:=(\u5BB9\u91CF).\n        int rev;  // rev:=(\u9006\
    \u8FBA\u30A4\u30C6\u30EC\u30FC\u30BF).\n        explicit Edge(int to_, T cap_,\
    \ int rev_) : to(to_), cap(cap_), rev(rev_) {}\n    };\n\n    std::vector<std::vector<Edge>\
    \ > m_g;      // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n    std::vector<std::pair<int, int> > m_pos;  // m_pos[i]:=(i\u756A\u76EE\u306E\
    \u8FBA\u60C5\u5831). pair of (from, index).\n\n    // \u5897\u52A0\u30D1\u30B9\
    \u3092\u63A2\u3059\uFF0E\n    T dfs(int v, int t, T flow, std::vector<bool> &seen)\
    \ {\n        if(v == t) return flow;\n        seen[v] = true;\n        for(Edge\
    \ &e : m_g[v]) {\n            if(e.cap > 0 and !seen[e.to]) {\n              \
    \  T res = dfs(e.to, t, std::min(flow, e.cap), seen);\n                if(res\
    \ > 0) {\n                    e.cap -= res;\n                    m_g[e.to][e.rev].cap\
    \ += res;\n                    return res;\n                }\n            }\n\
    \        }\n        return 0;\n    }\n\npublic:\n    FordFulkerson() : FordFulkerson(0)\
    \ {}\n    explicit FordFulkerson(size_t vn) : m_g(vn) {}\n\n    static constexpr\
    \ T infinity() { return std::numeric_limits<T>::max(); }\n    // \u30CE\u30FC\u30C9\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const { return m_g.size(); }\n\
    \    // \u8FBA\u6570\u3092\u8FD4\u3059.\n    int size() const { return m_pos.size();\
    \ }\n    // \u5BB9\u91CFcap\u306E\u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\
    \uFF0E\n    int add_edge(int from, int to, T cap) {\n        assert(0 <= from\
    \ and from < order());\n        assert(0 <= to and to < order());\n        assert(cap\
    \ >= 0);\n        int idx_from = m_g[from].size(), idx_to = m_g[to].size();\n\
    \        if(from == to) idx_to++;\n        m_g[from].emplace_back(to, cap, idx_to);\n\
    \        m_g[to].emplace_back(from, 0, idx_from);\n        m_pos.emplace_back(from,\
    \ idx_from);\n        return size() - 1;\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089t\u3078\u306E\u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\uFF0EO(F*|E|).\n\
    \    T max_flow(int s, int t) { return max_flow(s, t, infinity()); }\n    T max_flow(int\
    \ s, int t, T flow) {\n        assert(0 <= s and s < order());\n        assert(0\
    \ <= t and t < order());\n        T res = 0;\n        std::vector<bool> seen(order());\
    \  // seen[v]:=(DFS\u306B\u304A\u3044\u3066\u30CE\u30FC\u30C9v\u3092\u8ABF\u3079\
    \u305F\u304B).\n        while(res < flow) {\n            std::fill(seen.begin(),\
    \ seen.end(), false);\n            T tmp = dfs(s, t, flow - res, seen);\n    \
    \        if(tmp == 0) break;\n            res += tmp;\n        }\n        return\
    \ res;\n    }\n    // \u8FBA\u306E\u60C5\u5831\u3092\u8FD4\u3059\uFF0E\n    std::tuple<int,\
    \ int, T, T> get_edge(int i) const {\n        assert(0 <= i and i < size());\n\
    \        const auto &[from, idx] = m_pos[i];\n        const Edge &e = m_g[from][idx];\n\
    \        return {from, e.to, e.cap + m_g[e.to][e.rev].cap, m_g[e.to][e.rev].cap};\
    \  // tuple of (from, to, cap, flow).\n    }\n    // \u6700\u5C0F\u30AB\u30C3\u30C8\
    \u306B\u3088\u3063\u3066\uFF0C\u5404\u30CE\u30FC\u30C9\u3092\u5206\u3051\u308B\
    \uFF0E\n    std::vector<bool> min_cut(int s) const {\n        assert(0 <= s and\
    \ s < order());\n        std::vector<bool> res(order(), false);\n        std::queue<int>\
    \ que;\n        que.push(s);\n        while(!que.empty()) {\n            int v\
    \ = que.front();\n            que.pop();\n            if(res[v]) continue;\n \
    \           res[v] = true;\n            for(const Edge &e : m_g[v]) {\n      \
    \          if(e.cap > 0 and !res[e.to]) que.push(e.to);\n            }\n     \
    \   }\n        return res;\n    }\n    void reset() {\n        for(const auto\
    \ &[from, idx] : m_pos) {\n            Edge &e = m_g[from][idx];\n           \
    \ e.cap = e.cap + m_g[e.to][e.rev].cap;\n            m_g[e.to][e.rev].cap = 0;\n\
    \        }\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_FORD_FULKERSON_HPP\n#define ALGORITHM_FORD_FULKERSON_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \nnamespace algorithm {\n\ntemplate <typename T>  // T:\u5BB9\u91CF\u306E\u578B\
    .\nclass FordFulkerson {\n    struct Edge {\n        int to;   // to:=(\u884C\u304D\
    \u5148\u30CE\u30FC\u30C9).\n        T cap;    // cap:=(\u5BB9\u91CF).\n      \
    \  int rev;  // rev:=(\u9006\u8FBA\u30A4\u30C6\u30EC\u30FC\u30BF).\n        explicit\
    \ Edge(int to_, T cap_, int rev_) : to(to_), cap(cap_), rev(rev_) {}\n    };\n\
    \n    std::vector<std::vector<Edge> > m_g;      // m_g[v][]:=(\u30CE\u30FC\u30C9\
    v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8).\n    std::vector<std::pair<int, int> >\
    \ m_pos;  // m_pos[i]:=(i\u756A\u76EE\u306E\u8FBA\u60C5\u5831). pair of (from,\
    \ index).\n\n    // \u5897\u52A0\u30D1\u30B9\u3092\u63A2\u3059\uFF0E\n    T dfs(int\
    \ v, int t, T flow, std::vector<bool> &seen) {\n        if(v == t) return flow;\n\
    \        seen[v] = true;\n        for(Edge &e : m_g[v]) {\n            if(e.cap\
    \ > 0 and !seen[e.to]) {\n                T res = dfs(e.to, t, std::min(flow,\
    \ e.cap), seen);\n                if(res > 0) {\n                    e.cap -=\
    \ res;\n                    m_g[e.to][e.rev].cap += res;\n                   \
    \ return res;\n                }\n            }\n        }\n        return 0;\n\
    \    }\n\npublic:\n    FordFulkerson() : FordFulkerson(0) {}\n    explicit FordFulkerson(size_t\
    \ vn) : m_g(vn) {}\n\n    static constexpr T infinity() { return std::numeric_limits<T>::max();\
    \ }\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order()\
    \ const { return m_g.size(); }\n    // \u8FBA\u6570\u3092\u8FD4\u3059.\n    int\
    \ size() const { return m_pos.size(); }\n    // \u5BB9\u91CFcap\u306E\u6709\u5411\
    \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\uFF0E\n    int add_edge(int from, int to,\
    \ T cap) {\n        assert(0 <= from and from < order());\n        assert(0 <=\
    \ to and to < order());\n        assert(cap >= 0);\n        int idx_from = m_g[from].size(),\
    \ idx_to = m_g[to].size();\n        if(from == to) idx_to++;\n        m_g[from].emplace_back(to,\
    \ cap, idx_to);\n        m_g[to].emplace_back(from, 0, idx_from);\n        m_pos.emplace_back(from,\
    \ idx_from);\n        return size() - 1;\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089t\u3078\u306E\u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\uFF0EO(F*|E|).\n\
    \    T max_flow(int s, int t) { return max_flow(s, t, infinity()); }\n    T max_flow(int\
    \ s, int t, T flow) {\n        assert(0 <= s and s < order());\n        assert(0\
    \ <= t and t < order());\n        T res = 0;\n        std::vector<bool> seen(order());\
    \  // seen[v]:=(DFS\u306B\u304A\u3044\u3066\u30CE\u30FC\u30C9v\u3092\u8ABF\u3079\
    \u305F\u304B).\n        while(res < flow) {\n            std::fill(seen.begin(),\
    \ seen.end(), false);\n            T tmp = dfs(s, t, flow - res, seen);\n    \
    \        if(tmp == 0) break;\n            res += tmp;\n        }\n        return\
    \ res;\n    }\n    // \u8FBA\u306E\u60C5\u5831\u3092\u8FD4\u3059\uFF0E\n    std::tuple<int,\
    \ int, T, T> get_edge(int i) const {\n        assert(0 <= i and i < size());\n\
    \        const auto &[from, idx] = m_pos[i];\n        const Edge &e = m_g[from][idx];\n\
    \        return {from, e.to, e.cap + m_g[e.to][e.rev].cap, m_g[e.to][e.rev].cap};\
    \  // tuple of (from, to, cap, flow).\n    }\n    // \u6700\u5C0F\u30AB\u30C3\u30C8\
    \u306B\u3088\u3063\u3066\uFF0C\u5404\u30CE\u30FC\u30C9\u3092\u5206\u3051\u308B\
    \uFF0E\n    std::vector<bool> min_cut(int s) const {\n        assert(0 <= s and\
    \ s < order());\n        std::vector<bool> res(order(), false);\n        std::queue<int>\
    \ que;\n        que.push(s);\n        while(!que.empty()) {\n            int v\
    \ = que.front();\n            que.pop();\n            if(res[v]) continue;\n \
    \           res[v] = true;\n            for(const Edge &e : m_g[v]) {\n      \
    \          if(e.cap > 0 and !res[e.to]) que.push(e.to);\n            }\n     \
    \   }\n        return res;\n    }\n    void reset() {\n        for(const auto\
    \ &[from, idx] : m_pos) {\n            Edge &e = m_g[from][idx];\n           \
    \ e.cap = e.cap + m_g[e.to][e.rev].cap;\n            m_g[e.to][e.rev].cap = 0;\n\
    \        }\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2023-08-22 14:48:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/ford_fulkerson.hpp
layout: document
redirect_from:
- /library/src/Graph/ford_fulkerson.hpp
- /library/src/Graph/ford_fulkerson.hpp.html
title: src/Graph/ford_fulkerson.hpp
---