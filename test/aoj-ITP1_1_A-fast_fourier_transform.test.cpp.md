---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/Convolution/fast_fourier_transform.hpp
    title: "Fast Fourier Transform\uFF08\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\
      \u63DB\uFF09"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"test/aoj-ITP1_1_A-fast_fourier_transform.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n#include <cassert>\n\
    #include <cmath>\n#include <iostream>\n#include <random>\n\n#line 1 \"src/Math/Convolution/fast_fourier_transform.hpp\"\
    \n\n\n\n/**\n * @brief Fast Fourier Transform\uFF08\u9AD8\u901F\u30D5\u30FC\u30EA\
    \u30A8\u5909\u63DB\uFF09\n * @docs docs/Math/Convolution/fast_fourier_transform.md\n\
    \ */\n\n#include <algorithm>\n#line 12 \"src/Math/Convolution/fast_fourier_transform.hpp\"\
    \n#include <complex>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \nnamespace algorithm {\n\nnamespace fft {\n\nusing D = double;\n\nconst D PI\
    \ = std::acos(-1.0);\n\n// Fast Fourier Transform\uFF08\u9AD8\u901F\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB\uFF09.\n// \u5F15\u6570\u306E\u6570\u5217\u306E\u9577\
    \u3055\u306F2\u306E\u3079\u304D\u4E57\u3067\u3042\u308B\u3053\u3068\uFF0EO(N*logN).\n\
    void transform(std::vector<std::complex<D> > &a, bool inv = false) {\n    if(a.empty())\
    \ return;\n    const int n = a.size();\n    int h = 0;  // h:=log2(n).\n    while(1\
    \ << h < n) h++;\n    assert(n == 1 << h);\n    for(int i = 0; i < n; ++i) {\n\
    \        int j = 0;\n        for(int k = 0; k < h; ++k) j |= (i >> k & 1) << (h\
    \ - 1 - k);\n        if(i < j) std::swap(a[i], a[j]);\n    }\n    for(int b =\
    \ 1; b < n; b <<= 1) {\n        D ang = PI / b;\n        if(inv) ang = -ang;\n\
    \        for(int i = 0; i < b; ++i) {\n            std::complex<D> w = std::polar<D>(1.0,\
    \ ang * i);\n            for(int j = 0; j < n; j += b << 1) {\n              \
    \  std::complex<D> tmp = a[i + j + b] * w;\n                a[i + j + b] = a[i\
    \ + j] - tmp;\n                a[i + j] = a[i + j] + tmp;\n            }\n   \
    \     }\n    }\n    if(inv) {\n        for(int i = 0; i < n; ++i) a[i] /= n;\n\
    \    }\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217a, b\u306B\u5BFE\
    \u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217\
    c\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate <typename Type>\nstd::vector<Type>\
    \ convolve_naive(const std::vector<Type> &a, const std::vector<Type> &b) {\n \
    \   if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n    const\
    \ int n = a.size(), m = b.size();\n    std::vector<Type> res(n + m - 1, 0);\n\
    \    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < m; ++j) res[i +\
    \ j] += a[i] * b[j];\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\u307F\
    \uFF0E\n// \u6570\u5217a, b\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k]\
    \ \u3068\u306A\u308B\u6570\u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\ntemplate\
    \ <typename Type, typename std::enable_if_t<std::is_integral_v<Type>, bool> =\
    \ false>\nstd::vector<Type> convolve(const std::vector<Type> &a, const std::vector<Type>\
    \ &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size() + b.size() - 1;\n    int m = 1;\n    while(m < n)\
    \ m <<= 1;\n    std::vector<std::complex<D> > na(m, 0.0), nb(m, 0.0);\n    std::copy(a.begin(),\
    \ a.end(), na.begin());\n    std::copy(b.begin(), b.end(), nb.begin());\n    transform(na),\
    \ transform(nb);\n    for(int i = 0; i < m; ++i) na[i] *= nb[i];\n    transform(na,\
    \ true);\n    std::vector<Type> res(n);\n    for(int i = 0; i < n; ++i) res[i]\
    \ = na[i].real() + (na[i].real() < 0.0 ? -0.5 : 0.5);\n    return res;\n}\n\n\
    // \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217a, b\u306B\u5BFE\u3057\u3066\
    \uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c\u3092\u6C42\
    \u3081\u308B\uFF0EO(N*logN).\ntemplate <typename Type, typename std::enable_if_t<std::is_floating_point_v<Type>,\
    \ bool> = false>\nstd::vector<Type> convolve(const std::vector<Type> &a, const\
    \ std::vector<Type> &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size() + b.size() - 1;\n    int m = 1;\n    while(m < n)\
    \ m <<= 1;\n    std::vector<std::complex<D> > na(m, 0.0), nb(m, 0.0);\n    std::copy(a.begin(),\
    \ a.end(), na.begin());\n    std::copy(b.begin(), b.end(), nb.begin());\n    transform(na),\
    \ transform(nb);\n    for(int i = 0; i < m; ++i) na[i] *= nb[i];\n    transform(na,\
    \ true);\n    std::vector<Type> res(n);\n    for(int i = 0; i < n; ++i) res[i]\
    \ = na[i].real();\n    return res;\n}\n\n}  // namespace fft\n\n}  // namespace\
    \ algorithm\n\n\n#line 1 \"src/Utils/debug.hpp\"\n\n\n\n/**\n * @brief \u30C7\u30D0\
    \u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED\n * @docs docs/Utils/debug.md\n\
    \ */\n\n#line 10 \"src/Utils/debug.hpp\"\n#include <iterator>\n#include <queue>\n\
    #include <stack>\n#include <string>\n#include <string_view>\n#include <tuple>\n\
    #line 18 \"src/Utils/debug.hpp\"\n\n// #define DEBUG\n\n#ifdef DEBUG\n\n#define\
    \ debug(...) algorithm::debug::debug_internal(__LINE__, #__VA_ARGS__, __VA_ARGS__)\n\
    \nnamespace algorithm {\n\nnamespace debug {\n\nconstexpr std::ostream &os = std::cerr;\n\
    \nstruct has_iterator_impl {\n    template <class T>\n    static constexpr std::true_type\
    \ check(typename T::iterator *);\n\n    template <class T>\n    static constexpr\
    \ std::false_type check(...);\n};\n\ntemplate <class T>\nclass has_iterator :\
    \ public decltype(has_iterator_impl::check<T>(nullptr)) {};\n\n// Prototype declaration.\n\
    void print(const std::string &s);\nvoid print(std::string_view s);\ntemplate <typename\
    \ T, typename U>\nvoid print(const std::pair<T, U> &p);\ntemplate <class T, std::size_t...\
    \ Idxes>\nvoid print_tuple(const T &t, std::index_sequence<Idxes...>);\ntemplate\
    \ <typename... Ts>\nvoid print(const std::tuple<Ts...> &t);\ntemplate <typename...\
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
    \ static_cast<void>(0)\n\n#endif\n\n\n#line 10 \"test/aoj-ITP1_1_A-fast_fourier_transform.test.cpp\"\
    \n\nint main() {\n    std::random_device seed;\n    std::mt19937_64 rng(seed());\n\
    \    std::uniform_int_distribution<int> uniform_n(1, 200);\n    std::uniform_real_distribution<double>\
    \ uniform(-1e3, 1e3);\n    for(int i = 0; i < 100; ++i) {\n        const int n\
    \ = uniform_n(rng), m = uniform_n(rng);\n        std::vector<double> a(n), b(m);\n\
    \        for(auto &elem : a) elem = uniform(rng);\n        for(auto &elem : b)\
    \ elem = uniform(rng);\n        debug(n, a);\n        debug(m, b);\n\n       \
    \ auto res = algorithm::fft::convolve(a, b);\n        auto res_naive = algorithm::fft::convolve_naive(a,\
    \ b);\n        debug(res.size(), res);\n        debug(res_naive.size(), res_naive);\n\
    \        assert(res.size() == unsigned(n + m - 1));\n        assert(res_naive.size()\
    \ == unsigned(n + m - 1));\n        for(int j = 0; j < n + m - 1; ++j) assert(std::abs(res[j]\
    \ - res_naive[j]) < 1e-6);\n    }\n\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cassert>\n#include <cmath>\n#include <iostream>\n#include <random>\n\
    \n#include \"../src/Math/Convolution/fast_fourier_transform.hpp\"\n#include \"\
    ../src/Utils/debug.hpp\"\n\nint main() {\n    std::random_device seed;\n    std::mt19937_64\
    \ rng(seed());\n    std::uniform_int_distribution<int> uniform_n(1, 200);\n  \
    \  std::uniform_real_distribution<double> uniform(-1e3, 1e3);\n    for(int i =\
    \ 0; i < 100; ++i) {\n        const int n = uniform_n(rng), m = uniform_n(rng);\n\
    \        std::vector<double> a(n), b(m);\n        for(auto &elem : a) elem = uniform(rng);\n\
    \        for(auto &elem : b) elem = uniform(rng);\n        debug(n, a);\n    \
    \    debug(m, b);\n\n        auto res = algorithm::fft::convolve(a, b);\n    \
    \    auto res_naive = algorithm::fft::convolve_naive(a, b);\n        debug(res.size(),\
    \ res);\n        debug(res_naive.size(), res_naive);\n        assert(res.size()\
    \ == unsigned(n + m - 1));\n        assert(res_naive.size() == unsigned(n + m\
    \ - 1));\n        for(int j = 0; j < n + m - 1; ++j) assert(std::abs(res[j] -\
    \ res_naive[j]) < 1e-6);\n    }\n\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/Math/Convolution/fast_fourier_transform.hpp
  - src/Utils/debug.hpp
  isVerificationFile: true
  path: test/aoj-ITP1_1_A-fast_fourier_transform.test.cpp
  requiredBy: []
  timestamp: '2024-04-24 15:41:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ITP1_1_A-fast_fourier_transform.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ITP1_1_A-fast_fourier_transform.test.cpp
- /verify/test/aoj-ITP1_1_A-fast_fourier_transform.test.cpp.html
title: test/aoj-ITP1_1_A-fast_fourier_transform.test.cpp
---
