---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/Convolution/number_theoretic_transform.hpp
    title: "Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09"
  - icon: ':x:'
    path: src/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684modint"
  - icon: ':x:'
    path: src/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  - icon: ':x:'
    path: src/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  - icon: ':x:'
    path: src/Math/ModularArithmetic/modint_base.hpp
    title: src/Math/ModularArithmetic/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/yosupo-convolution_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 1 \"src/Math/Convolution/number_theoretic_transform.hpp\"\
    \n\n\n\n/**\n * @brief Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\
    \uFF09\n * @docs docs/Math/Convolution/number_theoretic_transform.md\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <cassert>\n#include <utility>\n\
    #line 14 \"src/Math/Convolution/number_theoretic_transform.hpp\"\n\n#line 1 \"\
    src/Math/ModularArithmetic/dynamic_modint.hpp\"\n\n\n\n/**\n * @brief \u52D5\u7684\
    modint\n * @docs docs/Math/ModularArithmetic/dynamic_modint.md\n */\n\n#line 12\
    \ \"src/Math/ModularArithmetic/dynamic_modint.hpp\"\n\n#line 1 \"src/Math/ModularArithmetic/modint_base.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace algorithm {\n\nclass ModintBase {};\n\
    \ntemplate <class T>\nusing is_modint = std::is_base_of<ModintBase, T>;\n\ntemplate\
    \ <class T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\ntemplate\
    \ <int mod>\nclass Modint : ModintBase {\n    long long val;\n\n    void normalize()\
    \ {\n        if(!(-mod <= val and val < mod)) val %= mod;\n        if(val < 0)\
    \ val += mod;\n    }\n\npublic:\n    Modint() : Modint(0) {}\n    Modint(long\
    \ long val_) : val(val_) {\n        static_assert(mod >= 1);\n        normalize();\n\
    \    }\n\n    Modint operator+() const { return Modint(*this); }\n    Modint operator-()\
    \ const { return (val == 0 ? Modint(*this) : Modint(mod - val)); }\n    Modint\
    \ &operator++() {\n        val++;\n        if(val == mod) val = 0;\n        return\
    \ *this;\n    }\n    Modint &operator--() {\n        if(val == 0) val = mod;\n\
    \        val--;\n        return *this;\n    }\n    Modint operator++(int) {\n\
    \        Modint res = *this;\n        ++(*this);\n        return res;\n    }\n\
    \    Modint operator--(int) {\n        Modint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    Modint &operator+=(const Modint &rhs) {\n   \
    \     val += rhs.val;\n        if(val >= mod) val -= mod;\n        return *this;\n\
    \    }\n    Modint &operator-=(const Modint &rhs) {\n        val -= rhs.val;\n\
    \        if(val < 0) val += mod;\n        return *this;\n    }\n    Modint &operator*=(const\
    \ Modint &rhs) {\n        val = val * rhs.val % mod;\n        return *this;\n\
    \    }\n    Modint &operator/=(const Modint &rhs) { return *this *= rhs.inv();\
    \ }\n\n    friend Modint operator+(const Modint &lhs, const Modint &rhs) { return\
    \ Modint(lhs) += rhs; }\n    friend Modint operator-(const Modint &lhs, const\
    \ Modint &rhs) { return Modint(lhs) -= rhs; }\n    friend Modint operator*(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }\n    friend Modint\
    \ operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs) /= rhs;\
    \ }\n    friend bool operator==(const Modint &lhs, const Modint &rhs) { return\
    \ lhs.val == rhs.val; }\n    friend bool operator!=(const Modint &lhs, const Modint\
    \ &rhs) { return lhs.val != rhs.val; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Modint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n    \
    \    return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    long long value() const { return val; }\n    Modint inv()\
    \ const {\n        long long a = val, b = mod, u = 1, v = 0;\n        while(b\
    \ != 0) {\n            long long t = a / b;\n            a -= b * t, u -= v *\
    \ t;\n            std::swap(a, b), std::swap(u, v);\n        }\n        return\
    \ Modint(u);\n    }\n    Modint pow(long long k) const {\n        if(k < 0) return\
    \ inv().pow(-k);\n        Modint res = 1, mul = *this;\n        while(k > 0) {\n\
    \            if(k & 1LL) res *= mul;\n            mul *= mul;\n            k >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    friend Modint mod_inv(const\
    \ Modint &a) { return a.inv(); }\n    friend Modint mod_pow(const Modint &a, long\
    \ long k) { return a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    \n#line 14 \"src/Math/ModularArithmetic/dynamic_modint.hpp\"\n\nnamespace algorithm\
    \ {\n\ntemplate <int id>\nclass DynamicModint : ModintBase {\n    static int mod;\n\
    \    long long val;\n\n    void normalize() {\n        if(!(-mod <= val and val\
    \ < mod)) val %= mod;\n        if(val < 0) val += mod;\n    }\n\npublic:\n   \
    \ DynamicModint() : DynamicModint(0) {}\n    DynamicModint(long long val_) : val(val_)\
    \ {\n        assert(mod >= 1);\n        normalize();\n    }\n\n    DynamicModint\
    \ operator+() const { return DynamicModint(*this); }\n    DynamicModint operator-()\
    \ const { return (val == 0 ? DynamicModint(*this) : DynamicModint(mod - val));\
    \ }\n    DynamicModint &operator++() {\n        val++;\n        if(val == mod)\
    \ val = 0;\n        return *this;\n    }\n    DynamicModint &operator--() {\n\
    \        if(val == 0) val = mod;\n        val--;\n        return *this;\n    }\n\
    \    DynamicModint operator++(int) {\n        DynamicModint res = *this;\n   \
    \     ++(*this);\n        return res;\n    }\n    DynamicModint operator--(int)\
    \ {\n        DynamicModint res = *this;\n        --(*this);\n        return res;\n\
    \    }\n    DynamicModint &operator+=(const DynamicModint &rhs) {\n        val\
    \ += rhs.val;\n        if(val >= mod) val -= mod;\n        return *this;\n   \
    \ }\n    DynamicModint &operator-=(const DynamicModint &rhs) {\n        val -=\
    \ rhs.val;\n        if(val < 0) val += mod;\n        return *this;\n    }\n  \
    \  DynamicModint &operator*=(const DynamicModint &rhs) {\n        val = val *\
    \ rhs.val % mod;\n        return *this;\n    }\n    DynamicModint &operator/=(const\
    \ DynamicModint &rhs) { return *this *= rhs.inv(); }\n\n    friend DynamicModint\
    \ operator+(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ += rhs; }\n    friend DynamicModint operator-(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) -= rhs; }\n    friend DynamicModint\
    \ operator*(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ *= rhs; }\n    friend DynamicModint operator/(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ DynamicModint &lhs, const DynamicModint &rhs) { return lhs.val == rhs.val; }\n\
    \    friend bool operator!=(const DynamicModint &lhs, const DynamicModint &rhs)\
    \ { return lhs.val != rhs.val; }\n    friend std::istream &operator>>(std::istream\
    \ &is, DynamicModint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n\
    \        return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const DynamicModint &rhs) { return os << rhs.val; }\n\n    static constexpr\
    \ int get_id() { return id; }\n    static void set_modulus(int mod_) {\n     \
    \   assert(mod_ >= 1);\n        mod = mod_;\n    }\n    static int modulus() {\
    \ return mod; }\n    long long value() const { return val; }\n    DynamicModint\
    \ inv() const {\n        long long a = val, b = mod, u = 1, v = 0;\n        while(b)\
    \ {\n            long long t = a / b;\n            a -= b * t, u -= v * t;\n \
    \           std::swap(a, b), std::swap(u, v);\n        }\n        return DynamicModint(u);\n\
    \    }\n    DynamicModint pow(long long k) const {\n        if(k < 0) return inv().pow(-k);\n\
    \        DynamicModint res = 1, mul = *this;\n        while(k > 0) {\n       \
    \     if(k & 1LL) res *= mul;\n            mul *= mul;\n            k >>= 1;\n\
    \        }\n        return res;\n    }\n\n    friend DynamicModint mod_inv(const\
    \ DynamicModint &a) { return a.inv(); }\n    friend DynamicModint mod_pow(const\
    \ DynamicModint &a, long long k) { return a.pow(k); }\n};\n\ntemplate <int id>\n\
    int DynamicModint<id>::mod = 1'000'000'007;\n\n}  // namespace algorithm\n\n\n\
    #line 1 \"src/Math/ModularArithmetic/modint.hpp\"\n\n\n\n/**\n * @brief Modint\u69CB\
    \u9020\u4F53\n * @docs docs/Math/ModularArithmetic/modint.md\n */\n\n#line 11\
    \ \"src/Math/ModularArithmetic/modint.hpp\"\n\n#line 13 \"src/Math/ModularArithmetic/modint.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <int mod>\nclass Modint : ModintBase {\n\
    \    long long val;\n\n    void normalize() {\n        if(!(-mod <= val and val\
    \ < mod)) val %= mod;\n        if(val < 0) val += mod;\n    }\n\npublic:\n   \
    \ Modint() : Modint(0) {}\n    Modint(long long val_) : val(val_) {\n        static_assert(mod\
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
    \ { return *this *= rhs.inv(); }\n\n    friend Modint operator+(const Modint &lhs,\
    \ const Modint &rhs) { return Modint(lhs) += rhs; }\n    friend Modint operator-(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }\n    friend Modint\
    \ operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs;\
    \ }\n    friend Modint operator/(const Modint &lhs, const Modint &rhs) { return\
    \ Modint(lhs) /= rhs; }\n    friend bool operator==(const Modint &lhs, const Modint\
    \ &rhs) { return lhs.val == rhs.val; }\n    friend bool operator!=(const Modint\
    \ &lhs, const Modint &rhs) { return lhs.val != rhs.val; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Modint &rhs) {\n        is >> rhs.val;\n     \
    \   rhs.normalize();\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int\
    \ modulus() { return mod; }\n    long long value() const { return val; }\n   \
    \ Modint inv() const {\n        long long a = val, b = mod, u = 1, v = 0;\n  \
    \      while(b != 0) {\n            long long t = a / b;\n            a -= b *\
    \ t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n        }\n \
    \       return Modint(u);\n    }\n    Modint pow(long long k) const {\n      \
    \  if(k < 0) return inv().pow(-k);\n        Modint res = 1, mul = *this;\n   \
    \     while(k > 0) {\n            if(k & 1LL) res *= mul;\n            mul *=\
    \ mul;\n            k >>= 1;\n        }\n        return res;\n    }\n\n    friend\
    \ Modint mod_inv(const Modint &a) { return a.inv(); }\n    friend Modint mod_pow(const\
    \ Modint &a, long long k) { return a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    \n#line 17 \"src/Math/Convolution/number_theoretic_transform.hpp\"\n\nnamespace\
    \ algorithm {\n\nnamespace ntt {\n\nconstexpr int MOD = 998'244'353;   // 998'244'353\
    \ = 2^23 * 7 * 17 + 1.\nconstexpr int MOD1 = 167'772'161;  // 167'772'161 = 2^25\
    \ * 5 + 1.\nconstexpr int MOD2 = 469'762'049;  // 469'762'049 = 2^26 * 7 + 1.\n\
    constexpr int MOD3 = 754'974'721;  // 754'974'721 = 2^24 * 3^2 * 5 + 1.\n// constexpr\
    \ int MOD4 = 1'107'296'257;  // 1'107'296'257 = 2^25 * 3 * 11 + 1.\n// constexpr\
    \ int MOD5 = 1'224'736'769;  // 1'224'736'769 = 2^24 * 73 + 1.\n// constexpr int\
    \ MOD6 = 1'711'276'033;  // 1'224'736'769 = 2^25 * 3 * 17 + 1.\n// constexpr int\
    \ MOD7 = 1'811'939'329;  // 1'224'736'769 = 2^26 * 3^3 + 1.\n\n// \u7E70\u308A\
    \u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0E\n// a^k (mod m)\
    \ \u3092\u6C42\u3081\u308B\uFF0EO(logK).\nlong long mod_pow(long long a, long\
    \ long k, int m) {\n    assert(k >= 0);\n    assert(m >= 1);\n    long long res\
    \ = 1;\n    a %= m;\n    while(k > 0) {\n        if(k & 1LL) res = res * a % m;\n\
    \        a = a * a % m;\n        k >>= 1;\n    }\n    return res;\n}\n\n// \u7D20\
    \u6570m\u3092\u6CD5\u3068\u3059\u308B\u6700\u5C0F\u306E\u539F\u59CB\u6839\u3092\
    \u6C42\u3081\u308B\uFF0E\nconstexpr int primitive_root(int m) {\n    assert(m\
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
    \u3053\u3068\uFF0EO(N*logN).\ntemplate <class mint>\nvoid transform(std::vector<mint>\
    \ &a, bool inv = false) {\n    if(a.empty()) return;\n    static bool first =\
    \ true;\n    static std::array<mint, 30> ws({}), iws({});  // ws[k]:=(2^k\u4E57\
    \u6839), iws[k]:=(2^k\u4E57\u6839\u306E\u9006\u5143).\n    if(first) {\n     \
    \   mint pr = primitive_root(mint::modulus());\n        int rank = 0;\n      \
    \  while(!((mint::modulus() - 1) & 1 << rank)) rank++;\n        ws[rank] = pr.pow((mint::modulus()\
    \ - 1) >> rank);\n        iws[rank] = ws[rank].inv();\n        for(int k = rank\
    \ - 1; k >= 0; --k) {\n            ws[k] = ws[k + 1] * ws[k + 1];\n          \
    \  iws[k] = iws[k + 1] * iws[k + 1];\n        }\n        first = false;\n    }\n\
    \    const int n = a.size();\n    assert((mint::modulus() - 1) % n == 0);\n  \
    \  int h = 0;  // h:=log2(n).\n    while(1 << h < n) h++;\n    assert(n == 1 <<\
    \ h);\n    for(int i = 0; i < n; ++i) {\n        int j = 0;\n        for(int k\
    \ = 0; k < h; ++k) j |= (i >> k & 1) << (h - 1 - k);\n        if(i < j) std::swap(a[i],\
    \ a[j]);\n    }\n    for(int b = 1, k = 1; b < n; b <<= 1, ++k) {\n        mint\
    \ w = 1;\n        for(int i = 0; i < b; ++i) {\n            for(int j = 0; j <\
    \ n; j += b << 1) {\n                mint tmp = a[i + j + b] * w;\n          \
    \      a[i + j + b] = a[i + j] - tmp;\n                a[i + j] = a[i + j] + tmp;\n\
    \            }\n            w *= (inv ? iws[k] : ws[k]);\n        }\n    }\n \
    \   if(inv) {\n        mint tmp = mint(n).inv();\n        for(int i = 0; i < n;\
    \ ++i) a[i] *= tmp;\n    }\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217\
    a, b\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\u308B\
    \u6570\u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate <typename Type>\n\
    std::vector<Type> convolve_naive(const std::vector<Type> &a, const std::vector<Type>\
    \ &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size(), m = b.size();\n    std::vector<Type> res(n + m -\
    \ 1, 0);\n    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < m; ++j)\
    \ res[i + j] += a[i] * b[j];\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\
    \u307F\uFF0E\n// \u6570\u5217a, b\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i}\
    \ a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\n\
    template <class mint>\nstd::vector<mint> convolve(std::vector<mint> a, std::vector<mint>\
    \ b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<mint>();\n \
    \   const int n = a.size() + b.size() - 1;\n    int m = 1;\n    while(m < n) m\
    \ <<= 1;\n    a.resize(m, 0), b.resize(m, 0);\n    transform(a), transform(b);\n\
    \    for(int i = 0; i < m; ++i) a[i] *= b[i];\n    transform(a, true);\n    a.resize(n);\n\
    \    return a;\n}\n\n}  // namespace ntt\n\n}  // namespace algorithm\n\n\n#line\
    \ 8 \"test/yosupo-convolution_mod.test.cpp\"\n\nint main() {\n    int n, m;\n\
    \    std::cin >> n >> m;\n\n    std::vector<algorithm::mint998244353> a(n), b(m);\n\
    \    for(auto &in : a) std::cin >> in;\n    for(auto &in : b) std::cin >> in;\n\
    \n    auto &&c = algorithm::ntt::convolve(a, b);\n    for(const auto &out : c)\
    \ std::cout << out << \" \";\n    std::cout << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../src/Math/Convolution/number_theoretic_transform.hpp\"\
    \n#include \"../src/Math/ModularArithmetic/modint.hpp\"\n\nint main() {\n    int\
    \ n, m;\n    std::cin >> n >> m;\n\n    std::vector<algorithm::mint998244353>\
    \ a(n), b(m);\n    for(auto &in : a) std::cin >> in;\n    for(auto &in : b) std::cin\
    \ >> in;\n\n    auto &&c = algorithm::ntt::convolve(a, b);\n    for(const auto\
    \ &out : c) std::cout << out << \" \";\n    std::cout << std::endl;\n}\n"
  dependsOn:
  - src/Math/Convolution/number_theoretic_transform.hpp
  - src/Math/ModularArithmetic/dynamic_modint.hpp
  - src/Math/ModularArithmetic/modint_base.hpp
  - src/Math/ModularArithmetic/modint.hpp
  - src/Math/ModularArithmetic/modint.hpp
  isVerificationFile: true
  path: test/yosupo-convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2023-10-18 00:58:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-convolution_mod.test.cpp
- /verify/test/yosupo-convolution_mod.test.cpp.html
title: test/yosupo-convolution_mod.test.cpp
---
