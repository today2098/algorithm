#ifndef ALGORITHM_MATRIX_FOR_MODINT_HPP
#define ALGORITHM_MATRIX_FOR_MODINT_HPP 1

#include <cassert>
#include <tuple>
#include <vector>

#include "../MathNumberTheory/modint.hpp"
#include "matrix.hpp"

namespace algorithm {

namespace matrix {

// PLU分解．O(N^3).
template <int mod>
std::tuple<Pivot, Matrix<Modint<mod> >, Matrix<Modint<mod> >, bool> lu_decomposition(Matrix<Modint<mod> > A) {
    assert(A.column() == A.row());
    const int n = A.column();
    Matrix<Modint<mod> > L(n, n, 0), U(n, n, 0);
    Pivot P(n);
    for(int k = 0; k < n; ++k) {
        int idx = k;
        while(idx < n and A.loc(idx, k) == 0) idx++;
        if(idx == n) return {P, L, U, false};
        if(idx != k) {
            P.swap(k, idx);
            for(int j = 0; j < k; ++j) {
                std::swap(L.loc(k, j), L.loc(idx, j));
                std::swap(U.loc(k, j), U.loc(idx, j));
            }
            for(int j = k; j < n; ++j) std::swap(A.loc(k, j), A.loc(idx, j));
        }
        auto tmp = 1 / A.loc(k, k);
        for(int i = k; i < n; ++i) L.loc(i, k) = A.loc(i, k) * tmp;
        for(int j = k; j < n; ++j) U.loc(k, j) = A.loc(k, j);
        for(int i = k + 1; i < n; ++i) {
            for(int j = k + 1; j < n; ++j) A.loc(i, j) -= L.loc(i, k) * U.loc(k, j);
        }
    }
    return {P, L, U, true};
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
        if(idx != k) {
            for(int j = l; j < sweep.row(); ++j) std::swap(sweep.loc(k, j), sweep.loc(idx, j));
        }
        auto tmp = 1 / sweep.loc(k, l);
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
