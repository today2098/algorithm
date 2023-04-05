#ifndef ALGORITHM_KITAMASA_HPP
#define ALGORITHM_KITAMASA_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// きたまさ法．線形漸化式 a[n]=d[0]*a[n-k]+d[1]*a[n-k+1]+....+d[k-1]*a[n-1] を求める．O((K^2)*logN).
template <typename T = long long>
class Kitamasa {
    int k;             // k:=(階数).
    std::vector<T> a;  // a[]:=(初項行列).
    std::vector<T> d;  // d[]:=(係数行列).

    // f(n)->f(n+1). O(K).
    std::vector<T> add(const std::vector<T> &x) const {
        std::vector<T> y(k);
        y[0] = x[k - 1] * d[0];
        for(int i = 1; i < k; ++i) y[i] = x[i - 1] + x[k - 1] * d[i];
        return y;
    }
    // f(n)->f(2*n). O(K^2).
    std::vector<T> mul(const std::vector<T> &x) const {
        std::vector<T> y(k, 0);
        auto t = x;
        for(int i = 0; i < k; ++i) {
            for(int j = 0; j < k; ++j) y[j] += x[i] * t[j];
            if(i < k - 1) t = add(t);
        }
        return y;
    }
    // f(n)を返す．O((K^2)*logN).
    std::vector<T> f(long long n) const {
        if(n == 0) {
            std::vector<T> x(k, 0);
            x[0] = 1;
            return x;  // f(0).
        }
        auto &&x = mul(f(n / 2));
        if(n & 1LL) x = add(x);
        return x;
    }

public:
    Kitamasa() : Kitamasa(std::vector<T>({0, 1}), std::vector<T>({1, 1})) {}  // フィボナッチ数列．
    explicit Kitamasa(const std::vector<T> &a_, const std::vector<T> &d_) : k(a_.size()), a(a_), d(d_) {
        assert(k >= 1 and a.size() == d.size());
    }

    T operator[](long long n) const { return calc(n); }

    // a[n]を返す．O((K^2)*logN).
    T calc(long long n) const {
        assert(n >= 0);
        const auto &&x = f(n);
        T res = 0;
        for(int i = 0; i < k; ++i) res += x[i] * a[i];
        return res;
    }
};

}  // namespace algorithm

#endif
