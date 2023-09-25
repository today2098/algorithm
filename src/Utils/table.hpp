/**
 * @docs docs/Utils/table.md
 */

#ifndef ALGORITHM_TABLE_HPP
#define ALGORITHM_TABLE_HPP 1

#include <vector>

namespace algorithm {

template <typename Type>
inline std::vector<Type> table(size_t n, const Type &val) { return std::vector<Type>(n, val); }

template <typename... Args>
inline auto table(size_t n, const Args &...args) { return std::vector(n, table(args...)); }

}  // namespace algorithm

#endif
