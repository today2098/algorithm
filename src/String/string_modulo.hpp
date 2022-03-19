#ifndef ALGORITHM_STRING_MODULO_HPP
#define ALGORITHM_STRING_MODULO_HPP 1

#include <cassert>
#include <string>

namespace algorithm {

long long string_modulo(const std::string &s, int m) {  // O(|S|).
    int n = s.size();
    long long res = 0;
    for(int i = 0; i < n; ++i) {
        assert('0' <= s[i] and s[i] <= '9');
        res = (10 * res + (s[i] - '0')) % m;
    }
    return res;
}

}  // namespace algorithm

#endif  // ALGORITHM_STRING_MODULO_HPP
