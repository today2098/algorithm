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
  bundledCode: "#line 1 \"algorithm/utils/random.hpp\"\n\n\n\n#include <concepts>\n\
    #include <limits>\n#include <random>\n\nnamespace algorithm {\n\ntemplate <std::uniform_random_bit_generator\
    \ Engine = std::default_random_engine>\nclass Random {\npublic:\n    using seed_type\
    \ = typename Engine::result_type;\n    using engine_type = Engine;\n\nprivate:\n\
    \    seed_type m_seed;\n    engine_type m_engine;\n\npublic:\n    explicit Random()\
    \ : Random(std::random_device()()) {}\n    explicit Random(seed_type seed) : m_seed(seed),\
    \ m_engine(seed) {}\n\n    seed_type seed() const { return m_seed; }\n    engine_type\
    \ &engine() { return m_engine; }\n    auto next() { return m_engine(); }\n\n \
    \   // \u96E2\u6563\u4E00\u69D8\u5206\u5E03 (discrete uniform distribution) \u306B\
    \u5F93\u3046\u4E71\u6570\uFF08\u6574\u6570\uFF09\u3092\u751F\u6210\u3059\u308B\
    \uFF0E\n    template <std::integral Type>\n    Type uniform(Type min = std::numeric_limits<Type>::min(),\
    \ Type max = std::numeric_limits<Type>::max()) {\n        std::uniform_int_distribution<Type>\
    \ dist(min, max);\n        return dist(m_engine);\n    }\n    // \u9023\u7D9A\u4E00\
    \u69D8\u5206\u5E03 (continuous uniform distribution) \u306B\u5F93\u3046\u4E71\u6570\
    \uFF08\u5B9F\u6570\uFF09\u3092\u751F\u6210\u3059\u308B\uFF0E\n    template <std::floating_point\
    \ Type>\n    Type uniform(Type min = std::numeric_limits<Type>::min(), Type max\
    \ = std::numeric_limits<Type>::max()) {\n        std::uniform_real_distribution<Type>\
    \ dist(min, max);\n        return dist(m_engine);\n    }\n};\n\nusing RandomWithMt19937\
    \ = Random<std::mt19937>;\nusing RandomWithMt19937_64 = Random<std::mt19937_64>;\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_RANDOM_HPP\n#define ALGORITHM_RANDOM_HPP 1\n\n#include\
    \ <concepts>\n#include <limits>\n#include <random>\n\nnamespace algorithm {\n\n\
    template <std::uniform_random_bit_generator Engine = std::default_random_engine>\n\
    class Random {\npublic:\n    using seed_type = typename Engine::result_type;\n\
    \    using engine_type = Engine;\n\nprivate:\n    seed_type m_seed;\n    engine_type\
    \ m_engine;\n\npublic:\n    explicit Random() : Random(std::random_device()())\
    \ {}\n    explicit Random(seed_type seed) : m_seed(seed), m_engine(seed) {}\n\n\
    \    seed_type seed() const { return m_seed; }\n    engine_type &engine() { return\
    \ m_engine; }\n    auto next() { return m_engine(); }\n\n    // \u96E2\u6563\u4E00\
    \u69D8\u5206\u5E03 (discrete uniform distribution) \u306B\u5F93\u3046\u4E71\u6570\
    \uFF08\u6574\u6570\uFF09\u3092\u751F\u6210\u3059\u308B\uFF0E\n    template <std::integral\
    \ Type>\n    Type uniform(Type min = std::numeric_limits<Type>::min(), Type max\
    \ = std::numeric_limits<Type>::max()) {\n        std::uniform_int_distribution<Type>\
    \ dist(min, max);\n        return dist(m_engine);\n    }\n    // \u9023\u7D9A\u4E00\
    \u69D8\u5206\u5E03 (continuous uniform distribution) \u306B\u5F93\u3046\u4E71\u6570\
    \uFF08\u5B9F\u6570\uFF09\u3092\u751F\u6210\u3059\u308B\uFF0E\n    template <std::floating_point\
    \ Type>\n    Type uniform(Type min = std::numeric_limits<Type>::min(), Type max\
    \ = std::numeric_limits<Type>::max()) {\n        std::uniform_real_distribution<Type>\
    \ dist(min, max);\n        return dist(m_engine);\n    }\n};\n\nusing RandomWithMt19937\
    \ = Random<std::mt19937>;\nusing RandomWithMt19937_64 = Random<std::mt19937_64>;\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/utils/random.hpp
  requiredBy: []
  timestamp: '2026-02-21 03:29:30+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/utils/random.hpp
layout: document
title: "\u4E71\u6570\u751F\u6210"
---


## 概要

乱数生成のためのユーティリティクラス．

## 参考

1. "コンピューターはどうやって乱数を生み出しているのか？". Gigazine. <https://gigazine.net/news/20210925-random-generate/>.
1. "random". cpprefjp. <https://cpprefjp.github.io/reference/random.html>.
