/**
 * @docs docs/Utils/debug.md
 */

#ifndef ALGORITHM_DEBUG_HPP
#define ALGORITHM_DEBUG_HPP 1

#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

namespace algorithm {

// #define DEBUG

#ifdef DEBUG

#define debug(...) debug::debug_internal(__LINE__, #__VA_ARGS__, __VA_ARGS__)

namespace debug {

constexpr std::ostream &os = std::cerr;

struct has_iterator_impl {
    template <class T>
    static constexpr std::true_type check(typename T::iterator *);

    template <class T>
    static constexpr std::false_type check(...);
};

template <class T>
class has_iterator : public decltype(has_iterator_impl::check<T>(nullptr)) {};

// Prototype declaration.
void print(const std::string &s);
void print(const std::string_view &s);
template <typename T, typename U>
void print(const std::pair<T, U> &p);
template <class T, std::size_t... Idx>
void print_tuple(const T &t, std::index_sequence<Idx...>);
template <typename... T>
void print(const std::tuple<T...> &t);
template <typename T>
void print(const std::stack<T> &st);
template <typename T>
void print(const std::queue<T> &que);
template <typename T, typename... U>
void print(const std::priority_queue<T, U...> &pque);
template <typename T, typename std::enable_if_t<has_iterator<T>::value, bool> = false>
void print(const T &v);
template <typename T, typename std::enable_if_t<!has_iterator<T>::value, bool> = false>
void print(const T &elem);
template <typename T, typename... Args>
void debug_internal(int l, std::string_view context, T &&first, Args &&...args);

void print(const std::string &s) { os << s; }

void print(const std::string_view &s) { os << s; }

template <typename T, typename U>
void print(const std::pair<T, U> &p) {
    os << "{";
    print(p.first);
    os << ", ";
    print(p.second);
    os << "}";
}

template <class T, std::size_t... Idx>
void print_tuple(const T &t, std::index_sequence<Idx...>) {
    os << "{";
    ((os << (Idx == 0 ? "" : ", "), print(std::get<Idx>(t))), ...);
    os << "}";
}

template <typename... T>
void print(const std::tuple<T...> &t) {
    print_tuple(t, std::make_index_sequence<sizeof...(T)>());
}

template <typename T>
void print(const std::stack<T> &st) {
    std::stack<T> tmp = st;
    os << "[";
    while(!tmp.empty()) {
        T elem = tmp.top();
        tmp.pop();
        print(elem);
        if(!tmp.empty()) os << " ";
    }
    os << "]";
}

template <typename T>
void print(const std::queue<T> &que) {
    std::queue<T> tmp = que;
    os << "[";
    while(!tmp.empty()) {
        T elem = tmp.front();
        tmp.pop();
        print(elem);
        if(!tmp.empty()) os << " ";
    }
    os << "]";
}

template <typename T, typename... U>
void print(const std::priority_queue<T, U...> &pque) {
    std::priority_queue<T, U...> tmp = pque;
    os << "[";
    while(!tmp.empty()) {
        T elem = tmp.top();
        tmp.pop();
        print(elem);
        if(!tmp.empty()) os << " ";
    }
    os << "]";
}

template <class T, typename std::enable_if_t<has_iterator<T>::value, bool> = false>
void print(const T &v) {
    os << "[";
    for(auto itr = std::cbegin(v); itr != std::cend(v); ++itr) {
        if(itr != std::cbegin(v)) os << " ";
        print(*itr);
    }
    os << "]";
}

template <typename T, typename std::enable_if_t<!has_iterator<T>::value, bool> = false>
void print(const T &elem) { os << elem; }

template <typename T, typename... Args>
void debug_internal(int l, std::string_view context, T &&first, Args &&...args) {
    constexpr const char *open_bracket = (sizeof...(args) == 0 ? "" : "(");
    constexpr const char *close_bracket = (sizeof...(args) == 0 ? "" : ")");
    os << "[L" << l << "] " << open_bracket << context << close_bracket << ": " << open_bracket;
    print(std::forward<T>(first));
    ((os << ", ", print(std::forward<Args>(args))), ...);
    os << close_bracket << std::endl;
}

}  // namespace debug

#else

#define debug(...) static_cast<void>(0)

#endif

}  // namespace algorithm

#endif
