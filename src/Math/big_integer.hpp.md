---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Utils/debug.hpp
    title: "\u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED"
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
    #include <cassert>\n#include <cmath>\n#include <cstdint>\n#include <iomanip>\n\
    #include <iostream>\n#include <sstream>\n#include <string>\n#include <string_view>\n\
    #include <vector>\n\n#line 1 \"src/Utils/debug.hpp\"\n\n\n\n/**\n * @brief \u30C7\
    \u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED\n * @docs docs/Utils/debug.md\n\
    \ */\n\n#line 10 \"src/Utils/debug.hpp\"\n#include <iterator>\n#include <queue>\n\
    #include <stack>\n#line 15 \"src/Utils/debug.hpp\"\n#include <tuple>\n#include\
    \ <type_traits>\n#include <utility>\n\n// #define DEBUG\n\n#ifdef DEBUG\n\n#define\
    \ debug(...) algorithm::debug::debug_internal(__LINE__, #__VA_ARGS__, __VA_ARGS__)\n\
    \nnamespace algorithm {\n\nnamespace debug {\n\nconstexpr std::ostream &os = std::cerr;\n\
    \nstruct has_iterator_impl {\n    template <class T>\n    static constexpr std::true_type\
    \ check(typename T::iterator *);\n\n    template <class T>\n    static constexpr\
    \ std::false_type check(...);\n};\n\ntemplate <class T>\nclass has_iterator :\
    \ public decltype(has_iterator_impl::check<T>(nullptr)) {};\n\n// Prototype declaration.\n\
    void print(const std::string &s);\nvoid print(std::string_view s);\ntemplate <typename\
    \ T, typename U>\nvoid print(const std::pair<T, U> &p);\ntemplate <class T, std::size_t...\
    \ Idxes>\nvoid print_tuple(const T &t, std::index_sequence<Idxes...>);\ntemplate\
    \ <typename... Ts>\nvoid print(const std::tuple<Ts...> &t);\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st);\ntemplate <typename... Ts>\nvoid\
    \ print(const std::queue<Ts...> &que);\ntemplate <typename... Ts>\nvoid print(const\
    \ std::priority_queue<Ts...> &pque);\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int line, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { os << s; }\n\nvoid print(std::string_view\
    \ s) { os << s; }\n\ntemplate <typename T, typename U>\nvoid print(const std::pair<T,\
    \ U> &p) {\n    os << \"{\";\n    print(p.first);\n    os << \", \";\n    print(p.second);\n\
    \    os << \"}\";\n}\n\ntemplate <class T, std::size_t... Idxes>\nvoid print_tuple(const\
    \ T &t, std::index_sequence<Idxes...>) {\n    os << \"{\";\n    ((os << (Idxes\
    \ == 0 ? \"\" : \", \"), print(std::get<Idxes>(t))), ...);\n    os << \"}\";\n\
    }\n\ntemplate <typename... Ts>\nvoid print(const std::tuple<Ts...> &t) {\n   \
    \ print_tuple(t, std::make_index_sequence<sizeof...(Ts)>());\n}\n\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st) {\n    std::stack<Ts...> tmp =\
    \ st;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <typename... Ts>\nvoid print(const std::queue<Ts...> &que)\
    \ {\n    std::queue<Ts...> tmp = que;\n    os << \"[\";\n    while(!tmp.empty())\
    \ {\n        print(tmp.front());\n        tmp.pop();\n        if(!tmp.empty())\
    \ os << \" \";\n    }\n    os << \"]\";\n}\n\ntemplate <typename... Ts>\nvoid\
    \ print(const std::priority_queue<Ts...> &pque) {\n    std::priority_queue<Ts...>\
    \ tmp = pque;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &v) {\n    os << \"[\";\n    for(auto itr\
    \ = std::cbegin(v); itr != std::cend(v); ++itr) {\n        if(itr != std::cbegin(v))\
    \ os << \" \";\n        print(*itr);\n    }\n    os << \"]\";\n}\n\ntemplate <typename\
    \ T, typename std::enable_if_t<!has_iterator<T>::value, bool> = false>\nvoid print(const\
    \ T &elem) { os << elem; }\n\ntemplate <typename T, typename... Args>\nvoid debug_internal(int\
    \ line, std::string_view context, T &&first, Args &&...args) {\n    constexpr\
    \ const char *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr\
    \ const char *close_bracket = (sizeof...(args) == 0 ? \"\" : \")\");\n    os <<\
    \ \"[L\" << line << \"] \" << open_bracket << context << close_bracket << \":\
    \ \" << open_bracket;\n    print(std::forward<T>(first));\n    ((os << \", \"\
    , print(std::forward<Args>(args))), ...);\n    os << close_bracket << std::endl;\n\
    }\n\n}  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n\n#line 21 \"src/Math/big_integer.hpp\"\n\n\
    namespace algorithm {\n\nclass BigInteger {\n    static constexpr int BASE_DIGIT\
    \ = 8;\n    static constexpr int64_t BASE[BASE_DIGIT + 1] = {1, 10, 100, 1'000,\
    \ 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000};\n\n    bool m_sign;  \
    \                 // m_sign:=(\u7B26\u53F7\u304C\u8CA0\u304B).\n    std::vector<int64_t>\
    \ m_digit;  // m_digit[k]:=(BASE_DIGIT*k+1\u6841\u76EE\u306E\u6570).\n\n    void\
    \ convert(std::string_view s) {\n        if(s.empty()) {\n            m_digit.assign(1,\
    \ 0);\n            return;\n        }\n        if(s[0] == '-') {\n           \
    \ assert(s.substr(1) != \"\");\n            convert(s.substr(1));\n          \
    \  if(m_digit.back() > 0) m_sign = true;\n            return;\n        }\n   \
    \     m_sign = false;\n        const int n = s.size();\n        const int sz =\
    \ (n + BASE_DIGIT - 1) / BASE_DIGIT;\n        m_digit.assign(sz, 0);\n       \
    \ for(int i = 0; i < sz; ++i) {\n            int offset = BASE_DIGIT * i;\n  \
    \          for(int j = 0; j < BASE_DIGIT and offset + j < n; ++j) {\n        \
    \        assert('0' <= s[n - 1 - (offset + j)] and s[n - 1 - (offset + j)] <=\
    \ '9');\n                m_digit[i] += BASE[j] * (s[n - 1 - (offset + j)] - '0');\n\
    \            }\n        }\n        while(m_digit.size() >= 2 and m_digit.back()\
    \ == 0) m_digit.pop_back();\n    }\n    void addition(const std::vector<int64_t>\
    \ &rhs) {\n        const int sz = rhs.size();\n        if(sz > m_digit.size())\
    \ m_digit.resize(sz, 0);\n        for(int i = 0; i < sz; ++i) m_digit[i] += rhs[i];\n\
    \    }\n    void subtraction(const std::vector<int64_t> &rhs) {\n        const\
    \ int sz = rhs.size();\n        if(sz > m_digit.size()) m_digit.resize(sz, 0);\n\
    \        for(int i = 0; i < sz; ++i) m_digit[i] -= rhs[i];\n    }\n    void carry()\
    \ {\n        auto itr = std::find_if(m_digit.crbegin(), m_digit.crend(), [](int64_t\
    \ x) -> bool { return x != 0; });\n        if(itr != m_digit.crend() and *itr\
    \ < 0) {\n            m_sign = !m_sign;\n            for(int64_t &elem : m_digit)\
    \ elem = -elem;\n        }\n        for(int i = 0; i < m_digit.size(); ++i) {\n\
    \            if(m_digit[i] < 0) {\n                int64_t c = (-m_digit[i] -\
    \ 1) / BASE[BASE_DIGIT] + 1;\n                m_digit[i] += BASE[BASE_DIGIT] *\
    \ c;\n                m_digit[i + 1] -= c;\n            } else if(10 <= m_digit[i])\
    \ {\n                int64_t c = m_digit[i] / BASE[BASE_DIGIT];\n            \
    \    m_digit[i] -= BASE[BASE_DIGIT] * c;\n                if(i + 1 < m_digit.size())\
    \ m_digit[i + 1] += c;\n                else m_digit.push_back(c);\n         \
    \   }\n        }\n        while(m_digit.size() >= 2 and m_digit.back() == 0) m_digit.pop_back();\n\
    \    }\n\npublic:\n    BigInteger() : m_sign(false), m_digit(1, 0) {}\n    explicit\
    \ BigInteger(int64_t a) : m_sign(a < 0), m_digit(1, std::abs(a)) {}\n    explicit\
    \ BigInteger(std::string_view s) : m_sign(false) {\n        convert(s);\n    }\n\
    \n    BigInteger &operator+=(const BigInteger &rhs) {\n        if(rhs.m_sign ==\
    \ m_sign) addition(rhs.m_digit);\n        else subtraction(rhs.m_digit);\n   \
    \     carry();\n        return *this;\n    }\n    BigInteger &operator-=(const\
    \ BigInteger &rhs) {\n        if(rhs.m_sign == m_sign) subtraction(rhs.m_digit);\n\
    \        else addition(rhs.m_digit);\n        carry();\n        return *this;\n\
    \    }\n    friend std::istream &operator>>(std::istream &is, BigInteger &rhs)\
    \ {\n        std::string s;\n        is >> s;\n        rhs.convert(s);\n     \
    \   return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ BigInteger &rhs) {\n        os << (rhs.m_sign ? \"-\" : \"\") << rhs.m_digit.back();\n\
    \        for(auto itr = rhs.m_digit.crbegin() + 1; itr < rhs.m_digit.crend();\
    \ ++itr) os << std::setfill('0') << std::right << std::setw(BASE_DIGIT) << *itr;\n\
    \        return os;\n    }\n\n    // \u7B26\u53F7\u304C\u8CA0\u304B\u5224\u5B9A\
    \u3059\u308B\uFF0EO(1).\n    bool sign() const { return m_sign; }\n    // \u6841\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int digit_number() const {\n        int res\
    \ = 1;\n        while(res < BASE_DIGIT and m_digit.back() >= BASE[res]) res++;\n\
    \        res += BASE_DIGIT * (m_digit.size() - 1);\n        return res;\n    }\n\
    \    std::string to_string() const {\n        std::ostringstream oss;\n      \
    \  oss << *this;\n        return oss.str();\n    };\n};\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_BIG_INTEGER_HPP\n#define ALGORITHM_BIG_INTEGER_HPP 1\n\n\
    /**\n * @brief \u591A\u500D\u9577\u6574\u6570\n * @docs docs/Math/big_integer.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <cstdint>\n\
    #include <iomanip>\n#include <iostream>\n#include <sstream>\n#include <string>\n\
    #include <string_view>\n#include <vector>\n\n#include \"../Utils/debug.hpp\"\n\
    \nnamespace algorithm {\n\nclass BigInteger {\n    static constexpr int BASE_DIGIT\
    \ = 8;\n    static constexpr int64_t BASE[BASE_DIGIT + 1] = {1, 10, 100, 1'000,\
    \ 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000};\n\n    bool m_sign;  \
    \                 // m_sign:=(\u7B26\u53F7\u304C\u8CA0\u304B).\n    std::vector<int64_t>\
    \ m_digit;  // m_digit[k]:=(BASE_DIGIT*k+1\u6841\u76EE\u306E\u6570).\n\n    void\
    \ convert(std::string_view s) {\n        if(s.empty()) {\n            m_digit.assign(1,\
    \ 0);\n            return;\n        }\n        if(s[0] == '-') {\n           \
    \ assert(s.substr(1) != \"\");\n            convert(s.substr(1));\n          \
    \  if(m_digit.back() > 0) m_sign = true;\n            return;\n        }\n   \
    \     m_sign = false;\n        const int n = s.size();\n        const int sz =\
    \ (n + BASE_DIGIT - 1) / BASE_DIGIT;\n        m_digit.assign(sz, 0);\n       \
    \ for(int i = 0; i < sz; ++i) {\n            int offset = BASE_DIGIT * i;\n  \
    \          for(int j = 0; j < BASE_DIGIT and offset + j < n; ++j) {\n        \
    \        assert('0' <= s[n - 1 - (offset + j)] and s[n - 1 - (offset + j)] <=\
    \ '9');\n                m_digit[i] += BASE[j] * (s[n - 1 - (offset + j)] - '0');\n\
    \            }\n        }\n        while(m_digit.size() >= 2 and m_digit.back()\
    \ == 0) m_digit.pop_back();\n    }\n    void addition(const std::vector<int64_t>\
    \ &rhs) {\n        const int sz = rhs.size();\n        if(sz > m_digit.size())\
    \ m_digit.resize(sz, 0);\n        for(int i = 0; i < sz; ++i) m_digit[i] += rhs[i];\n\
    \    }\n    void subtraction(const std::vector<int64_t> &rhs) {\n        const\
    \ int sz = rhs.size();\n        if(sz > m_digit.size()) m_digit.resize(sz, 0);\n\
    \        for(int i = 0; i < sz; ++i) m_digit[i] -= rhs[i];\n    }\n    void carry()\
    \ {\n        auto itr = std::find_if(m_digit.crbegin(), m_digit.crend(), [](int64_t\
    \ x) -> bool { return x != 0; });\n        if(itr != m_digit.crend() and *itr\
    \ < 0) {\n            m_sign = !m_sign;\n            for(int64_t &elem : m_digit)\
    \ elem = -elem;\n        }\n        for(int i = 0; i < m_digit.size(); ++i) {\n\
    \            if(m_digit[i] < 0) {\n                int64_t c = (-m_digit[i] -\
    \ 1) / BASE[BASE_DIGIT] + 1;\n                m_digit[i] += BASE[BASE_DIGIT] *\
    \ c;\n                m_digit[i + 1] -= c;\n            } else if(10 <= m_digit[i])\
    \ {\n                int64_t c = m_digit[i] / BASE[BASE_DIGIT];\n            \
    \    m_digit[i] -= BASE[BASE_DIGIT] * c;\n                if(i + 1 < m_digit.size())\
    \ m_digit[i + 1] += c;\n                else m_digit.push_back(c);\n         \
    \   }\n        }\n        while(m_digit.size() >= 2 and m_digit.back() == 0) m_digit.pop_back();\n\
    \    }\n\npublic:\n    BigInteger() : m_sign(false), m_digit(1, 0) {}\n    explicit\
    \ BigInteger(int64_t a) : m_sign(a < 0), m_digit(1, std::abs(a)) {}\n    explicit\
    \ BigInteger(std::string_view s) : m_sign(false) {\n        convert(s);\n    }\n\
    \n    BigInteger &operator+=(const BigInteger &rhs) {\n        if(rhs.m_sign ==\
    \ m_sign) addition(rhs.m_digit);\n        else subtraction(rhs.m_digit);\n   \
    \     carry();\n        return *this;\n    }\n    BigInteger &operator-=(const\
    \ BigInteger &rhs) {\n        if(rhs.m_sign == m_sign) subtraction(rhs.m_digit);\n\
    \        else addition(rhs.m_digit);\n        carry();\n        return *this;\n\
    \    }\n    friend std::istream &operator>>(std::istream &is, BigInteger &rhs)\
    \ {\n        std::string s;\n        is >> s;\n        rhs.convert(s);\n     \
    \   return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ BigInteger &rhs) {\n        os << (rhs.m_sign ? \"-\" : \"\") << rhs.m_digit.back();\n\
    \        for(auto itr = rhs.m_digit.crbegin() + 1; itr < rhs.m_digit.crend();\
    \ ++itr) os << std::setfill('0') << std::right << std::setw(BASE_DIGIT) << *itr;\n\
    \        return os;\n    }\n\n    // \u7B26\u53F7\u304C\u8CA0\u304B\u5224\u5B9A\
    \u3059\u308B\uFF0EO(1).\n    bool sign() const { return m_sign; }\n    // \u6841\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int digit_number() const {\n        int res\
    \ = 1;\n        while(res < BASE_DIGIT and m_digit.back() >= BASE[res]) res++;\n\
    \        res += BASE_DIGIT * (m_digit.size() - 1);\n        return res;\n    }\n\
    \    std::string to_string() const {\n        std::ostringstream oss;\n      \
    \  oss << *this;\n        return oss.str();\n    };\n};\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn:
  - src/Utils/debug.hpp
  isVerificationFile: false
  path: src/Math/big_integer.hpp
  requiredBy: []
  timestamp: '2023-09-30 18:36:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/big_integer.hpp
layout: document
redirect_from:
- /library/src/Math/big_integer.hpp
- /library/src/Math/big_integer.hpp.html
title: "\u591A\u500D\u9577\u6574\u6570"
---
## 概要

多倍長整数を扱う構造体．


## 参考文献

1. square1001. "超高速！多倍長整数の計算手法【前編：大きな数の四則計算を圧倒的な速度で！】". Qiita. <https://qiita.com/square1001/items/1aa12e04934b6e749962>.
