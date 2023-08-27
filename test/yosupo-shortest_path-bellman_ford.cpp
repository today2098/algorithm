#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <iostream>

#include "../src/Graph/bellman_ford.hpp"

int main() {
    int n, m;
    int s, t;
    std::cin >> n >> m >> s >> t;

    algorithm::BellmanFord<long long> bellman_ford(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;

        bellman_ford.add_edge(a, b, c);
    }
    bellman_ford.bellman_ford(s);

    auto x = bellman_ford.distance(t);
    if(x == bellman_ford.infinity()) {
        std::cout << -1 << std::endl;
        return 0;
    }

    auto path = bellman_ford.shortest_path(t);
    int y = path.size() - 1;

    std::cout << x << ' ' << y << std::endl;
    for(int i = 0; i < y; ++i) std::cout << path[i] << ' ' << path[i + 1] << std::endl;
}
