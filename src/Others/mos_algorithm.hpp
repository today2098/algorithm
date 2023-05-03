#ifndef ALGORITHM_MOS_ALGORITHM_HPP
#define ALGORITHM_MOS_ALGORITHM_HPP 1

#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

namespace algorithm {

// Mo's Algorithm.
class Mo {
    int n;
    int q;
    std::vector<std::tuple<int, int, int> > query;

    // クエリ平方分割．
    void sort_query() {
        int width = std::sqrt(n);
        std::sort(query.begin(), query.end(), [width](const std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b) -> bool {
            const auto &[al, ar, _] = a;
            const auto &[bl, br, __] = b;
            return (al / width == bl / width ? ar < br : al / width < bl / width);
        });
    }

public:
    Mo() : Mo(0) {}
    explicit Mo(int n_) : n(n_), q(0) {}

    void insert(int l, int r) {
        assert(0 <= l and l < r and r <= n);
        query.emplace_back(l, r, q++);
    }
    // 各クエリを実行する．F1~5はラムダ式．O((N+Q)√N*α).
    template <typename F1, typename F2, typename F3, typename F4, typename F5>
    void execute(F1 &&add_l, F2 &&add_r, F3 &&del_l, F4 &&del_r, F5 &&solve) {
        sort_query();
        int l = 0, r = 0;
        for(const auto &[nl, nr, idx] : query) {
            while(l < nl) del_l(l++);
            while(nl < l) add_l(--l);
            while(r < nr) add_r(r++);
            while(nr < r) del_r(--r);
            solve(idx);
        }
    }
};

}  // namespace algorithm

#endif

/*
参考文献
- Mo's algorithm，アルゴリズムとデータ構造大全，https://take44444.github.io/Algorithm-Book/range/mo/main.html（参照2023.5.3）．
- ageprocpp, Mo's algorithm（クエリ平方分割）の話，Qiita, https://qiita.com/ageprocpp/items/34121c58e571ea8c4023（参照2023.5.3）．
*/
