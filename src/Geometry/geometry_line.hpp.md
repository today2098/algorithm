---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/Geometry/geometry_vector.hpp
    title: src/Geometry/geometry_vector.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/Geometry/geometry_figure.hpp
    title: src/Geometry/geometry_figure.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - "https://qiita.com/zu_rin/items/09876d2c7ec12974bc0f\uFF08\u53C2\u71672023.2.6\uFF09\
      \uFF0E"
    - "https://qiita.com/zu_rin/items/e04fdec4e3dec6072104\uFF08\u53C2\u71672023.2.6\uFF09\
      \uFF0E"
  bundledCode: "#line 1 \"src/Geometry/geometry_line.hpp\"\n\n\n\n#include <array>\n\
    #include <cassert>\n#include <iostream>\n\n#line 1 \"src/Geometry/geometry_vector.hpp\"\
    \n\n\n\n#include <cmath>\n#line 6 \"src/Geometry/geometry_vector.hpp\"\n#include\
    \ <vector>\n\nnamespace algorithm {\n\nnamespace geometry {\n\nusing Type = double;\n\
    \nconst Type INF = 1e18;\nconst Type EPS = 1e-10;\nconst Type PI = std::acos(-1.0);\n\
    \ninline bool equal_to(const Type &a, const Type &b) { return std::abs(a - b)\
    \ < EPS; }\ninline bool less_than(const Type &a, const Type &b) { return a - b\
    \ < -EPS; }\ninline bool more_than(const Type &a, const Type &b) { return a -\
    \ b > EPS; }\ninline bool no_more(const Type &a, const Type &b) { return a - b\
    \ < EPS; }\ninline bool no_less(const Type &a, const Type &b) { return a - b >\
    \ -EPS; }\n\n// \u89D2\u5EA6\u3092\u5F27\u5EA6\u6CD5\u306B\u5909\u63DB\u3059\u308B\
    \uFF0E\ninline Type to_radian(Type deg) { return deg / 180.0 * PI; }\n// \u89D2\
    \u5EA6\u3092\u5EA6\u6570\u6CD5\u306B\u5909\u63DB\u3059\u308B\uFF0E\ninline Type\
    \ to_degree(Type rad) { return rad / PI * 180.0; }\n\nstruct Vector {\n    Type\
    \ x, y;\n\n    Vector() : Vector(0.0, 0.0) {}\n    Vector(Type x_, Type y_) :\
    \ x(x_), y(y_) {}\n\n    Vector operator+() const { return Vector(*this); }\n\
    \    Vector operator-() const { return Vector(-x, -y); }\n    Vector operator*(Type\
    \ n) const { return Vector(x * n, y * n); }\n    Vector operator/(Type n) const\
    \ { return Vector(x / n, y / n); }\n    Vector &operator*=(Type n) {\n       \
    \ x *= n, y *= n;\n        return *this;\n    }\n    Vector &operator/=(Type n)\
    \ {\n        x /= n, y /= n;\n        return *this;\n    }\n    Vector &operator+=(const\
    \ Vector &a) {\n        x += a.x, y += a.y;\n        return *this;\n    }\n  \
    \  Vector &operator-=(const Vector &a) {\n        x -= a.x, y -= a.y;\n      \
    \  return *this;\n    }\n\n    friend Vector operator*(Type n, const Vector &a)\
    \ { return a * n; }\n    friend Vector operator+(const Vector &a, const Vector\
    \ &b) { return Vector(a.x + b.x, a.y + b.y); }\n    friend Vector operator-(const\
    \ Vector &a, const Vector &b) { return Vector(a.x - b.x, a.y - b.y); }\n    friend\
    \ bool operator<(const Vector &a, const Vector &b) { return (equal_to(a.x, b.x)\
    \ ? less_than(a.y, b.y) : less_than(a.x, b.x)); }\n    friend bool operator>(const\
    \ Vector &a, const Vector &b) { return (equal_to(a.x, b.x) ? more_than(a.y, b.y)\
    \ : more_than(a.x, b.x)); }\n    friend bool operator<=(const Vector &a, const\
    \ Vector &b) { return (equal_to(a.x, b.x) ? no_more(a.y, b.y) : no_more(a.x, b.x));\
    \ }\n    friend bool operator>=(const Vector &a, const Vector &b) { return (equal_to(a.x,\
    \ b.x) ? no_less(a.y, b.y) : no_less(a.x, b.x)); }\n    friend bool operator==(const\
    \ Vector &a, const Vector &b) { return (equal_to(a.x, b.x) and equal_to(a.y, b.y));\
    \ }\n    friend bool operator!=(const Vector &a, const Vector &b) { return !(a\
    \ == b); }\n    friend std::ostream &operator<<(std::ostream &os, const Vector\
    \ &a) { return os << \"(\" << a.x << \", \" << a.y << \")\"; }\n\n    // \u30CE\
    \u30EB\u30E0\uFF0E\n    Type norm() const { return std::sqrt(dot(*this, *this));\
    \ }\n    // x\u8EF8\u3068\u306A\u3059\u89D2\uFF0E[-\u03C0,\u03C0].\n    Type arg()\
    \ const { return std::atan2(y, x); }\n    // x\u8EF8\u3068\u306A\u3059\u89D2\uFF0E\
    [0,2\u03C0).\n    Type arg2() const {\n        auto res = arg();\n        if(less_than(res,\
    \ 0.0)) res += 2 * PI;\n        return res;\n    }\n    // \u53CD\u6642\u8A08\u56DE\
    \u308A\u306B\u89D2\u5EA6arg\uFF08\u30E9\u30B8\u30A2\u30F3\u5358\u4F4D\uFF09\u56DE\
    \u8EE2\u3057\u305F\u30D9\u30AF\u30C8\u30EB\uFF0E\n    Vector rotate(Type arg)\
    \ const {\n        Type nx = x * std::cos(arg) - y * std::sin(arg);\n        Type\
    \ ny = x * std::sin(arg) + y * std::cos(arg);\n        return Vector(nx, ny);\n\
    \    }\n    // \u53CD\u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\u3057\u305F\
    \u30D9\u30AF\u30C8\u30EB\uFF0E\n    Vector rotate90() const { return Vector(-y,\
    \ x); }\n    // 180\u5EA6\u56DE\u8EE2\u3057\u305F\u30D9\u30AF\u30C8\u30EB\uFF0E\
    \n    Vector rotate180() const { return Vector(-x, -y); }\n    // \u5358\u4F4D\
    \u30D9\u30AF\u30C8\u30EB\uFF0E\n    Vector unit() const { return *this / norm();\
    \ }\n\n    // \u5185\u7A4D\uFF0E\n    friend inline Type dot(const Vector &a,\
    \ const Vector &b) { return a.x * b.x + a.y * b.y; }\n    // \u5916\u7A4D\uFF0E\
    \n    friend inline Type cross(const Vector &a, const Vector &b) { return a.x\
    \ * b.y - a.y * b.x; }\n};\n\nusing Point = Vector;\nusing Polygon = std::vector<Point>;\n\
    \n// \u53CD\u6642\u8A08\u56DE\u308A\u306B\u89D2\u5EA6arg\uFF08\u30E9\u30B8\u30A2\
    \u30F3\u5358\u4F4D\uFF09\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\nvoid rotate(Vector\
    \ &a, Type arg) {\n    Type nx = a.x * std::cos(arg) - a.y * std::sin(arg);\n\
    \    Type ny = a.x * std::sin(arg) + a.y * std::cos(arg);\n    a.x = nx, a.y =\
    \ ny;\n}\n// \u53CD\u6642\u8A08\u5468\u308A\u306B90\u5EA6\u56DE\u8EE2\u3055\u305B\
    \u308B\uFF0E\ninline void rotate90(Vector &a) {\n    auto tmp = a.x;\n    a.x\
    \ = -a.y;\n    a.y = tmp;\n}\n// \u53CD\u6642\u8A08\u5468\u308A\u306B180\u5EA6\
    \u56DE\u8EE2\u3055\u305B\u308B\uFF0E\ninline void rotate180(Vector &a) { a.x =\
    \ -a.x, a.y = -a.y; }\n\n// 2\u70B9\u9593\u8DDD\u96E2\u3092\u8A08\u7B97\u3059\u308B\
    \uFF0E\ninline Type distance(const Point &P, const Point &Q) { return (Q - P).norm();\
    \ }\n\n// 3\u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2\uFF0E\nint simple_ccw(const Point\
    \ &A, const Point &B, const Point &P) {\n    Vector b = B - A, p = P - A;\n  \
    \  if(more_than(cross(b, p), 0.0)) return 1;   // A->B\u306E\u53CD\u6642\u8A08\
    \u65B9\u5411\u306BP\uFF0E\n    if(less_than(cross(b, p), 0.0)) return -1;  //\
    \ A->B\u306E\u6642\u8A08\u65B9\u5411\u306BP\uFF0E\n    return 0;             \
    \                      // \u4E00\u76F4\u7DDA\u4E0A\uFF0E\n}\nint ccw(const Point\
    \ &A, const Point &B, const Point &P) {\n    Vector b = B - A, p = P - A;\n  \
    \  if(more_than(cross(b, p), 0.0)) return 1;      // A->B\u306E\u53CD\u6642\u8A08\
    \u65B9\u5411\u306BP\uFF0Ecounter clockwise.\n    if(less_than(cross(b, p), 0.0))\
    \ return -1;     // A->B\u306E\u6642\u8A08\u65B9\u5411\u306BP\uFF0Eclockwise.\n\
    \    if(less_than(dot(b, p), 0.0)) return -2;       // P->A->B\u306E\u9806\u306B\
    \u4E00\u76F4\u7DDA\u4E0A\uFF0Eonline back.\n    if(more_than(dot(p, p), dot(b,\
    \ b))) return 2;  // A->B->P\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\uFF0Eonline\
    \ front.\n    return 0;                                      // A->P->B\u306E\u9806\
    \u306B\u4E00\u76F4\u7DDA\u4E0A\uFF0Eon segment.\n}\n\n// \u4E09\u89D2\u5F62\u3068\
    \u70B9\u306E\u5305\u542B\u95A2\u4FC2\uFF0E\nint contain(const Point &A, const\
    \ Point &B, const Point &C, const Point &P) {\n    int flag1 = ccw(A, B, P), flag2\
    \ = ccw(B, C, P), flag3 = ccw(C, A, P);\n    if(flag1 == 0 or flag2 == 0 or flag3\
    \ == 0) return 1;       // on.\n    if(flag1 == -1 and flag2 == -1 and flag3 ==\
    \ -1) return 2;  // in.\n    if(flag1 == 1 and flag2 == 1 and flag3 == 1) return\
    \ 2;     // in.\n    return 0;                                               \
    \   // out.\n}\n\n// \u8907\u7D20\u6570\uFF0E\nstruct Complex : public Point {\n\
    \    Complex() : Point() {}\n    Complex(const Point &P) : Point(P) {}\n    Complex(Type\
    \ x_, Type y_) : Point(x_, y_) {}\n\n    Complex &operator*=(const Complex &z)\
    \ {\n        const auto [tx, ty] = *this;\n        x = tx * z.x - ty * z.y;\n\
    \        y = tx * z.y + ty * z.x;\n        return *this;\n    }\n    Complex &operator/=(const\
    \ Complex &z) {\n        const auto [tx, ty] = *this;\n        x = tx * z.x -\
    \ ty * z.y;\n        y = tx * z.y + ty * z.x;\n        return *this;\n    }\n\n\
    \    friend Complex operator*(const Complex &z, const Complex &w) { return Complex(z.x\
    \ * w.x - z.y * w.y, z.x * w.y + z.y * w.x); }\n    friend Complex operator/(const\
    \ Complex &z, const Complex &w) { return Complex(z / (w.x * w.x + w.y * w.y))\
    \ * w; }\n\n    // \u5171\u5F79\u8907\u7D20\u6570\uFF0EConjugate complex number.\n\
    \    Complex conj() const { return Complex(x, -y); }\n};\n\n// \u6975\u5F62\u5F0F\
    \uFF0E\u5927\u304D\u3055r\uFF0C\u504F\u89D2arg\u306E\u8907\u7D20\u6570\u3092\u8FD4\
    \u3059\uFF0E\ninline Complex polar(Type r, Type arg) { return Complex(r * std::cos(arg),\
    \ r * std::sin(arg)); }\n// \u6975\u5F62\u5F0F(r,\u03B8)\u306B\u5909\u63DB\u3059\
    \u308B\uFF0E\u03B8\u2208[-\u03C0,\u03C0].\ninline std::pair<Type, Type> convert_polor(const\
    \ Complex &z) { return {z.norm(), z.arg()}; }\n// \u6975\u5F62\u5F0F(r,\u03B8\
    )\u306B\u5909\u63DB\u3059\u308B\uFF0E\u03B8\u2208[0,2\u03C0).\ninline std::pair<Type,\
    \ Type> convert_polor2(const Complex &z) { return {z.norm(), z.arg2()}; }\n\n\
    }  // namespace geometry\n\n// using namespace geometry;\n\n}  // namespace algorithm\n\
    \n\n#line 9 \"src/Geometry/geometry_line.hpp\"\n\nnamespace algorithm {\n\nnamespace\
    \ geometry {\n\n// \u76F4\u7DDA\uFF0E\nstruct Line {\n    std::array<Point, 2>\
    \ ps;\n\n    Line() : Line(Point(), Point()) {}\n    explicit Line(const Point\
    \ &P, const Point &Q) : ps({P, Q}) {}\n\n    Point &operator[](int i) {\n    \
    \    assert(0 <= i and i < 2);\n        return ps[i];\n    }\n    const Point\
    \ &operator[](int i) const {\n        assert(0 <= i and i < 2);\n        return\
    \ ps[i];\n    }\n\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ Line &s) { return os << \"{\" << s[0] << \", \" << s[1] << \"}\"; }\n\n    //\
    \ \u50BE\u304D\uFF0E\n    Type slope() const { return (ps[1].y - ps[0].y) / (ps[1].x\
    \ - ps[0].x); }\n    // y\u5207\u7247\uFF0E\n    Type y_intercept() const { return\
    \ ps[0].y - slope() * ps[0].x; }\n    // x\u5207\u7247\uFF0E\n    Type x_intercept()\
    \ const { return ps[0].x - ps[0].y / slope(); }\n    bool on_line(const Point\
    \ &P) const { return equal_to(cross(ps[1] - ps[0], P - ps[0]), 0.0); }\n};\n\n\
    // \u7DDA\u5206\uFF0E\nstruct Segment : public Line {\n    Segment() : Line()\
    \ {}\n    Segment(const Line &l) : Line(l) {}\n    explicit Segment(const Point\
    \ &P, const Point &Q) : Line(P, Q) {}\n\n    // \u7DDA\u5206\u306E\u9577\u3055\
    \uFF0E\n    Type length() const { return distance(ps[0], ps[1]); }\n    bool on_segment(const\
    \ Point &P) const {\n        Vector b = ps[1] - ps[0], p = P - ps[0];\n      \
    \  if(!equal_to(cross(b, p), 0.0)) return false;\n        return (no_less(dot(b,\
    \ p), 0.0) and no_more(dot(p, p), dot(b, b)));\n    }\n};\n\n// \u76F4\u7DDA\u306E\
    \u76F4\u4EA4\u5224\u5B9A\uFF0E\nbool jud_orthogonal(const Line &l, const Line\
    \ &m) {\n    Vector b = l[1] - l[0], d = m[1] - m[0];\n    return equal_to(dot(b,\
    \ d), 0.0);\n}\n// \u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A\uFF0E\nbool jud_parallel(const\
    \ Line &l, const Line &m) {\n    Vector b = l[1] - l[0], d = m[1] - m[0];\n  \
    \  return equal_to(cross(b, d), 0.0);\n}\n// \u76F4\u7DDA\u306E\u4EA4\u5DEE\u5224\
    \u5B9A\uFF0E\nbool jud_intersection(const Line &l, const Line &m) { return !jud_parallel(l,\
    \ m); }\n// \u76F4\u7DDA\u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\uFF0E\
    \nbool jud_intersection(const Line &l, const Segment &m) {\n    Vector b = l[1]\
    \ - l[0];\n    auto s = cross(b, m[0] - l[0]);\n    auto t = cross(b, m[1] - l[0]);\n\
    \    return no_more(s * t, 0.0);\n}\nbool jud_intersection(const Segment &l, const\
    \ Line &m) { return jud_intersection(m, l); }\n// \u7DDA\u5206\u306E\u4EA4\u5DEE\
    \u5224\u5B9A\uFF0E\nbool jud_intersection(const Segment &l, const Segment &m)\
    \ {\n    Vector b = l[1] - l[0], d = m[1] - m[0];\n    auto s = cross(b, m[0]\
    \ - l[0]);\n    auto t = cross(b, m[1] - l[0]);\n    if(more_than(s * t, 0.0))\
    \ return false;\n    s = cross(d, l[0] - m[0]);\n    t = cross(d, l[1] - m[0]);\n\
    \    if(more_than(s * t, 0.0)) return false;\n    return true;\n}\n\n// 2\u76F4\
    \u7DDA\u306E\u4EA4\u70B9\uFF0E\nPoint intersection(const Line &l, const Line &m)\
    \ {\n    Vector b = l[1] - l[0], d = m[1] - m[0];\n    auto s = cross(m[0] - l[0],\
    \ d) / cross(b, d);\n    return Point(l[0] + s * b);\n    // auto t = cross(b,\
    \ l[0] - m[0]) / cross(b, d);\n    // return Point(m[0] + t * d);\n}\n\n// \u5782\
    \u7DDA\u306E\u8DB3\uFF0E\nPoint projection(const Line &l, const Point &P) {\n\
    \    Vector a = l[1] - l[0];\n    return l[0] + a * (dot(P - l[0], a) / dot(a,\
    \ a));\n}\n// \u5BFE\u8C61\u70B9\uFF0E\nPoint reflection(const Line &l, const\
    \ Point &P) {\n    Point H = projection(l, P);\n    return P + 2 * (H - P);\n\
    }\n\n// \u70B9\u3068\u7DDA\u306E\u8DDD\u96E2\uFF0E\nType distance(const Line &l,\
    \ const Point &P) {\n    Point H = projection(l, P);\n    return distance(P, H);\n\
    }\nType distance(const Point &P, const Line &l) { return distance(l, P); }\nType\
    \ distance(const Segment &s, const Point &P) {\n    Point H = projection(s, P);\n\
    \    if(s.on_segment(H)) return distance(H, P);\n    return std::min(distance(P,\
    \ s[0]), distance(P, s[1]));\n}\nType distance(const Point &P, const Segment &s)\
    \ { return distance(s, P); }\n\n}  // namespace geometry\n\n// using namespace\
    \ geometry;\n\n}  // namespace algorithm\n\n\n\n/*\n\u53C2\u8003\u6587\u732E\n\
    - zu_rin, 2\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\u624B\u6CD5 (2\u6B21\u5143\
    )\uFF0Chttps://qiita.com/zu_rin/items/e04fdec4e3dec6072104\uFF08\u53C2\u71672023.2.6\uFF09\
    \uFF0E\n- zu_rin, 2\u7DDA\u5206\u306E\u4EA4\u70B9\u5EA7\u6A19(2\u6B21\u5143)\uFF0C\
    https://qiita.com/zu_rin/items/09876d2c7ec12974bc0f\uFF08\u53C2\u71672023.2.6\uFF09\
    \uFF0E\n*/\n"
  code: "#ifndef ALGORITHM_GEOMETRY_LINE_HPP\n#define ALGORITHM_GEOMETRY_LINE_HPP\
    \ 1\n\n#include <array>\n#include <cassert>\n#include <iostream>\n\n#include \"\
    geometry_vector.hpp\"\n\nnamespace algorithm {\n\nnamespace geometry {\n\n// \u76F4\
    \u7DDA\uFF0E\nstruct Line {\n    std::array<Point, 2> ps;\n\n    Line() : Line(Point(),\
    \ Point()) {}\n    explicit Line(const Point &P, const Point &Q) : ps({P, Q})\
    \ {}\n\n    Point &operator[](int i) {\n        assert(0 <= i and i < 2);\n  \
    \      return ps[i];\n    }\n    const Point &operator[](int i) const {\n    \
    \    assert(0 <= i and i < 2);\n        return ps[i];\n    }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Line &s) { return os << \"{\" << s[0] <<\
    \ \", \" << s[1] << \"}\"; }\n\n    // \u50BE\u304D\uFF0E\n    Type slope() const\
    \ { return (ps[1].y - ps[0].y) / (ps[1].x - ps[0].x); }\n    // y\u5207\u7247\uFF0E\
    \n    Type y_intercept() const { return ps[0].y - slope() * ps[0].x; }\n    //\
    \ x\u5207\u7247\uFF0E\n    Type x_intercept() const { return ps[0].x - ps[0].y\
    \ / slope(); }\n    bool on_line(const Point &P) const { return equal_to(cross(ps[1]\
    \ - ps[0], P - ps[0]), 0.0); }\n};\n\n// \u7DDA\u5206\uFF0E\nstruct Segment :\
    \ public Line {\n    Segment() : Line() {}\n    Segment(const Line &l) : Line(l)\
    \ {}\n    explicit Segment(const Point &P, const Point &Q) : Line(P, Q) {}\n\n\
    \    // \u7DDA\u5206\u306E\u9577\u3055\uFF0E\n    Type length() const { return\
    \ distance(ps[0], ps[1]); }\n    bool on_segment(const Point &P) const {\n   \
    \     Vector b = ps[1] - ps[0], p = P - ps[0];\n        if(!equal_to(cross(b,\
    \ p), 0.0)) return false;\n        return (no_less(dot(b, p), 0.0) and no_more(dot(p,\
    \ p), dot(b, b)));\n    }\n};\n\n// \u76F4\u7DDA\u306E\u76F4\u4EA4\u5224\u5B9A\
    \uFF0E\nbool jud_orthogonal(const Line &l, const Line &m) {\n    Vector b = l[1]\
    \ - l[0], d = m[1] - m[0];\n    return equal_to(dot(b, d), 0.0);\n}\n// \u76F4\
    \u7DDA\u306E\u5E73\u884C\u5224\u5B9A\uFF0E\nbool jud_parallel(const Line &l, const\
    \ Line &m) {\n    Vector b = l[1] - l[0], d = m[1] - m[0];\n    return equal_to(cross(b,\
    \ d), 0.0);\n}\n// \u76F4\u7DDA\u306E\u4EA4\u5DEE\u5224\u5B9A\uFF0E\nbool jud_intersection(const\
    \ Line &l, const Line &m) { return !jud_parallel(l, m); }\n// \u76F4\u7DDA\u3068\
    \u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\uFF0E\nbool jud_intersection(const\
    \ Line &l, const Segment &m) {\n    Vector b = l[1] - l[0];\n    auto s = cross(b,\
    \ m[0] - l[0]);\n    auto t = cross(b, m[1] - l[0]);\n    return no_more(s * t,\
    \ 0.0);\n}\nbool jud_intersection(const Segment &l, const Line &m) { return jud_intersection(m,\
    \ l); }\n// \u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\uFF0E\nbool jud_intersection(const\
    \ Segment &l, const Segment &m) {\n    Vector b = l[1] - l[0], d = m[1] - m[0];\n\
    \    auto s = cross(b, m[0] - l[0]);\n    auto t = cross(b, m[1] - l[0]);\n  \
    \  if(more_than(s * t, 0.0)) return false;\n    s = cross(d, l[0] - m[0]);\n \
    \   t = cross(d, l[1] - m[0]);\n    if(more_than(s * t, 0.0)) return false;\n\
    \    return true;\n}\n\n// 2\u76F4\u7DDA\u306E\u4EA4\u70B9\uFF0E\nPoint intersection(const\
    \ Line &l, const Line &m) {\n    Vector b = l[1] - l[0], d = m[1] - m[0];\n  \
    \  auto s = cross(m[0] - l[0], d) / cross(b, d);\n    return Point(l[0] + s *\
    \ b);\n    // auto t = cross(b, l[0] - m[0]) / cross(b, d);\n    // return Point(m[0]\
    \ + t * d);\n}\n\n// \u5782\u7DDA\u306E\u8DB3\uFF0E\nPoint projection(const Line\
    \ &l, const Point &P) {\n    Vector a = l[1] - l[0];\n    return l[0] + a * (dot(P\
    \ - l[0], a) / dot(a, a));\n}\n// \u5BFE\u8C61\u70B9\uFF0E\nPoint reflection(const\
    \ Line &l, const Point &P) {\n    Point H = projection(l, P);\n    return P +\
    \ 2 * (H - P);\n}\n\n// \u70B9\u3068\u7DDA\u306E\u8DDD\u96E2\uFF0E\nType distance(const\
    \ Line &l, const Point &P) {\n    Point H = projection(l, P);\n    return distance(P,\
    \ H);\n}\nType distance(const Point &P, const Line &l) { return distance(l, P);\
    \ }\nType distance(const Segment &s, const Point &P) {\n    Point H = projection(s,\
    \ P);\n    if(s.on_segment(H)) return distance(H, P);\n    return std::min(distance(P,\
    \ s[0]), distance(P, s[1]));\n}\nType distance(const Point &P, const Segment &s)\
    \ { return distance(s, P); }\n\n}  // namespace geometry\n\n// using namespace\
    \ geometry;\n\n}  // namespace algorithm\n\n#endif\n\n/*\n\u53C2\u8003\u6587\u732E\
    \n- zu_rin, 2\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\u624B\u6CD5 (2\u6B21\u5143\
    )\uFF0Chttps://qiita.com/zu_rin/items/e04fdec4e3dec6072104\uFF08\u53C2\u71672023.2.6\uFF09\
    \uFF0E\n- zu_rin, 2\u7DDA\u5206\u306E\u4EA4\u70B9\u5EA7\u6A19(2\u6B21\u5143)\uFF0C\
    https://qiita.com/zu_rin/items/09876d2c7ec12974bc0f\uFF08\u53C2\u71672023.2.6\uFF09\
    \uFF0E\n*/\n"
  dependsOn:
  - src/Geometry/geometry_vector.hpp
  isVerificationFile: false
  path: src/Geometry/geometry_line.hpp
  requiredBy:
  - src/Geometry/geometry_figure.hpp
  timestamp: '2023-02-14 22:14:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Geometry/geometry_line.hpp
layout: document
redirect_from:
- /library/src/Geometry/geometry_line.hpp
- /library/src/Geometry/geometry_line.hpp.html
title: src/Geometry/geometry_line.hpp
---
