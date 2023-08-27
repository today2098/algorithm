---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - "https://marycore.jp/prog/cpp/std-string-split/\uFF08\u53C2\u71672023.1.21\uFF09\
      ."
  bundledCode: "#line 1 \"src/String/split.hpp\"\n\n\n\n#include <sstream>\n#include\
    \ <string>\n#include <vector>\n\nnamespace algorithm {\n\n// \u6587\u5B57\u5217\
    \u5206\u5272\uFF0E\u6307\u5B9A\u306E\u6587\u5B57delim\u3067\u5206\u5272\u3059\u308B\
    \uFF0E\nstd::vector<std::string> split(std::string s, char delim, bool erace_empty\
    \ = true) {\n    s = s + std::string({delim});\n    std::vector<std::string> res;\n\
    \    std::stringstream ss(s);\n    std::string item;\n    while(std::getline(ss,\
    \ item, delim)) {\n        if(!item.empty() or !erace_empty) res.push_back(item);\n\
    \    }\n    return res;\n}\n\n// \u6587\u5B57\u5217\u5206\u5272\uFF0E\u6307\u5B9A\
    \u306E\u6587\u5B57\u5217delim\u3067\u5206\u5272\u3059\u308B\uFF0E\nstd::vector<std::string>\
    \ split(const std::string &s, const std::string &delim, bool erace_empty = true)\
    \ {\n    std::vector<std::string> res;\n    const auto length = delim.size();\n\
    \    auto offset = std::string::size_type(0);\n    while(1) {\n        auto pos\
    \ = s.find(delim, offset);\n        if(pos == std::string::npos) {\n         \
    \   auto &&item = s.substr(offset);\n            if(!item.empty() or !erace_empty)\
    \ res.push_back(item);\n            break;\n        }\n        auto &&item = s.substr(offset,\
    \ pos - offset);\n        if(!item.empty() or !erace_empty) res.push_back(item);\n\
    \        offset = pos + length;\n    }\n    return res;\n}\n\n}  // namespace\
    \ algorithm\n\n\n\n/*\n\u53C2\u8003\u6587\u732E\n- C++ std::string \u6587\u5B57\
    \u5217\u306E\u5206\u5272\uFF08split\uFF09\uFF5C\u533A\u5207\u308A\u6587\u5B57\uFF0F\
    \u6587\u5B57\u5217\u306B\u5BFE\u5FDC\uFF0CMaryCore, https://marycore.jp/prog/cpp/std-string-split/\uFF08\
    \u53C2\u71672023.1.21\uFF09.\n*/\n"
  code: "#ifndef ALGORITHM_SPLIT_HPP\n#define ALGORITHM_SPLIT_HPP 1\n\n#include <sstream>\n\
    #include <string>\n#include <vector>\n\nnamespace algorithm {\n\n// \u6587\u5B57\
    \u5217\u5206\u5272\uFF0E\u6307\u5B9A\u306E\u6587\u5B57delim\u3067\u5206\u5272\u3059\
    \u308B\uFF0E\nstd::vector<std::string> split(std::string s, char delim, bool erace_empty\
    \ = true) {\n    s = s + std::string({delim});\n    std::vector<std::string> res;\n\
    \    std::stringstream ss(s);\n    std::string item;\n    while(std::getline(ss,\
    \ item, delim)) {\n        if(!item.empty() or !erace_empty) res.push_back(item);\n\
    \    }\n    return res;\n}\n\n// \u6587\u5B57\u5217\u5206\u5272\uFF0E\u6307\u5B9A\
    \u306E\u6587\u5B57\u5217delim\u3067\u5206\u5272\u3059\u308B\uFF0E\nstd::vector<std::string>\
    \ split(const std::string &s, const std::string &delim, bool erace_empty = true)\
    \ {\n    std::vector<std::string> res;\n    const auto length = delim.size();\n\
    \    auto offset = std::string::size_type(0);\n    while(1) {\n        auto pos\
    \ = s.find(delim, offset);\n        if(pos == std::string::npos) {\n         \
    \   auto &&item = s.substr(offset);\n            if(!item.empty() or !erace_empty)\
    \ res.push_back(item);\n            break;\n        }\n        auto &&item = s.substr(offset,\
    \ pos - offset);\n        if(!item.empty() or !erace_empty) res.push_back(item);\n\
    \        offset = pos + length;\n    }\n    return res;\n}\n\n}  // namespace\
    \ algorithm\n\n#endif\n\n/*\n\u53C2\u8003\u6587\u732E\n- C++ std::string \u6587\
    \u5B57\u5217\u306E\u5206\u5272\uFF08split\uFF09\uFF5C\u533A\u5207\u308A\u6587\u5B57\
    \uFF0F\u6587\u5B57\u5217\u306B\u5BFE\u5FDC\uFF0CMaryCore, https://marycore.jp/prog/cpp/std-string-split/\uFF08\
    \u53C2\u71672023.1.21\uFF09.\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/String/split.hpp
  requiredBy: []
  timestamp: '2023-01-21 21:11:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/String/split.hpp
layout: document
redirect_from:
- /library/src/String/split.hpp
- /library/src/String/split.hpp.html
title: src/String/split.hpp
---
