#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/9/ALDS1_9_C"

#include <iostream>
#include <string>

#include "../src/DataStructure/binary_heap.hpp"

int main() {
    algorithm::BinaryHeap<int> heap;

    while(true) {
        std::string op;
        std::cin >> op;

        if(op == "end") break;
        if(op == "insert") {
            int k;
            std::cin >> k;

            heap.push(k);
        } else {
            std::cout << heap.top() << "\n";
            heap.pop();
        }
    }
}
