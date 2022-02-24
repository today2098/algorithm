#ifndef ALGORITHM_Z_ALGORITHM_HPP
#define ALGORITHM_Z_ALGORITHM_HPP 1

#include <vector>

namespace algorithm {

// 最長共通接頭辞 (LCP:Longest Common Prefix)．O(|S|).
template <class Class>
std::vector<int> z_algorithm(const Class &s) {
    int n = s.size();
    std::vector<int> z(n, 0);  // z[i]:=(sとs[i:]のLCPの長さ).
    z[0] = n;
    int i = 1, j = 0;
    while(i < n) {
        while(i + j < n and s[j] == s[i + j]) j++;
        z[i] = j;
        if(j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while(i + k < n and z[k] + k < j) {
            z[i + k] = z[k];
            k++;
        }
        i += k, j -= k;
    }
    return z;
}

}  // namespace algorithm

#endif  // ALGORITHM_Z_ALGORITHM_HPP
