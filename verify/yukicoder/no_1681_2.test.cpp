// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/1681
#include <iostream>
#include <vector>

#include "../../algorithm/Math/ModularArithmetic/dynamic_modint.hpp"

int main() {
    constexpr int MOD = 1'000'000'007;

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(auto &elem : a) std::cin >> elem;

    using mint = algorithm::DynamicModint<0>;
    mint::set_modulus(MOD);

    mint ans = 0;
    mint mul = 1;
    for(int i = 0; i < n; ++i) {
        mul *= a[i];
        if(i == n - 1) ans += mul;
        else ans += mul * mint(2) * mint(3).pow(n - 2 - i);
    }

    std::cout << ans << std::endl;
}
