#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cassert>
#include <iostream>
#include <limits>
#include <random>

#include "../src/Others/popcount.hpp"
#include "../src/Utils/debug.hpp"

template <typename Type>
int naive_popcount(Type n) {
    int res = 0;
    while(n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int main() {
    std::random_device seed;
    std::mt19937_64 rng(seed());

    for(int i = 0; i < 32; ++i) {
        uint32_t target = 1U << i;
        debug(target);
        assert(algorithm::popcount32(target) == naive_popcount(target));
    }
    assert(algorithm::popcount32(-1) == naive_popcount<uint32_t>(-1));

    std::uniform_int_distribution<int> uniform32(std::numeric_limits<int>::min(),
                                                 std::numeric_limits<int>::max());
    for(int i = 0; i < 100; ++i) {
        int target = uniform32(rng);
        debug(i, target);
        assert(algorithm::popcount32(target) == naive_popcount<uint32_t>(target));
    }

    for(int i = 0; i < 64; ++i) {
        uint64_t target = 1ULL << i;
        debug(target);
        assert(algorithm::popcount64(target) == naive_popcount(target));
    }
    assert(algorithm::popcount64(-1LL) == naive_popcount<uint64_t>(-1LL));

    std::uniform_int_distribution<long long> uniform64(std::numeric_limits<long long>::min(),
                                                       std::numeric_limits<long long>::max());
    for(int i = 0; i < 100; ++i) {
        long long target = uniform64(rng);
        debug(i, target);
        assert(algorithm::popcount64(target) == naive_popcount<uint64_t>(target));
    }

    std::cout << "Hello World" << std::endl;
}
