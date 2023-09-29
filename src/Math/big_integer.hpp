#ifndef ALGORITHM_BIG_INTEGER_HPP
#define ALGORITHM_BIG_INTEGER_HPP 1

/**
 * @brief 多倍長整数
 * @docs docs/Math/big_integer.md
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../Utils/debug.hpp"

namespace algorithm {

class BigInteger {
    static constexpr int BASE_DIGIT = 8;
    static constexpr int64_t BASE[BASE_DIGIT + 1] = {1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000};

    std::vector<int64_t> m_digit;  // m_digit[k]:=(BASE_DIGIT*k+1桁目の数).

    void convert(const std::string &s) {
        if(s.empty()) {
            m_digit.assign(1, 0);
            return;
        }
        if(s[0] == '-') {
            assert(s != "-");
            const int n = s.size();
            const int sz = (n - 1 + BASE_DIGIT - 1) / BASE_DIGIT;
            m_digit.assign(sz, 0);
            for(int i = 0; i < sz; ++i) {
                int offset = BASE_DIGIT * i;
                for(int j = 0; j < BASE_DIGIT and offset + j < n - 1; ++j) {
                    assert('0' <= s[n - 1 - (offset + j)] and s[n - 1 - (offset + j)] <= '9');
                    m_digit[i] -= BASE[j] * (s[n - 1 - (offset + j)] - '0');
                }
            }
        } else {
            const int n = s.size();
            const int sz = (n + BASE_DIGIT - 1) / BASE_DIGIT;
            m_digit.assign(sz, 0);
            for(int i = 0; i < sz; ++i) {
                int offset = BASE_DIGIT * i;
                for(int j = 0; j < BASE_DIGIT and offset + j < n; ++j) {
                    assert('0' <= s[n - 1 - (offset + j)] and s[n - 1 - (offset + j)] <= '9');
                    m_digit[i] += BASE[j] * (s[n - 1 - (offset + j)] - '0');
                }
            }
        }
        while(m_digit.size() >= 2 and m_digit.back() == 0) m_digit.pop_back();
    }

public:
    BigInteger() : m_digit(1, 0) {}
    explicit BigInteger(int64_t a) : m_digit(1, a) {}
    explicit BigInteger(const std::string &s) {
        convert(s);
    }

    friend std::istream &operator>>(std::istream &is, BigInteger &rhs) {
        std::string s;
        is >> s;
        rhs.convert(s);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const BigInteger &rhs) {
        os << rhs.m_digit.back();
        for(auto itr = rhs.m_digit.crbegin() + 1; itr < rhs.m_digit.crend(); ++itr) os << std::setfill('0') << std::right << std::setw(BASE_DIGIT) << std::abs(*itr);
        return os;
    }

    // 桁数を返す．
    int digit_number() const {
        int res = 1;
        while(res < BASE_DIGIT and std::abs(m_digit.back()) >= BASE[res]) res++;
        res += BASE_DIGIT * ((int)m_digit.size() - 1);
        return res;
    }
    std::string to_string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    };
};

}  // namespace algorithm

#endif
