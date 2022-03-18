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
    RuntimeModint(long long val_) : val(val_) {
        assert(0 <= id and id < (int)mods.size());
        assert(mods[id] >= 1);
        val = (val % mods[id] + mods[id]) % mods[id];
    }

    RuntimeModint operator+() const { return RuntimeModint(*this); }
    RuntimeModint operator-() const { return RuntimeModint() - (*this); }
    RuntimeModint &operator++() { return (*this) += 1; }
    RuntimeModint &operator--() { return (*this) -= 1; }
    RuntimeModint operator++(int) {
        RuntimeModint res = *this;
        (*this) += 1;
        return res;
    }
    RuntimeModint operator--(int) {
        RuntimeModint res = *this;
        (*this) -= 1;
        return res;
    }
    friend RuntimeModint operator*(const RuntimeModint &x, const RuntimeModint &y) { return RuntimeModint(x) *= y; }
    friend RuntimeModint operator/(const RuntimeModint &x, const RuntimeModint &y) { return RuntimeModint(x) /= y; }
    friend RuntimeModint operator+(const RuntimeModint &x, const RuntimeModint &y) { return RuntimeModint(x) += y; }
    friend RuntimeModint operator-(const RuntimeModint &x, const RuntimeModint &y) { return RuntimeModint(x) -= y; }
    RuntimeModint &operator*=(const RuntimeModint &a) {
        val = val * a.val % mods[id];
        return *this;
    }
    RuntimeModint &operator/=(const RuntimeModint &a) { return (*this) *= a.inv(); }
    RuntimeModint &operator+=(const RuntimeModint &a) {
        val = (val + a.val) % mods[id];
        return *this;
    }
    RuntimeModint &operator-=(const RuntimeModint &a) {
        val = (val - a.val + mods[id]) % mods[id];
        return *this;
    }
    friend bool operator==(const RuntimeModint &x, const RuntimeModint &y) { return x.val == y.val; }
    friend bool operator!=(const RuntimeModint &x, const RuntimeModint &y) { return x.val != y.val; }
    friend std::istream &operator>>(std::istream &is, RuntimeModint &x) {
        is >> x.val;
        x.val = (x.val % mods[id] + mods[id]) % mods[id];
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const RuntimeModint &x) { return os << x.val; }

    int get_id() const { return id; }
    int modulus() const { return mods[id]; }
    long long value() const { return val; }
    RuntimeModint inv() const {
        long long a = val, b = mods[id], u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b, u -= t * v;
            std::swap(a, b), std::swap(u, v);
        }
        return RuntimeModint(u);
    }

    friend RuntimeModint pow(const RuntimeModint &x, long long k) {
        if(k < 0) return pow(x.inv(), -k);
        RuntimeModint res = 1, tmp = x;
        while(k > 0) {
            if(k & 1LL) res *= tmp;
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
