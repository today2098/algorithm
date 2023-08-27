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
    - "https://qiita.com/Pro_ktmr/items/16904c9570aa0953bf05\uFF08\u53C2\u71672022.9.8\uFF09\
      \uFF0E"
  bundledCode: "#line 1 \"src/String/z_algorithm.hpp\"\n\n\n\n#include <vector>\n\n\
    namespace algorithm {\n\n// \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E (LCP: Longest\
    \ Common Prefix)\uFF0EO(|S|).\ntemplate <class Sequence>\nstd::vector<int> z_algorithm(const\
    \ Sequence &s) {\n    const int n = s.size();\n    std::vector<int> z(n + 1);\
    \  // z[i]:=(s\u3068s[i:]\u306ELCP\u306E\u9577\u3055).\n    z[0] = n, z[n] = 0;\n\
    \    int i = 1, j = 0;\n    while(i < n) {\n        while(i + j < n and s[j] ==\
    \ s[i + j]) j++;\n        z[i] = j;\n        if(j == 0) {\n            i++;\n\
    \            continue;\n        }\n        int k = 1;\n        while(i + k < n\
    \ and z[k] + k < j) {\n            z[i + k] = z[k];\n            k++;\n      \
    \  }\n        i += k, j -= k;\n    }\n    return z;\n}\n\n}  // namespace algorithm\n\
    \n\n\n/*\n\u53C2\u8003\u6587\u732E\n- Pro_ktmr\uFF0C\u3010\u56F3\u89E3\u3011\u7DDA\
    \u5F62\u6642\u9593\u306E\u6587\u5B57\u5217\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\
    \u300CZ algorithm\u300D\u3092\u30A4\u30E9\u30B9\u30C8\u3068\u30A2\u30CB\u30E1\u30FC\
    \u30B7\u30E7\u30F3\u3067\u304B\u307F\u7815\u304F\uFF0CQiita\uFF0Chttps://qiita.com/Pro_ktmr/items/16904c9570aa0953bf05\uFF08\
    \u53C2\u71672022.9.8\uFF09\uFF0E\n*/\n"
  code: "#ifndef ALGORITHM_Z_ALGORITHM_HPP\n#define ALGORITHM_Z_ALGORITHM_HPP 1\n\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u6700\u9577\u5171\u901A\u63A5\
    \u982D\u8F9E (LCP: Longest Common Prefix)\uFF0EO(|S|).\ntemplate <class Sequence>\n\
    std::vector<int> z_algorithm(const Sequence &s) {\n    const int n = s.size();\n\
    \    std::vector<int> z(n + 1);  // z[i]:=(s\u3068s[i:]\u306ELCP\u306E\u9577\u3055\
    ).\n    z[0] = n, z[n] = 0;\n    int i = 1, j = 0;\n    while(i < n) {\n     \
    \   while(i + j < n and s[j] == s[i + j]) j++;\n        z[i] = j;\n        if(j\
    \ == 0) {\n            i++;\n            continue;\n        }\n        int k =\
    \ 1;\n        while(i + k < n and z[k] + k < j) {\n            z[i + k] = z[k];\n\
    \            k++;\n        }\n        i += k, j -= k;\n    }\n    return z;\n\
    }\n\n}  // namespace algorithm\n\n#endif\n\n/*\n\u53C2\u8003\u6587\u732E\n- Pro_ktmr\uFF0C\
    \u3010\u56F3\u89E3\u3011\u7DDA\u5F62\u6642\u9593\u306E\u6587\u5B57\u5217\u30A2\
    \u30EB\u30B4\u30EA\u30BA\u30E0\u300CZ algorithm\u300D\u3092\u30A4\u30E9\u30B9\u30C8\
    \u3068\u30A2\u30CB\u30E1\u30FC\u30B7\u30E7\u30F3\u3067\u304B\u307F\u7815\u304F\
    \uFF0CQiita\uFF0Chttps://qiita.com/Pro_ktmr/items/16904c9570aa0953bf05\uFF08\u53C2\
    \u71672022.9.8\uFF09\uFF0E\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/String/z_algorithm.hpp
  requiredBy: []
  timestamp: '2023-04-06 12:37:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/String/z_algorithm.hpp
layout: document
redirect_from:
- /library/src/String/z_algorithm.hpp
- /library/src/String/z_algorithm.hpp.html
title: src/String/z_algorithm.hpp
---
