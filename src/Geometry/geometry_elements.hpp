#ifndef ALGORITHM_GEOMETRY_ELEMENT_HPP
#define ALGORITHM_GEOMETRY_ELEMENT_HPP 1

#include <array>
#include <cassert>
#include <cmath>  // for acos() and fabs().
#include <iostream>
#include <vector>

namespace algorithm {

namespace geometry {

using Type = double;

const Type INF = 1e18;
const Type EPS = 1e-10;
const Type PI = std::acos(-1.0);

bool equals(const Type &a, const Type &b) { return std::fabs(a - b) < EPS; }
bool less_than(const Type &a, const Type &b) { return a - b < -EPS; }
bool no_more(const Type &a, const Type &b) { return a - b < EPS; }
bool more_than(const Type &a, const Type &b) { return a - b > EPS; }
bool no_less(const Type &a, const Type &b) { return a - b > -EPS; }
Type to_rad(Type deg) { return deg / 180.0 * PI; }
Type to_deg(Type rad) { return rad / PI * 180.0; }

// 点．
struct Point {
    Type x, y;

    Point() : Point(0.0, 0.0) {}
    explicit Point(Type x_, Type y_) : x(x_), y(y_) {}

    Point operator-() const { return Point(-x, -y); }
    friend Point operator+(const Point &P, const Point &Q) { return Point(P.x + Q.x, P.y + Q.y); }
    friend Point operator-(const Point &P, const Point &Q) { return Point(P.x - Q.x, P.y - Q.y); }
    Point operator*(Type k) const { return Point(k * x, k * y); }
    friend Point operator*(Type k, const Point &P) { return P * k; }
    friend Point operator*(const Point &P, const Point &Q) { return Point(P.x * Q.x - P.y * Q.y, P.x * Q.y + P.y * Q.x); }  // complex arithmetic.
    Point operator/(Type k) const { return Point(x / k, y / k); }
    Point operator/(const Point &P) const { return (*this) / (P.x * P.x + P.y * P.y) * Point(P.x, -P.y); }  // complex arithmetic.
    friend bool operator<(const Point &P, const Point &Q) { return (!equals(P.x, Q.x) ? P.x < Q.x : P.y < Q.y); }
    friend bool operator<=(const Point &P, const Point &Q) { return (!equals(P.x, Q.x) ? P.x <= Q.x : P.y <= Q.y); }
    friend bool operator>(const Point &P, const Point &Q) { return (!equals(P.x, Q.x) ? P.x > Q.x : P.y > Q.y); }
    friend bool operator>=(const Point &P, const Point &Q) { return (!equals(P.x, Q.x) ? P.x >= Q.x : P.y >= Q.y); }
    friend bool operator==(const Point &P, const Point &Q) { return (equals(P.x, Q.x) and equals(P.y, Q.y)); }
    friend bool operator!=(const Point &P, const Point &Q) { return (!equals(P.x, Q.x) or !equals(P.y, Q.y)); }
    friend std::ostream &operator<<(std::ostream &os, const Point &P) { return os << "(" << P.x << ", " << P.y << ")"; }
};

using Vector = Point;
using Complex = Point;
using Polygon = std::vector<Point>;

// 線分．
struct Segment {
    std::array<Point, 2> ps;

    Segment() {}
    explicit Segment(const Point &P, const Point &Q) : ps({P, Q}) {}

    Point &operator[](int i) {
        assert(0 <= i and i < 2);
        return ps[i];
    }
    const Point &operator[](int i) const {
        assert(0 <= i and i < 2);
        return ps[i];
    }
    friend std::ostream &operator<<(std::ostream &os, const Segment &s) { return os << "{" << s[0] << ", " << s[1] << "}"; }
};

using Line = Segment;

// 円．
struct Circle {
    Point C;
    Type r;

    Circle() : C(0.0, 0.0), r(1.0) {}
    explicit Circle(Type r_) : C(0.0, 0.0), r(r_) {}
    explicit Circle(const Point &c_, Type r_) : C(c_), r(r_) {}

    friend std::ostream &operator<<(std::ostream &os, const Circle &circ) { return os << "{C" << circ.C << ", r=" << circ.r << "}"; }
};

}  // namespace geometry

// using namespace geometry;

}  // namespace algorithm

#endif  // ALGORITHM_GEOMETRY_ELEMENT_HPP
