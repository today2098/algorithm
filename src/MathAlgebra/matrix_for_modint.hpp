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

// 掃き出し法．ガウス・ジョルダンの消去法．O(N^3).
template <int mod>
void gaussian_elimination(Matrix<Modint<mod> > &sweep) {
    int k = 0, l = 0;
    while(k < sweep.column() and l < sweep.row()) {
        int idx = k;
        while(idx < sweep.column() and sweep.loc(idx, l) == 0) idx++;
        if(idx == sweep.column()) {
            l++;
            continue;
        }
        std::swap(sweep[k], sweep[idx]);
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

}  // namespace matrix

}  // namespace algorithm

#endif
