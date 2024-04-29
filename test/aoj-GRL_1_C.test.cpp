#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include <iostream>

#include "../src/Graph/ShortestPath/floyd_warshall.hpp"

int main() {
    int vn, en;
    std::cin >> vn >> en;

    algorithm::FloydWarshall<long long> floyd_warshall(vn);
    for(int i = 0; i < en; ++i) {
        int s, t;
        long long d;
        std::cin >> s >> t >> d;

        floyd_warshall.add_edge(s, t, d);
    }
    floyd_warshall.floyd_warshall();

    if(floyd_warshall.find_negative_cycle()) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
        return 0;
    }

    for(int s = 0; s < vn; ++s) {
        for(int t = 0; t < vn; ++t) {
            auto d = floyd_warshall.distance(s, t);
            if(d == floyd_warshall.infinity()) std::cout << "INF ";
            else std::cout << d << " ";
        }
        std::cout << "\n";
    }
}
