#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>

#include "../src/DataStructure/binary_trie.hpp"
#include "../src/Utils/debug.hpp"

int main() {
    int q;
    std::cin >> q;

    algorithm::BinaryTrie<30> trie;
    while(q--) {
        int t;
        int x;
        std::cin >> t >> x;

        if(t == 0) {
            if(!trie.exist(x)) trie.insert(x);
        } else if(t == 1) {
            if(trie.exist(x)) trie.erase(x);
        } else {
            debug(trie);
            trie.operate_xor_all(x);
            debug(trie);
            std::cout << trie.min_element().to_ulong() << "\n";
            trie.operate_xor_all(x);
        }
    }
}
