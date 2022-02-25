#ifndef ALGORITHM_ISQRT_HPP
#define ALGORITHM_ISQRT_HPP 1

#include <cassert>
#include <cmath>

namespace algorithm {

double isqrt(double x, double eps = 1e-12) {  // 平方根（ニュートン法）．
    assert(0.0 <= x);
    double res = 5.0;
    while(1) {
        double tmp = (x / res + res) / 2;
        if(std::abs(tmp - res) < eps) break;
        res = tmp;
    }
    return res;
}

}  // namespace algorithm

#endif  // ALGORITHM_ISQRT_HPP
