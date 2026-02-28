#ifndef ALGORITHM_DEBUG_HPP
#define ALGORITHM_DEBUG_HPP 1

#include <chrono>
#include <concepts>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <queue>
#include <ranges>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>

#ifdef DEBUG

#define debug(...) algorithm::debug::debug_internal(std::clog, __LINE__ __VA_OPT__(, #__VA_ARGS__, __VA_ARGS__))

namespace algorithm {

namespace debug {

// Forward declaration.

template <typename C, typename Tr, typename Type>
void print(std::basic_ostream<C, Tr> &, const Type &);

template <typename C, typename Tr, std::ranges::input_range R>
    requires(!std::convertible_to<R, const char *>)
void print(std::basic_ostream<C, Tr> &, const R &);

template <typename C, typename Tr>
void print(std::basic_ostream<C, Tr> &, const char *);

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &, const std::basic_string<Types...> &);

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &, std::basic_string_view<Types...>);

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &, std::stack<Types...>);

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &, std::queue<Types...>);

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &, std::priority_queue<Types...>);

template <typename C, typename Tr, typename T, typename U>
void print(std::basic_ostream<C, Tr> &, const std::pair<T, U> &);

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &, const std::tuple<Types...> &);

template <typename C, typename Tr, typename... Types, std::size_t... Idxes>
void print_tuple(std::basic_ostream<C, Tr> &, const std::tuple<Types...> &, std::index_sequence<Idxes...>);

template <typename C, typename Tr, typename Type>
void print(std::basic_ostream<C, Tr> &, const std::initializer_list<Type> &);

// Implementation.

auto elapsed() {
    static const auto start = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count();
}

template <typename C, typename Tr, typename Type, typename... Args>
void debug_internal(std::basic_ostream<C, Tr> &os, int line, std::string_view context, Type &&first, Args &&...args) {
    constexpr const char *open_bracket = (sizeof...(args) == 0 ? "" : "(");
    constexpr const char *close_bracket = (sizeof...(args) == 0 ? "" : ")");
    os << "(" << std::setw(8) << elapsed() << ") [L" << line << "] " << open_bracket << context << close_bracket << ": " << open_bracket;
    print(os, std::forward<Type>(first));
    ((os << ", ", print(os, std::forward<Args>(args))), ...);
    os << close_bracket << std::endl;
}

template <typename C, typename Tr>
void debug_internal(std::basic_ostream<C, Tr> &os, int line) {
    os << "(" << std::setw(8) << elapsed() << ") [L" << line << "] (empty)" << std::endl;
}

template <typename C, typename Tr, typename Type>
void print(std::basic_ostream<C, Tr> &os, const Type &a) {
    os << a;
}

template <typename C, typename Tr, std::ranges::input_range R>
    requires(!std::convertible_to<R, const char *>)
void print(std::basic_ostream<C, Tr> &os, const R &r) {
    os << "[";
    auto iter = std::ranges::cbegin(r);
    const auto end = std::ranges::cend(r);
    if(iter != end) {
        print(os, *iter++);
        while(iter != end) {
            os << " ";
            print(os, *iter++);
        }
    }
    os << "]";
}

template <typename C, typename Tr>
void print(std::basic_ostream<C, Tr> &os, const char *s) {
    os << s;
}

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &os, const std::basic_string<Types...> &s) {
    os << s;
}

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &os, std::basic_string_view<Types...> sv) {
    os << sv;
}

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &os, std::stack<Types...> st) {
    os << "[";
    if(!st.empty()) {
        print(os, st.top());
        st.pop();
        for(; !st.empty(); st.pop()) {
            os << " ";
            print(os, st.top());
        }
    }
    os << "]";
}

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &os, std::queue<Types...> que) {
    os << "[";
    if(!que.empty()) {
        print(os, que.front());
        que.pop();
        for(; !que.empty(); que.pop()) {
            os << " ";
            print(os, que.front());
        }
    }
    os << "]";
}

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &os, std::priority_queue<Types...> pque) {
    os << "[";
    if(!pque.empty()) {
        print(os, pque.top());
        pque.pop();
        for(; !pque.empty(); pque.pop()) {
            os << " ";
            print(os, pque.top());
        }
    }
    os << "]";
}

template <typename C, typename Tr, typename T, typename U>
void print(std::basic_ostream<C, Tr> &os, const std::pair<T, U> &p) {
    os << "{";
    print(os, p.first);
    os << ", ";
    print(os, p.second);
    os << "}";
}

template <typename C, typename Tr, typename... Types>
void print(std::basic_ostream<C, Tr> &os, const std::tuple<Types...> &t) {
    print_tuple(os, t, std::make_index_sequence<sizeof...(Types)>());
}

template <typename C, typename Tr, typename... Types, std::size_t... Idxes>
void print_tuple(std::basic_ostream<C, Tr> &os, const std::tuple<Types...> &t, std::index_sequence<Idxes...>) {
    os << "{";
    ((os << (Idxes == 0 ? "" : ", "), print(os, std::get<Idxes>(t))), ...);
    os << "}";
}

template <typename C, typename Tr, typename Type>
void print(std::basic_ostream<C, Tr> &os, const std::initializer_list<Type> &il) {
    print(os, std::ranges::subrange(il.begin(), il.end()));
}

}  // namespace debug

}  // namespace algorithm

#else

#define debug(...) static_cast<void>(0)

#endif

#endif
