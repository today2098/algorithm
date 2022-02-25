#ifndef ALGORITHM_MATRIX_HPP
#define ALGORITHM_MATRIX_HPP 1

#include <cassert>
#include <iostream>
#include <vector>

namespace algorithm {

template <typename T>
class Matrix {
    int col, row;
    std::vector<std::vector<T> > val;

public:
    // constructor.
    Matrix() : Matrix(0, 0, 0){};
    explicit Matrix(std::size_t m, std::size_t n, T x = 0) : col(m), row(n), val(m, std::vector<T>(n, x)) {}
    explicit Matrix(const std::vector<std::vector<T> > &v) : col(v.size()), row(v[0].size()), val(v) {}

    std::vector<T> &operator[](int i) { return val[i]; }
    const std::vector<T> &operator[](int i) const { return val[i]; }
    Matrix operator-() const { return (*this) * -1; }
    Matrix operator*(T a) const {
        Matrix R(*this);
        for(int i = 0; i < R.col; ++i)
            for(int j = 0; j < R.row; ++j) R[i][j] *= a;
        return R;
    }
    friend Matrix<T> operator*(T a, const Matrix<T> &A) { return A * a; }
    Matrix operator/(T a) const {
        Matrix R(*this);
        for(int i = 0; i < R.col; ++i)
            for(int j = 0; j < R.row; ++j) R[i][j] /= a;
        return R;
    }
    friend Matrix<T> operator+(const Matrix<T> &A, const Matrix<T> &B) {
        assert(A.col == B.col and A.row == B.row);
        Matrix<T> R(A.col, A.row);
        for(int i = 0; i < A.col; ++i)
            for(int j = 0; j < A.row; ++j) R[i][j] = A[i][j] + B[i][j];
        return R;
    }
    friend Matrix<T> operator-(const Matrix<T> &A, const Matrix<T> &B) {
        assert(A.col == B.col and A.row == B.row);
        Matrix<T> R(A.col, A.row);
        for(int i = 0; i < A.col; ++i)
            for(int j = 0; j < A.row; ++j) R[i][j] = A[i][j] - B[i][j];
        return R;
    }
    friend std::vector<T> operator*(const Matrix<T> &A, const std::vector<T> &B) {
        assert(A.row == B.size());
        std::vector<T> R(A.col, 0);
        for(int i = 0; i < A.col; ++i)
            for(int k = 0; k < A.row; ++k) R[i] += A[i][k] * B[k];
        return R;
    }
    friend Matrix<T> operator*(const Matrix<T> &A, const Matrix<T> &B) {
        assert(A.row == B.col);
        Matrix<T> R(A.col, B.row, 0);
        for(int i = 0; i < A.col; ++i)
            for(int j = 0; j < B.row; ++j)
                for(int k = 0; k < A.row; ++k) R[i][j] += A[i][k] * B[k][j];
        return R;
    }
    friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &A) {
        for(int i = 0; i < A.col; ++i) {
            for(int j = 0; j < A.row; ++j) os << A[i][j] << ' ';
            os << std::endl;
        }
        return os;
    }

    std::pair<int, int> size() const { return std::pair<int, int>(col, row); }
    Matrix transpose() const {  // 転置．
        Matrix R(row, col, 0);
        for(int i = 0; i < col; ++i)
            for(int j = 0; j < row; ++j) R[j][i] = val[i][j];
        return R;
    }

    friend Matrix<T> pow(const Matrix<T> &A, long long k) {  // 行列累乗．
        assert(A.row == A.col and k >= 0);
        Matrix<T> R(A.col, A.row, 0);
        for(int i = 0; i < A.col; ++i) R[i][i] = 1;
        auto B = A;
        while(k > 0) {
            if(k & 1) R = B * R;
            B = B * B, k >>= 1;
        }
        return R;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_MATRIX_HPP
