---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/NTL_1_B.test.cpp
    title: verify/aoj/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/no_1681.test.cpp
    title: verify/yukicoder/no_1681.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/no_1681_2.test.cpp
    title: verify/yukicoder/no_1681_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\n\n\n\n#include\
    \ <concepts>\n#include <cstdint>\n\nnamespace algorithm {\n\nnamespace internal\
    \ {\n\n// Returns x mod m.\ntemplate <std::unsigned_integral Type>\nconstexpr\
    \ std::uint32_t modulo(Type x, std::uint32_t m) { return x % m; }\n\n// Returns\
    \ x mod m.\ntemplate <std::unsigned_integral Type>\nconstexpr std::uint32_t modulo(Type\
    \ x, std::int32_t m) { return x % static_cast<std::uint32_t>(m); }\n\n// Returns\
    \ x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t modulo(Type\
    \ x, std::uint32_t m) {\n    x %= static_cast<std::int64_t>(m);\n    if(x < 0)\
    \ x += static_cast<std::int64_t>(m);\n    return x;\n}\n\n// Returns x mod m.\n\
    template <std::signed_integral Type>\nconstexpr std::uint32_t modulo(Type x, std::int32_t\
    \ m) {\n    x %= m;\n    if(x < 0) x += m;\n    return x;\n}\n\n}  // namespace\
    \ internal\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MODULO_HPP\n#define ALGORITHM_MODULO_HPP 1\n\n#include\
    \ <concepts>\n#include <cstdint>\n\nnamespace algorithm {\n\nnamespace internal\
    \ {\n\n// Returns x mod m.\ntemplate <std::unsigned_integral Type>\nconstexpr\
    \ std::uint32_t modulo(Type x, std::uint32_t m) { return x % m; }\n\n// Returns\
    \ x mod m.\ntemplate <std::unsigned_integral Type>\nconstexpr std::uint32_t modulo(Type\
    \ x, std::int32_t m) { return x % static_cast<std::uint32_t>(m); }\n\n// Returns\
    \ x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t modulo(Type\
    \ x, std::uint32_t m) {\n    x %= static_cast<std::int64_t>(m);\n    if(x < 0)\
    \ x += static_cast<std::int64_t>(m);\n    return x;\n}\n\n// Returns x mod m.\n\
    template <std::signed_integral Type>\nconstexpr std::uint32_t modulo(Type x, std::int32_t\
    \ m) {\n    x %= m;\n    if(x < 0) x += m;\n    return x;\n}\n\n}  // namespace\
    \ internal\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/modulo.hpp
  requiredBy:
  - algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  - algorithm/Math/ModularArithmetic/mod_pow.hpp
  - algorithm/Math/ModularArithmetic/modint.hpp
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  timestamp: '2026-02-27 06:07:42+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/no_1681_2.test.cpp
  - verify/yukicoder/no_1681.test.cpp
  - verify/aoj/NTL_1_B.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/modulo.hpp
layout: document
title: "\u30E2\u30B8\u30E5\u30ED\u6F14\u7B97"
---


## 参考

1. "剰余演算". Wikipedia. <https://ja.wikipedia.org/wiki/剰余演算>.
