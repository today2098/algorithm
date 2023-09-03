#ifndef ALGORITHM_TABLE_HPP
#define ALGORITHM_TABLE_HPP 1

#include <utility>
#include <vector>

namespace algorithm {

template <typename Type>
inline std::vector<Type> table(size_t n, const Type &val) { return std::vector<Type>(n, val); }

template <typename... Args>
auto table(size_t n, const Args &...args) {
    auto val = table(args...);
    return std::vector<decltype(val)>(n, std::move(val));
}

}  // namespace algorithm

#endif
