#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"

#include <iostream>

#include "../src/Math/NumberTheory/extgcd.hpp"
#include "../src/Utils/debug.hpp"

int main() {
    int a, b;
    std::cin >> a >> b;

    int x, y;
    algorithm::extgcd(a, b, x, y);
    debug(a * x + b * y);

    std::cout << x << " " << y << std::endl;
}
