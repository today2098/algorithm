#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "../src/Math/Convolution/number_theoretic_transform.hpp"
#include "../src/Math/ModularArithmetic/modint.hpp"
#include "../src/Utils/debug.hpp"

int main() {
    std::random_device seed;
    std::mt19937_64 rng(seed());

    std::uniform_int_distribution<int> uniform_n(1, 1000);
    std::uniform_int_distribution<long long> uniform(-1e18, 1e18);
    for(int i = 0; i < 100; ++i) {
        const int n = uniform_n(rng), m = uniform_n(rng);
        std::vector<algorithm::mint998244353> a(n), b(m);
        for(auto &elem : a) elem = uniform(rng);
        for(auto &elem : b) elem = uniform(rng);
        debug(n, a);
        debug(m, b);

        auto &&res = algorithm::ntt::convolve(a, b);
        auto &&res_naive = algorithm::ntt::convolve_naive(a, b);
        debug(res.size(), res);
        debug(res_naive.size(), res_naive);

        assert(res.size() == size_t(n + m - 1));
        assert(res_naive.size() == size_t(n + m - 1));
        for(int j = 0; j < n + m - 1; ++j) assert(res[j] == res_naive[j]);
    }

    std::cout << "Hello World" << std::endl;
}
