#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include <iostream>

#include "../src/DataStructure/SegmentTree/binary_indexed_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::BIT<int> bit(n);
    while(q--) {
        int com;
        int x;
        int y;
        std::cin >> com >> x >> y;

        if(com == 0) bit.add(x, y);
        else std::cout << bit.sum(x, y) << std::endl;
    }
}
