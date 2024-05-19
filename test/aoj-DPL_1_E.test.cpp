#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_E"

#include <iostream>
#include <string>

#include "../src/DP/edit_distance.hpp"

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::cout << algorithm::edit_distance(s, t) << std::endl;
}
