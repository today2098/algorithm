#ifndef ALGORITHM_GEOMETRY_FUNCTION_HPP
#define ALGORITHM_GEOMETRY_FUNCTION_HPP 1

#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

#include "geometry_elements.hpp"

namespace algorithm {

namespace geometry {

// ベクトルに関する関数．
Type dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y; }    // 内積．
Type cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }  // 外積．
Type norm(const Vector &a) { return std::sqrt(dot(a, a)); }                     // ノルム．
Vector unit(const Vector &a) { return a / norm(a); }                            // 単位ベクトル．
Vector rot(const Vector &a, Type arg) {                                         // 回転．Rotate.
    Type x = a.x * std::cos(arg) - a.y * std::sin(arg);
    Type y = a.y * std::cos(arg) + a.x * std::sin(arg);
    return Vector(x, y);
}
Vector rot90(const Vector &a) { return Vector(-a.y, a.x); }

// 複素数に関する関数．
Complex conj(const Complex &z) { return Complex(z.x, -z.y); }                              // 共役複素数．Conjugate complex number.
Complex polar(Type r, Type arg) { return Complex(r * std::cos(arg), r * std::sin(arg)); }  // 極形式．大きさr，偏角argの複素数を返す．
Type arg(const Complex &z) {                                                               //偏角．Argument. [-π, π].
    Type res = std::atan2(z.y, z.x);
    return res;
}

// 線分，直線に関する関数．
Type length(const Segment &s) { return norm(s[1] - s[0]); }                  // 線分の長さ．
Type slope(const Line &l) { return (l[1].y - l[0].y) / (l[1].x - l[0].x); }  // 傾き．

// 円に関する関数.
Type length(const Circle &circ) { return 2 * circ.r * PI; }          // 円周の長さ．
Type area(const Circle &circ) { return circ.r * circ.r * PI; }       // 円の面積．
Circle apporonius(const Point &A, const Point &B, Type m, Type n) {  // 2点からの距離の比率m:nのアポロニウスの円．
    if(equals(m, n)) return Circle();
    Point P = (n * A + m * B) / (m + n), Q = (-n * A + m * B) / (m - n);
    Point C = (P + Q) / 2;
    Type r = norm(P - C);
    return Circle(C, r);
}

// 点と線分，直線，円の関係．
int simple_ccw(const Point &A, const Point &B, const Point &P) {
    Vector b = B - A, p = P - A;
    if(more_than(cross(b, p), 0.0)) return 1;   // A->Bの反時計方向にP．
    if(less_than(cross(b, p), 0.0)) return -1;  // A->Bの時計方向にP．
    return 0;                                   // 一直線上．
}
int ccw(const Point &A, const Point &B, const Point &P) {
    Vector b = B - A, p = P - A;
    if(more_than(cross(b, p), 0.0)) return 1;       // A->Bの反時計方向にP．counter clockwise.
    if(less_than(cross(b, p), 0.0)) return -1;      // A->Bの時計方向にP．clockwise.
    if(less_than(dot(b, p), 0.0)) return 2;         // P->A->Bの順に一直線上．online back.
    if(more_than(dot(p, p), dot(b, b))) return -2;  // A->B->Pの順に一直線上．online front.
    return 0;                                       // A->P->Bの順に一直線上．on segment.
}

bool on_segment(const Segment &s, const Point &P) { return (ccw(s[0], s[1], P) == 0); }
bool on_line(const Line &l, const Point &P) { return (simple_ccw(l[0], l[1], P) == 0); }

Point projection(const Line &l, const Point &P) {  // 垂線の足．
    Vector a = (l[1] - l[0]);
    return l[0] + a * (dot(P - l[0], a) / dot(a, a));
}
Point reflection(const Line &l, const Point &P) { return P + 2.0 * (projection(l, P) - P); }  // 対象点．

Type dist_ptop(const Point &P, const Point &Q) { return norm(Q - P); }
Type dist_ptol(const Point &P, const Line &l) {
    Point H = projection(l, P);
    return dist_ptop(P, H);
}
Type dist_ptos(const Point &P, const Segment &s) {
    Point H = projection(s, P);
    if(on_segment(s, H)) return dist_ptop(P, H);
    return std::min(dist_ptop(P, s[0]), dist_ptop(P, s[1]));
}

int contain(const Point &A, const Point &B, const Point &C, const Point &P) {  // 三角形と点の包含関係．
    int flag1 = ccw(A, B, P), flag2 = ccw(B, C, P), flag3 = ccw(C, A, P);
    if(flag1 == 0 or flag2 == 0 or flag3 == 0) return 1;       // on.
    if(flag1 == 1 and flag2 == 1 and flag3 == 1) return 2;     // in.
    if(flag1 == -1 and flag2 == -1 and flag3 == -1) return 2;  // in.
    return 0;                                                  // out.
}
int contain(const Circle &circ, const Point &P) {  // 円と点の包含関係．
    Type dif = dist_ptop(circ.C, P) - circ.r;
    if(less_than(dif, 0.0)) return 2;  // in.
    if(equals(dif, 0.0)) return 1;     // on.
    return 0;                          // out.
}

bool orthogonal(const Line &l, const Line &m) {  // 直線の直交判定．
    Vector b = l[1] - l[0], d = m[1] - m[0];
    return equals(dot(b, d), 0.0);
}
bool parallel(const Line &l, const Line &m) {  // 直線の平行判定．
    Vector b = l[1] - l[0], d = m[1] - m[0];
    return equals(cross(b, d), 0.0);
}
bool cross(const Segment &s, const Segment &t) {  // 線分の交点判定．
    Vector b = s[1] - s[0], c1 = t[0] - s[0], d1 = t[1] - s[0];
    Vector a = s[0] - s[1], c2 = t[0] - s[1], d2 = t[1] - s[1];
    return (no_more(cross(b, c1) * cross(b, d1), 0.0) and no_more(cross(a, c2) * cross(a, d2), 0.0));
}

// 線分，直線，円の交点を求める関数．
std::vector<Point> cross_point(const Line &l, const Line &m) {
    std::vector<Point> ps;
    if(parallel(l, m)) return ps;
    Vector a = l[1] - l[0], b = m[1] - m[0];
    ps.push_back(l[0] + a / cross(b, a) * cross(b, m[0] - l[0]));
    return ps;
}
std::vector<Point> cross_point(const Circle &circ, const Line &l) {
    std::vector<Point> ps;
    Point H = projection(l, circ.C);
    int flag = contain(circ, H);
    if(flag == 0) {
    } else if(flag == 1) {
        ps.push_back(H);
    } else {
        Type dist = dist_ptop(circ.C, H);
        Type arg = std::acos(dist / circ.r);
        ps.push_back(circ.C + polar(circ.r, arg));
        ps.push_back(circ.C + polar(circ.r, -arg));
    }
    return ps;
}
std::vector<Point> cross_point(Circle circ1, Circle circ2) {
    std::vector<Point> ps;
    if(less_than(circ1.r, circ2.r)) std::swap(circ1, circ2);
    Type dist = norm(circ2.C - circ1.C);
    if(more_than(dist, circ1.r + circ2.r)) {      // 離れている場合．
    } else if(equals(dist, circ1.r + circ2.r)) {  // 外接する場合．
        Vector base = (circ2.C - circ1.C) / norm(circ2.C - circ1.C);
        ps.push_back(circ1.C + base * circ1.r);
    } else if(less_than(std::abs(circ1.r - circ2.r), dist) and less_than(dist, circ1.r + circ2.r)) {  // 交差する場合．
        Type tmp = circ1.r - (circ1.r + circ2.r - dist) / 2.0;
        Type arg = std::acos(tmp / circ1.r);
        ps.push_back(circ1.C + polar(circ1.r, arg));
        ps.push_back(circ1.C + polar(circ1.r, -arg));
    } else if(equals(dist, std::abs(circ1.r - circ2.r))) {  // 内接する場合．
        Vector base = (circ2.C - circ1.C) / norm(circ2.C - circ1.C);
        ps.push_back(circ1.C + base * circ1.r);
    } else if(less_than(dist, std::abs(circ1.r - circ2.r))) {  // 内部にある場合．
    }
    return ps;
}

// 多角形に関する関数，アルゴリズム．
void vertices_sort(Polygon &pol) {  // 点を反時計周りにソート．O(NlogN).
    int n = pol.size();
    Polygon tmp = pol;
    int p = 0;
    for(int i = 1; i < n; ++i) {
        if(less_than(tmp[i].y, tmp[p].y))
            p = i;
        else if(no_more(tmp[i].y, tmp[p].y) and less_than(tmp[i].x, tmp[p].x))
            p = i;
    }
    std::vector<std::pair<Type, int> > vp(n);
    for(int i = 0; i < n; ++i) {
        if(i == p)
            vp[i] = std::pair<Type, int>(-10.0, i);
        else
            vp[i] = std::pair<Type, int>(arg(tmp[i] - tmp[p]), i);
    }
    std::sort(vp.begin(), vp.end());
    for(int i = 0; i < n; ++i) pol[i] = tmp[vp[i].second];
}

Type area(const Point &A, const Point &B, const Point &C) { return std::abs(cross(B - A, C - A)) / 2.0; }  // 三角形の面積．
Type area(const Polygon &pol) {                                                                            // O(N).
    Type res = 0.0;
    int n = pol.size();
    for(int i = 0; i < n; ++i) res += cross(pol[i], pol[(i + 1) % n]);
    return res / 2.0;
}

int contain(const Polygon &pol, const Point &P) {  // 多角形と点の包含関係．O(N).
    int n = pol.size();
    bool jud = false;
    for(int i = 0; i < n; ++i) {
        Vector A = pol[i] - P, B = pol[(i + 1) % n] - P;
        if(equals(cross(A, B), 0.0) and no_more(dot(A, B), 0.0)) return 1;  // on.
        if(A.y > B.y) std::swap(A, B);
        if(no_more(A.y, 0.0) and less_than(0.0, B.y) and more_than(cross(A, B), 0.0)) jud = !jud;
    }
    return (jud ? 2 : 0);  // in or out.
}

bool is_convex(const Polygon &pol) {  // 凸性判定．O(N).
    int n = pol.size();
    for(int i = 0; i < n; ++i) {
        if(ccw(pol[i], pol[(i + 1) % n], pol[(i + 2) % n]) == -1) return false;
    }
    return true;
}

Polygon andrew_scan(Polygon &pol, bool eliminate_dup = true) {  // アンドリューのアルゴリズム．凸包．O(NlogN).
    int cmp = (eliminate_dup ? geometry::EPS : -geometry::EPS);
    int n = pol.size();
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

Polygon convex_cut(const Polygon &pol, const Line &l) {  // 凸多角形の切断．O(N).
    assert(is_convex(pol));
    Polygon res;
    int n = pol.size();
    for(int i = 0; i < n; ++i) {
        Point P = pol[i], Q = pol[(i + 1) % n];
        if(ccw(l[0], l[1], P) != -1) {
            if(res.size() == 0 or P != *res.rbegin()) res.push_back(P);
        }
        if(ccw(l[0], l[1], P) * ccw(l[0], l[1], Q) < 0) {
            std::vector<Point> temp = cross_point(Line(P, Q), l);
            if(temp.size() == 0) continue;
            if(res.size() == 0 or temp[0] != *res.rbegin()) res.push_back(temp[0]);
        }
    }
    return res;
}

}  // namespace geometry

// using namespace geometry;

}  // namespace algorithm

#endif  // ALGORITHM_GEOMETRY_FUNCTION_HPP
