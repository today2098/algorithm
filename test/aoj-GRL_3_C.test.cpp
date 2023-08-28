#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include <iostream>

#include "../src/Graph/strongly_connected_components.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    algorithm::SCC scc(n);
    for(int i = 0; i < m; ++i) {
        int s, t;
        std::cin >> s >> t;

        scc.add_edge(s, t);
    }
    auto &&[_, ids] = scc.scc();

    int q;
    std::cin >> q;

    while(q--) {
        int u, v;
        std::cin >> u >> v;

        std::cout << (ids[u] == ids[v]) << std::endl;
    }
}
