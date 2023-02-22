#ifndef ALGORITHM_MATRIX_HPP
#define ALGORITHM_MATRIX_HPP 1

#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>
#include <tuple>
#include <vector>

namespace algorithm {

namespace matrix {

using Type = double;

constexpr Type EPS = 1e-10;

template <typename T>
class Matrix {
    int m_col;
    int m_row;
    std::vector<std::vector<T> > m_dat;
    bool m_is_transposed;

public:
    Matrix() : Matrix(0, 0) {}
    explicit Matrix(int m, int n) : m_col(m), m_row(n), m_dat(m, std::vector<T>(n)), m_is_transposed(false) {}
    explicit Matrix(int m, int n, T val) : m_col(m), m_row(n), m_dat(m, std::vector<T>(n, val)), m_is_transposed(false) {}
    explicit Matrix(const std::vector<std::vector<T> > &val) : m_col(val.size()), m_row(0), m_dat(val), m_is_transposed(false) {
        for(const auto &v : m_dat) m_row = std::max(m_row, static_cast<int>(v.size()));
        for(auto &v : m_dat) v.resize(m_row, 0);
    }

    Matrix operator+() const { return Matrix(*this); }
    Matrix operator-() const {
        Matrix R(column(), row());
        for(int i = 0; i < column(); ++i) {
            for(int j = 0; j < row(); ++j) R.loc(i, j) = -loc(i, j);
        }
        return R;
    }
    Matrix &operator*=(T a) {
        for(int i = 0; i < column(); ++i) {
            for(int j = 0; j < row(); ++j) loc(i, j) *= a;
        }
        return *this;
    }
    Matrix &operator/=(T a) {
        for(int i = 0; i < column(); ++i) {
            for(int j = 0; j < row(); ++j) loc(i, j) /= a;
        }
        return *this;
    }
    Matrix &operator+=(const Matrix &A) {
        assert(A.column() == column() and A.row() == row());
        for(int i = 0; i < column(); ++i) {
            for(int j = 0; j < row(); ++j) loc(i, j) += A.loc(i, j);
        }
        return *this;
    }
    Matrix &operator-=(const Matrix &A) {
        assert(A.column() == column() and A.row() == row());
        for(int i = 0; i < column(); ++i) {
            for(int j = 0; j < row(); ++j) loc(i, j) -= A.loc(i, j);
        }
        return *this;
    }
    Matrix operator*(T a) const {
        Matrix R(*this);
        R *= a;
        return R;
    }
    Matrix operator/(T a) const {
        Matrix R(*this);
        R /= a;
        return R;
    }

    friend Matrix operator*(T a, const Matrix &A) { return A * a; }
    friend Matrix operator*(const Matrix &A, const Matrix &B) {
        assert(A.row() == B.column());
        Matrix R(A.column(), B.row(), 0);
        for(int i = 0; i < A.column(); ++i) {
            for(int j = 0; j < B.row(); ++j) {
                for(int k = 0; k < A.row(); ++k) R.loc(i, j) += A.loc(i, k) * B.loc(k, j);
            }
        }
        return R;
    }
    friend Matrix operator+(const Matrix<T> &A, const Matrix<T> &B) {
        assert(A.column() == B.column() and A.row() == B.row());
        Matrix R(A.column(), A.row());
        for(int i = 0; i < R.column(); ++i) {
            for(int j = 0; j < R.row(); ++j) R.loc(i, j) = A.loc(i, j) + B.loc(i, j);
        }
        return R;
    }
    friend Matrix operator-(const Matrix<T> &A, const Matrix<T> &B) {
        assert(A.column() == B.column() and A.row() == B.row());
        Matrix R(A.column(), A.row());
        for(int i = 0; i < R.column(); ++i) {
            for(int j = 0; j < R.row(); ++j) R.loc(i, j) = A.loc(i, j) - B.loc(i, j);
        }
        return R;
    }
    friend bool operator==(const Matrix<T> &A, const Matrix<T> &B) {
        assert(A.column() == B.column() and A.row() == B.row());
        for(int i = 0; i < A.column(); ++i) {
            for(int j = 0; j < A.row(); ++j) {
                if(A.loc(i, j) != B.loc(i, j)) return false;
            }
        }
        return true;
    }
    friend bool operator!=(const Matrix<T> &A, const Matrix<T> &B) { return !(A == B); }
    friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &A) {
        for(int i = 0; i < A.column(); ++i) {
            for(int j = 0; j < A.row(); ++j) os << (i == 0 and j == 0 ? '[' : ' ') << A.loc(i, j);
            os << (i == A.column() - 1 ? ']' : '\n');
        }
        return os;
    }

    // 零行列．
    static Matrix zero_matrix(int m, int n) {
        assert(m >= 0 and n >= 0);
        Matrix O(m, n, 0);
        return O;
    }
    // 単位行列．
    static Matrix identity_matrix(int n) {
        assert(n >= 0);
        Matrix I(n, n, 0);
        for(int i = 0; i < n; ++i) I.loc(i, i) = 1;
        return I;
    }

    // 行数．
    int column() const { return (m_is_transposed ? m_row : m_col); }
    // 列数．
    int row() const { return (m_is_transposed ? m_col : m_row); }
    T &loc(int i, int j) {
        assert(0 <= i and i < column() and 0 <= j and j < row());
        return (m_is_transposed ? m_dat[j][i] : m_dat[i][j]);
    }
    const T loc(int i, int j) const {
        assert(0 <= i and i < column() and 0 <= j and j < row());
        return (m_is_transposed ? m_dat[j][i] : m_dat[i][j]);
    }
    bool is_transposed() const { return m_is_transposed; }
    // 転置．
    void transpose() { m_is_transposed = !m_is_transposed; }
};

using mat = Matrix<Type>;

// 転置行列．
template <typename T>
inline Matrix<T> transposed_matrix(const Matrix<T> &A) {
    Matrix<T> tA(A.row(), A.column());
    for(int i = 0; i < A.row(); ++i) {
        for(int j = 0; j < A.column(); ++j) tA.loc(i, j) = A.loc(j, i);
    }
    return tA;
}

class Permutation {
    int m_n;                  // m_n:=(次元数).
    std::vector<int> m_perm;  // m_perm[]:=(置換行列).
    std::vector<int> m_inv;   // m_inv[]:=(m_perm[]に対する逆置換行列). m_inv[m_perm[i]]==i
    bool m_is_inversed;

    int &operator[](int i) {
        assert(0 <= i and i < order());
        return (is_inversed() ? m_inv[i] : m_perm[i]);
    }

    int &inv(int i) {
        assert(0 <= i and i < order());
        return (is_inversed() ? m_perm[i] : m_inv[i]);
    }
    bool is_inversed() const { return m_is_inversed; }

public:
    Permutation() : Permutation(0) {}
    explicit Permutation(int n) : m_n(n), m_perm(n), m_inv(n), m_is_inversed(false) {
        std::iota(m_perm.begin(), m_perm.end(), 0);
        std::iota(m_inv.begin(), m_inv.end(), 0);
    }
    explicit Permutation(const std::vector<int> &pivot)
        : m_n(pivot.size()), m_perm(pivot), m_inv(pivot.size(), -1), m_is_inversed(false) {
        for(int i = 0; i < m_n; ++i) {
            assert(0 <= m_perm[i] and m_perm[i] < m_n);
            assert(m_inv[m_perm[i]] == -1);
            m_inv[m_perm[i]] = i;
        }
    }

    const int operator[](int i) const {
        assert(0 <= i and i < order());
        return (is_inversed() ? m_inv[i] : m_perm[i]);
    }
    template <typename T>
    Matrix<T> operator*(const Matrix<T> &A) {
        assert(A.column() == order());
        Matrix<T> R(A.column(), A.row());
        for(int i = 0; i < A.column(); ++i) {
            for(int j = 0; j < A.row(); ++j) R.loc(i, j) = A.loc((*this)[i], j);
        }
        return R;
    }
    Permutation operator*(const Permutation &P) {
        assert(P.order() == order());
        std::vector<int> res(order());
        for(int i = 0; i < order(); ++i) res[i] = P[(*this)[i]];
        return Permutation(res);
    }

    friend std::ostream &operator<<(std::ostream &os, const Permutation &P) {
        for(int i = 0; i < P.order(); ++i) os << (i == 0 ? '[' : ' ') << i;
        os << '\n';
        for(int i = 0; i < P.order(); ++i) os << ' ' << P[i];
        os << ']';
        return os;
    }

    int order() const { return m_n; }
    const int inv(int i) const {
        assert(0 <= i and i < order());
        return (is_inversed() ? m_perm[i] : m_inv[i]);
    }
    void swap(int i, int j) {
        assert(0 <= i and i < order());
        assert(0 <= j and j < order());
        std::swap((*this)[i], (*this)[j]);
        inv((*this)[i]) = i;
        inv((*this)[j]) = j;
    }
    void inverse() { m_is_inversed = !m_is_inversed; }
    template <typename T>
    void sort(Matrix<T> &A) const {
        assert(A.column() == order());
        bool seen[order()] = {};
        for(int i = 0; i < order(); ++i) {
            if(seen[i]) continue;
            int idx = inv(i);
            while(idx != i) {
                for(int j = 0; j < A.row(); ++j) std::swap(A.loc(i, j), A.loc(idx, j));
                seen[idx] = true;
                idx = inv(idx);
            }
            seen[i] = true;
        }
    }
    void sort(Permutation &P) const {
        assert(P.order() == order());
        bool seen[order()] = {};
        for(int i = 0; i < order(); ++i) {
            if(seen[i]) continue;
            int idx = inv(i);
            while(idx != i) {
                std::swap(P[i], P[idx]);
                seen[idx] = true;
                idx = inv(idx);
            }
            seen[i] = true;
        }
    }
    template <typename T>
    void reverse(Matrix<T> &A) {
        inverse();
        sort(A);
        inverse();
    }
    void reverse(Permutation &P) {
        inverse();
        sort(P);
        inverse();
    }
    void init() {
        std::iota(m_perm.begin(), m_perm.end(), 0);
        std::iota(m_inv.begin(), m_inv.end(), 0);
        m_is_inversed = false;
    }

    auto begin() const { return (is_inversed() ? m_inv.begin() : m_perm.begin()); }
    auto end() const { return (is_inversed() ? m_inv.end() : m_perm.end()); }
};

// 逆置換行列．
Permutation inv_permutaion(const Permutation &P) {
    Permutation inv(P);
    inv.inverse();
    return inv;
}

// LU分解．O(N^3).
template <typename T>
std::tuple<Matrix<T>, Matrix<T>, bool> lu_decomposition(const Matrix<T> &A) {
    assert(A.column() == A.row());
    const int n = A.column();
    Matrix<T> L(n, n, 0), U(n, n, 0), B(A);
    for(int k = 0; k < n; ++k) {
        if(std::abs(B.loc(k, k)) < EPS) return {L, U, false};
        for(int i = k; i < n; ++i) L.loc(i, k) = B.loc(i, k) / B.loc(k, k);
        for(int j = k; j < n; ++j) U.loc(k, j) = B.loc(k, j);
        for(int i = k + 1; i < n; ++i) {
            for(int j = k + 1; j < n; ++j) B.loc(i, j) -= L.loc(i, k) * U.loc(k, j);
        }
    }
    return {L, U, true};
}

// サラスの方法．1次，2次，3次の正方行列の行列式を求める．O(N^2).
template <typename T>
T sarrus(const Matrix<T> &A) {
    assert(A.column() == A.row());
    assert(1 <= A.column() and A.column() <= 3);
    if(A.column() == 1) return A.loc(0, 0);                                            // 1次の場合．
    if(A.column() == 2) return A.loc(0, 0) * A.loc(1, 1) - A.loc(0, 1) * A.loc(1, 0);  // 2次の場合．
    // 3次の場合．
    auto a = A.loc(0, 0) * A.loc(1, 1) * A.loc(2, 2) + A.loc(0, 1) * A.loc(1, 2) * A.loc(2, 0) + A.loc(0, 2) * A.loc(1, 0) * A.loc(2, 1);
    auto b = A.loc(0, 2) * A.loc(1, 1) * A.loc(2, 0) + A.loc(0, 1) * A.loc(1, 0) * A.loc(2, 2) + A.loc(0, 0) * A.loc(1, 2) * A.loc(2, 1);
    return a - b;
}

// 行列式．
template <typename T>
T det(const Matrix<T> &A) {
    assert(A.column() == A.row());
    assert(A.column() > 0);
    if(1 <= A.column() and A.column() <= 3) return sarrus(A);
    const auto &&[L, U, success] = lu_decomposition(A);
    assert(success);
    T res = 1;
    for(int i = 0; i < U.column(); ++i) res *= U.loc(i, i);
    return res;
}

// 掃き出し法．ガウス・ジョルダンの消去法．O(N^3).
template <typename T>
void gaussian_elimination(Matrix<T> &sweep) {
    int k = 0, l = 0;
    while(k < sweep.column() and l < sweep.row()) {
        T mx = std::abs(sweep.loc(k, l));
        int idx = k;
        for(int i = k + 1; i < sweep.column(); ++i) {
            if(std::abs(sweep.loc(i, l)) > mx) {
                mx = std::abs(sweep.loc(i, l));
                idx = i;
            }
        }
        if(mx < EPS) {
            l++;
            continue;
        }
        for(int j = l; j < sweep.row(); ++j) std::swap(sweep.loc(k, j), sweep.loc(idx, j));
        auto tmp = 1.0 / sweep.loc(k, l);
        for(int j = l; j < sweep.row(); ++j) sweep.loc(k, j) *= tmp;
        for(int i = 0; i < sweep.column(); ++i) {
            if(i == k) continue;
            auto tmp2 = -sweep.loc(i, l);
            for(int j = l; j < sweep.row(); ++j) sweep.loc(i, j) += sweep.loc(k, j) * tmp2;
        }
        k++, l++;
    }
}

// 逆行列．掃き出し法を用いる．O(N^3).
template <typename T>
Matrix<T> inv_matrix(const Matrix<T> &A) {
    assert(A.column() == A.row());
    assert(det(A) != 0);
    const int n = A.column();
    Matrix<T> sweep(n, 2 * n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            sweep.loc(i, j) = A.loc(i, j);
            sweep.loc(i, j + n) = (i == j ? 1 : 0);
        }
    }
    gaussian_elimination(sweep);
    Matrix<T> inv(n, n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) inv.loc(i, j) = sweep.loc(i, j + n);
    }
    return inv;
}

// 回転行列．
inline mat rotation_matrix(Type arg) {
    auto sv = std::sin(arg);
    auto cv = std::cos(arg);
    mat R({{cv, -sv}, {sv, cv}});
    return R;
}

// 行列累乗．O((logK)*N^3)
template <typename T>
Matrix<T> pow(const Matrix<T> &A, long long k, bool right_side = false) {
    assert(A.row() == A.column() and k >= 0);
    auto &&R = Matrix<T>::identity_matrix(A.column());
    auto B = A;
    while(k > 0) {
        if(k & 1) R = (right_side ? R * B : B * R);
        B = B * B;
        k >>= 1;
    }
    return R;
}

// 連立一次方程式を解く．Linear Simultaneous Equation.
template <typename T>
Matrix<T> solve_lse(const Matrix<T> &A, const std::vector<T> &b) {
    assert(A.column() == static_cast<int>(b.size()));
    Matrix<T> res(A.column(), A.row() + 1);
    for(int i = 0; i < A.column(); ++i) {
        for(int j = 0; j < A.row(); ++j) res.loc(i, j) = A.loc(i, j);
        res.loc(i, A.row()) = b[i];
    }
    gaussian_elimination(res);
    return res;
}

}  // namespace matrix

// using namespace matrix;

}  // namespace algorithm

#endif

/*
参考文献：
- だえう，【C言語】掃き出し法による逆行列の求め方（4×4の逆行列も算出可能），https://daeudaeu.com/c-mat-inverse/（参照2023.2.20）．
*/