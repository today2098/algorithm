#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <iostream>
#include <vector>

#include "../src/Others/mo_algorithm.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for(auto &in : a) std::cin >> in;

    algorithm::Mo mo(n);
    for(int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        mo.insert(l, r);
    }

    std::vector<long long> ans(q);
    long long tmp = 0;
    std::vector<int> v;
    v.reserve(n);
    auto add_l = [&](int i) -> void {
        auto itr = std::lower_bound(v.begin(), v.end(), a[i]);
        tmp += itr - v.begin();
        v.insert(itr, a[i]);
    };
    auto del_l = [&](int i) -> void {
        auto itr = std::lower_bound(v.begin(), v.end(), a[i]);
        tmp -= itr - v.begin();
        v.erase(itr);
    };
    auto add_r = [&](int i) -> void {
        auto itr = std::upper_bound(v.begin(), v.end(), a[i]);
        tmp += v.end() - itr;
        v.insert(itr, a[i]);
    };
    auto del_r = [&](int i) -> void {
        auto itr = std::upper_bound(v.begin(), v.end(), a[i]);
        tmp -= v.end() - itr;
        v.erase(itr - 1);
    };
    auto solve = [&](int idx) -> void { ans[idx] = tmp; };
    mo.execute(add_l, del_l, add_r, del_r, solve);

    for(const auto &out : ans) std::cout << out << std::endl;
}
