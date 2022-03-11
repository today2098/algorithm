#ifndef ALGORITHM_MODINT_HPP
#define ALGORITHM_MODINT_HPP 1

#include <cassert>
#include <iostream>
#include <utility>

namespace algorithm {

template <int mod>
class Modint {
    long long val;

public:
    // constructor.
    Modint() : Modint(0) {}
    Modint(long long val_) : val(val_) {
        assert(mod >= 1);
        val = (val % mod + mod) % mod;
    }

    Modint operator-() const { return Modint(-val); }
    Modint operator++(int) {
        Modint tmp = *this;
        (*this) += 1;
        return tmp;
    }
    Modint operator--(int) {
        Modint tmp = *this;
        (*this) -= 1;
        return tmp;
    }
    Modint &operator++() { return (*this) += 1; }
    Modint &operator--() { return (*this) -= 1; }
    Modint operator*(const Modint &a) const { return Modint(*this) *= a; }
    Modint operator/(const Modint &a) const { return Modint(*this) /= a; }
    Modint operator+(const Modint &a) const { return Modint(*this) += a; }
    Modint operator-(const Modint &a) const { return Modint(*this) -= a; }
    Modint &operator*=(const Modint &a) {
        val = val * a.val % mod;
        return *this;
    }
    Modint &operator/=(const Modint &a) { return (*this) *= a.inv(); }
    Modint &operator+=(const Modint &a) {
        val = (val + a.val) % mod;
        return *this;
    }
    Modint &operator-=(const Modint &a) {
        val = (val - a.val + mod) % mod;
        return *this;
    }
    bool operator==(const Modint &a) const { return val == a.val; }
    bool operator!=(const Modint &a) const { return val != a.val; }
    friend std::istream &operator>>(std::istream &is, Modint<mod> &x) {
        is >> x.val;
        x.val = (x.val % mod + mod) % mod;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Modint<mod> &x) { return os << x.val; }

    long long value() const { return val; }
    int modulus() const { return mod; }
    Modint inv() const {
        long long a = val, b = mod, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b, u -= t * v;
            std::swap(a, b), std::swap(u, v);
        }
        return Modint(u);
    }

    friend Modint<mod> pow(const Modint<mod> &x, long long k) {
        if(k == 0LL) return 1;
        if(k < 0LL) return pow(x.inv(), -k);
        Modint<mod> res = 1, tmp = x;
        while(k > 0LL) {
            if(k & 1LL) res *= tmp;
            tmp = tmp * tmp, k >>= 1;
        }
        return res;
    }
};

using mint998244353 = Modint<998'244'353>;
using mint = Modint<1'000'000'007>;

}  // namespace algorithm

#endif  // ALGORITHM_MODINT_HPP
