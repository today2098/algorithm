---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/big_integer.md
    document_title: "\u591A\u500D\u9577\u6574\u6570"
    links: []
  bundledCode: "#line 1 \"src/Math/big_integer.hpp\"\n\n\n\n/**\n * @brief \u591A\u500D\
    \u9577\u6574\u6570\n * @docs docs/Math/big_integer.md\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cstdint>\n#include <iostream>\n#include <string>\n\
    #include <vector>\n\nnamespace algorithm {\n\nclass BigInteger {\n    std::vector<int32_t>\
    \ m_digit;\n\npublic:\n    BigInteger() : m_digit(1, 0) {}\n    explicit BigInteger(const\
    \ std::string &s) : m_digit(s.size() + 1, 0) {\n        if(s.size() == 0) return;\n\
    \        assert(('0' <= s[0] and s[0] <= '9') or s[0] == '-');\n        const\
    \ int n = s.size();\n        for(int i = 0; i < n - 1; ++i) {\n            assert('0'\
    \ <= s[n - 1 - i] and s[n - 1 - i] <= '9');\n            m_digit[i] = s[n - 1\
    \ - i] - '0';\n        }\n        if(s[0] != '-') m_digit[n - 1] = s[0] - '0';\n\
    \        while(m_digit.size() >= 2 and m_digit.back() == 0) m_digit.pop_back();\n\
    \        if(s[0] == '-') m_digit.back() = -m_digit.back();\n    }\n    explicit\
    \ BigInteger(long long a) {\n        bool is_minus = false;\n        if(a < 0)\
    \ is_minus = true, a = -a;\n        while(a > 0) {\n            m_digit.push_back(a\
    \ % 10);\n            a /= 10;\n        }\n        if(m_digit.empty()) m_digit.assign(1,\
    \ 0);\n        if(is_minus) m_digit.back() = -m_digit.back();\n    };\n\n    //\
    \ \u6841\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    int size() const { return m_digit.size();\
    \ }\n\n    friend std::ostream &operator<<(std::ostream &os, const BigInteger\
    \ &rhs) {\n        for(auto itr = rhs.m_digit.crbegin(); itr != rhs.m_digit.crend();\
    \ ++itr) os << *itr;\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_BIG_INTEGER_HPP\n#define ALGORITHM_BIG_INTEGER_HPP 1\n\n\
    /**\n * @brief \u591A\u500D\u9577\u6574\u6570\n * @docs docs/Math/big_integer.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n#include\
    \ <iostream>\n#include <string>\n#include <vector>\n\nnamespace algorithm {\n\n\
    class BigInteger {\n    std::vector<int32_t> m_digit;\n\npublic:\n    BigInteger()\
    \ : m_digit(1, 0) {}\n    explicit BigInteger(const std::string &s) : m_digit(s.size()\
    \ + 1, 0) {\n        if(s.size() == 0) return;\n        assert(('0' <= s[0] and\
    \ s[0] <= '9') or s[0] == '-');\n        const int n = s.size();\n        for(int\
    \ i = 0; i < n - 1; ++i) {\n            assert('0' <= s[n - 1 - i] and s[n - 1\
    \ - i] <= '9');\n            m_digit[i] = s[n - 1 - i] - '0';\n        }\n   \
    \     if(s[0] != '-') m_digit[n - 1] = s[0] - '0';\n        while(m_digit.size()\
    \ >= 2 and m_digit.back() == 0) m_digit.pop_back();\n        if(s[0] == '-') m_digit.back()\
    \ = -m_digit.back();\n    }\n    explicit BigInteger(long long a) {\n        bool\
    \ is_minus = false;\n        if(a < 0) is_minus = true, a = -a;\n        while(a\
    \ > 0) {\n            m_digit.push_back(a % 10);\n            a /= 10;\n     \
    \   }\n        if(m_digit.empty()) m_digit.assign(1, 0);\n        if(is_minus)\
    \ m_digit.back() = -m_digit.back();\n    };\n\n    // \u6841\u6570\u3092\u8FD4\
    \u3059\uFF0EO(1).\n    int size() const { return m_digit.size(); }\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const BigInteger &rhs) {\n      \
    \  for(auto itr = rhs.m_digit.crbegin(); itr != rhs.m_digit.crend(); ++itr) os\
    \ << *itr;\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/big_integer.hpp
  requiredBy: []
  timestamp: '2023-09-27 16:10:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/big_integer.hpp
layout: document
redirect_from:
- /library/src/Math/big_integer.hpp
- /library/src/Math/big_integer.hpp.html
title: "\u591A\u500D\u9577\u6574\u6570"
---
