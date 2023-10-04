#ifndef ALGORITHM_DISCRETE_FOURIER_TRANSFORM_HPP
#define ALGORITHM_DISCRETE_FOURIER_TRANSFORM_HPP 1

/**
 * @brief Discrete Fourier Transform（離散フーリエ変換）
 * @docs docs/Math/FFT/discrete_fourier_transform.md
 */

#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>

namespace algorithm {

namespace dft {

using D = double;

const D PI = std::acos(-1.0);

// Discrete Fourier Transform（離散フーリエ変換）. O(N^2).
void transform(std::vector<std::complex<D> > &a, bool inv = false) {
    const int n = a.size();
    std::vector<std::complex<D> > res(n, 0.0);
    D ang = 2 * PI / n;
    if(inv) ang = -ang;
    for(int i = 0; i < n; ++i) {
        D tmp = ang * i;
        for(int j = 0; j < n; ++j) res[i] += a[j] * std::polar<D>(1.0, tmp * j);
    }
    if(inv) {
        for(int i = 0; i < n; ++i) res[i] /= n;
    }
    a = res;
}

// 畳み込み．
// 数列a, bに対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列cを求める．O(N^2).
std::vector<double> convolve(const std::vector<double> &a, const std::vector<double> &b) {
    if(a.size() == 0 or b.size() == 0) return std::vector<double>();
    const int n = a.size() + b.size() - 1;
    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0);
    std::copy(a.begin(), a.end(), na.begin());
    std::copy(b.begin(), b.end(), nb.begin());
    transform(na), transform(nb);
    for(int i = 0; i < n; ++i) na[i] *= nb[i];
    transform(na, true);
    std::vector<double> res(n);
    for(int i = 0; i < n; ++i) res[i] = na[i].real();
    return res;
}

// 畳み込み．
// 数列a, bに対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列cを求める．O(N^2).
std::vector<long long> convolve(const std::vector<long long> &a, const std::vector<long long> &b) {
    if(a.size() == 0 or b.size() == 0) return std::vector<long long>();
    const int n = a.size() + b.size() - 1;
    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0);
    std::copy(a.begin(), a.end(), na.begin());
    std::copy(b.begin(), b.end(), nb.begin());
    transform(na), transform(nb);
    for(int i = 0; i < n; ++i) na[i] *= nb[i];
    transform(na, true);
    std::vector<long long> res(n);
    for(int i = 0; i < n; ++i) res[i] = na[i].real() + 0.5;
    return res;
}

}  // namespace dft

}  // namespace algorithm

#endif
