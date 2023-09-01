#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Final/0425"

#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

#include "../src/Others/mo_algorithm.hpp"

int main() {
    int n;
    int k;
    int q;
    std::cin >> n >> k >> q;

    std::vector<std::pair<int, int> > vp(k);
    for(auto &[a, b] : vp) {
        std::cin >> a >> b;
        a--, b--;
    }

    algorithm::Mo mo(k);
    std::vector<std::pair<int, int> > query(q);
    for(int i = 0; i < q; ++i) {
        int type;
        int s, t;
        int x;
        std::cin >> type >> s >> t >> x;
        s--, x--;

        mo.insert(s, t);
        query[i] = std::pair<int, int>(type, x);
    }

    std::vector<int> ans(q);
    std::vector<int> alpha(n), inv(n);
    std::iota(alpha.begin(), alpha.end(), 0);
    std::iota(inv.begin(), inv.end(), 0);
    auto l_swap = [&](int idx) -> void {
        const auto &[a, b] = vp[idx];
        std::swap(alpha[inv[a]], alpha[inv[b]]);
        std::swap(inv[a], inv[b]);
    };
    auto r_swap = [&](int idx) -> void {
        const auto &[a, b] = vp[idx];
        std::swap(inv[alpha[a]], inv[alpha[b]]);
        std::swap(alpha[a], alpha[b]);
    };
    auto solve = [&](int idx) -> void {
        const auto &[type, x] = query[idx];
        ans[idx] = (type == 1 ? alpha[x] + 1 : inv[x] + 1);
    };
    mo.execute(l_swap, l_swap, r_swap, r_swap, solve);

    for(const int &out : ans) std::cout << out << '\n';
}
