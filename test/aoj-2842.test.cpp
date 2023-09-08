#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2842"

#include <iostream>
#include <queue>
#include <tuple>

#include "../src/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp"

int main() {
    int h, w;
    int t;
    int q;
    std::cin >> h >> w >> t >> q;

    algorithm::BIT2D<int> bit2d_undercooked(h, w), bit2d_cooked(h, w);
    std::queue<std::tuple<int, int, int> > que;
    while(q--) {
        int time;
        int c;
        int h, w;
        std::cin >> time >> c >> h >> w;

        while(!que.empty()) {
            auto [end, hh, ww] = que.front();
            if(time < end) break;
            que.pop();

            bit2d_undercooked.add(hh, ww, -1);
            bit2d_cooked.add(hh, ww, 1);
        }

        if(c == 0) {
            bit2d_undercooked.add(h, w, 1);
            que.emplace(time + t, h, w);
        } else if(c == 1) {
            if(bit2d_cooked.sum(h, w, h, w) >= 1) bit2d_cooked.add(h, w, -1);
        } else {
            int h2, w2;
            std::cin >> h2 >> w2;

            int a = bit2d_cooked.sum(h, w, h2, w2);
            int b = bit2d_undercooked.sum(h, w, h2, w2);
            std::cout << a << " " << b << "\n";
        }
    }
}
