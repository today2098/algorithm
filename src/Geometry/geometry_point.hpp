#ifndef ALGORITHM_GEOMETRY_POINT_HPP
#define ALGORITHM_GEOMETRY_POINT_HPP 1

#include <cmath>  // for abs(), acos(), atan2(), cos(), sin() and sqrt().
#include <iostream>
#include <utility>  // pair.
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

inline Type to_radian(Type deg) { return deg / 180.0 * PI; }
inline Type to_degree(Type rad) { return rad / PI * 180.0; }

struct Point {
    Type x, y;

    Point() : Point(0.0, 0.0) {}
    Point(Type x_, Type y_) : x(x_), y(y_) {}

    Point operator+() const { return Point(*this); }
    Point operator-() const { return Point(-x, -y); }
    Point operator*(Type n) const { return Point(x * n, y * n); }
    friend Point operator*(Type n, const Point &P) { return P * n; }
    Point operator/(Type n) const { return Point(x / n, y / n); }
    friend Point operator+(const Point &P, const Point &Q) { return Point(P.x + Q.x, P.y + Q.y); }
    friend Point operator-(const Point &P, const Point &Q) { return Point(P.x - Q.x, P.y - Q.y); }
    Point &operator*=(Type n) {
        x *= n, y *= n;
        return *this;
    }
    Point &operator/=(Type n) {
        x /= n, y /= n;
        return *this;
    }
    Point &operator+=(const Point &P) {
        x += P.x, y += P.y;
        return *this;
    }
    Point &operator-=(const Point &P) {
        x -= P.x, y -= P.y;
        return *this;
    }
    friend bool operator<(const Point &P, const Point &Q) { return (!equal_to(P.x, Q.x) ? P.x < Q.x : P.y < Q.y); }
    friend bool operator>(const Point &P, const Point &Q) { return (!equal_to(P.x, Q.x) ? P.x > Q.x : P.y > Q.y); }
    friend bool operator<=(const Point &P, const Point &Q) { return (!equal_to(P.x, Q.x) ? P.x <= Q.x : P.y <= Q.y); }
    friend bool operator>=(const Point &P, const Point &Q) { return (!equal_to(P.x, Q.x) ? P.x >= Q.x : P.y >= Q.y); }
    friend bool operator==(const Point &P, const Point &Q) { return (equal_to(P.x, Q.x) and equal_to(P.y, Q.y)); }
    friend bool operator!=(const Point &P, const Point &Q) { return !(P == Q); }
    friend std::ostream &operator<<(std::ostream &os, const Point &P) { return os << "(" << P.x << ", " << P.y << ")"; }
};

using Vector = Point;
using Polygon = std::vector<Point>;

Type dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y; }    // 内積．
Type cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }  // 外積．
Type norm(const Vector &a) { return std::sqrt(dot(a, a)); }                     // ノルム．
Vector unit(const Vector &a) { return a / norm(a); }                            // 単位ベクトル．
Type argument(const Vector &a) { return std::atan2(a.y, a.x); }                 // x軸方向のベクトルとなす角を返す．[-π, π].
Vector rotate(const Vector &a, Type arg) {                                      // 回転．Rotate.
    Type x = a.x * std::cos(arg) - a.y * std::sin(arg);
    Type y = a.y * std::cos(arg) + a.x * std::sin(arg);
    return Vector(x, y);
}
Vector rotate90(const Vector &a) { return Vector(-a.y, a.x); }

struct Complex : public Point {
    Complex() : Point() {}
    Complex(const Point &P) : Point(P) {}
    Complex(Type x_, Type y_) : Point(x_, y_) {}

    friend Complex operator*(const Complex &z, const Complex &w) { return Complex(z.x * w.x - z.y * w.y, z.x * w.y + z.y * w.x); }
    friend Complex operator/(const Complex &z, const Complex &w) { return Complex(z / (w.x * w.x + w.y * w.y)) * w; }
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
};

std::pair<Type, Type> convert_polor(const Complex &z) { return {std::sqrt(z.y * z.y + z.x * z.x), std::atan2(z.y, z.x)}; }  // 極形式(r,θ)に変換．θ∈[-π, π].
Complex polar(Type r, Type arg) { return Complex(r * std::cos(arg), r * std::sin(arg)); }                                   // 極形式．大きさr，偏角argの複素数を返す．
Complex conj(const Complex &z) { return Complex(z.x, -z.y); }                                                               // 共役複素数．Conjugate complex number.

}  // namespace geometry

// using namespace geometry;

}  // namespace algorithm

#endif  // ALGORITHM_GEOMETRY_POINT_HPP
