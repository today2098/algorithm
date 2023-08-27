---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/MathAlgebra/matrix.hpp
    title: src/MathAlgebra/matrix.hpp
  - icon: ':warning:'
    path: src/MathNumberTheory/modint.hpp
    title: src/MathNumberTheory/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/MathAlgebra/matrix_for_modint.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <tuple>\n#include <vector>\n\n#line 1 \"src/MathNumberTheory/modint.hpp\"\
    \n\n\n\n#line 5 \"src/MathNumberTheory/modint.hpp\"\n#include <iostream>\n\nnamespace\
    \ algorithm {\n\ntemplate <int mod>\nclass Modint {\n    long long val;\n\npublic:\n\
    \    Modint() : Modint(0) {}\n    Modint(long long val_) : val(val_) {\n     \
    \   static_assert(mod >= 1);\n        if(!(0 <= val and val < mod)) {\n      \
    \      val %= mod;\n            if(val < 0) val += mod;\n        }\n    }\n\n\
    \    Modint operator+() const { return Modint(*this); }\n    Modint operator-()\
    \ const { return Modint(0) - (*this); }\n    Modint &operator++() {\n        val++;\n\
    \        if(val == mod) val = 0;\n        return *this;\n    }\n    Modint &operator--()\
    \ {\n        if(val == 0) val = mod;\n        val--;\n        return *this;\n\
    \    }\n    Modint operator++(int) {\n        Modint res = *this;\n        ++(*this);\n\
    \        return res;\n    }\n    Modint operator--(int) {\n        Modint res\
    \ = *this;\n        --(*this);\n        return res;\n    }\n    Modint &operator+=(const\
    \ Modint &a) {\n        val += a.val;\n        if(val >= mod) val -= mod;\n  \
    \      return *this;\n    }\n    Modint &operator-=(const Modint &a) {\n     \
    \   val -= a.val;\n        if(val < 0) val += mod;\n        return *this;\n  \
    \  }\n    Modint &operator*=(const Modint &a) {\n        val = val * a.val % mod;\n\
    \        return *this;\n    }\n    Modint &operator/=(const Modint &a) { return\
    \ (*this) *= a.inv(); }\n\n    friend Modint operator+(const Modint &x, const\
    \ Modint &y) { return Modint(x) += y; }\n    friend Modint operator-(const Modint\
    \ &x, const Modint &y) { return Modint(x) -= y; }\n    friend Modint operator*(const\
    \ Modint &x, const Modint &y) { return Modint(x) *= y; }\n    friend Modint operator/(const\
    \ Modint &x, const Modint &y) { return Modint(x) /= y; }\n    friend bool operator==(const\
    \ Modint &x, const Modint &y) { return x.val == y.val; }\n    friend bool operator!=(const\
    \ Modint &x, const Modint &y) { return x.val != y.val; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Modint &x) {\n        is >> x.val;\n        if(!(0\
    \ <= x.val and x.val < mod)) {\n            x.val %= mod;\n            if(x.val\
    \ < 0) x.val += mod;\n        }\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Modint &x) { return os << x.val; }\n\n \
    \   static constexpr int modulus() { return mod; }\n    long long value() const\
    \ { return val; }\n    Modint inv() const {\n        long long a = val, b = mod,\
    \ u = 1, v = 0;\n        while(b) {\n            long long t = a / b;\n      \
    \      a -= t * b, u -= t * v;\n            std::swap(a, b), std::swap(u, v);\n\
    \        }\n        return Modint(u);\n    }\n\n    friend Modint mod_pow(const\
    \ Modint &x, long long k) {\n        if(k < 0) return mod_pow(x.inv(), -k);\n\
    \        Modint res = 1, tmp = x;\n        while(k > 0) {\n            if(k &\
    \ 1LL) res *= tmp;\n            tmp = tmp * tmp;\n            k >>= 1;\n     \
    \   }\n        return res;\n    }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    \n#line 1 \"src/MathAlgebra/matrix.hpp\"\n\n\n\n#include <algorithm>\n#line 6\
    \ \"src/MathAlgebra/matrix.hpp\"\n#include <cmath>\n#include <numeric>\n#include\
    \ <ostream>\n#line 11 \"src/MathAlgebra/matrix.hpp\"\n\nnamespace algorithm {\n\
    \nnamespace matrix {\n\nusing Type = double;\n\nconstexpr Type EPS = 1e-10;\n\n\
    template <typename T>\nclass Matrix {\n    int m_col;\n    int m_row;\n    std::vector<std::vector<T>\
    \ > m_dat;\n    bool m_is_transposed;\n\npublic:\n    Matrix() : Matrix(0, 0)\
    \ {}\n    explicit Matrix(int m, int n) : m_col(m), m_row(n), m_dat(m, std::vector<T>(n)),\
    \ m_is_transposed(false) {}\n    explicit Matrix(int m, int n, T val) : m_col(m),\
    \ m_row(n), m_dat(m, std::vector<T>(n, val)), m_is_transposed(false) {}\n    explicit\
    \ Matrix(const std::vector<std::vector<T> > &val) : m_col(val.size()), m_row(0),\
    \ m_dat(val), m_is_transposed(false) {\n        for(const auto &v : m_dat) m_row\
    \ = std::max(m_row, static_cast<int>(v.size()));\n        for(auto &v : m_dat)\
    \ v.resize(m_row, 0);\n    }\n\n    Matrix operator+() const { return Matrix(*this);\
    \ }\n    Matrix operator-() const {\n        Matrix R(*this);\n        for(auto\
    \ &v : R.m_dat) {\n            for(auto &elem : v) elem = -elem;\n        }\n\
    \        return R;\n    }\n    Matrix &operator*=(T a) {\n        for(auto &v\
    \ : m_dat) {\n            for(auto &elem : v) elem *= a;\n        }\n        return\
    \ *this;\n    }\n    Matrix &operator/=(T a) {\n        for(auto &v : m_dat) {\n\
    \            for(auto &elem : v) elem /= a;\n        }\n        return *this;\n\
    \    }\n    Matrix &operator+=(const Matrix &A) {\n        assert(A.column() ==\
    \ column() and A.row() == row());\n        for(int i = 0; i < column(); ++i) {\n\
    \            for(int j = 0; j < row(); ++j) loc(i, j) += A.loc(i, j);\n      \
    \  }\n        return *this;\n    }\n    Matrix &operator-=(const Matrix &A) {\n\
    \        assert(A.column() == column() and A.row() == row());\n        for(int\
    \ i = 0; i < column(); ++i) {\n            for(int j = 0; j < row(); ++j) loc(i,\
    \ j) -= A.loc(i, j);\n        }\n        return *this;\n    }\n    Matrix operator*(T\
    \ a) const {\n        Matrix R(*this);\n        R *= a;\n        return R;\n \
    \   }\n    Matrix operator/(T a) const {\n        Matrix R(*this);\n        R\
    \ /= a;\n        return R;\n    }\n    Matrix operator*(const Matrix &A) const\
    \ {\n        assert(row() == A.column());\n        Matrix R(column(), A.row(),\
    \ 0);\n        for(int i = 0; i < column(); ++i) {\n            for(int j = 0;\
    \ j < A.row(); ++j) {\n                for(int k = 0; k < row(); ++k) R.loc(i,\
    \ j) += loc(i, k) * A.loc(k, j);\n            }\n        }\n        return R;\n\
    \    }\n    Matrix operator+(const Matrix<T> &A) const {\n        assert(A.column()\
    \ == column() and A.row() == row());\n        Matrix R(*this);\n        R += A;\n\
    \        return R;\n    }\n    Matrix operator-(const Matrix<T> &A) const {\n\
    \        assert(A.column() == column() and A.row() == row());\n        Matrix\
    \ R(*this);\n        R -= A;\n        return R;\n    }\n    bool operator==(const\
    \ Matrix<T> &A) const {\n        assert(A.column() == column() and A.row() ==\
    \ row());\n        for(int i = 0; i < column(); ++i) {\n            for(int j\
    \ = 0; j < row(); ++j) {\n                if(loc(i, j) != A.loc(i, j)) return\
    \ false;\n            }\n        }\n        return true;\n    }\n    bool operator!=(const\
    \ Matrix<T> &A) const { return !(*this == A); }\n\n    friend Matrix operator*(T\
    \ a, const Matrix &A) { return A * a; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Matrix<T> &A) {\n        for(int i = 0; i < A.column(); ++i) {\n\
    \            for(int j = 0; j < A.row(); ++j) os << (i == 0 and j == 0 ? \"[\"\
    \ : \" \") << A.loc(i, j);\n            os << (i == A.column() - 1 ? \"]\" : \"\
    \\n\");\n        }\n        return os;\n    }\n\n    // \u96F6\u884C\u5217\uFF0E\
    \n    static Matrix zero_matrix(int m, int n) {\n        assert(m >= 0 and n >=\
    \ 0);\n        Matrix O(m, n, 0);\n        return O;\n    }\n    // \u5358\u4F4D\
    \u884C\u5217\uFF0E\n    static Matrix identity_matrix(int n) {\n        assert(n\
    \ >= 0);\n        Matrix I(n, n, 0);\n        for(int i = 0; i < n; ++i) I.loc(i,\
    \ i) = 1;\n        return I;\n    }\n\n    // \u884C\u6570\uFF0E\n    int column()\
    \ const { return (m_is_transposed ? m_row : m_col); }\n    // \u5217\u6570\uFF0E\
    \n    int row() const { return (m_is_transposed ? m_col : m_row); }\n    const\
    \ T &loc(int i, int j) const {\n        assert(0 <= i and i < column());\n   \
    \     assert(0 <= j and j < row());\n        return (m_is_transposed ? m_dat[j][i]\
    \ : m_dat[i][j]);\n    }\n    T &loc(int i, int j) {\n        assert(0 <= i and\
    \ i < column());\n        assert(0 <= j and j < row());\n        return (m_is_transposed\
    \ ? m_dat[j][i] : m_dat[i][j]);\n    }\n    // \u8EE2\u7F6E\uFF0E\n    void transpose()\
    \ { m_is_transposed = !m_is_transposed; }\n    // \u884C\u30FB\u5217\u306E\u5165\
    \u308C\u66FF\u3048\uFF0E\n    void swap(int p, int q, int axis = 0) {\n      \
    \  if(axis == 0) {\n            assert(0 <= p and p < column());\n           \
    \ assert(0 <= q and q < column());\n            if(p == q) return;\n         \
    \   for(int j = 0; j < row(); ++j) std::swap(loc(p, j), loc(q, j));\n        }\
    \ else {\n            assert(0 <= p and p < row());\n            assert(0 <= q\
    \ and q < row());\n            if(p == q) return;\n            for(int i = 0;\
    \ i < column(); ++i) std::swap(loc(i, p), loc(i, q));\n        }\n    }\n};\n\n\
    using mat = Matrix<Type>;\n\n// \u8EE2\u7F6E\u884C\u5217\uFF0E\ntemplate <typename\
    \ T>\ninline Matrix<T> transposed_matrix(const Matrix<T> &A) {\n    Matrix<T>\
    \ tA(A);\n    tA.transpose();\n    return tA;\n}\n\n// \u56DE\u8EE2\u884C\u5217\
    \uFF0E\ninline mat rotation_matrix(Type arg) {\n    auto sv = std::sin(arg);\n\
    \    auto cv = std::cos(arg);\n    mat rot({{cv, -sv}, {sv, cv}});\n    return\
    \ rot;\n}\n\n// \u884C\u5217\u7D2F\u4E57\uFF0EO((logK)*N^3)\ntemplate <typename\
    \ T>\nMatrix<T> pow(const Matrix<T> &A, long long k, bool right_side = false)\
    \ {\n    assert(A.row() == A.column() and k >= 0);\n    auto &&R = Matrix<T>::identity_matrix(A.column());\n\
    \    auto B = A;\n    while(k > 0) {\n        if(k & 1) R = (right_side ? R *\
    \ B : B * R);\n        B = B * B;\n        k >>= 1;\n    }\n    return R;\n}\n\
    \n// \u7F6E\u63DB\uFF0E\nclass Permutation {\n    int m_n;                  //\
    \ m_n:=(\u6B21\u6570).\n    std::vector<int> m_perm;  // m_perm[]:=(\u7F6E\u63DB\
    ).\n    std::vector<int> m_inv;   // m_inv[]:=(\u9006\u7F6E\u63DB). m_inv[m_perm[i]]==i\n\
    \    bool m_is_inversed;\n\npublic:\n    Permutation() : Permutation(0) {}\n \
    \   explicit Permutation(int n) : m_n(n), m_perm(n), m_inv(n), m_is_inversed(false)\
    \ {\n        std::iota(m_perm.begin(), m_perm.end(), 0);\n        std::iota(m_inv.begin(),\
    \ m_inv.end(), 0);\n    }\n    explicit Permutation(int n, const std::vector<int>\
    \ &cycle) : Permutation(n, std::vector<std::vector<int> >(1, cycle)) {}\n    explicit\
    \ Permutation(int n, const std::vector<std::vector<int> > &cycles) : m_n(n), m_perm(n,\
    \ -1), m_inv(n), m_is_inversed(false) {\n        for(const auto &cycle : cycles)\
    \ {\n            const int n = static_cast<int>(cycle.size());\n            for(int\
    \ i = 0; i < n; ++i) {\n                assert(0 <= cycle[i] and cycle[i] < m_n);\n\
    \                assert(m_perm[cycle[i]] == -1);\n                m_perm[cycle[i]]\
    \ = cycle[(i + 1) % n];\n            }\n        }\n        for(int i = 0; i <\
    \ m_n; ++i) {\n            if(m_perm[i] == -1) m_perm[i] = i;\n        }\n   \
    \     for(int i = 0; i < m_n; ++i) m_inv[m_perm[i]] = i;\n    }\n    explicit\
    \ Permutation(const std::vector<int> &perm) : m_n(perm.size()), m_perm(perm),\
    \ m_inv(perm.size(), -1), m_is_inversed(false) {\n        for(int i = 0; i < m_n;\
    \ ++i) {\n            assert(0 <= m_perm[i] and m_perm[i] < m_n);\n          \
    \  assert(m_inv[m_perm[i]] == -1);\n            m_inv[m_perm[i]] = i;\n      \
    \  }\n    }\n\n    // \u7F6E\u63DB\uFF0E\n    const int &operator[](int i) const\
    \ {\n        assert(0 <= i and i < order());\n        return (m_is_inversed ?\
    \ m_inv[i] : m_perm[i]);\n    }\n    // \u7F6E\u63DB\u306E\u7A4D\uFF0E\n    Permutation\
    \ operator*(const Permutation &P) {\n        assert(P.order() == order());\n \
    \       std::vector<int> res(order());\n        for(int i = 0; i < order(); ++i)\
    \ res[i] = (*this)[P[i]];\n        return Permutation(res);\n    }\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Permutation &P) {\n       \
    \ for(int i = 0; i < P.order(); ++i) os << (i == 0 ? \"[\" : \" \") << i;\n  \
    \      os << \"\\n\";\n        for(int i = 0; i < P.order(); ++i) os << \" \"\
    \ << P[i];\n        os << \"]\";\n        return os;\n    }\n\n    // \u6B21\u6570\
    \uFF0E\n    int order() const { return m_n; }\n    // \u9006\u7F6E\u63DB\uFF0E\
    \n    const int &inv(int i) const {\n        assert(0 <= i and i < order());\n\
    \        return (m_is_inversed ? m_perm[i] : m_inv[i]);\n    }\n    void swap(int\
    \ i, int j) {\n        assert(0 <= i and i < order());\n        assert(0 <= j\
    \ and j < order());\n        if(m_is_inversed) {\n            std::swap(m_inv[i],\
    \ m_inv[j]);\n            m_perm[m_inv[i]] = i;\n            m_perm[m_inv[j]]\
    \ = j;\n        } else {\n            std::swap(m_perm[i], m_perm[j]);\n     \
    \       m_inv[m_perm[i]] = i;\n            m_inv[m_perm[j]] = j;\n        }\n\
    \    }\n    void inverse() { m_is_inversed = !m_is_inversed; }\n    template <class\
    \ Sequence>\n    void sort(Sequence &a) const {\n        assert(static_cast<int>(a.size())\
    \ == order());\n        bool seen[order()] = {};\n        for(int i = 0; i < order();\
    \ ++i) {\n            if(seen[i]) continue;\n            int idx = inv(i);\n \
    \           while(idx != i) {\n                std::swap(a[i], a[idx]);\n    \
    \            seen[idx] = true;\n                idx = inv(idx);\n            }\n\
    \            seen[i] = true;\n        }\n    }\n    template <class Sequence>\n\
    \    void reverse(Sequence &a) {\n        inverse();\n        sort(a);\n     \
    \   inverse();\n    }\n    // \u5DE1\u56DE\u7F6E\u63DB\uFF0E\n    std::vector<std::vector<int>\
    \ > cycles() const {\n        std::vector<std::vector<int> > res;\n        bool\
    \ seen[order()] = {};\n        for(int i = 0; i < order(); ++i) {\n          \
    \  if(seen[i]) continue;\n            std::vector<int> cycle({i});\n         \
    \   seen[i] = true;\n            int idx = (*this)[i];\n            while(!seen[idx])\
    \ {\n                cycle.push_back(idx);\n                seen[idx] = true;\n\
    \                idx = (*this)[idx];\n            }\n            res.push_back(cycle);\n\
    \        }\n        return res;\n    }\n    // \u7F6E\u63DB\u7B26\u53F7\uFF0E\n\
    \    int sgn() const {\n        int res = 1;\n        bool seen[order()] = {};\n\
    \        for(int i = 0; i < order(); ++i) {\n            if(seen[i]) continue;\n\
    \            seen[i] = true;\n            int idx = (*this)[i];\n            int\
    \ cnt = 0;\n            while(!seen[idx]) {\n                cnt++;\n        \
    \        seen[idx] = true;\n                idx = (*this)[idx];\n            }\n\
    \            if(cnt % 2 == 1) res *= -1;  // \u5947\u7F6E\u63DB\u3067\u3042\u308B\
    \u5834\u5408\uFF0E\n        }\n        return res;\n    }\n    void init() {\n\
    \        std::iota(m_perm.begin(), m_perm.end(), 0);\n        std::iota(m_inv.begin(),\
    \ m_inv.end(), 0);\n        m_is_inversed = false;\n    }\n\n    auto begin()\
    \ const { return (m_is_inversed ? m_inv.begin() : m_perm.begin()); }\n    auto\
    \ end() const { return (m_is_inversed ? m_inv.end() : m_perm.end()); }\n};\n\n\
    // \u9006\u7F6E\u63DB\uFF0E\nPermutation inv_permutation(const Permutation &P)\
    \ {\n    Permutation inv(P);\n    inv.inverse();\n    return inv;\n}\n\n// \u7F6E\
    \u63DB\u884C\u5217\uFF0E\nclass Pivot {\n    Permutation m_perm;  // m_perm[i]:=(i\u884C\
    \u76EE\u306B\u304A\u3051\u308B\u30D4\u30DC\u30C3\u30C8\u306E\u4F4D\u7F6E).\n\n\
    public:\n    Pivot() : Pivot(0) {}\n    explicit Pivot(int n) : m_perm(n) {}\n\
    \    explicit Pivot(const std::vector<int> &perm) : m_perm(perm) {}\n\n    const\
    \ int &operator[](int i) const {\n        assert(0 <= i and i < order());\n  \
    \      return m_perm[i];\n    }\n    template <typename T>\n    Matrix<T> operator*(const\
    \ Matrix<T> &A) const {\n        assert(A.column() == order());\n        Matrix<T>\
    \ R(A.column(), A.row());\n        for(int i = 0; i < R.column(); ++i) {\n   \
    \         for(int j = 0; j < R.row(); ++j) R.loc(i, j) = A.loc(m_perm[i], j);\n\
    \        }\n        return R;\n    }\n    Pivot operator*(const Pivot &pivot)\
    \ const {\n        assert(pivot.order() == order());\n        std::vector<int>\
    \ res(order());\n        for(int i = 0; i < order(); ++i) res[i] = pivot[(*this)[i]];\n\
    \        return Pivot(res);\n    }\n\n    template <typename T>\n    friend Matrix<T>\
    \ operator*(Matrix<T> &A, Pivot &pivot) {\n        assert(A.row() == pivot.order());\n\
    \        A.transpose();\n        pivot.inverse();\n        auto &&R = pivot *\
    \ A;\n        R.transpose();\n        A.transpose();\n        pivot.inverse();\n\
    \        return R;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Pivot &pivot) {\n        for(int i = 0; i < pivot.order(); ++i) os <<\
    \ (i == 0 ? \"[\" : \" \") << pivot[i];\n        os << \"]\";\n        return\
    \ os;\n    }\n\n    int order() const { return m_perm.order(); }\n    void swap(int\
    \ i, int j) {\n        assert(0 <= i and i < order());\n        assert(0 <= j\
    \ and j < order());\n        m_perm.swap(i, j);\n    }\n    void inverse() { m_perm.inverse();\
    \ }\n    template <typename T>\n    void sort(Matrix<T> &A) {\n        assert(A.column()\
    \ == order());\n        bool seen[order()] = {};\n        for(int i = 0; i < order();\
    \ ++i) {\n            if(seen[i]) continue;\n            int idx = m_perm.inv(i);\n\
    \            while(idx != i) {\n                A.swap(i, idx);\n            \
    \    seen[idx] = true;\n                idx = m_perm.inv(idx);\n            }\n\
    \            seen[i] = true;\n        }\n    }\n    template <typename T>\n  \
    \  void reverse(Matrix<T> &A) {\n        inverse();\n        sort(A);\n      \
    \  inverse();\n    }\n    int sgn() const { return m_perm.sgn(); }\n    void init()\
    \ { m_perm.init(); }\n\n    auto begin() const { return m_perm.begin(); }\n  \
    \  auto end() const { return m_perm.end(); }\n};\n\nPivot inv_pivot(const Pivot\
    \ &pivot) {\n    Pivot inv(pivot);\n    inv.inverse();\n    return inv;\n}\n\n\
    // PLU\u5206\u89E3\uFF0EO(N^3).\ntemplate <typename T>\nstd::tuple<Pivot, Matrix<T>,\
    \ Matrix<T>, bool> lu_decomposition(Matrix<T> A) {\n    assert(A.column() == A.row());\n\
    \    const int n = A.column();\n    Matrix<T> L(n, n, 0), U(n, n, 0);\n    Pivot\
    \ P(n);\n    for(int k = 0; k < n; ++k) {\n        int idx = k;\n        for(int\
    \ i = k + 1; i < n; ++i) {\n            if(std::abs(A.loc(i, k)) > std::abs(A.loc(idx,\
    \ k))) idx = i;\n        }\n        if(std::abs(A.loc(idx, k)) <= EPS) return\
    \ {P, L, U, false};\n        if(idx != k) {\n            P.swap(k, idx);\n   \
    \         for(int j = 0; j < k; ++j) {\n                std::swap(L.loc(k, j),\
    \ L.loc(idx, j));\n                std::swap(U.loc(k, j), U.loc(idx, j));\n  \
    \          }\n            for(int j = k; j < n; ++j) std::swap(A.loc(k, j), A.loc(idx,\
    \ j));\n        }\n        auto tmp = 1.0 / A.loc(k, k);\n        for(int i =\
    \ k; i < n; ++i) L.loc(i, k) = A.loc(i, k) * tmp;\n        for(int j = k; j <\
    \ n; ++j) U.loc(k, j) = A.loc(k, j);\n        for(int i = k + 1; i < n; ++i) {\n\
    \            for(int j = k + 1; j < n; ++j) A.loc(i, j) -= L.loc(i, k) * U.loc(k,\
    \ j);\n        }\n    }\n    return {P, L, U, true};\n}\n\n// \u30B5\u30E9\u30B9\
    \u306E\u65B9\u6CD5\uFF0E1\u6B21\uFF0C2\u6B21\uFF0C3\u6B21\u306E\u6B63\u65B9\u884C\
    \u5217\u306E\u884C\u5217\u5F0F\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate\
    \ <typename T>\nT sarrus(const Matrix<T> &A) {\n    assert(A.column() == A.row());\n\
    \    assert(1 <= A.column() and A.column() <= 3);\n    if(A.column() == 1) return\
    \ A.loc(0, 0);                                            // 1\u6B21\u306E\u5834\
    \u5408\uFF0E\n    if(A.column() == 2) return A.loc(0, 0) * A.loc(1, 1) - A.loc(0,\
    \ 1) * A.loc(1, 0);  // 2\u6B21\u306E\u5834\u5408\uFF0E\n    // 3\u6B21\u306E\u5834\
    \u5408\uFF0E\n    auto a = A.loc(0, 0) * A.loc(1, 1) * A.loc(2, 2) + A.loc(0,\
    \ 1) * A.loc(1, 2) * A.loc(2, 0) + A.loc(0, 2) * A.loc(1, 0) * A.loc(2, 1);\n\
    \    auto b = A.loc(0, 2) * A.loc(1, 1) * A.loc(2, 0) + A.loc(0, 1) * A.loc(1,\
    \ 0) * A.loc(2, 2) + A.loc(0, 0) * A.loc(1, 2) * A.loc(2, 1);\n    return a -\
    \ b;\n}\n\n// \u884C\u5217\u5F0F\uFF0E\ntemplate <typename T>\nT det(const Matrix<T>\
    \ &A) {\n    assert(A.column() == A.row());\n    assert(A.column() > 0);\n   \
    \ if(1 <= A.column() and A.column() <= 3) return sarrus(A);\n    const auto &&[P,\
    \ L, U, success] = lu_decomposition(A);\n    if(!success) return 0;\n    T res\
    \ = P.sgn();\n    for(int i = 0; i < U.column(); ++i) res *= U.loc(i, i);\n  \
    \  return res;\n}\n\n// \u6383\u304D\u51FA\u3057\u6CD5\uFF0E\u30AC\u30A6\u30B9\
    \u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5\uFF0E\u8FD4\u308A\
    \u5024\u306F\u884C\u5217\u306E\u968E\u6570\uFF0EO(N^3).\ntemplate <typename T>\n\
    int gaussian_elimination(Matrix<T> &sweep) {\n    int k = 0, l = 0;\n    while(k\
    \ < sweep.column() and l < sweep.row()) {\n        int idx = k;\n        for(int\
    \ i = k + 1; i < sweep.column(); ++i) {\n            if(std::abs(sweep.loc(i,\
    \ l)) > std::abs(sweep.loc(idx, l))) idx = i;\n        }\n        if(std::abs(sweep.loc(idx,\
    \ l)) <= EPS) {\n            l++;\n            continue;\n        }\n        if(idx\
    \ != k) {\n            for(int j = l; j < sweep.row(); ++j) std::swap(sweep.loc(k,\
    \ j), sweep.loc(idx, j));\n        }\n        auto tmp = 1.0 / sweep.loc(k, l);\n\
    \        for(int j = l; j < sweep.row(); ++j) sweep.loc(k, j) *= tmp;\n      \
    \  for(int i = 0; i < sweep.column(); ++i) {\n            if(i == k) continue;\n\
    \            auto tmp2 = -sweep.loc(i, l);\n            for(int j = l; j < sweep.row();\
    \ ++j) sweep.loc(i, j) += sweep.loc(k, j) * tmp2;\n        }\n        k++, l++;\n\
    \    }\n    return k;\n}\n\n// \u9006\u884C\u5217\uFF0E\u6383\u304D\u51FA\u3057\
    \u6CD5\u3092\u7528\u3044\u308B\uFF0EO(N^3).\ntemplate <typename T>\nMatrix<T>\
    \ inv_matrix(const Matrix<T> &A) {\n    assert(A.column() == A.row());\n    //\
    \ assert(det(A) != 0);\n    const int n = A.column();\n    Matrix<T> sweep(n,\
    \ 2 * n);\n    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < n; ++j)\
    \ {\n            sweep.loc(i, j) = A.loc(i, j);\n            sweep.loc(i, j +\
    \ n) = (i == j ? 1 : 0);\n        }\n    }\n    const int rank = gaussian_elimination(sweep);\n\
    \    assert(rank == n);\n    Matrix<T> inv(n, n);\n    for(int i = 0; i < n; ++i)\
    \ {\n        for(int j = 0; j < n; ++j) inv.loc(i, j) = sweep.loc(i, j + n);\n\
    \    }\n    return inv;\n}\n\n// \u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F\u3092\
    \u89E3\u304F\uFF0ELinear Simultaneous Equation.\ntemplate <typename T>\nstd::tuple<Matrix<T>,\
    \ std::vector<int>, int> solve_lse(const Matrix<T> &A, const std::vector<T> &b)\
    \ {\n    assert(A.column() == static_cast<int>(b.size()));\n    Matrix<T> res(A.column(),\
    \ A.row() + 1);\n    for(int i = 0; i < A.column(); ++i) {\n        for(int j\
    \ = 0; j < A.row(); ++j) res.loc(i, j) = A.loc(i, j);\n        res.loc(i, A.row())\
    \ = b[i];\n    }\n    const int rank = gaussian_elimination(res);\n    std::vector<int>\
    \ posi;\n    int i = 0, j = -1;\n    for(; i < rank; ++i) {\n        for(j = j\
    \ + 1; j < A.row(); ++j) {\n            if(std::abs(res.loc(i, j)) > EPS) {\n\
    \                posi.push_back(j);\n                break;\n            }\n \
    \       }\n        if(j == A.row()) break;\n    }\n    for(; i < rank; ++i) {\n\
    \        if(std::abs(res.loc(i, A.row())) > EPS) return {res, std::vector<int>(),\
    \ 0};  // \u89E3\u306A\u3057\uFF0E\n    }\n    return {res, posi, rank};\n}\n\n\
    }  // namespace matrix\n\n// using namespace matrix;\n\n}  // namespace algorithm\n\
    \n\n\n/*\n\u53C2\u8003\u6587\u732E\uFF1A\n- \u3060\u3048\u3046\uFF0C\u3010C\u8A00\
    \u8A9E\u3011\u6383\u304D\u51FA\u3057\u6CD5\u306B\u3088\u308B\u9006\u884C\u5217\
    \u306E\u6C42\u3081\u65B9\uFF084\xD74\u306E\u9006\u884C\u5217\u3082\u7B97\u51FA\
    \u53EF\u80FD\uFF09\uFF0Chttps://daeudaeu.com/c-mat-inverse/\uFF08\u53C2\u7167\
    2023.2.20\uFF09\uFF0E\n*/\n#line 10 \"src/MathAlgebra/matrix_for_modint.hpp\"\n\
    \nnamespace algorithm {\n\nnamespace matrix {\n\n// PLU\u5206\u89E3\uFF0EO(N^3).\n\
    template <int mod>\nstd::tuple<Pivot, Matrix<Modint<mod> >, Matrix<Modint<mod>\
    \ >, bool> lu_decomposition(Matrix<Modint<mod> > A) {\n    assert(A.column() ==\
    \ A.row());\n    const int n = A.column();\n    Matrix<Modint<mod> > L(n, n, 0),\
    \ U(n, n, 0);\n    Pivot P(n);\n    for(int k = 0; k < n; ++k) {\n        int\
    \ idx = k;\n        while(idx < n and A.loc(idx, k) == 0) idx++;\n        if(idx\
    \ == n) return {P, L, U, false};\n        if(idx != k) {\n            P.swap(k,\
    \ idx);\n            for(int j = 0; j < k; ++j) {\n                std::swap(L.loc(k,\
    \ j), L.loc(idx, j));\n                std::swap(U.loc(k, j), U.loc(idx, j));\n\
    \            }\n            for(int j = k; j < n; ++j) std::swap(A.loc(k, j),\
    \ A.loc(idx, j));\n        }\n        auto tmp = 1 / A.loc(k, k);\n        for(int\
    \ i = k; i < n; ++i) L.loc(i, k) = A.loc(i, k) * tmp;\n        for(int j = k;\
    \ j < n; ++j) U.loc(k, j) = A.loc(k, j);\n        for(int i = k + 1; i < n; ++i)\
    \ {\n            for(int j = k + 1; j < n; ++j) A.loc(i, j) -= L.loc(i, k) * U.loc(k,\
    \ j);\n        }\n    }\n    return {P, L, U, true};\n}\n\n// \u6383\u304D\u51FA\
    \u3057\u6CD5\uFF0E\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\
    \u6D88\u53BB\u6CD5\uFF0E\u8FD4\u308A\u5024\u306F\u884C\u5217\u306E\u968E\u6570\
    \uFF0EO(N^3).\ntemplate <int mod>\nint gaussian_elimination(Matrix<Modint<mod>\
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
    }  // namespace matrix\n\n}  // namespace algorithm\n\n\n"
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
  dependsOn:
  - src/MathNumberTheory/modint.hpp
  - src/MathAlgebra/matrix.hpp
  isVerificationFile: false
  path: src/MathAlgebra/matrix_for_modint.hpp
  requiredBy: []
  timestamp: '2023-04-12 19:02:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/MathAlgebra/matrix_for_modint.hpp
layout: document
redirect_from:
- /library/src/MathAlgebra/matrix_for_modint.hpp
- /library/src/MathAlgebra/matrix_for_modint.hpp.html
title: src/MathAlgebra/matrix_for_modint.hpp
---
