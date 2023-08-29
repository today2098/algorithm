#ifndef ALGORITHM_Z_ALGORITHM_HPP
#define ALGORITHM_Z_ALGORITHM_HPP 1

#include <vector>

namespace algorithm {

// 最長共通接頭辞 (LCP: Longest Common Prefix)．O(|S|).
template <class Sequence>
std::vector<int> z_algorithm(const Sequence &s) {
    const int n = s.size();
    std::vector<int> z(n + 1);  // z[i]:=(sとs[i:]のLCPの長さ).
    z[0] = n, z[n] = 0;
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

#endif

/*
参考文献
- Pro_ktmr，【図解】線形時間の文字列アルゴリズム「Z algorithm」をイラストとアニメーションでかみ砕く，Qiita，https://qiita.com/Pro_ktmr/items/16904c9570aa0953bf05（参照2022.9.8）．
*/