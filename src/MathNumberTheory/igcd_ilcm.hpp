#ifndef ALGORITHM_IGCD_ILCM_HPP
#define ALGORITHM_IGCD_ILCM_HPP 1

namespace algorithm {

template <typename Type>
Type igcd(Type x, Type y) { return (y == 0) ? x : igcd(y, x % y); }  // 最大公約数 (GCD:Greatest Common Divisor).

template <typename Type>
Type ilcm(Type x, Type y) { return x / igcd(x, y) * y; }  // 最小公倍数 (LCM:Least Common Multiple).

}  // namespace algorithm

#endif  // ALGORITHM_IGCD_ILCM_HPP
