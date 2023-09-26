#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_9_B"

#include <iostream>
#include <vector>

#include "../src/DataStructure/heap.hpp"

int main() {
    int h;
    std::cin >> h;

    std::vector<int> v(h);
    for(auto &in : v) std::cin >> in;

    algorithm::Heap<int> heap(v);
    while(!heap.empty()) {
        printf(" %d", heap.top());
        heap.pop();
    }
    std::cout << std::endl;
}
