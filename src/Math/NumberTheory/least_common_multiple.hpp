#ifndef ALGORITHM_LEAST_COMMON_MULTIPLE_HPP
#define ALGORITHM_LEAST_COMMON_MULTIPLE_HPP 1

/**
 * @brief Least Common Multiple（最小公倍数）
 * @docs docs/Math/NumberTheory/least_common_multiple.md
 */

#include "greatest_common_divisor.hpp"

namespace algorithm {

// Least Common Multiple（最小公倍数）. O(log(min(a,b))).
template <typename Type>
Type ilcm(Type a, Type b) { return a / igcd(a, b) * b; }

}  // namespace algorithm

#endif
