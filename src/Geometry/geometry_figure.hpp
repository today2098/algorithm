#ifndef ALGORITHM_GEOMETRY_FIGURE_HPP
#define ALGORITHM_GEOMETRY_FIGURE_HPP 1

#include <array>
#include <cassert>
#include <cmath>  // for sqrt().
#include <iostream>
#include <utility>  // pair.

#include "./geometry_point.hpp"

namespace algorithm {

namespace geometry {

struct Segment {
    std::array<Point, 2> ps;

    Segment() : Segment(Point(), Point()) {}
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

Type pythagoras(Type a, Type b) { return std::sqrt(a * a + b * b); }                    // 三平方の定理．
Type length(const Segment &s) { return pythagoras(s[1].x - s[0].x, s[1].y - s[0].y); }  // 線分の長さ．
std::pair<Type, Type> equation(const Line &l) {                                         // 直線の方程式．return pair of slope（傾き） and intercept（切片）.
    Type slope = (l[1].y - l[0].y) / (l[1].x - l[0].x);
    Type intercept = l[0].y - slope * l[0].x;
    return {slope, intercept};
}

struct Circle {
    Point C;
    Type r;

    Circle() : C(Point()), r(1.0) {}
    explicit Circle(Type r_) : C(Point()), r(r_) {}
    explicit Circle(const Point &C_, Type r_) : C(C_), r(r_) {}

    friend std::ostream &operator<<(std::ostream &os, const Circle &circ) { return os << "{C" << circ.C << ", r = " << circ.r << "}"; }
};

Type length(const Circle &circ) { return 2 * circ.r * PI; }          // 円周の長さ．
Type area(const Circle &circ) { return circ.r * circ.r * PI; }       // 円の面積．
Circle apporonius(const Point &A, const Point &B, Type m, Type n) {  // 2点からの距離の比率m:nのアポロニウスの円．
    assert(!equal_to(m, n));
    Point &&P = (n * A + m * B) / (m + n);
    Point &&Q = (-n * A + m * B) / (m - n);
    Point C = (P + Q) / 2;
    Type r = pythagoras(P.x - C.x, P.y - C.y);
    return Circle(C, r);
}

}  // namespace geometry

// using namespace geometry;

}  // namespace algorithm

#endif  // ALGORITHM_GEOMETRY_FIGURE_HPP
