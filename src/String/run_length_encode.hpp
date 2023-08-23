#ifndef ALGORITHM_RUN_LENGTH_ENCODING_HPP
#define ALGORITHM_RUN_LENGTH_ENCODING_HPP 1

#include <string>
#include <utility>
#include <vector>

namespace algorithm {

// ランレングス圧縮（連長圧縮）．
std::vector<std::pair<char, int> > run_length_encoding(const std::string &s) {
    std::vector<std::pair<char, int> > res;
    const int n = s.size();
    if(n == 0) return res;
    int cnt = 1;
    for(int i = 1; i < n; ++i) {
        if(s[i] != s[i - 1]) {
            res.emplace_back(s[i - 1], cnt);
            cnt = 0;
        }
        cnt++;
    }
    res.emplace_back(s[n - 1], cnt);
    return res;
}

}  // namespace algorithm

#endif
