#ifndef ALGORITHM_SPLIT_HPP
#define ALGORITHM_SPLIT_HPP 1

/**
 * @brief 文字列分割
 * @docs docs/String/split.md
 */

#include <sstream>
#include <string>
#include <vector>

namespace algorithm {

// 文字列分割．文字列sを指定の文字delimで分割する．
std::vector<std::string> split(const std::string &s, char delim, bool disable_empty = false) {
    std::vector<std::string> res;
    std::istringstream ss(s + delim);
    std::string item;
    while(std::getline(ss, item, delim)) {
        if(!(item.empty() and disable_empty)) res.push_back(item);
    }
    return res;
}

// 文字列分割．文字列sを指定の文字列delimで分割する．
std::vector<std::string> split(const std::string &s, const std::string &delim, bool disable_empty = false) {
    std::vector<std::string> res;
    const size_t length = delim.size();
    size_t offset = 0;
    while(true) {
        size_t pos = s.find(delim, offset);
        if(pos == std::string::npos) {
            std::string &&item = s.substr(offset);
            if(!(item.empty() and disable_empty)) res.push_back(item);
            break;
        }
        std::string &&item = s.substr(offset, pos - offset);
        if(!(item.empty() and disable_empty)) res.push_back(item);
        offset = pos + length;
    }
    return res;
}

}  // namespace algorithm

#endif
