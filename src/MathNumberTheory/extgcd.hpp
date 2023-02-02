#ifndef ALGORITHM_EXTGCD_HPP
#define ALGORITHM_EXTGCD_HPP 1

namespace algorithm {

// 拡張ユークリッド互除法．ax+by=GCD(a,b) を満たす整数の組(x,y)を格納する．O(logN).
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

}  // namespace algorithm

#endif

/*
参考文献
- drken, 拡張ユークリッドの互除法 〜 一次不定方程式 ax + by = c の解き方 〜，Qiita, https://qiita.com/drken/items/b97ff231e43bce50199a#3-%E4%B8%80%E6%AC%A1%E4%B8%8D%E5%AE%9A%E6%96%B9%E7%A8%8B%E5%BC%8F-ax--by--c-%E3%81%AE%E6%95%B4%E6%95%B0%E8%A7%A3,（参照2023.2.2）．
*/
