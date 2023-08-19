#ifndef ALGORITHM_DEBUG_HPP
#define ALGORITHM_DEBUG_HPP 1

#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

namespace algorithm {

// #define DEBUG

#ifdef DEBUG

#define debug(...) debug::debug_internal(__LINE__, #__VA_ARGS__, __VA_ARGS__)

namespace debug {

struct has_iterator_impl {
    template <class T>
    static std::true_type check(typename T::iterator *);

    template <class T>
    static std::false_type check(...);
};

template <class T>
class has_iterator : public decltype(has_iterator_impl::check<T>(nullptr)) {};

// Prototype declaration
void print(const std::string &s);
template <typename T, typename U>
void print(const std::pair<T, U> &p);
template <class T, std::size_t... Idx>
void print_tuple(const T &t, std::index_sequence<Idx...>);
template <typename... T>
void print(const std::tuple<T...> &t);
template <typename T, typename std::enable_if_t<has_iterator<T>::value, bool> = false>
void print(const T &v);
template <typename T, typename std::enable_if_t<!has_iterator<T>::value, bool> = false>
void print(const T &elem);
template <typename T, typename... Args>
void debug_internal(int l, std::string_view context, T &&first, Args &&...args);

void print(const std::string &s) { std::cerr << s; }

template <typename T, typename U>
void print(const std::pair<T, U> &p) {
    std::cerr << "{";
    print(p.first);
    std::cerr << ", ";
    print(p.second);
    std::cerr << "}";
}

template <class T, std::size_t... Idx>
void print_tuple(const T &t, std::index_sequence<Idx...>) {
    std::cerr << "{";
    ((std::cerr << (Idx == 0 ? "" : ", "), print(std::get<Idx>(t))), ...);
    std::cerr << "}";
}

template <typename... T>
void print(const std::tuple<T...> &t) {
    print_tuple(t, std::make_index_sequence<sizeof...(T)>());
}

template <class T, typename std::enable_if_t<has_iterator<T>::value, bool> = false>
void print(const T &v) {
    std::cerr << "[";
    for(auto itr = std::cbegin(v); itr != std::cend(v); ++itr) {
        if(itr != std::cbegin(v)) std::cerr << " ";
        print(*itr);
    }
    std::cerr << "]";
}

template <typename T, typename std::enable_if_t<!has_iterator<T>::value, bool> = false>
void print(const T &elem) { std::cerr << elem; }

template <typename T, typename... Args>
void debug_internal(int l, std::string_view context, T &&first, Args &&...args) {
    constexpr const char *open_bracket = (sizeof...(args) == 0 ? "" : "(");
    constexpr const char *close_bracket = (sizeof...(args) == 0 ? "" : ")");
    std::cerr << "[L" << l << "] " << open_bracket << context << close_bracket << ": " << open_bracket;
    print(std::forward<T>(first));
    ((std::cerr << ", ", print(std::forward<Args>(args))), ...);
    std::cerr << close_bracket << std::endl;
}

}  // namespace debug

#else

#define debug(...) static_cast<void>(0)

#endif

}  // namespace algorithm

#endif

/*
参考文献：
- 競技プログラミングで print デバッグ，https://naskya.net/post/0002/（参照2023.3.1）．
- EnumHack, C++メタ関数のまとめ，Qiita, https://qiita.com/_EnumHack/items/ee2141ad47915c55d9cb（参照2023.3.1）．
- terukazu, 特定のメンバ関数有無で、呼び出す関数を変えたい，Qiita, https://qiita.com/terukazu/items/e257c05a7b191d32c577（参照2023.3.1）．
*/
