#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>

#include "../src/DataStructure/union_find.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::UnionFind uf(n);
    while(q--) {
        int t;
        int u, v;
        std::cin >> t >> u >> v;

        if(t == 0) uf.unite(u, v);
        else std::cout << uf.is_same(u, v) << std::endl;
    }
}
