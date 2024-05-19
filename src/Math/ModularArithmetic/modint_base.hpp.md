---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Math/Convolution/number_theoretic_transform.hpp
    title: "Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09"
  - icon: ':heavy_check_mark:'
    path: src/Math/Convolution/number_theoretic_transform.hpp
    title: "Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684modint"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-3110.test.cpp
    title: test/aoj-3110.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp
    title: test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp
    title: test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-convolution_mod.test.cpp
    title: test/yosupo-convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-convolution_mod.test.cpp
    title: test/yosupo-convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-range_affine_range_sum.test.cpp
    title: test/yosupo-range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/ModularArithmetic/modint_base.md
    document_title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
    links: []
  bundledCode: "#line 1 \"src/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n/**\n\
    \ * @brief Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9\n * @docs\
    \ docs/Math/ModularArithmetic/modint_base.md\n */\n\n#include <type_traits>\n\n\
    namespace algorithm {\n\nclass ModintBase {};\n\ntemplate <class T>\nusing is_modint\
    \ = std::is_base_of<ModintBase, T>;\n\ntemplate <class T>\ninline constexpr bool\
    \ is_modint_v = is_modint<T>::value;\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MODINT_BASE_HPP\n#define ALGORITHM_MODINT_BASE_HPP 1\n\n\
    /**\n * @brief Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9\n\
    \ * @docs docs/Math/ModularArithmetic/modint_base.md\n */\n\n#include <type_traits>\n\
    \nnamespace algorithm {\n\nclass ModintBase {};\n\ntemplate <class T>\nusing is_modint\
    \ = std::is_base_of<ModintBase, T>;\n\ntemplate <class T>\ninline constexpr bool\
    \ is_modint_v = is_modint<T>::value;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/ModularArithmetic/modint_base.hpp
  requiredBy:
  - src/Math/Convolution/number_theoretic_transform.hpp
  - src/Math/Convolution/number_theoretic_transform.hpp
  - src/Math/ModularArithmetic/modint.hpp
  - src/Math/ModularArithmetic/dynamic_modint.hpp
  timestamp: '2023-10-18 06:43:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-range_affine_range_sum.test.cpp
  - test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp
  - test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp
  - test/yosupo-convolution_mod.test.cpp
  - test/yosupo-convolution_mod.test.cpp
  - test/aoj-3110.test.cpp
documentation_of: src/Math/ModularArithmetic/modint_base.hpp
layout: document
redirect_from:
- /library/src/Math/ModularArithmetic/modint_base.hpp
- /library/src/Math/ModularArithmetic/modint_base.hpp.html
title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
---
