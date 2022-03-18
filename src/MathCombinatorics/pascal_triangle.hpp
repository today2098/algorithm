#ifndef ALGORITHM_PASCAL_TRIANGLE_HPP
#define ALGORITHM_PASCAL_TRIANGLE_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// パスカルの三角形．
class PascalTriangle {
    int sz;
    std::vector<std::vector<long long> > c;

public:
    // constructor. O(N^2).
    PascalTriangle() : PascalTriangle(101) {}
    explicit PascalTriangle(size_t sz_) : sz(sz_), c(sz_) {
        for(int i = 0; i < sz; ++i) {
            c[i].resize(i + 1);
            for(int j = 0; j <= i; ++j) {
                if(j == 0 or j == i)
                    c[i][j] = 1;
                else
                    c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }

    long long nCk(int n, int k) const {
        assert(0 <= n and n < sz);
        assert(0 <= k and k <= n);
        return c[n][k];
    }
    long long nHk(int n, int k) const { return nCk(k + n - 1, n - 1); }
};

}  // namespace algorithm

#endif  // ALGORITHM_PASCAL_TRIANGLE_HPP
