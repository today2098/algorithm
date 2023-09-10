#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>

#include "../src/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.hpp"
#include "../src/Others/compress.hpp"
#include "../src/Utils/debug.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<std::tuple<int, int, int> > points(n);
    for(auto &[x, y, w] : points) std::cin >> x >> y >> w;

    std::vector<std::tuple<int, int, int, int, int> > queries(q);
    std::vector<int> xs(2 * q + 1, 0), ys(2 * q + 1, 0);
    for(int i = 0; i < q; ++i) {
        auto &[t, l, d, r, u] = queries[i];
        std::cin >> t;

        if(t == 0) {
            std::cin >> l >> d >> r;
            u = -1;
        } else {
            std::cin >> l >> d >> r >> u;
            xs[2 * i] = l;
            ys[2 * i] = d;
            xs[2 * i + 1] = r;
            ys[2 * i + 1] = u;
        }
    }

    auto &&key_x = algorithm::compress(xs);
    auto &&key_y = algorithm::compress(ys);
    debug(key_x, key_y);
    debug(xs);
    debug(ys);

    algorithm::BIT2D0<long long> bit(key_y.size(), key_x.size());
    for(const auto &[x, y, w] : points) {
        int nx = std::prev(std::upper_bound(key_x.begin(), key_x.end(), x)) - key_x.begin();
        int ny = std::prev(std::upper_bound(key_y.begin(), key_y.end(), y)) - key_y.begin();
        debug(x, y, nx, ny, w);
        bit.add(ny, nx, w);
    }

    for(int i = 0; i < q; ++i) {
        const auto &[t, l, d, r, u] = queries[i];

        if(t == 0) {
            int nx = std::prev(std::upper_bound(key_x.begin(), key_x.end(), l)) - key_x.begin();
            int ny = std::prev(std::upper_bound(key_y.begin(), key_y.end(), d)) - key_y.begin();
            debug(l, d, nx, ny, r);
            bit.add(ny, nx, r);
        } else {
            auto ans = bit.sum(ys[2 * i], xs[2 * i], ys[2 * i + 1], xs[2 * i + 1]);
            std::cout << ans << "\n";
        }
    }
}
