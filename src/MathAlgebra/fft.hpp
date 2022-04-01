#ifndef ALGORITHM_FFT_HPP
#define ALGORITHM_FFT_HPP 1

#include <algorithm>  // for max().
#include <cassert>
#include <cmath>    // for acos().
#include <complex>  // for complex and polar().
#include <vector>

namespace algorithm {

namespace fourier {

using D = double;
const D PI = std::acos(-1.0);

// 離散フーリエ変換 (DFT:Discrete Fourier Transform)．O(N^2).
std::vector<std::complex<D> > dft(const std::vector<std::complex<D> > &a, bool inverse = false) {
    const int n = a.size();
    std::vector<std::complex<D> > res(n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) res[i] += a[j] * std::polar<D>(1.0, (inverse ? -1 : 1) * 2 * PI / n * i * j);
    if(inverse) {
        for(int i = 0; i < n; ++i) res[i] /= n;
    }
    return res;
}

// 高速フーリエ変換 (FFT:Fast Fourier Transform)．|A|は2冪と想定．O(N*logN).
void fft(std::vector<std::complex<D> > &a, bool inverse = false, bool first = true) {
    const int n = a.size();
    if(n == 1) return;
    std::vector<std::complex<D> > even(n / 2), odd(n / 2);
    for(int i = 0; i < n / 2; ++i) even[i] = a[2 * i], odd[i] = a[2 * i + 1];
    fft(even, inverse, false), fft(odd, inverse, false);
    for(int i = 0; i < n / 2; ++i) {
        odd[i] *= std::polar<D>(1.0, (inverse ? -1 : 1) * 2 * PI / n * i);
        a[i] = even[i] + odd[i];
        a[n / 2 + i] = even[i] - odd[i];
    }
    if(first and inverse) {
        for(int i = 0; i < n; ++i) a[i] /= n;
    }
}

// 高速フーリエ変換 (FFT:Fast Fourier Transform)．Cooley–Tukey型FFTアルゴリズム．|A|は2冪と想定．O(N*logN).
void fft_cooley_tukey(std::vector<std::complex<D> > &a, bool inverse = false) {
    const int n = a.size();  // n=2^h.
    int h = 0;               // h:=log_2(n).
    while(1 << h < n) h++;
    assert(n == 1 << h);
    for(int i = 0; i < n; ++i) {
        int j = 0;
        for(int k = 0; k < h; ++k) j |= ((i >> k & 1) << (h - 1 - k));
        if(i < j) std::swap(a[i], a[j]);
    }
    for(int t = 1; t < n; t <<= 1)
        for(int i = 0; i < t; ++i) {
            std::complex<D> w = std::polar<D>(1.0, (inverse ? -1 : 1) * 2 * PI / (2 * t) * i);
            for(int j = 0; j < n; j += 2 * t) {
                std::complex<D> c1 = a[i + j];
                std::complex<D> c2 = a[i + j + t] * w;
                a[i + j] = c1 + c2;
                a[i + j + t] = c1 - c2;
            }
        }
    if(inverse) {
        for(int i = 0; i < n; ++i) a[i] /= n;
    }
}

// 畳み込み．c_i=sum_{j=0}^{i}(a_j*b_{i-j}) を求める．O(N^2).
template <typename Type>
std::vector<Type> convolution_naive(const std::vector<Type> &a, const std::vector<Type> &b) {
    const int n = a.size(), m = b.size();
    std::vector<Type> res(n + m - 1, 0);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) res[i + j] += a[i] * b[j];
    return res;
}

// 畳み込み．c_i=sum_{j=0}^{i}(a_j*b_{i-j}) を求める．O(N*logN).
std::vector<double> convolution_fft(const std::vector<double> &a, const std::vector<double> &b) {
    const int an = a.size(), bn = b.size();
    int n = 1;
    const int s = an + bn - 1;
    while(n < s) n <<= 1;
    std::vector<std::complex<D> > ca(n), cb(n);
    for(int i = 0; i < an; ++i) ca[i] = std::complex<D>(a[i], 0.0);
    for(int i = 0; i < bn; ++i) cb[i] = std::complex<D>(b[i], 0.0);
    fft_cooley_tukey(ca), fft_cooley_tukey(cb);
    for(int i = 0; i < n; ++i) ca[i] *= cb[i];
    fft_cooley_tukey(ca, true);
    ca.resize(s);
    std::vector<double> res(s);
    for(int i = 0; i < s; ++i) res[i] = (double)ca[i].real();
    return res;
}

std::vector<long long> convolution_fft(const std::vector<long long> &a, const std::vector<long long> &b) {
    const int an = a.size(), bn = b.size();
    int n = 1;
    const int s = an + bn - 1;
    while(n < s) n <<= 1;
    std::vector<std::complex<D> > ca(n), cb(n);
    for(int i = 0; i < an; ++i) ca[i] = std::complex<D>(a[i], 0.0);
    for(int i = 0; i < bn; ++i) cb[i] = std::complex<D>(b[i], 0.0);
    fft_cooley_tukey(ca), fft_cooley_tukey(cb);
    for(int i = 0; i < n; ++i) ca[i] *= cb[i];
    fft_cooley_tukey(ca, true);
    ca.resize(s);
    std::vector<long long> res(s);
    for(int i = 0; i < s; ++i) res[i] = (long long)(ca[i].real() + 0.5);
    return res;
}

}  // namespace fourier

}  // namespace algorithm

#endif  // ALGORITHM_FFT_HPP
