#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>

#include "../src/Graph/strongly_connected_components.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    algorithm::SCC scc(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;

        scc.add_edge(a, b);
    }

    auto &&res = scc.decompose();

    std::cout << res.size() << '\n';
    for(const auto &vs : res) {
        std::cout << vs.size();
        for(const auto &v : vs) std::cout << ' ' << v;
        std::cout << std::endl;
    }
}
