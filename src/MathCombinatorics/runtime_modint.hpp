#ifndef ALGORITHM_RUNTIME_MODINT_HPP
#define ALGORITHM_RUNTIME_MODINT_HPP

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

namespace algorithm {

namespace runtime_modint {

std::vector<int> mods({998'244'353, 1'000'000'007});

template <int id>
class RuntimeModint {
    long long val;

public:
    // constructor.
    RuntimeModint() : RuntimeModint(0) {}
    explicit RuntimeModint(long long val_) : val(val_) {
        assert(mods[id] >= 1);
        val = (val % mods[id] + mods[id]) % mods[id];
    }

    bool operator==(const RuntimeModint &a) const { return val == a.val; }
    bool operator!=(const RuntimeModint &a) const { return val != a.val; }
    RuntimeModint operator-() const { return RuntimeModint(-val); }
    RuntimeModint operator+(const RuntimeModint &a) const { return RuntimeModint(*this) += a; }
    RuntimeModint operator-(const RuntimeModint &a) const { return RuntimeModint(*this) -= a; }
    RuntimeModint operator*(const RuntimeModint &a) const { return RuntimeModint(*this) *= a; }
    RuntimeModint operator/(const RuntimeModint &a) const { return RuntimeModint(*this) /= a; }
    RuntimeModint &operator+=(const RuntimeModint &a) {
        val = (val + a.val) % mods[id];
        return *this;
    }
    RuntimeModint &operator-=(const RuntimeModint &a) {
        val = (val - a.val + mods[id]) % mods[id];
        return *this;
    }
    RuntimeModint &operator*=(const RuntimeModint &a) {
        val = val * a.val % mods[id];
        return *this;
    }
    RuntimeModint &operator/=(const RuntimeModint &a) { return (*this) *= a.inv(); }
    RuntimeModint operator++(int) {
        RuntimeModint tmp = *this;
        (*this) += 1;
        return tmp;
    }
    RuntimeModint operator--(int) {
        RuntimeModint tmp = *this;
        (*this) -= 1;
        return tmp;
    }
    RuntimeModint &operator++() { return (*this) += 1; }
    RuntimeModint &operator--() { return (*this) -= 1; }
    friend std::istream &operator>>(std::istream &is, RuntimeModint<id> &x) {
        is >> x.val;
        x.val = (x.val % mods[id] + mods[id]) % mods[id];
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const RuntimeModint<id> &x) { return os << x.val; }

    long long value() const { return val; }
    int get_id() const { return id; }
    int modulus() const { return mods[id]; }
    RuntimeModint inv() const {
        long long a = val, b = mods[id], u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b, u -= t * v;
            std::swap(a, b), std::swap(u, v);
        }
        return RuntimeModint(u);
    }

    friend RuntimeModint<id> pow(const RuntimeModint<id> &x, long long k) {
        if(k == 0LL) return 1;
        if(k < 0LL) return pow(x.inv(), -k);
        RuntimeModint<id> res = 1, tmp = x;
        while(k > 0) {
            if(k & 1) res *= tmp;
            tmp = tmp * tmp, k >>= 1;
        }
        return res;
    }
};

using runmint998244353 = RuntimeModint<0>;
using runmint1000000007 = RuntimeModint<1>;

}  // namespace runtime_modint

// using namespace runtime_modint;

}  // namespace algorithm

#endif  // ALGORITHM_RUNTIME_MODINT_HPP
