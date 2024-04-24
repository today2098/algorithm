#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cassert>
#include <cmath>
#include <iostream>
#include <random>

#include "../src/Math/Convolution/discrete_fourier_transform.hpp"
#include "../src/Utils/debug.hpp"

int main() {
    std::random_device seed;
    std::mt19937_64 rng(seed());
    std::uniform_int_distribution<int> uniform_n(1, 200);
    std::uniform_real_distribution<double> uniform(-1e3, 1e3);
    for(int i = 0; i < 100; ++i) {
        const int n = uniform_n(rng), m = uniform_n(rng);
        std::vector<double> a(n), b(m);
        for(auto &elem : a) elem = uniform(rng);
        for(auto &elem : b) elem = uniform(rng);
        debug(n, a);
        debug(m, b);

        auto res = algorithm::dft::convolve(a, b);
        auto res_naive = algorithm::dft::convolve_naive(a, b);
        debug(res.size(), res);
        debug(res_naive.size(), res_naive);
        assert(res.size() == unsigned(n + m - 1));
        assert(res_naive.size() == unsigned(n + m - 1));
        for(int j = 0; j < n + m - 1; ++j) assert(std::abs(res[j] - res_naive[j]) < 1e-6);
    }

    std::cout << "Hello World" << std::endl;
}
