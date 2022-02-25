#ifndef ALGORITHM_COUNT_BITS_HPP
#define ALGORITHM_COUNT_BITS_HPP 1

namespace algorithm {

int count_bits32(unsigned int n) {
    unsigned int masks[5] = {0x55555555U, 0x33333333U, 0x0f0f0f0fU, 0x00ff00ffU, 0x0000ffffU};
    for(int i = 0; i < 5; ++i) n = (n & masks[i]) + ((n >> (1 << i)) & masks[i]);
    return n;
}

int count_bits64(unsigned long long n) {
    unsigned long long masks[6] = {0x5555555555555555ULL, 0x3333333333333333ULL, 0x0f0f0f0f0f0f0f0fULL,
                                   0x00ff00ff00ff00ffULL, 0x0000ffff0000ffffULL, 0x00000000ffffffffULL};
    for(int i = 0; i < 6; ++i) n = (n & masks[i]) + ((n >> (1 << i)) & masks[i]);
    return n;
}

}  // namespace algorithm

#endif  // ALGORITHM_COUNT_BITS_HPP
