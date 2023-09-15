#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2659"

#include <iostream>
#include <vector>

#include "../src/Math/NumberTheory/chinese_remainder_theorem.hpp"
#include "../src/Utils/debug.hpp"

int main() {
    int n;
    int m;
    int d;
    std::cin >> n >> m >> d;

    std::vector<int> a(m);
    for(auto &in : a) std::cin >> in;

    long long ans = n;
    for(int i = 0; i < d; ++i) {
        std::vector<int> r, na;
        r.reserve(m);
        na.reserve(m);
        for(int j = 0; j < m; ++j) {
            int in;
            std::cin >> in;
            if(in == -1) continue;
            r.push_back(in);
            na.push_back(a[j]);
        }

        const auto &&[first, second] = algorithm::crt(r, na);
        debug(r, na, first, second);
        if((first == 0 and second == -1) or first > ans) {
            std::cout << -1 << std::endl;
            return 0;
        }

        ans = first + (ans - first) / second * second;
        debug(ans);
    }

    std::cout << ans << std::endl;
}
