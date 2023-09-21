#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"

#include <iostream>

#include "../src/DataStructure/binary_trie.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::BinaryTrie<20> trie;
    while(q--) {
        int com;
        int x;
        int y;
        std::cin >> com >> x >> y;

        if(com == 0) trie.insert(x, y);
        else std::cout << trie.upper_bound(y) - trie.lower_bound(x) << "\n";
    }
}
