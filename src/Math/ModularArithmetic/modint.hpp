#ifndef ALGORITHM_MODINT_HPP
#define ALGORITHM_MODINT_HPP 1

/**
 * @brief Modint構造体
 * @docs docs/Math/ModularArithmetic/modint.md
 */

#include <iostream>
#include <utility>

#include "modint_base.hpp"

namespace algorithm {

template <int mod>
class Modint : ModintBase {
    long long val;

    void normalize() {
        if(val < -mod or mod <= val) val %= mod;
        if(val < 0) val += mod;
    }

public:
    Modint() : Modint(0) {}
    Modint(long long val_) : val(val_) {
        static_assert(mod >= 1);
        normalize();
    }

    Modint operator+() const { return Modint(*this); }
    Modint operator-() const { return (val == 0 ? Modint(*this) : Modint(mod - val)); }
    Modint &operator++() {
        val++;
        if(val == mod) val = 0;
        return *this;
    }
    Modint &operator--() {
        if(val == 0) val = mod;
        val--;
        return *this;
    }
    Modint operator++(int) {
        Modint res = *this;
        ++(*this);
        return res;
    }
    Modint operator--(int) {
        Modint res = *this;
        --(*this);
        return res;
    }
    Modint &operator+=(const Modint &rhs) {
        val += rhs.val;
        if(val >= mod) val -= mod;
        return *this;
    }
    Modint &operator-=(const Modint &rhs) {
        val -= rhs.val;
        if(val < 0) val += mod;
        return *this;
    }
    Modint &operator*=(const Modint &rhs) {
        val = val * rhs.val % mod;
        return *this;
    }
    Modint &operator/=(const Modint &rhs) { return *this *= rhs.inv(); }

    friend bool operator==(const Modint &lhs, const Modint &rhs) { return lhs.val == rhs.val; }
    friend bool operator!=(const Modint &lhs, const Modint &rhs) { return lhs.val != rhs.val; }
    friend Modint operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs) += rhs; }
    friend Modint operator-(const Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }
    friend Modint operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }
    friend Modint operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs) /= rhs; }
    friend std::istream &operator>>(std::istream &is, Modint &rhs) {
        is >> rhs.val;
        rhs.normalize();
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Modint &rhs) { return os << rhs.val; }

    static constexpr int modulus() { return mod; }
    long long value() const { return val; }
    Modint inv() const {
        long long a = mod, b = val, u = 0, v = 1;
        while(b != 0) {
            long long t = a / b;
            a -= b * t, u -= v * t;
            std::swap(a, b), std::swap(u, v);
        }
        return Modint(u);
    }
    Modint pow(long long k) const {
        if(k < 0) return inv().pow(-k);
        Modint res = 1, mul = *this;
        while(k > 0) {
            if(k & 1LL) res *= mul;
            mul *= mul;
            k >>= 1;
        }
        return res;
    }

    friend Modint mod_inv(const Modint &a) { return a.inv(); }
    friend Modint mod_pow(const Modint &a, long long k) { return a.pow(k); }
};

using mint998244353 = Modint<998'244'353>;
using mint1000000007 = Modint<1'000'000'007>;

}  // namespace algorithm

#endif
