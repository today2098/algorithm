#ifndef ALGORITHM_DIVISOR_HPP
#define ALGORITHM_DIVISOR_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// 最大公約数 (GCD: Greatest Common Divisor)．O(logN).
template <typename Type>
Type igcd(Type a, Type b) { return (b == 0) ? a : igcd(b, a % b); }

// 最小公倍数 (LCM: Least Common Multiple)．O(logN).
template <typename Type>
Type ilcm(Type a, Type b) { return a / igcd(a, b) * b; }

// 約数列挙．O(√N).
template <typename Type>
std::vector<Type> divisors(Type n) {
    assert(n >= 0);
    std::vector<Type> res;  // res[]:=(自然数nの約数の集合).
    for(Type p = 1; p * p <= n; ++p) {
        if(n % p == 0) {
            res.push_back(p);
            Type q = n / p;
            if(q != p) res.push_back(q);
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

}  // namespace algorithm

#endif
