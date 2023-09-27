#ifndef ALGORITHM_BIG_INTEGER_HPP
#define ALGORITHM_BIG_INTEGER_HPP 1

/**
 * @brief 多倍長整数
 * @docs docs/Math/big_integer.md
 */

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace algorithm {

class BigInteger {
    std::vector<int32_t> m_digit;

public:
    BigInteger() : m_digit(1, 0) {}
    explicit BigInteger(const std::string &s) : m_digit(s.size() + 1, 0) {
        if(s.size() == 0) return;
        assert(('0' <= s[0] and s[0] <= '9') or s[0] == '-');
        const int n = s.size();
        for(int i = 0; i < n - 1; ++i) {
            assert('0' <= s[n - 1 - i] and s[n - 1 - i] <= '9');
            m_digit[i] = s[n - 1 - i] - '0';
        }
        if(s[0] != '-') m_digit[n - 1] = s[0] - '0';
        while(m_digit.size() >= 2 and m_digit.back() == 0) m_digit.pop_back();
        if(s[0] == '-') m_digit.back() = -m_digit.back();
    }
    explicit BigInteger(long long a) {
        bool is_minus = false;
        if(a < 0) is_minus = true, a = -a;
        while(a > 0) {
            m_digit.push_back(a % 10);
            a /= 10;
        }
        if(m_digit.empty()) m_digit.assign(1, 0);
        if(is_minus) m_digit.back() = -m_digit.back();
    };

    // 桁数を返す．O(1).
    int size() const { return m_digit.size(); }

    friend std::ostream &operator<<(std::ostream &os, const BigInteger &rhs) {
        for(auto itr = rhs.m_digit.crbegin(); itr != rhs.m_digit.crend(); ++itr) os << *itr;
        return os;
    }
};

}  // namespace algorithm

#endif
