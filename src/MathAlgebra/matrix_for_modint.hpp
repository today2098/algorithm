#ifndef ALGORITHM_MATRIX_FOR_MODINT_HPP
#define ALGORITHM_MATRIX_FOR_MODINT_HPP 1

#include <cassert>
#include <tuple>
#include <vector>

#include "../MathNumberTheory/modint.hpp"
#include "matrix.hpp"

namespace algorithm {

namespace matrix {

// LU分解．O(N^3).
template <int mod>
std::tuple<Matrix<Modint<mod> >, Matrix<Modint<mod> >, bool> lu_decomposition(const Matrix<Modint<mod> > &A) {
    assert(A.column() == A.row());
    const int n = A.column();
    Matrix<Modint<mod> > L(n, n, 0), U(n, n, 0), B(n, n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) B.loc(i, j) = A.loc(i, j);
    }
    for(int k = 0; k < n; ++k) {
        if(B.loc(k, k) == 0) return {L, U, false};
        for(int i = k; i < n; ++i) L.loc(i, k) = B.loc(i, k) / B.loc(k, k);
        for(int j = k; j < n; ++j) U.loc(k, j) = B.loc(k, j);
        for(int i = k + 1; i < n; ++i) {
            for(int j = k + 1; j < n; ++j) B.loc(i, j) -= L.loc(i, k) * U.loc(k, j);
        }
    }
    return {L, U, true};
}

// 掃き出し法．逆行列を求める．O(N^3).
template <int mod>
Matrix<Modint<mod> > inv_matrix(const Matrix<Modint<mod> > &A) {
    assert(A.column() == A.row());
    assert(det(A) != 0);
    const int n = A.column();
    Matrix<Modint<mod> > sweep(n, 2 * n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            sweep.loc(i, j) = A.loc(i, j);
            sweep.loc(i, j + n) = (i == j ? 1 : 0);
        }
    }
    for(int k = 0; k < n; ++k) {
        int idx = k;
        for(int i = k + 1; i < n and sweep.loc(idx, k) == 0; ++i) idx = i;
        assert(sweep.loc(idx, k) != 0);
        std::swap(sweep[k], sweep[idx]);
        auto tmp = 1 / sweep.loc(k, k);
        for(int j = k; j < 2 * n; ++j) sweep.loc(k, j) *= tmp;
        for(int i = 0; i < n; ++i) {
            if(i == k) continue;
            auto tmp2 = -sweep.loc(i, k);
            for(int j = k; j < 2 * n; ++j) sweep.loc(i, j) += sweep.loc(k, j) * tmp2;
        }
    }
    Matrix<Modint<mod> > inv(n, n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) inv.loc(i, j) = sweep.loc(i, j + n);
    }
    return inv;
}

}  // namespace matrix

}  // namespace algorithm

#endif
