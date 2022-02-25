#ifndef ALGORITHM_MATRIX_FUNCTIONS_HPP
#define ALGORITHM_MATRIX_FUNCTIONS_HPP 1

#include <cassert>
#include <vector>

#include "matrix.hpp"

namespace algorithm {

namespace matrix {

template <typename T>
Matrix<T> matrix_identity(int n, T x = 1) {  // n次の単位行列．
    assert(n >= 0);
    Matrix<T> R(n, n, 0);
    for(int i = 0; i < n; ++i) R[i][i] = x;
    return R;
}

template <typename T>
std::tuple<Matrix<T>, Matrix<T>, bool> lu_decomposition(const Matrix<T> &A) {  // LU分解．O(N^3).
    const auto &&[col, row] = A.size();
    assert(col == row);
    Matrix<T> L(col, row, 0), U(col, row, 0), B(A);
    for(int k = 0; k < col; ++k) {
        if(std::abs(B[k][k]) < 1e-10) return std::tuple<Matrix<T>, Matrix<T>, bool>(L, U, false);
        for(int i = k; i < col; ++i) L[i][k] = B[i][k] / B[k][k];
        for(int j = k; j < row; ++j) U[k][j] = B[k][j];
        for(int i = k + 1; i < col; ++i)
            for(int j = k + 1; j < row; ++j) B[i][j] -= L[i][k] * U[k][j];
    }
    return std::tuple<Matrix<T>, Matrix<T>, bool>(L, U, true);
}

template <typename T>
T det(const Matrix<T> &A) {  // 行列式．
    const auto &&[col, row] = A.size();
    assert(col == row);
    const auto &&[L, U, jud] = lu_decomposition(A);
    if(!jud) return 0;
    T res = 1;
    for(int i = 0; i < col; ++i) res *= U[i][i];
    return res;
}

template <typename T>
T sarrus(const Matrix<T> &A) {  // サラスの方法．
    const auto &&[col, row] = A.size();
    assert(col == row);
    if(col == 1) return A[0][0];
    if(col == 2) return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    if(col == 3) {
        T res = A[0][0] * A[1][1] * A[2][2] + A[0][1] * A[1][2] * A[2][0] + A[0][2] * A[1][0] * A[2][1] - A[0][1] * A[1][0] * A[2][2] - A[0][0] * A[1][2] * A[2][1] - A[0][2] * A[1][1] * A[2][0];
        return res;
    }
    return det(A);
}

template <typename T>
std::vector<T> liner(const Matrix<T> &A, const std::vector<T> &b) {  // 連立一次方程式．
    const auto &&[col, row] = A.size();
    int n = b.size();
    assert(col == row and col == n);
    const auto &&[L, U, jud] = lu_decomposition(A);
    assert(jud);
    std::vector<T> x(b);
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < i; ++j) x[i] -= L[i][j] * x[j];
    x[n - 1] /= U[n - 1][n - 1];
    for(int i = n - 2; i >= 0; --i) {
        for(int j = n - 1; j > i; --j) x[i] -= U[i][j] * x[j];
        x[i] /= U[i][i];
    }
    return x;
}

};  // namespace matrix

// using namespace matrix;

}  // namespace algorithm

#endif  // ALGORITHM_MATRIX_FUNCTIONS_HPP
