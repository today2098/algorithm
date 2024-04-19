---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Others/popcount.md
    document_title: Population Count (Popcount)
    links: []
  bundledCode: "#line 1 \"src/Others/popcount.hpp\"\n\n\n\n/**\n * @brief Population\
    \ Count (Popcount)\n * @docs docs/Others/popcount.md\n */\n\n#include <cstdint>\n\
    \nnamespace algorithm {\n\nint popcount32(uint32_t n) {\n    constexpr uint32_t\
    \ masks[5] = {0x55555555U, 0x33333333U, 0x0f0f0f0fU, 0x00ff00ffU, 0x0000ffffU};\n\
    \    for(int i = 0; i < 5; ++i) n = (n & masks[i]) + ((n >> (1 << i)) & masks[i]);\n\
    \    return n;\n}\n\nint popcount64(uint64_t n) {\n    constexpr uint64_t masks[6]\
    \ = {0x5555555555555555ULL, 0x3333333333333333ULL, 0x0f0f0f0f0f0f0f0fULL,\n  \
    \                                 0x00ff00ff00ff00ffULL, 0x0000ffff0000ffffULL,\
    \ 0x00000000ffffffffULL};\n    for(int i = 0; i < 6; ++i) n = (n & masks[i]) +\
    \ ((n >> (1 << i)) & masks[i]);\n    return n;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_POPCOUNT_HPP\n#define ALGORITHM_POPCOUNT_HPP 1\n\n/**\n\
    \ * @brief Population Count (Popcount)\n * @docs docs/Others/popcount.md\n */\n\
    \n#include <cstdint>\n\nnamespace algorithm {\n\nint popcount32(uint32_t n) {\n\
    \    constexpr uint32_t masks[5] = {0x55555555U, 0x33333333U, 0x0f0f0f0fU, 0x00ff00ffU,\
    \ 0x0000ffffU};\n    for(int i = 0; i < 5; ++i) n = (n & masks[i]) + ((n >> (1\
    \ << i)) & masks[i]);\n    return n;\n}\n\nint popcount64(uint64_t n) {\n    constexpr\
    \ uint64_t masks[6] = {0x5555555555555555ULL, 0x3333333333333333ULL, 0x0f0f0f0f0f0f0f0fULL,\n\
    \                                   0x00ff00ff00ff00ffULL, 0x0000ffff0000ffffULL,\
    \ 0x00000000ffffffffULL};\n    for(int i = 0; i < 6; ++i) n = (n & masks[i]) +\
    \ ((n >> (1 << i)) & masks[i]);\n    return n;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Others/popcount.hpp
  requiredBy: []
  timestamp: '2024-04-19 16:59:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Others/popcount.hpp
layout: document
redirect_from:
- /library/src/Others/popcount.hpp
- /library/src/Others/popcount.hpp.html
title: Population Count (Popcount)
---
## 概要

与えられた数値を2進数表記した際に1となっているビットの数を効率的に求める．
"popcount" は "population count" の略．


## 参考文献

1. "Hamming weight". Wikipedia. <https://en.wikipedia.org/wiki/Hamming_weight>.
