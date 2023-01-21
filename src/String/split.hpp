#ifndef ALGORITHM_SPLIT_HPP
#define ALGORITHM_SPLIT_HPP 1

#include <sstream>
#include <string>
#include <vector>

namespace algorithm {

// 文字列分割．指定の文字delimで分割する．
std::vector<std::string> split(std::string s, char delim, bool erace_empty = true) {
    s = s + std::string({delim});
    std::vector<std::string> res;
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        if(!item.empty() or !erace_empty) res.push_back(item);
    }
    return res;
}

// 文字列分割．指定の文字列delimで分割する．
std::vector<std::string> split(const std::string &s, const std::string &delim, bool erace_empty = true) {
    std::vector<std::string> res;
    const auto length = delim.size();
    auto offset = std::string::size_type(0);
    while(1) {
        auto pos = s.find(delim, offset);
        if(pos == std::string::npos) {
            auto &&item = s.substr(offset);
            if(!item.empty() or !erace_empty) res.push_back(item);
            break;
        }
        auto &&item = s.substr(offset, pos - offset);
        if(!item.empty() or !erace_empty) res.push_back(item);
        offset = pos + length;
    }
    return res;
}

}  // namespace algorithm

#endif

/*
参考文献
- C++ std::string 文字列の分割（split）｜区切り文字／文字列に対応，MaryCore, https://marycore.jp/prog/cpp/std-string-split/（参照2023.1.21）.
*/
