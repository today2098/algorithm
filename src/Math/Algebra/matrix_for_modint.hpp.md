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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../MathNumberTheory/modint.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef ALGORITHM_MATRIX_FOR_MODINT_HPP\n#define ALGORITHM_MATRIX_FOR_MODINT_HPP\
    \ 1\n\n#include <cassert>\n#include <tuple>\n#include <vector>\n\n#include \"\
    ../MathNumberTheory/modint.hpp\"\n#include \"matrix.hpp\"\n\nnamespace algorithm\
    \ {\n\nnamespace matrix {\n\n// PLU\u5206\u89E3\uFF0EO(N^3).\ntemplate <int mod>\n\
    std::tuple<Pivot, Matrix<Modint<mod> >, Matrix<Modint<mod> >, bool> lu_decomposition(Matrix<Modint<mod>\
    \ > A) {\n    assert(A.column() == A.row());\n    const int n = A.column();\n\
    \    Matrix<Modint<mod> > L(n, n, 0), U(n, n, 0);\n    Pivot P(n);\n    for(int\
    \ k = 0; k < n; ++k) {\n        int idx = k;\n        while(idx < n and A.loc(idx,\
    \ k) == 0) idx++;\n        if(idx == n) return {P, L, U, false};\n        if(idx\
    \ != k) {\n            P.swap(k, idx);\n            for(int j = 0; j < k; ++j)\
    \ {\n                std::swap(L.loc(k, j), L.loc(idx, j));\n                std::swap(U.loc(k,\
    \ j), U.loc(idx, j));\n            }\n            for(int j = k; j < n; ++j) std::swap(A.loc(k,\
    \ j), A.loc(idx, j));\n        }\n        auto tmp = 1 / A.loc(k, k);\n      \
    \  for(int i = k; i < n; ++i) L.loc(i, k) = A.loc(i, k) * tmp;\n        for(int\
    \ j = k; j < n; ++j) U.loc(k, j) = A.loc(k, j);\n        for(int i = k + 1; i\
    \ < n; ++i) {\n            for(int j = k + 1; j < n; ++j) A.loc(i, j) -= L.loc(i,\
    \ k) * U.loc(k, j);\n        }\n    }\n    return {P, L, U, true};\n}\n\n// \u6383\
    \u304D\u51FA\u3057\u6CD5\uFF0E\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\
    \u30F3\u306E\u6D88\u53BB\u6CD5\uFF0E\u8FD4\u308A\u5024\u306F\u884C\u5217\u306E\
    \u968E\u6570\uFF0EO(N^3).\ntemplate <int mod>\nint gaussian_elimination(Matrix<Modint<mod>\
    \ > &sweep) {\n    int k = 0, l = 0;\n    while(k < sweep.column() and l < sweep.row())\
    \ {\n        int idx = k;\n        while(idx < sweep.column() and sweep.loc(idx,\
    \ l) == 0) idx++;\n        if(idx == sweep.column()) {\n            l++;\n   \
    \         continue;\n        }\n        if(idx != k) {\n            for(int j\
    \ = l; j < sweep.row(); ++j) std::swap(sweep.loc(k, j), sweep.loc(idx, j));\n\
    \        }\n        auto tmp = 1 / sweep.loc(k, l);\n        for(int j = l; j\
    \ < sweep.row(); ++j) sweep.loc(k, j) *= tmp;\n        for(int i = 0; i < sweep.column();\
    \ ++i) {\n            if(i == k) continue;\n            auto tmp2 = -sweep.loc(i,\
    \ l);\n            for(int j = l; j < sweep.row(); ++j) sweep.loc(i, j) += sweep.loc(k,\
    \ j) * tmp2;\n        }\n        k++, l++;\n    }\n    return k;\n}\n\n// \u9023\
    \u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F\u3092\u89E3\u304F\uFF0ELinear Simultaneous\
    \ Equation.\ntemplate <int mod>\nstd::tuple<Matrix<Modint<mod> >, std::vector<int>,\
    \ int> solve_lse(const Matrix<Modint<mod> > &A, const std::vector<Modint<mod>\
    \ > &b) {\n    assert(A.column() == static_cast<int>(b.size()));\n    Matrix<Modint<mod>\
    \ > res(A.column(), A.row() + 1);\n    for(int i = 0; i < A.column(); ++i) {\n\
    \        for(int j = 0; j < A.row(); ++j) res.loc(i, j) = A.loc(i, j);\n     \
    \   res.loc(i, A.row()) = b[i];\n    }\n    const int rank = gaussian_elimination(res);\n\
    \    std::vector<int> posi;\n    int i = 0, j = -1;\n    for(; i < rank; ++i)\
    \ {\n        for(j = j + 1; j < A.row(); ++j) {\n            if(res.loc(i, j)\
    \ != 0) {\n                posi.push_back(j);\n                break;\n      \
    \      }\n        }\n        if(j == A.row()) break;\n    }\n    for(; i < rank;\
    \ ++i) {\n        if(res.loc(i, A.row()) != 0) return {res, std::vector<int>(),\
    \ 0};  // \u89E3\u306A\u3057\uFF0E\n    }\n    return {res, posi, rank};\n}\n\n\
    }  // namespace matrix\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Algebra/matrix_for_modint.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/Algebra/matrix_for_modint.hpp
layout: document
redirect_from:
- /library/src/Math/Algebra/matrix_for_modint.hpp
- /library/src/Math/Algebra/matrix_for_modint.hpp.html
title: src/Math/Algebra/matrix_for_modint.hpp
---
