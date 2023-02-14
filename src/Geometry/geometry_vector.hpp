#ifndef ALGORITHM_GEOMETRY_VECTOR_HPP
#define ALGORITHM_GEOMETRY_VECTOR_HPP 1

#include <cmath>
#include <iostream>
#include <vector>

namespace algorithm {

namespace geometry {

using Type = double;

const Type INF = 1e18;
const Type EPS = 1e-10;
const Type PI = std::acos(-1.0);

inline bool equal_to(const Type &a, const Type &b) { return std::abs(a - b) < EPS; }
inline bool less_than(const Type &a, const Type &b) { return a - b < -EPS; }
inline bool more_than(const Type &a, const Type &b) { return a - b > EPS; }
inline bool no_more(const Type &a, const Type &b) { return a - b < EPS; }
inline bool no_less(const Type &a, const Type &b) { return a - b > -EPS; }

// 角度を弧度法に変換する．
inline Type to_radian(Type deg) { return deg / 180.0 * PI; }
// 角度を度数法に変換する．
inline Type to_degree(Type rad) { return rad / PI * 180.0; }

struct Vector {
    Type x, y;

    Vector() : Vector(0.0, 0.0) {}
    Vector(Type x_, Type y_) : x(x_), y(y_) {}

    Vector operator+() const { return Vector(*this); }
    Vector operator-() const { return Vector(-x, -y); }
    Vector operator*(Type n) const { return Vector(x * n, y * n); }
    Vector operator/(Type n) const { return Vector(x / n, y / n); }
    Vector &operator*=(Type n) {
        x *= n, y *= n;
        return *this;
    }
    Vector &operator/=(Type n) {
        x /= n, y /= n;
        return *this;
    }
    Vector &operator+=(const Vector &a) {
        x += a.x, y += a.y;
        return *this;
    }
    Vector &operator-=(const Vector &a) {
        x -= a.x, y -= a.y;
        return *this;
    }

    friend Vector operator*(Type n, const Vector &a) { return a * n; }
    friend Vector operator+(const Vector &a, const Vector &b) { return Vector(a.x + b.x, a.y + b.y); }
    friend Vector operator-(const Vector &a, const Vector &b) { return Vector(a.x - b.x, a.y - b.y); }
    friend bool operator<(const Vector &a, const Vector &b) { return (equal_to(a.x, b.x) ? less_than(a.y, b.y) : less_than(a.x, b.x)); }
    friend bool operator>(const Vector &a, const Vector &b) { return (equal_to(a.x, b.x) ? more_than(a.y, b.y) : more_than(a.x, b.x)); }
    friend bool operator<=(const Vector &a, const Vector &b) { return (equal_to(a.x, b.x) ? no_more(a.y, b.y) : no_more(a.x, b.x)); }
    friend bool operator>=(const Vector &a, const Vector &b) { return (equal_to(a.x, b.x) ? no_less(a.y, b.y) : no_less(a.x, b.x)); }
    friend bool operator==(const Vector &a, const Vector &b) { return (equal_to(a.x, b.x) and equal_to(a.y, b.y)); }
    friend bool operator!=(const Vector &a, const Vector &b) { return !(a == b); }
    friend std::ostream &operator<<(std::ostream &os, const Vector &a) { return os << "(" << a.x << ", " << a.y << ")"; }

    // ノルム．
    Type norm() const { return std::sqrt(dot(*this, *this)); }
    // x軸となす角．[-π,π].
    Type arg() const { return std::atan2(y, x); }
    // x軸となす角．[0,2π).
    Type arg2() const {
        auto res = arg();
        if(less_than(res, 0.0)) res += 2 * PI;
        return res;
    }
    // 反時計回りに角度arg（ラジアン単位）回転したベクトル．
    Vector rotate(Type arg) const {
        Type nx = x * std::cos(arg) - y * std::sin(arg);
        Type ny = x * std::sin(arg) + y * std::cos(arg);
        return Vector(nx, ny);
    }
    // 反時計回りに90度回転したベクトル．
    Vector rotate90() const { return Vector(-y, x); }
    // 180度回転したベクトル．
    Vector rotate180() const { return Vector(-x, -y); }
    // 単位ベクトル．
    Vector unit() const { return *this / norm(); }

    // 内積．
    friend inline Type dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y; }
    // 外積．
    friend inline Type cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }
};

using Point = Vector;
using Polygon = std::vector<Point>;

// 反時計回りに角度arg（ラジアン単位）回転させる．
void rotate(Vector &a, Type arg) {
    Type nx = a.x * std::cos(arg) - a.y * std::sin(arg);
    Type ny = a.x * std::sin(arg) + a.y * std::cos(arg);
    a.x = nx, a.y = ny;
}
// 反時計周りに90度回転させる．
inline void rotate90(Vector &a) {
    auto tmp = a.x;
    a.x = -a.y;
    a.y = tmp;
}
// 反時計周りに180度回転させる．
inline void rotate180(Vector &a) { a.x = -a.x, a.y = -a.y; }

// 2点間距離を計算する．
inline Type distance(const Point &P, const Point &Q) { return (Q - P).norm(); }

// 3点の位置関係．
int simple_ccw(const Point &A, const Point &B, const Point &P) {
    Vector b = B - A, p = P - A;
    if(more_than(cross(b, p), 0.0)) return 1;   // A->Bの反時計方向にP．
    if(less_than(cross(b, p), 0.0)) return -1;  // A->Bの時計方向にP．
    return 0;                                   // 一直線上．
}
int ccw(const Point &A, const Point &B, const Point &P) {
    Vector b = B - A, p = P - A;
    if(more_than(cross(b, p), 0.0)) return 1;      // A->Bの反時計方向にP．counter clockwise.
    if(less_than(cross(b, p), 0.0)) return -1;     // A->Bの時計方向にP．clockwise.
    if(less_than(dot(b, p), 0.0)) return -2;       // P->A->Bの順に一直線上．online back.
    if(more_than(dot(p, p), dot(b, b))) return 2;  // A->B->Pの順に一直線上．online front.
    return 0;                                      // A->P->Bの順に一直線上．on segment.
}

// 三角形と点の包含関係．
int contain(const Point &A, const Point &B, const Point &C, const Point &P) {
    int flag1 = ccw(A, B, P), flag2 = ccw(B, C, P), flag3 = ccw(C, A, P);
    if(flag1 == 0 or flag2 == 0 or flag3 == 0) return 1;       // on.
    if(flag1 == -1 and flag2 == -1 and flag3 == -1) return 2;  // in.
    if(flag1 == 1 and flag2 == 1 and flag3 == 1) return 2;     // in.
    return 0;                                                  // out.
}

// 複素数．
struct Complex : public Point {
    Complex() : Point() {}
    Complex(const Point &P) : Point(P) {}
    Complex(Type x_, Type y_) : Point(x_, y_) {}

    Complex &operator*=(const Complex &z) {
        const auto [tx, ty] = *this;
        x = tx * z.x - ty * z.y;
        y = tx * z.y + ty * z.x;
        return *this;
    }
    Complex &operator/=(const Complex &z) {
        const auto [tx, ty] = *this;
        x = tx * z.x - ty * z.y;
        y = tx * z.y + ty * z.x;
        return *this;
    }

    friend Complex operator*(const Complex &z, const Complex &w) { return Complex(z.x * w.x - z.y * w.y, z.x * w.y + z.y * w.x); }
    friend Complex operator/(const Complex &z, const Complex &w) { return Complex(z / (w.x * w.x + w.y * w.y)) * w; }

    // 共役複素数．Conjugate complex number.
    Complex conj() const { return Complex(x, -y); }
};

// 極形式．大きさr，偏角argの複素数を返す．
inline Complex polar(Type r, Type arg) { return Complex(r * std::cos(arg), r * std::sin(arg)); }
// 極形式(r,θ)に変換する．θ∈[-π,π].
inline std::pair<Type, Type> convert_polor(const Complex &z) { return {z.norm(), z.arg()}; }
// 極形式(r,θ)に変換する．θ∈[0,2π).
inline std::pair<Type, Type> convert_polor2(const Complex &z) { return {z.norm(), z.arg2()}; }

}  // namespace geometry

// using namespace geometry;

}  // namespace algorithm

#endif
