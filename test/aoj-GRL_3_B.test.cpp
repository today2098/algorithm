#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B"

#include <iostream>

#include "../src/Graph/low_link.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    algorithm::LowLink lowlink(n);
    for(int i = 0; i < m; ++i) {
        int s, t;
        std::cin >> s >> t;

        lowlink.add_edge(s, t);
    }
    lowlink.lowlink();

    for(const auto &[s, t] : lowlink.bridges()) std::cout << s << " " << t << "\n";
}
