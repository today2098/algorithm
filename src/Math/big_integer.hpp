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
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "../Utils/debug.hpp"

namespace algorithm {

class BigInteger {
    static constexpr int BASE_DIGIT = 8;
    static constexpr int64_t BASE[BASE_DIGIT + 1] = {1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000};

    bool m_sign;                   // m_sign:=(符号が負か).
    std::vector<int64_t> m_digit;  // m_digit[k]:=(BASE_DIGIT*k+1桁目の数).

    void convert(std::string_view s) {
        if(s.empty()) {
            m_digit.assign(1, 0);
            return;
        }
        if(s[0] == '-') {
            assert(s.substr(1) != "");
            convert(s.substr(1));
            if(m_digit.back() > 0) m_sign = true;
            return;
        }
        m_sign = false;
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
        while(m_digit.size() >= 2 and m_digit.back() == 0) m_digit.pop_back();
    }
    void addition(const std::vector<int64_t> &rhs) {
        const int sz = rhs.size();
        if(sz > m_digit.size()) m_digit.resize(sz, 0);
        for(int i = 0; i < sz; ++i) m_digit[i] += rhs[i];
    }
    void subtraction(const std::vector<int64_t> &rhs) {
        const int sz = rhs.size();
        if(sz > m_digit.size()) m_digit.resize(sz, 0);
        for(int i = 0; i < sz; ++i) m_digit[i] -= rhs[i];
    }
    void carry() {
        auto itr = std::find_if(m_digit.crbegin(), m_digit.crend(), [](int64_t x) -> bool { return x != 0; });
        if(itr != m_digit.crend() and *itr < 0) {
            m_sign = !m_sign;
            for(int64_t &elem : m_digit) elem = -elem;
        }
        for(int i = 0; i < m_digit.size(); ++i) {
            if(m_digit[i] < 0) {
                int64_t c = (-m_digit[i] - 1) / BASE[BASE_DIGIT] + 1;
                m_digit[i] += BASE[BASE_DIGIT] * c;
                m_digit[i + 1] -= c;
            } else if(10 <= m_digit[i]) {
                int64_t c = m_digit[i] / BASE[BASE_DIGIT];
                m_digit[i] -= BASE[BASE_DIGIT] * c;
                if(i + 1 < m_digit.size()) m_digit[i + 1] += c;
                else m_digit.push_back(c);
            }
        }
        while(m_digit.size() >= 2 and m_digit.back() == 0) m_digit.pop_back();
    }

public:
    BigInteger() : m_sign(false), m_digit(1, 0) {}
    explicit BigInteger(int64_t a) : m_sign(a < 0), m_digit(1, std::abs(a)) {}
    explicit BigInteger(std::string_view s) : m_sign(false) {
        convert(s);
    }

    BigInteger &operator+=(const BigInteger &rhs) {
        if(rhs.m_sign == m_sign) addition(rhs.m_digit);
        else subtraction(rhs.m_digit);
        carry();
        return *this;
    }
    BigInteger &operator-=(const BigInteger &rhs) {
        if(rhs.m_sign == m_sign) subtraction(rhs.m_digit);
        else addition(rhs.m_digit);
        carry();
        return *this;
    }
    friend std::istream &operator>>(std::istream &is, BigInteger &rhs) {
        std::string s;
        is >> s;
        rhs.convert(s);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const BigInteger &rhs) {
        os << (rhs.m_sign ? "-" : "") << rhs.m_digit.back();
        for(auto itr = rhs.m_digit.crbegin() + 1; itr < rhs.m_digit.crend(); ++itr) os << std::setfill('0') << std::right << std::setw(BASE_DIGIT) << *itr;
        return os;
    }

    // 符号が負か判定する．O(1).
    bool sign() const { return m_sign; }
    // 桁数を返す．
    int digit_number() const {
        int res = 1;
        while(res < BASE_DIGIT and m_digit.back() >= BASE[res]) res++;
        res += BASE_DIGIT * (m_digit.size() - 1);
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
