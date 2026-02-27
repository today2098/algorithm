---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  _extendedVerifiedWith:
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
  bundledCode: '#line 1 "algorithm/Math/ModularArithmetic/modint_base.hpp"




    #include <type_traits>


    namespace algorithm {


    class ModintBase {};


    template <typename T>

    using is_modint = std::is_base_of<ModintBase, T>;


    template <typename T>

    inline constexpr bool is_modint_v = is_modint<T>::value;


    template <typename T>

    concept modint = is_modint_v<T>;


    }  // namespace algorithm



    '
  code: '#ifndef ALGORITHM_MODINT_BASE_HPP

    #define ALGORITHM_MODINT_BASE_HPP 1


    #include <type_traits>


    namespace algorithm {


    class ModintBase {};


    template <typename T>

    using is_modint = std::is_base_of<ModintBase, T>;


    template <typename T>

    inline constexpr bool is_modint_v = is_modint<T>::value;


    template <typename T>

    concept modint = is_modint_v<T>;


    }  // namespace algorithm


    #endif

    '
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/modint_base.hpp
  requiredBy:
  - algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  - algorithm/Math/ModularArithmetic/modint.hpp
  timestamp: '2026-02-21 15:50:59+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/no_1681_2.test.cpp
  - verify/yukicoder/no_1681.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/modint_base.hpp
layout: document
title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
---
