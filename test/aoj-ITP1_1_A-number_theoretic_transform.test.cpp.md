---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/Convolution/number_theoretic_transform.hpp
    title: "Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684modint"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/Utils/debug.hpp
    title: "\u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#line 1 \"src/Math/Convolution/number_theoretic_transform.hpp\"\n\n\n\n/**\n\
    \ * @brief Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09\n *\
    \ @docs docs/Math/Convolution/number_theoretic_transform.md\n */\n\n#include <algorithm>\n\
    #include <array>\n#line 12 \"src/Math/Convolution/number_theoretic_transform.hpp\"\
    \n#include <type_traits>\n#include <utility>\n#line 15 \"src/Math/Convolution/number_theoretic_transform.hpp\"\
    \n\n#line 1 \"src/Math/ModularArithmetic/dynamic_modint.hpp\"\n\n\n\n/**\n * @brief\
    \ \u52D5\u7684modint\n * @docs docs/Math/ModularArithmetic/dynamic_modint.md\n\
    \ */\n\n#line 12 \"src/Math/ModularArithmetic/dynamic_modint.hpp\"\n\n#line 1\
    \ \"src/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n/**\n * @brief Modint\u69CB\
    \u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9\n * @docs docs/Math/ModularArithmetic/modint_base.md\n\
    \ */\n\n#line 10 \"src/Math/ModularArithmetic/modint_base.hpp\"\n\nnamespace algorithm\
    \ {\n\nclass ModintBase {};\n\ntemplate <class T>\nusing is_modint = std::is_base_of<ModintBase,\
    \ T>;\n\ntemplate <class T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\
    \n}  // namespace algorithm\n\n\n#line 14 \"src/Math/ModularArithmetic/dynamic_modint.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <int id>\nclass DynamicModint : ModintBase\
    \ {\n    static int mod;\n    long long val;\n\n    void normalize() {\n     \
    \   if(val < -mod or mod <= val) val %= mod;\n        if(val < 0) val += mod;\n\
    \    }\n\npublic:\n    DynamicModint() : DynamicModint(0) {}\n    DynamicModint(long\
    \ long val_) : val(val_) {\n        assert(mod >= 1);\n        normalize();\n\
    \    }\n\n    DynamicModint operator+() const { return DynamicModint(*this); }\n\
    \    DynamicModint operator-() const { return (val == 0 ? DynamicModint(*this)\
    \ : DynamicModint(mod - val)); }\n    DynamicModint &operator++() {\n        val++;\n\
    \        if(val == mod) val = 0;\n        return *this;\n    }\n    DynamicModint\
    \ &operator--() {\n        if(val == 0) val = mod;\n        val--;\n        return\
    \ *this;\n    }\n    DynamicModint operator++(int) {\n        DynamicModint res\
    \ = *this;\n        ++(*this);\n        return res;\n    }\n    DynamicModint\
    \ operator--(int) {\n        DynamicModint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    DynamicModint &operator+=(const DynamicModint\
    \ &rhs) {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n     \
    \   return *this;\n    }\n    DynamicModint &operator-=(const DynamicModint &rhs)\
    \ {\n        val -= rhs.val;\n        if(val < 0) val += mod;\n        return\
    \ *this;\n    }\n    DynamicModint &operator*=(const DynamicModint &rhs) {\n \
    \       val = val * rhs.val % mod;\n        return *this;\n    }\n    DynamicModint\
    \ &operator/=(const DynamicModint &rhs) { return *this *= rhs.inv(); }\n\n   \
    \ friend bool operator==(const DynamicModint &lhs, const DynamicModint &rhs) {\
    \ return lhs.val == rhs.val; }\n    friend bool operator!=(const DynamicModint\
    \ &lhs, const DynamicModint &rhs) { return lhs.val != rhs.val; }\n    friend DynamicModint\
    \ operator+(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ += rhs; }\n    friend DynamicModint operator-(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) -= rhs; }\n    friend DynamicModint\
    \ operator*(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ *= rhs; }\n    friend DynamicModint operator/(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) /= rhs; }\n    friend std::istream\
    \ &operator>>(std::istream &is, DynamicModint &rhs) {\n        is >> rhs.val;\n\
    \        rhs.normalize();\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const DynamicModint &rhs) { return os << rhs.val;\
    \ }\n\n    static constexpr int get_id() { return id; }\n    static void set_modulus(int\
    \ mod_) {\n        assert(mod_ >= 1);\n        mod = mod_;\n    }\n    static\
    \ int modulus() { return mod; }\n    long long value() const { return val; }\n\
    \    DynamicModint inv() const {\n        long long a = mod, b = val, u = 0, v\
    \ = 1;\n        while(b != 0) {\n            long long t = a / b;\n          \
    \  a -= b * t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n  \
    \      }\n        return DynamicModint(u);\n    }\n    DynamicModint pow(long\
    \ long k) const {\n        if(k < 0) return inv().pow(-k);\n        DynamicModint\
    \ res = 1, mul = *this;\n        while(k > 0) {\n            if(k & 1LL) res *=\
    \ mul;\n            mul *= mul;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    friend DynamicModint mod_inv(const DynamicModint &a) { return\
    \ a.inv(); }\n    friend DynamicModint mod_pow(const DynamicModint &a, long long\
    \ k) { return a.pow(k); }\n};\n\ntemplate <int id>\nint DynamicModint<id>::mod\
    \ = 1'000'000'007;\n\n}  // namespace algorithm\n\n\n#line 1 \"src/Math/ModularArithmetic/modint.hpp\"\
    \n\n\n\n/**\n * @brief Modint\u69CB\u9020\u4F53\n * @docs docs/Math/ModularArithmetic/modint.md\n\
    \ */\n\n#line 11 \"src/Math/ModularArithmetic/modint.hpp\"\n\n#line 13 \"src/Math/ModularArithmetic/modint.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <int mod>\nclass Modint : ModintBase {\n\
    \    long long val;\n\n    void normalize() {\n        if(val < -mod or mod <=\
    \ val) val %= mod;\n        if(val < 0) val += mod;\n    }\n\npublic:\n    Modint()\
    \ : Modint(0) {}\n    Modint(long long val_) : val(val_) {\n        static_assert(mod\
    \ >= 1);\n        normalize();\n    }\n\n    Modint operator+() const { return\
    \ Modint(*this); }\n    Modint operator-() const { return (val == 0 ? Modint(*this)\
    \ : Modint(mod - val)); }\n    Modint &operator++() {\n        val++;\n      \
    \  if(val == mod) val = 0;\n        return *this;\n    }\n    Modint &operator--()\
    \ {\n        if(val == 0) val = mod;\n        val--;\n        return *this;\n\
    \    }\n    Modint operator++(int) {\n        Modint res = *this;\n        ++(*this);\n\
    \        return res;\n    }\n    Modint operator--(int) {\n        Modint res\
    \ = *this;\n        --(*this);\n        return res;\n    }\n    Modint &operator+=(const\
    \ Modint &rhs) {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n\
    \        return *this;\n    }\n    Modint &operator-=(const Modint &rhs) {\n \
    \       val -= rhs.val;\n        if(val < 0) val += mod;\n        return *this;\n\
    \    }\n    Modint &operator*=(const Modint &rhs) {\n        val = val * rhs.val\
    \ % mod;\n        return *this;\n    }\n    Modint &operator/=(const Modint &rhs)\
    \ { return *this *= rhs.inv(); }\n\n    friend bool operator==(const Modint &lhs,\
    \ const Modint &rhs) { return lhs.val == rhs.val; }\n    friend bool operator!=(const\
    \ Modint &lhs, const Modint &rhs) { return lhs.val != rhs.val; }\n    friend Modint\
    \ operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs) += rhs;\
    \ }\n    friend Modint operator-(const Modint &lhs, const Modint &rhs) { return\
    \ Modint(lhs) -= rhs; }\n    friend Modint operator*(const Modint &lhs, const\
    \ Modint &rhs) { return Modint(lhs) *= rhs; }\n    friend Modint operator/(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) /= rhs; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Modint &rhs) {\n        is >> rhs.val;\n     \
    \   rhs.normalize();\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int\
    \ modulus() { return mod; }\n    long long value() const { return val; }\n   \
    \ Modint inv() const {\n        long long a = mod, b = val, u = 0, v = 1;\n  \
    \      while(b != 0) {\n            long long t = a / b;\n            a -= b *\
    \ t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n        }\n \
    \       return Modint(u);\n    }\n    Modint pow(long long k) const {\n      \
    \  if(k < 0) return inv().pow(-k);\n        Modint res = 1, mul = *this;\n   \
    \     while(k > 0) {\n            if(k & 1LL) res *= mul;\n            mul *=\
    \ mul;\n            k >>= 1;\n        }\n        return res;\n    }\n\n    friend\
    \ Modint mod_inv(const Modint &a) { return a.inv(); }\n    friend Modint mod_pow(const\
    \ Modint &a, long long k) { return a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    \n#line 19 \"src/Math/Convolution/number_theoretic_transform.hpp\"\n\nnamespace\
    \ algorithm {\n\nnamespace ntt {\n\nconstexpr int MOD = 998'244'353;     // 998'244'353\
    \ = 2^23 * 7 * 17 + 1.\nconstexpr int MOD1 = 167'772'161;    // 167'772'161 =\
    \ 2^25 * 5 + 1.\nconstexpr int MOD2 = 469'762'049;    // 469'762'049 = 2^26 *\
    \ 7 + 1.\nconstexpr int MOD3 = 754'974'721;    // 754'974'721 = 2^24 * 3^2 * 5\
    \ + 1.\nconstexpr int MOD4 = 1'107'296'257;  // 1'107'296'257 = 2^25 * 3 * 11\
    \ + 1.\nconstexpr int MOD5 = 1'224'736'769;  // 1'224'736'769 = 2^24 * 73 + 1.\n\
    constexpr int MOD6 = 1'711'276'033;  // 1'224'736'769 = 2^25 * 3 * 17 + 1.\nconstexpr\
    \ int MOD7 = 1'811'939'329;  // 1'224'736'769 = 2^26 * 3^3 + 1.\n\n// \u7D20\u6570\
    \u5224\u5B9A\uFF0EO(\u221AN).\ntemplate <typename Type>\nbool is_prime(Type n)\
    \ {\n    assert(n >= 0);\n    if(n < 2) return false;\n    if(n == 2) return true;\n\
    \    if(n % 2 == 0) return false;\n    for(Type p = 3; p * p <= n; p += 2) {\n\
    \        if(n % p == 0) return false;\n    }\n    return true;\n}\n\n// \u7E70\
    \u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0E\n// a^k\
    \ (mod m) \u3092\u6C42\u3081\u308B\uFF0EO(logK).\nlong long mod_pow(long long\
    \ a, long long k, int m) {\n    assert(k >= 0);\n    assert(m >= 1);\n    long\
    \ long res = 1;\n    a %= m;\n    while(k > 0) {\n        if(k & 1LL) res = res\
    \ * a % m;\n        a = a * a % m;\n        k >>= 1;\n    }\n    return res;\n\
    }\n\n// \u7D20\u6570m\u3092\u6CD5\u3068\u3059\u308B\u6700\u5C0F\u306E\u539F\u59CB\
    \u6839\u3092\u6C42\u3081\u308B\uFF0E\nint primitive_root(int m) {\n    assert(m\
    \ >= 2);\n    if(m == 2) return 1;\n    if(m == 998'244'353) return 3;\n    if(m\
    \ == 167'772'161) return 3;\n    if(m == 469'762'049) return 3;\n    if(m == 754'974'721)\
    \ return 11;\n    std::array<int, 20> divs({2});  // divs[]:=(m-1\u306E\u7D20\u56E0\
    \u6570).\n    int cnt = 1;\n    int n = (m - 1) / 2;\n    while(n % 2 == 0) n\
    \ /= 2;\n    for(int p = 3; p * p <= n; p += 2) {\n        if(n % p == 0) {\n\
    \            divs[cnt++] = p;\n            while(n % p == 0) n /= p;\n       \
    \ }\n    }\n    if(n > 1) divs[cnt++] = n;\n    for(int g = 2;; ++g) {\n     \
    \   bool ok = true;\n        for(int i = 0; i < cnt; ++i) {\n            if(mod_pow(g,\
    \ (m - 1) / divs[i], m) == 1) {\n                ok = false;\n               \
    \ break;\n            }\n        }\n        if(ok) return g;\n    }\n}\n\n// Number\
    \ Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09.\n// \u5F15\u6570\u306E\
    \u6570\u5217\u306E\u9577\u3055\u306F2\u306E\u3079\u304D\u4E57\u3067\u3042\u308B\
    \u3053\u3068\uFF0EO(N*logN).\ntemplate <class mint, typename std::enable_if_t<is_modint_v<mint>,\
    \ bool> = false>\nvoid transform(std::vector<mint> &a, bool inv = false) {\n \
    \   if(a.size() == 0) return;\n    static bool first = true;\n    static std::array<mint,\
    \ 30> ws, inv_ws;  // ws[k]:=(2^k\u4E57\u6839), inv_ws[k]:=(2^k\u4E57\u6839\u306E\
    \u9006\u5143).\n    if(first) {\n        mint pr = primitive_root(mint::modulus());\n\
    \        int rank = 0;\n        while(!((mint::modulus() - 1) & 1 << rank)) rank++;\n\
    \        ws[rank] = pr.pow((mint::modulus() - 1) >> rank);\n        inv_ws[rank]\
    \ = ws[rank].inv();\n        for(int k = rank - 1; k >= 0; --k) {\n          \
    \  ws[k] = ws[k + 1] * ws[k + 1];\n            inv_ws[k] = inv_ws[k + 1] * inv_ws[k\
    \ + 1];\n        }\n        first = false;\n    }\n    const int n = a.size();\n\
    \    assert((mint::modulus() - 1) % n == 0);\n    int lb = 0;  // lb:=log2(n).\n\
    \    while(1 << lb < n) lb++;\n    assert(n == 1 << lb);\n    for(int i = 0; i\
    \ < n; ++i) {\n        int j = 0;\n        for(int k = 0; k < lb; ++k) j |= (i\
    \ >> k & 1) << (lb - 1 - k);\n        if(i < j) std::swap(a[i], a[j]);\n    }\n\
    \    for(int b = 1, k = 1; b < n; b <<= 1, ++k) {\n        mint w = 1;\n     \
    \   for(int i = 0; i < b; ++i) {\n            for(int j = 0; j < n; j += b <<\
    \ 1) {\n                mint tmp = a[i + j + b] * w;\n                a[i + j\
    \ + b] = a[i + j] - tmp;\n                a[i + j] = a[i + j] + tmp;\n       \
    \     }\n            w *= (inv ? inv_ws[k] : ws[k]);\n        }\n    }\n    if(inv)\
    \ {\n        mint &&tmp = mint(n).inv();\n        for(int i = 0; i < n; ++i) a[i]\
    \ *= tmp;\n    }\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217a, b\u306B\
    \u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\u308B\u6570\
    \u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate <typename Type>\nstd::vector<Type>\
    \ convolve_naive(const std::vector<Type> &a, const std::vector<Type> &b) {\n \
    \   if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n    const\
    \ int n = a.size(), m = b.size();\n    std::vector<Type> res(n + m - 1, 0);\n\
    \    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < m; ++j) res[i +\
    \ j] += a[i] * b[j];\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\u307F\
    \uFF0E\n// \u6570\u5217a, b\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k]\
    \ \u3068\u306A\u308B\u6570\u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\ntemplate\
    \ <class mint, typename std::enable_if_t<is_modint_v<mint>, bool> = false>\nstd::vector<mint>\
    \ convolve(std::vector<mint> a, std::vector<mint> b) {\n    if(a.size() == 0 or\
    \ b.size() == 0) return std::vector<mint>();\n    const int n = a.size() + b.size()\
    \ - 1;\n    int m = 1;\n    while(m < n) m <<= 1;\n    a.resize(m, 0), b.resize(m,\
    \ 0);\n    transform(a), transform(b);\n    for(int i = 0; i < m; ++i) a[i] *=\
    \ b[i];\n    transform(a, true);\n    a.resize(n);\n    return a;\n}\n\n}  //\
    \ namespace ntt\n\n}  // namespace algorithm\n\n\n#line 1 \"src/Utils/debug.hpp\"\
    \n\n\n\n/**\n * @brief \u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\
    \u30AF\u30ED\n * @docs docs/Utils/debug.md\n */\n\n#line 10 \"src/Utils/debug.hpp\"\
    \n#include <iterator>\n#include <queue>\n#include <stack>\n#include <string>\n\
    #include <string_view>\n#include <tuple>\n#line 18 \"src/Utils/debug.hpp\"\n\n\
    // #define DEBUG\n\n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__,\
    \ #__VA_ARGS__, __VA_ARGS__)\n\nnamespace algorithm {\n\nnamespace debug {\n\n\
    constexpr std::ostream &os = std::cerr;\n\nstruct has_iterator_impl {\n    template\
    \ <class T>\n    static constexpr std::true_type check(typename T::iterator *);\n\
    \n    template <class T>\n    static constexpr std::false_type check(...);\n};\n\
    \ntemplate <class T>\nclass has_iterator : public decltype(has_iterator_impl::check<T>(nullptr))\
    \ {};\n\n// Prototype declaration.\nvoid print(const std::string &s);\nvoid print(std::string_view\
    \ s);\ntemplate <typename T, typename U>\nvoid print(const std::pair<T, U> &p);\n\
    template <class T, std::size_t... Idxes>\nvoid print_tuple(const T &t, std::index_sequence<Idxes...>);\n\
    template <typename... Ts>\nvoid print(const std::tuple<Ts...> &t);\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st);\ntemplate <typename... Ts>\nvoid\
    \ print(const std::queue<Ts...> &que);\ntemplate <typename... Ts>\nvoid print(const\
    \ std::priority_queue<Ts...> &pque);\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int line, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { os << s; }\n\nvoid print(std::string_view\
    \ s) { os << s; }\n\ntemplate <typename T, typename U>\nvoid print(const std::pair<T,\
    \ U> &p) {\n    os << \"{\";\n    print(p.first);\n    os << \", \";\n    print(p.second);\n\
    \    os << \"}\";\n}\n\ntemplate <class T, std::size_t... Idxes>\nvoid print_tuple(const\
    \ T &t, std::index_sequence<Idxes...>) {\n    os << \"{\";\n    ((os << (Idxes\
    \ == 0 ? \"\" : \", \"), print(std::get<Idxes>(t))), ...);\n    os << \"}\";\n\
    }\n\ntemplate <typename... Ts>\nvoid print(const std::tuple<Ts...> &t) {\n   \
    \ print_tuple(t, std::make_index_sequence<sizeof...(Ts)>());\n}\n\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st) {\n    std::stack<Ts...> tmp =\
    \ st;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <typename... Ts>\nvoid print(const std::queue<Ts...> &que)\
    \ {\n    std::queue<Ts...> tmp = que;\n    os << \"[\";\n    while(!tmp.empty())\
    \ {\n        print(tmp.front());\n        tmp.pop();\n        if(!tmp.empty())\
    \ os << \" \";\n    }\n    os << \"]\";\n}\n\ntemplate <typename... Ts>\nvoid\
    \ print(const std::priority_queue<Ts...> &pque) {\n    std::priority_queue<Ts...>\
    \ tmp = pque;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &v) {\n    os << \"[\";\n    for(auto itr\
    \ = std::cbegin(v); itr != std::cend(v); ++itr) {\n        if(itr != std::cbegin(v))\
    \ os << \" \";\n        print(*itr);\n    }\n    os << \"]\";\n}\n\ntemplate <typename\
    \ T, typename std::enable_if_t<!has_iterator<T>::value, bool> = false>\nvoid print(const\
    \ T &elem) { os << elem; }\n\ntemplate <typename T, typename... Args>\nvoid debug_internal(int\
    \ line, std::string_view context, T &&first, Args &&...args) {\n    constexpr\
    \ const char *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr\
    \ const char *close_bracket = (sizeof...(args) == 0 ? \"\" : \")\");\n    os <<\
    \ \"[L\" << line << \"] \" << open_bracket << context << close_bracket << \":\
    \ \" << open_bracket;\n    print(std::forward<T>(first));\n    ((os << \", \"\
    , print(std::forward<Args>(args))), ...);\n    os << close_bracket << std::endl;\n\
    }\n\n}  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n\n#line 11 \"test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp\"\
    \n\nint main() {\n    std::random_device seed;\n    std::mt19937_64 rng(seed());\n\
    \n    std::uniform_int_distribution<int> uniform_n(1, 1000);\n    std::uniform_int_distribution<long\
    \ long> uniform(-1e18, 1e18);\n    for(int i = 0; i < 100; ++i) {\n        const\
    \ int n = uniform_n(rng), m = uniform_n(rng);\n        std::vector<algorithm::mint998244353>\
    \ a(n), b(m);\n        for(auto &elem : a) elem = uniform(rng);\n        for(auto\
    \ &elem : b) elem = uniform(rng);\n        debug(n, a);\n        debug(m, b);\n\
    \n        auto &&res = algorithm::ntt::convolve(a, b);\n        auto &&res_naive\
    \ = algorithm::ntt::convolve_naive(a, b);\n        debug(res.size(), res);\n \
    \       debug(res_naive.size(), res_naive);\n\n        assert(res.size() == size_t(n\
    \ + m - 1));\n        assert(res_naive.size() == size_t(n + m - 1));\n       \
    \ for(int j = 0; j < n + m - 1; ++j) assert(res[j] == res_naive[j]);\n    }\n\n\
    \    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#include \"../src/Math/Convolution/number_theoretic_transform.hpp\"\n#include\
    \ \"../src/Math/ModularArithmetic/modint.hpp\"\n#include \"../src/Utils/debug.hpp\"\
    \n\nint main() {\n    std::random_device seed;\n    std::mt19937_64 rng(seed());\n\
    \n    std::uniform_int_distribution<int> uniform_n(1, 1000);\n    std::uniform_int_distribution<long\
    \ long> uniform(-1e18, 1e18);\n    for(int i = 0; i < 100; ++i) {\n        const\
    \ int n = uniform_n(rng), m = uniform_n(rng);\n        std::vector<algorithm::mint998244353>\
    \ a(n), b(m);\n        for(auto &elem : a) elem = uniform(rng);\n        for(auto\
    \ &elem : b) elem = uniform(rng);\n        debug(n, a);\n        debug(m, b);\n\
    \n        auto &&res = algorithm::ntt::convolve(a, b);\n        auto &&res_naive\
    \ = algorithm::ntt::convolve_naive(a, b);\n        debug(res.size(), res);\n \
    \       debug(res_naive.size(), res_naive);\n\n        assert(res.size() == size_t(n\
    \ + m - 1));\n        assert(res_naive.size() == size_t(n + m - 1));\n       \
    \ for(int j = 0; j < n + m - 1; ++j) assert(res[j] == res_naive[j]);\n    }\n\n\
    \    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/Math/Convolution/number_theoretic_transform.hpp
  - src/Math/ModularArithmetic/dynamic_modint.hpp
  - src/Math/ModularArithmetic/modint_base.hpp
  - src/Math/ModularArithmetic/modint.hpp
  - src/Math/ModularArithmetic/modint_base.hpp
  - src/Math/ModularArithmetic/modint.hpp
  - src/Utils/debug.hpp
  isVerificationFile: true
  path: test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp
  requiredBy: []
  timestamp: '2024-05-19 17:43:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp
- /verify/test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp.html
title: test/aoj-ITP1_1_A-number_theoretic_transform.test.cpp
---
