#ifndef ALGORITHM_TABLE_HPP
#define ALGORITHM_TABLE_HPP 1

namespace algorithm {

#include <utility>  // for move().
#include <vector>

template <typename Type>
std::vector<Type> table(size_t n, Type val) { return std::vector<Type>(n, val); }

template <class... Args>
auto table(size_t n, Args... args) {
    auto val = table(args...);
    return std::vector<decltype(val)>(n, std::move(val));
}

}  // namespace algorithm

#endif  // ALGORITHM_TABLE_HPP
