/**
 * @brief Least Common Multiple（最小公倍数）
 */

#ifndef ALGORITHM_ILCM_HPP
#define ALGORITHM_ILCM_HPP 1

#include "igcd.hpp"

namespace algorithm {

// Least Common Multiple（最小公倍数）. O(logN).
template <typename Type>
Type ilcm(Type a, Type b) { return a / igcd(a, b) * b; }

}  // namespace algorithm

#endif
