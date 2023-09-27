#ifndef ALGORITHM_DISCRETE_FOURIER_TRANSFORMATION_HPP
#define ALGORITHM_DISCRETE_FOURIER_TRANSFORMATION_HPP 1

#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>

namespace algorithm {

namespace dft {

using D = double;

const D PI = std::acos(-1.0);

// 離散フーリエ変換．O(N^2).
std::vector<std::complex<D> > transform(const std::vector<std::complex<D> > &a, bool inv = false) {
    const int n = a.size();
    std::vector<std::complex<D> > res(n, 0.0);
    for(int i = 0; i < n; ++i) {
        D ang = 2 * PI / n * i;
        if(inv) ang = -ang;
        for(int j = 0; j < n; ++j) res[i] += a[j] * std::polar(1.0, ang * j);
    }
    if(inv) {
        for(int i = 0; i < n; ++i) res[i] /= n;
    }
    return res;
}

// 畳み込み．
// c[k]=sum_{i=0}^{k} a[i]*b[k-i] を求める．O(N^2).
std::vector<long long> convolution(const std::vector<long long> &a, const std::vector<long long> &b) {
    if(a.size() == 0 or b.size() == 0) return std::vector<long long>();
    const int n = a.size() + b.size() - 1;
    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0), c(n);
    std::copy(a.begin(), a.end(), na.begin());
    std::copy(b.begin(), b.end(), nb.begin());
    na = transform(na), nb = transform(nb);
    for(int i = 0; i < n; ++i) c[i] = na[i] * nb[i];
    c = transform(c, true);
    std::vector<long long> res(n);
    for(int i = 0; i < n; ++i) res[i] = c[i].real() + 0.5;
    return res;
}

}  // namespace dft

}  // namespace algorithm

#endif