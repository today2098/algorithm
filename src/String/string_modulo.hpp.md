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
  bundledCode: "#line 1 \"src/String/string_modulo.hpp\"\n\n\n\n#include <cassert>\n\
    #include <string>\n\nnamespace algorithm {\n\n// \u6587\u5B57\u5217\u5270\u4F59\
    \uFF0EO(|S|).\ntemplate <typename Type>\nType string_modulo(const std::string\
    \ &s, const Type mod) {\n    const int n = s.size();\n    long long res = 0;\n\
    \    for(int i = 0; i < n; ++i) {\n        assert('0' <= s[i] and s[i] <= '9');\n\
    \        res = (10 * res + (s[i] - '0')) % mod;\n    }\n    return res;\n}\n\n\
    }  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_STRING_MODULO_HPP\n#define ALGORITHM_STRING_MODULO_HPP\
    \ 1\n\n#include <cassert>\n#include <string>\n\nnamespace algorithm {\n\n// \u6587\
    \u5B57\u5217\u5270\u4F59\uFF0EO(|S|).\ntemplate <typename Type>\nType string_modulo(const\
    \ std::string &s, const Type mod) {\n    const int n = s.size();\n    long long\
    \ res = 0;\n    for(int i = 0; i < n; ++i) {\n        assert('0' <= s[i] and s[i]\
    \ <= '9');\n        res = (10 * res + (s[i] - '0')) % mod;\n    }\n    return\
    \ res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/String/string_modulo.hpp
  requiredBy: []
  timestamp: '2023-04-06 12:37:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/String/string_modulo.hpp
layout: document
redirect_from:
- /library/src/String/string_modulo.hpp
- /library/src/String/string_modulo.hpp.html
title: src/String/string_modulo.hpp
---
