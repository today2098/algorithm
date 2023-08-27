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
  bundledCode: "#line 1 \"src/Utils/timer.hpp\"\n\n\n\n#include <chrono>\n\nnamespace\
    \ algorithm {\n\nclass Timer {\n    std::chrono::system_clock::time_point m_start;\n\
    \npublic:\n    Timer() : m_start(std::chrono::system_clock::now()) {}\n\n    //\
    \ \u8A08\u6E2C\u958B\u59CB\u6642\u9593\u3092\u4FDD\u5B58\u3059\u308B\uFF0E\n \
    \   void restart() { m_start = std::chrono::system_clock::now(); }\n    // \u7D4C\
    \u904E\u6642\u9593\u3092\u8FD4\u3059\uFF0E[millisec].\n    auto elapsed() const\
    \ {\n        auto now = std::chrono::system_clock::now();\n        return std::chrono::duration_cast<std::chrono::milliseconds>(now\
    \ - m_start).count();\n    }\n    // \u7D4C\u904E\u6642\u9593\u3092\u8FD4\u3059\
    \uFF0E[microsec].\n    auto elapsed_micro() const {\n        auto now = std::chrono::system_clock::now();\n\
    \        return std::chrono::duration_cast<std::chrono::microseconds>(now - m_start).count();\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_TIMER_HPP\n#define ALGORITHM_TIMER_HPP 1\n\n#include <chrono>\n\
    \nnamespace algorithm {\n\nclass Timer {\n    std::chrono::system_clock::time_point\
    \ m_start;\n\npublic:\n    Timer() : m_start(std::chrono::system_clock::now())\
    \ {}\n\n    // \u8A08\u6E2C\u958B\u59CB\u6642\u9593\u3092\u4FDD\u5B58\u3059\u308B\
    \uFF0E\n    void restart() { m_start = std::chrono::system_clock::now(); }\n \
    \   // \u7D4C\u904E\u6642\u9593\u3092\u8FD4\u3059\uFF0E[millisec].\n    auto elapsed()\
    \ const {\n        auto now = std::chrono::system_clock::now();\n        return\
    \ std::chrono::duration_cast<std::chrono::milliseconds>(now - m_start).count();\n\
    \    }\n    // \u7D4C\u904E\u6642\u9593\u3092\u8FD4\u3059\uFF0E[microsec].\n \
    \   auto elapsed_micro() const {\n        auto now = std::chrono::system_clock::now();\n\
    \        return std::chrono::duration_cast<std::chrono::microseconds>(now - m_start).count();\n\
    \    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Utils/timer.hpp
  requiredBy: []
  timestamp: '2023-01-21 21:15:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Utils/timer.hpp
layout: document
redirect_from:
- /library/src/Utils/timer.hpp
- /library/src/Utils/timer.hpp.html
title: src/Utils/timer.hpp
---
