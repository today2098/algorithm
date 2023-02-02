#ifndef ALGORITHM_EXTGCD_HPP
#define ALGORITHM_EXTGCD_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// 拡張ユークリッドの互除法．
// ax+by=GCD(a,b) を満たす整数の組(x,y)を求め，GCD(a,b)を返す．O(logN).
template <typename Type>
Type extgcd(Type a, Type b, Type &x, Type &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    Type d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 中国剰余定理 (Chinese Remainder Theorem)．
// x≡b1 (mod. m1) かつ x≡b2 (mod. m2) を満たす整数x(0≦x＜lcm(m1,m2))を求める．
// 返り値は x≡r (mod. m) となる組(r,m)．解なしの場合，(0,-1)を返す．
std::pair<long long, long long> crt(long long b1, long long m1, long long b2, long long m2) {
    long long p, q;
    long long d = extgcd(m1, m2, p, q);  // p is inv of m1/d (mod. m2/d)
    if((b2 - b1) % d != 0) return {0, -1};
    long long m = m1 / d * m2;  // lcm of (m1,m2)
    long long tmp = (b2 - b1) / d * p % (m2 / d);
    long long r = ((b1 + m1 * tmp) % m + m) % m;
    return {r, m};
}

// 中国剰余定理 (Chinese Remainder Theorem)．
// 各iについて，x≡b[i] (mod. m[i]) を満たす整数x(0≦x＜lcm(m[i]))を求める．
// 返り値は x≡r (mod. m) となる組(r,m)．解なしの場合，(0,-1)を返す．
std::pair<long long, long long> crt(const std::vector<long long> &bs, const std::vector<long long> &ms) {
    assert(bs.size() == ms.size());
    const int sz = bs.size();
    long long r = 0, m = 1;
    for(int i = 0; i < sz; ++i) {
        auto &&[rr, mm] = crt(r, m, bs[i], ms[i]);
        if(rr == 0 and mm == -1) return {0, -1};
        r = rr, m = mm;
    }
    return {r, m};
}

}  // namespace algorithm

#endif

/*
参考文献
- drken, 拡張ユークリッドの互除法 〜 一次不定方程式 ax + by = c の解き方 〜，Qiita, https://qiita.com/drken/items/b97ff231e43bce50199a（参照2023.2.2）．
- drken，中国剰余定理 (CRT) の解説とそれを用いる問題のまとめ，Qiita, https://qiita.com/drken/items/ae02240cd1f8edfc86fd（参照2022.9.16）．
*/
