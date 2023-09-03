#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"

#include <iostream>

#include "../src/Graph/Flow/ford_fulkerson.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    algorithm::FordFulkerson<int> ford_fulkerson(n);
    int s = 0, t = n - 1;
    for(int i = 0; i < m; ++i) {
        int u, v;
        int c;
        std::cin >> u >> v >> c;

        ford_fulkerson.add_edge(u, v, c);
    }

    std::cout << ford_fulkerson.max_flow(s, t) << std::endl;
}
