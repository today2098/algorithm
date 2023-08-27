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
  bundledCode: "#line 1 \"src/Others/bit_count.hpp\"\n\n\n\n#include <cstdint>\n\n\
    namespace algorithm {\n\nint bit_count32(uint32_t n) {\n    const uint32_t masks[5]\
    \ = {0x55555555U, 0x33333333U, 0x0f0f0f0fU, 0x00ff00ffU, 0x0000ffffU};\n    for(int\
    \ i = 0; i < 5; ++i) n = (n & masks[i]) + ((n >> (1U << i)) & masks[i]);\n   \
    \ return n;\n}\n\nint bit_count64(uint64_t n) {\n    const uint64_t masks[6] =\
    \ {0x5555555555555555ULL, 0x3333333333333333ULL, 0x0f0f0f0f0f0f0f0fULL,\n    \
    \                           0x00ff00ff00ff00ffULL, 0x0000ffff0000ffffULL, 0x00000000ffffffffULL};\n\
    \    for(int i = 0; i < 6; ++i) n = (n & masks[i]) + ((n >> (1ULL << i)) & masks[i]);\n\
    \    return n;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BIT_COUNT_HPP\n#define ALGORITHM_BIT_COUNT_HPP 1\n\n#include\
    \ <cstdint>\n\nnamespace algorithm {\n\nint bit_count32(uint32_t n) {\n    const\
    \ uint32_t masks[5] = {0x55555555U, 0x33333333U, 0x0f0f0f0fU, 0x00ff00ffU, 0x0000ffffU};\n\
    \    for(int i = 0; i < 5; ++i) n = (n & masks[i]) + ((n >> (1U << i)) & masks[i]);\n\
    \    return n;\n}\n\nint bit_count64(uint64_t n) {\n    const uint64_t masks[6]\
    \ = {0x5555555555555555ULL, 0x3333333333333333ULL, 0x0f0f0f0f0f0f0f0fULL,\n  \
    \                             0x00ff00ff00ff00ffULL, 0x0000ffff0000ffffULL, 0x00000000ffffffffULL};\n\
    \    for(int i = 0; i < 6; ++i) n = (n & masks[i]) + ((n >> (1ULL << i)) & masks[i]);\n\
    \    return n;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Others/bit_count.hpp
  requiredBy: []
  timestamp: '2023-01-21 15:28:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Others/bit_count.hpp
layout: document
redirect_from:
- /library/src/Others/bit_count.hpp
- /library/src/Others/bit_count.hpp.html
title: src/Others/bit_count.hpp
---
