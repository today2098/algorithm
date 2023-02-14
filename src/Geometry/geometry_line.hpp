#ifndef ALGORITHM_GEOMETRY_LINE_HPP
#define ALGORITHM_GEOMETRY_LINE_HPP 1

#include <array>
#include <cassert>
#include <iostream>

#include "geometry_vector.hpp"

namespace algorithm {

namespace geometry {

// 直線．
struct Line {
    std::array<Point, 2> ps;

    Line() : Line(Point(), Point()) {}
    explicit Line(const Point &P, const Point &Q) : ps({P, Q}) {}

    Point &operator[](int i) {
        assert(0 <= i and i < 2);
        return ps[i];
    }
    const Point &operator[](int i) const {
        assert(0 <= i and i < 2);
        return ps[i];
    }

    friend std::ostream &operator<<(std::ostream &os, const Line &s) { return os << "{" << s[0] << ", " << s[1] << "}"; }

    // 傾き．
    Type slope() const { return (ps[1].y - ps[0].y) / (ps[1].x - ps[0].x); }
    // y切片．
    Type y_intercept() const { return ps[0].y - slope() * ps[0].x; }
    // x切片．
    Type x_intercept() const { return ps[0].x - ps[0].y / slope(); }
    bool on_line(const Point &P) const { return equal_to(cross(ps[1] - ps[0], P - ps[0]), 0.0); }
};

// 線分．
struct Segment : public Line {
    Segment() : Line() {}
    Segment(const Line &l) : Line(l) {}
    explicit Segment(const Point &P, const Point &Q) : Line(P, Q) {}

    // 線分の長さ．
    Type length() const { return distance(ps[0], ps[1]); }
    bool on_segment(const Point &P) const {
        Vector b = ps[1] - ps[0], p = P - ps[0];
        if(!equal_to(cross(b, p), 0.0)) return false;
        return (no_less(dot(b, p), 0.0) and no_more(dot(p, p), dot(b, b)));
    }
};

// 直線の直交判定．
bool jud_orthogonal(const Line &l, const Line &m) {
    Vector b = l[1] - l[0], d = m[1] - m[0];
    return equal_to(dot(b, d), 0.0);
}
// 直線の平行判定．
bool jud_parallel(const Line &l, const Line &m) {
    Vector b = l[1] - l[0], d = m[1] - m[0];
    return equal_to(cross(b, d), 0.0);
}
// 直線の交差判定．
bool jud_intersection(const Line &l, const Line &m) { return !jud_parallel(l, m); }
// 直線と線分の交差判定．
bool jud_intersection(const Line &l, const Segment &m) {
    Vector b = l[1] - l[0];
    auto s = cross(b, m[0] - l[0]);
    auto t = cross(b, m[1] - l[0]);
    return no_more(s * t, 0.0);
}
bool jud_intersection(const Segment &l, const Line &m) { return jud_intersection(m, l); }
// 線分の交差判定．
bool jud_intersection(const Segment &l, const Segment &m) {
    Vector b = l[1] - l[0], d = m[1] - m[0];
    auto s = cross(b, m[0] - l[0]);
    auto t = cross(b, m[1] - l[0]);
    if(more_than(s * t, 0.0)) return false;
    s = cross(d, l[0] - m[0]);
    t = cross(d, l[1] - m[0]);
    if(more_than(s * t, 0.0)) return false;
    return true;
}

// 2直線の交点．
Point intersection(const Line &l, const Line &m) {
    Vector b = l[1] - l[0], d = m[1] - m[0];
    auto s = cross(m[0] - l[0], d) / cross(b, d);
    return Point(l[0] + s * b);
    // auto t = cross(b, l[0] - m[0]) / cross(b, d);
    // return Point(m[0] + t * d);
}

// 垂線の足．
Point projection(const Line &l, const Point &P) {
    Vector a = l[1] - l[0];
    return l[0] + a * (dot(P - l[0], a) / dot(a, a));
}
// 対象点．
Point reflection(const Line &l, const Point &P) {
    Point H = projection(l, P);
    return P + 2 * (H - P);
}

// 点と線の距離．
Type distance(const Line &l, const Point &P) {
    Point H = projection(l, P);
    return distance(P, H);
}
Type distance(const Point &P, const Line &l) { return distance(l, P); }
Type distance(const Segment &s, const Point &P) {
    Point H = projection(s, P);
    if(s.on_segment(H)) return distance(H, P);
    return std::min(distance(P, s[0]), distance(P, s[1]));
}
Type distance(const Point &P, const Segment &s) { return distance(s, P); }

}  // namespace geometry

// using namespace geometry;

}  // namespace algorithm

#endif

/*
参考文献
- zu_rin, 2線分の交差判定手法 (2次元)，https://qiita.com/zu_rin/items/e04fdec4e3dec6072104（参照2023.2.6）．
- zu_rin, 2線分の交点座標(2次元)，https://qiita.com/zu_rin/items/09876d2c7ec12974bc0f（参照2023.2.6）．
*/
