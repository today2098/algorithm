#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/7/ITP2_7_C"

#include <iostream>

#include "../src/DataStructure/avl_tree.hpp"

int main() {
    int q;
    std::cin >> q;

    algorithm::AVL<int> avl;
    while(q--) {
        int type;
        std::cin >> type;

        if(type == 0) {
            int x;
            std::cin >> x;

            avl.insert(x);
            std::cout << avl.size() << "\n";
        } else if(type == 1) {
            int x;
            std::cin >> x;

            std::cout << (avl.find(x) == avl.end() ? 0 : 1) << "\n";
        } else if(type == 2) {
            int x;
            std::cin >> x;

            avl.erase(x);
        } else {
            int l, r;
            std::cin >> l >> r;

            auto left = avl.lower_bound(l);
            auto right = avl.upper_bound(r);
            for(auto itr = left; itr != right; ++itr) std::cout << *itr << "\n";
        }
    }
}
