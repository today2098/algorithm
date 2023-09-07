#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B"

#include <iostream>

#include "../src/Graph/topological_sort.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    algorithm::TopologicalSort topological_sort(n);
    for(int i = 0; i < m; ++i) {
        int s, t;
        std::cin >> s >> t;

        topological_sort.add_edge(s, t);
    }

    for(auto elem : topological_sort.topological_sort()) std::cout << elem << "\n";
}
