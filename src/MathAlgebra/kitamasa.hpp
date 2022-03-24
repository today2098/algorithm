#ifndef ALGORITHM_KITAMASA_HPP
#define ALGORITHM_KITAMASA_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// きたまさ法．k項間漸化式a[n]=d[0]*a[n-k]+d[1]*a[n-k+1]+....+d[k-1]*a[n-1]を求める．
template <typename T = long long>
class Kitamasa {
    int k;                // k:=(漸化式の階数).
    std::vector<T> a, d;  // a[]:=(初項ベクトル), d[]:=(係数ベクトル).

    std::vector<T> add(const std::vector<T> &x) const {  // f(n)->f(n+1).
        std::vector<T> y(k);
        y[0] = x[k - 1] * d[0];
        for(int i = 1; i < k; ++i) y[i] = x[i - 1] + x[k - 1] * d[i];
        return y;
    }
    std::vector<T> mul(const std::vector<T> &x) const {  // f(n)->f(2*n).
        std::vector<T> y(k, 0);
        std::vector<T> t = x;
        for(int i = 0; i < k; ++i) {
            for(int j = 0; j < k; ++j) y[j] += x[i] * t[j];
            if(i < k - 1) t = add(t);
        }
        return y;
    }
    std::vector<T> calc(long long n) const {  // f(n)を返す．
        if(n == 0) {
            std::vector<T> x(k, 0);
            x[0] = 1;
            return x;  // f(0).
        }
        std::vector<T> &&x = mul(calc(n / 2));
        if(n & 1LL) x = add(x);
        return x;
    }

public:
    // constructor.
    Kitamasa() : Kitamasa(std::vector<T>({0, 1}), std::vector<T>({1, 1})) {}  // フィボナッチ数列．
    explicit Kitamasa(const std::vector<T> &a_, const std::vector<T> &d_) : k(a_.size()), a(a_), d(d_) {
        assert(a.size() == d.size());
    }

    T operator[](long long n) const {  // a[n]を返す．O((K^2)*logN).
        assert(0 <= n);
        std::vector<T> &&x = calc(n);  // f(n).
        T res = 0;
        for(int i = 0; i < k; ++i) res += x[i] * a[i];
        return res;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_KITAMASA_HPP
