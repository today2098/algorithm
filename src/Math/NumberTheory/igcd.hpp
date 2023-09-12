/**
 * @brief Greatest Common Divisor（最大公約数）
 */

#ifndef ALGORITHM_IGCD_HPP
#define ALGORITHM_IGCD_HPP 1

namespace algorithm {

// Greatest Common Divisor（最大公約数）. O(logN).
template <typename Type>
Type igcd(Type a, Type b) { return (b == 0) ? a : igcd(b, a % b); }

}  // namespace algorithm

#endif
