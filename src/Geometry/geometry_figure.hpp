#ifndef ALGORITHM_GEOMETRY_FIGURE_HPP
#define ALGORITHM_GEOMETRY_FIGURE_HPP 1

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>

#include "geometry_line.hpp"
#include "geometry_vector.hpp"

namespace algorithm {

namespace geometry {

// 長方形．
struct Box {
    std::array<Point, 2> ps;

    // constructor. 2点を対角とする長方形を定義する．
    Box() : Box(Point(), Point(1, 1)) {}
    explicit Box(const Point &P, const Point &Q) {
        ps[0].x = std::min<Type>(P.x, Q.x);
        ps[0].y = std::min<Type>(P.y, Q.y);
        ps[1].x = std::max<Type>(P.x, Q.x);
        ps[1].y = std::max<Type>(P.y, Q.y);
    }

    friend std::ostream &operator<<(std::ostream &os, const Box &box) {
        return os << "{" << Point(box.ps[0].x, box.ps[1].y) << ", " << box.ps[0]
                  << ", " << Point(box.ps[1].x, box.ps[0].y) << ", " << box.ps[1] << "}";
    }

    // 面積．
    Type area() const { return (ps[1].x - ps[0].x) * (ps[1].y - ps[0].y); }
    int contain(const Point &P) const {
        if(less_than(ps[0].x, P.x) and less_than(P.x, ps[1].x) and less_than(ps[0].y, P.y) and less_than(P.y, ps[1].y)) return 2;  // in.
        if(no_more(ps[0].x, P.x) and no_more(P.x, ps[1].x) and no_more(ps[0].y, P.y) and no_more(P.y, ps[1].y)) return 1;          // on.
        return 0;                                                                                                                  // out.
    }
};

// 円形．
struct Circle {
    Point O;
    Type r;

    Circle() : O(Point()), r(1.0) {}
    explicit Circle(Type r_) : O(Point()), r(r_) {}
    explicit Circle(const Point &C_, Type r_) : O(C_), r(r_) {}

    friend std::ostream &operator<<(std::ostream &os, const Circle &C) { return os << "{O" << C.O << ", r = " << C.r << "}"; }

    // 円周の長さ．
    Type length() const { return 2 * r * PI; }
    // 面積．
    Type area() const { return r * r * PI; }
    int contain(const Point &P) const {
        if(less_than(distance(O, P), r)) return 2;  // in.
        if(no_more(distance(O, P), r)) return 1;    // on.
        return 0;                                   // out.
    }
};

// 2点からの距離の比率がm:nであるアポロニウスの円．
Circle apporonius(const Point &A, const Point &B, Type m, Type n) {
    assert(!equal_to(m, n));
    Point P = (n * A + m * B) / (m + n);
    Point Q = (-n * A + m * B) / (m - n);
    Point O = (P + Q) / 2;
    Type r = (P - O).norm();
    return Circle(O, r);
}

// 円と直線の交点．
std::vector<Point> intersection(const Circle &C, const Line &l) {
    std::vector<Point> res;
    Point H = projection(l, C.O);
    auto flag = C.contain(H);
    if(flag == 1) {
        res.push_back(H);
    } else if(flag == 2) {
        auto dist = distance(C.O, H);
        auto arg = std::acos(dist / C.r);
        Vector a = H - C.O;
        res.push_back(C.O + a.rotate(-arg));
        res.push_back(C.O + a.rotate(arg));
    }
    return res;
}
// 円と円の交点．
std::vector<Point> intersection(Circle C, Circle D) {
    std::vector<Point> res;
    if(less_than(C.r, D.r)) std::swap(C, D);
    auto dist = distance(C.O, D.O);
    if(more_than(dist, C.r + D.r)) {  // 離れている場合．
        // No points.
    } else if(equal_to(dist, C.r + D.r)) {  // 外接する場合．
        Vector a = (D.O - C.O).unit() * C.r;
        res.push_back(C.O + a);
    } else if(more_than(dist, std::abs(C.r - D.r))) {  // 交差する場合．
        auto arg = std::acos((C.r * C.r + dist * dist - D.r * D.r) / (2 * C.r * dist));
        Vector a = (D.O - C.O).unit() * C.r;
        res.push_back(C.O + a.rotate(-arg));
        res.push_back(C.O + a.rotate(arg));
    } else if(equal_to(dist, C.r - D.r)) {  // 内接する場合．
        Vector a = (D.O - C.O).unit() * C.r;
        res.push_back(C.O + a);
    } else {  // 内部にある場合．
        // No points.
    }
    return res;
}

// 三角形の面積．
Type area(const Point &A, const Point &B, const Point &C) { return std::abs(cross(B - A, C - A)) / 2; }
// 多角形の面積．O(N).
Type area(const Polygon &pol) {
    const int n = pol.size();
    Type res = 0.0;
    for(int i = 0; i < n; ++i) res += cross(pol[i], pol[(i + 1) % n]);
    return res / 2;
}

// 多角形と点の包含関係．O(N).
int contain(const Polygon &pol, const Point &P) {
    const int n = pol.size();
    Type sum = 0.0;
    for(int i = 0; i < n; ++i) {
        if(Segment(pol[i], pol[(i + 1) % n]).on_segment(P)) return 1;  // on.
        Vector a = pol[i] - P, b = pol[(i + 1) % n] - P;
        auto arg = std::acos(dot(a, b) / a.norm() / b.norm());
        if(less_than(cross(a, b), 0.0)) sum -= arg;
        else sum += arg;
    }
    if(equal_to(sum, 0.0)) return 0;  // out. sum==0.
    return 2;                         // in. sum==2*PI.
}

// 偏角ソート．点を反時計回りにソートする．O(NlogN).
void argument_sort(Polygon &pol) {
    auto comp = [](const Vector &p, const Vector &q) -> bool {
        return p.arg() < q.arg();
    };
    std::sort(pol.begin(), pol.end(), comp);
}

// 凸性判定．O(N). 多角形の頂点は反時計回りに並んでいること．
bool is_convex(const Polygon &pol) {
    const int n = pol.size();
    for(int i = 0; i < n; ++i) {
        if(simple_ccw(pol[i], pol[(i + 1) % n], pol[(i + 2) % n]) == -1) return false;
    }
    return true;
}

// アンドリューのアルゴリズム．凸包．O(N*logN).
Polygon andrew_scan(Polygon pol, bool is_strong = true) {
    const auto cmp = (is_strong ? geometry::EPS : -geometry::EPS);
    const int n = pol.size();
    Polygon res(2 * n);
    int k = 0;
    std::sort(pol.begin(), pol.end());
    for(int i = 0; i < n; ++i) {
        while(k >= 2 and cross(res[k - 1] - res[k - 2], pol[i] - res[k - 2]) < cmp) k--;
        res[k++] = pol[i];
    }
    int t = k + 1;
    for(int i = n - 2; i >= 0; --i) {
        while(k >= t and cross(res[k - 1] - res[k - 2], pol[i] - res[k - 2]) < cmp) k--;
        res[k++] = pol[i];
    }
    res.resize(k - 1);
    return res;
}

// 凸多角形の切断．O(N).
Polygon convex_cut(const Polygon &pol, const Line &l) {
    assert(is_convex(pol));
    const int n = pol.size();
    Polygon res;
    for(int i = 0; i < n; ++i) {
        const Point &P = pol[i];
        const Point &Q = pol[(i + 1) % n];
        if(simple_ccw(l[0], l[1], P) != -1) {
            if(res.size() == 0 or P != *res.rbegin()) res.push_back(P);
        }
        if(simple_ccw(l[0], l[1], P) * simple_ccw(l[0], l[1], Q) < 0) {
            Point R = intersection(Line(P, Q), l);
            res.push_back(R);
        }
    }
    return res;
}

}  // namespace geometry

// using namespace geometry;

}  // namespace algorithm

#endif

/*
参考文献
- yapoo, 二つの円の交点を求める，競プロやります，HatenaBlog, https://poporix.hatenablog.com/entry/2020/03/03/223631（参照2023.2.14）．
- ganyariya, C++で点を偏角ソートをしたい(反時計にソートしたい)【軽実装編】，Qiita, https://qiita.com/ganyariya/items/adef1a7f89ae88b804da（参照2023.2.14）．
- 川島 真寛，【第2回】点の多角形に対する内外判定，NTT PC, https://www.nttpc.co.jp/technology/number_algorithm.html（参照2023.2.15）．
*/
