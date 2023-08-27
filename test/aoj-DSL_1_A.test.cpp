#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <iostream>

#include "../src/DataStructure/union_find.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::UnionFind uf(n);
    while(q--) {
        int com;
        int x, y;
        std::cin >> com >> x >> y;

        if(com == 0) uf.unite(x, y);
        else std::cout << uf.is_same(x, y) << std::endl;
    }
}
