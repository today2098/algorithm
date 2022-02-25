#ifndef ALGORITHM_EXTGCD_HPP
#define ALGORITHM_EXTGCD_HPP 1

namespace algorithm {

// 拡張ユークリッド互除法．ax+by=GCD(a,b)を満たす(x,y)を格納する．O(logN).
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

#endif  // ALGORITHM_EXTGCD_HPP
