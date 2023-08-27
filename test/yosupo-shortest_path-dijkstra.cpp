#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <iostream>

#include "../src/Graph/dijkstra.hpp"

int main() {
    int n, m;
    int s, t;
    std::cin >> n >> m >> s >> t;

    algorithm::Dijkstra<long long> dijkstra(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;

        dijkstra.add_edge(a, b, c);
    }
    dijkstra.dijkstra(s);

    auto x = dijkstra.distance(t);
    if(x == dijkstra.infinity()) {
        std::cout << -1 << std::endl;
        return 0;
    }

    auto path = dijkstra.shortest_path(t);
    int y = path.size() - 1;

    std::cout << x << ' ' << y << std::endl;
    for(int i = 0; i < y; ++i) std::cout << path[i] << ' ' << path[i + 1] << std::endl;
}
