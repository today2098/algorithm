#ifndef ALGORITHM_DIVISOR_HPP
#define ALGORITHM_DIVISOR_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

template <typename Type>
std::vector<Type> calc_divisors(Type n) {  // 約数列挙．O(√N).
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

#endif  // ALGORITHM_DIVISOR_HPP
