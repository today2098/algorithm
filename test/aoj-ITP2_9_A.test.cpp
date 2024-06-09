#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/9/ITP2_9_A"

#include <iostream>

#include "../src/DataStructure/avl_tree.hpp"

int main() {
    int n;
    std::cin >> n;

    algorithm::AVL<int> avl;
    for(int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;

        avl.insert(a);
    }

    int m;
    std::cin >> m;

    for(int i = 0; i < m; ++i) {
        int b;
        std::cin >> b;

        avl.insert(b);
    }

    for(auto elem : avl) std::cout << elem << "\n";
}
