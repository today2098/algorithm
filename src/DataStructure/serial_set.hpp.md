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
  bundledCode: "#line 1 \"src/DataStructure/serial_set.hpp\"\n\n\n\n#include <cassert>\n\
    #include <iostream>\n#include <set>\n\nnamespace algorithm {\n\n// \u6574\u6570\
    \u306E\u96C6\u5408\u3092\u9023\u7D9A\u7BC4\u56F2\u3067\u7BA1\u7406\u3059\u308B\
    \u30C7\u30FC\u30BF\u69CB\u9020\uFF0E\ntemplate <typename T>\nclass SerialSet {\n\
    \    std::set<std::pair<T, T> > m_st;  // m_st:=(\u6574\u6570\u306E\u96C6\u5408\
    ). \u9023\u7D9A\u3059\u308B\u6574\u6570\u5217[l,r)\u3092pair(l,r)\u3067\u8868\u73FE\
    \u3059\u308B\uFF0E\n    T m_inf;\n\npublic:\n    explicit SerialSet(T inf = 1e9)\
    \ : m_inf(inf) {\n        m_st.emplace(-m_inf, -m_inf + 1);  // \u756A\u5175\u7528\
    \uFF0E\n        m_st.emplace(m_inf, m_inf + 1);    // \u3003\n    }\n\n    T infinity()\
    \ const { return m_inf; }\n    // \u7BC4\u56F2[l,r)\u306E\u6574\u6570\u3092\u633F\
    \u5165\u3059\u308B\uFF0EO(logN).\n    bool insert(T l, T r) {\n        assert(-m_inf\
    \ < l and l < r and r < m_inf);\n        auto itr1 = std::prev(m_st.lower_bound(std::pair<T,\
    \ T>(l + 1, l + 2)));\n        auto [l1, r1] = *itr1;\n        if(r <= r1) return\
    \ false;  // \u96C6\u5408\u306B\u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\
    \u308B\u5834\u5408\uFF0E\n        auto itr3 = m_st.lower_bound(std::pair<T, T>(r,\
    \ r + 1));\n        auto itr2 = std::prev(itr3);\n        auto [l2, r2] = *itr2;\n\
    \        auto [l3, r3] = *itr3;\n        if(l <= r1) l = l1;\n        else itr1++;\n\
    \        if(l3 <= r) {\n            m_st.erase(itr1, ++itr3);\n            m_st.emplace(l,\
    \ r3);\n        } else {\n            m_st.erase(itr1, itr3);\n            if(r\
    \ <= r2) m_st.emplace(l, r2);\n            else m_st.emplace(l, r);\n        }\n\
    \        return true;\n    }\n    // \u6574\u6570x\u3092\u633F\u5165\u3059\u308B\
    \uFF0EO(logN).\n    bool insert(T x) { return insert(x, x + 1); }\n    // \u7BC4\
    \u56F2[l,r)\u306E\u6574\u6570\u3092\u524A\u9664\u3059\u308B\uFF0EO(logN).\n  \
    \  bool erase(T l, T r) {\n        assert(-m_inf < l and l < r and r < m_inf);\n\
    \        auto itr1 = std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 2)));\n\
    \        auto itr3 = m_st.lower_bound(std::pair<T, T>(r, r + 1));\n        auto\
    \ itr2 = std::prev(itr3);\n        auto [l1, r1] = *itr1;\n        auto [l2, r2]\
    \ = *itr2;\n        if(l < r1) {\n            m_st.erase(itr1, itr3);\n      \
    \      if(l1 < l) m_st.emplace(l1, l);\n        } else {\n            if(itr1\
    \ == itr2) return false;  // \u96C6\u5408\u306B\u5168\u304F\u542B\u307E\u308C\u3066\
    \u3044\u306A\u3044\u5834\u5408\uFF0E\n            m_st.erase(++itr1, itr3);\n\
    \        }\n        if(r < r2) m_st.emplace(r, r2);\n        return true;\n  \
    \  }\n    // \u6574\u6570x\u3092\u524A\u9664\u3059\u308B\uFF0EO(logN).\n    bool\
    \ erase(T x) { return erase(x, x + 1); }\n    // \u7BC4\u56F2[l,r)\u306E\u6574\
    \u6570\u304C\u96C6\u5408\u306B\u5168\u3066\u542B\u307E\u308C\u308B\u304B\u5224\
    \u5B9A\u3059\u308B\uFF0EO(logN).\n    bool contains(T l, T r) const {\n      \
    \  assert(-m_inf < l and l < r and r <= m_inf);\n        const auto &[_, pr] =\
    \ *std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 2)));\n        return\
    \ r <= pr;\n    }\n    // \u6574\u6570x\u304C\u96C6\u5408\u306B\u542B\u307E\u308C\
    \u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(logN).\n    bool contains(T x) const\
    \ { return contains(x, x + 1); }\n    // \u96C6\u5408\u306B\u542B\u307E\u308C\u306A\
    \u3044x\u4EE5\u4E0A\u306E\u6574\u6570\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u5024\
    \ (MEX:Minimum EXcluded value) \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T mex(T\
    \ x) const {\n        assert(-m_inf < x and x < m_inf);\n        const auto &[_,\
    \ r] = *std::prev(m_st.lower_bound(std::pair<T, T>(x + 1, x + 2)));\n        return\
    \ (x < r ? r : x);\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const SerialSet &ob) {\n        for(auto itr = ob.m_st.cbegin(); itr !=\
    \ ob.m_st.cend(); ++itr) {\n            const auto &[l, r] = *itr;\n         \
    \   os << (itr == ob.m_st.cbegin() ? \"[\" : \" \") << \"[\" << l << \", \" <<\
    \ r << \")\";\n        }\n        os << \"]\";\n        return os;\n    }\n};\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_SERIAL_SET_HPP\n#define ALGORITHM_SERIAL_SET_HPP 1\n\n\
    #include <cassert>\n#include <iostream>\n#include <set>\n\nnamespace algorithm\
    \ {\n\n// \u6574\u6570\u306E\u96C6\u5408\u3092\u9023\u7D9A\u7BC4\u56F2\u3067\u7BA1\
    \u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\uFF0E\ntemplate <typename T>\n\
    class SerialSet {\n    std::set<std::pair<T, T> > m_st;  // m_st:=(\u6574\u6570\
    \u306E\u96C6\u5408). \u9023\u7D9A\u3059\u308B\u6574\u6570\u5217[l,r)\u3092pair(l,r)\u3067\
    \u8868\u73FE\u3059\u308B\uFF0E\n    T m_inf;\n\npublic:\n    explicit SerialSet(T\
    \ inf = 1e9) : m_inf(inf) {\n        m_st.emplace(-m_inf, -m_inf + 1);  // \u756A\
    \u5175\u7528\uFF0E\n        m_st.emplace(m_inf, m_inf + 1);    // \u3003\n   \
    \ }\n\n    T infinity() const { return m_inf; }\n    // \u7BC4\u56F2[l,r)\u306E\
    \u6574\u6570\u3092\u633F\u5165\u3059\u308B\uFF0EO(logN).\n    bool insert(T l,\
    \ T r) {\n        assert(-m_inf < l and l < r and r < m_inf);\n        auto itr1\
    \ = std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 2)));\n        auto\
    \ [l1, r1] = *itr1;\n        if(r <= r1) return false;  // \u96C6\u5408\u306B\u5B8C\
    \u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u5834\u5408\uFF0E\n        auto\
    \ itr3 = m_st.lower_bound(std::pair<T, T>(r, r + 1));\n        auto itr2 = std::prev(itr3);\n\
    \        auto [l2, r2] = *itr2;\n        auto [l3, r3] = *itr3;\n        if(l\
    \ <= r1) l = l1;\n        else itr1++;\n        if(l3 <= r) {\n            m_st.erase(itr1,\
    \ ++itr3);\n            m_st.emplace(l, r3);\n        } else {\n            m_st.erase(itr1,\
    \ itr3);\n            if(r <= r2) m_st.emplace(l, r2);\n            else m_st.emplace(l,\
    \ r);\n        }\n        return true;\n    }\n    // \u6574\u6570x\u3092\u633F\
    \u5165\u3059\u308B\uFF0EO(logN).\n    bool insert(T x) { return insert(x, x +\
    \ 1); }\n    // \u7BC4\u56F2[l,r)\u306E\u6574\u6570\u3092\u524A\u9664\u3059\u308B\
    \uFF0EO(logN).\n    bool erase(T l, T r) {\n        assert(-m_inf < l and l <\
    \ r and r < m_inf);\n        auto itr1 = std::prev(m_st.lower_bound(std::pair<T,\
    \ T>(l + 1, l + 2)));\n        auto itr3 = m_st.lower_bound(std::pair<T, T>(r,\
    \ r + 1));\n        auto itr2 = std::prev(itr3);\n        auto [l1, r1] = *itr1;\n\
    \        auto [l2, r2] = *itr2;\n        if(l < r1) {\n            m_st.erase(itr1,\
    \ itr3);\n            if(l1 < l) m_st.emplace(l1, l);\n        } else {\n    \
    \        if(itr1 == itr2) return false;  // \u96C6\u5408\u306B\u5168\u304F\u542B\
    \u307E\u308C\u3066\u3044\u306A\u3044\u5834\u5408\uFF0E\n            m_st.erase(++itr1,\
    \ itr3);\n        }\n        if(r < r2) m_st.emplace(r, r2);\n        return true;\n\
    \    }\n    // \u6574\u6570x\u3092\u524A\u9664\u3059\u308B\uFF0EO(logN).\n   \
    \ bool erase(T x) { return erase(x, x + 1); }\n    // \u7BC4\u56F2[l,r)\u306E\u6574\
    \u6570\u304C\u96C6\u5408\u306B\u5168\u3066\u542B\u307E\u308C\u308B\u304B\u5224\
    \u5B9A\u3059\u308B\uFF0EO(logN).\n    bool contains(T l, T r) const {\n      \
    \  assert(-m_inf < l and l < r and r <= m_inf);\n        const auto &[_, pr] =\
    \ *std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 2)));\n        return\
    \ r <= pr;\n    }\n    // \u6574\u6570x\u304C\u96C6\u5408\u306B\u542B\u307E\u308C\
    \u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(logN).\n    bool contains(T x) const\
    \ { return contains(x, x + 1); }\n    // \u96C6\u5408\u306B\u542B\u307E\u308C\u306A\
    \u3044x\u4EE5\u4E0A\u306E\u6574\u6570\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u5024\
    \ (MEX:Minimum EXcluded value) \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T mex(T\
    \ x) const {\n        assert(-m_inf < x and x < m_inf);\n        const auto &[_,\
    \ r] = *std::prev(m_st.lower_bound(std::pair<T, T>(x + 1, x + 2)));\n        return\
    \ (x < r ? r : x);\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const SerialSet &ob) {\n        for(auto itr = ob.m_st.cbegin(); itr !=\
    \ ob.m_st.cend(); ++itr) {\n            const auto &[l, r] = *itr;\n         \
    \   os << (itr == ob.m_st.cbegin() ? \"[\" : \" \") << \"[\" << l << \", \" <<\
    \ r << \")\";\n        }\n        os << \"]\";\n        return os;\n    }\n};\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/serial_set.hpp
  requiredBy: []
  timestamp: '2023-04-06 22:36:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/serial_set.hpp
layout: document
redirect_from:
- /library/src/DataStructure/serial_set.hpp
- /library/src/DataStructure/serial_set.hpp.html
title: src/DataStructure/serial_set.hpp
---
