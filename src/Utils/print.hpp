#ifndef ALGORITHM_PRINT_HPP
#define ALGORITHM_PRINT_HPP 1

#include <iostream>
#include <string>
#include <vector>

namespace algorithm {

template <typename Type>
std::istream &operator>>(std::istream &is, std::vector<Type> &v) {
    for(auto &in : v) is >> in;
    return is;
}

template <typename Type>
std::ostream &operator<<(std::ostream &os, const std::vector<Type> &v) {
    int cnt = 0;
    for(const auto &out : v) os << (cnt++ ? " " : "") << out;
    return os;
}

template <class Class>
void line(const Class &a, std::string delim = " ") {
    int cnt = 0;
    for(const auto &elem : a) std::cout << (cnt++ == 0 ? "" : delim) << elem;
    std::cout << std::endl;
}

template <typename Type>
int print_table(std::ostream &os, const Type &value, int depth = 0, int cnt = 0) {
    os << value;
    if(depth == 0) os << std::endl;
    return depth;
}

template <class Class>
int print_table(std::ostream &os, const std::vector<Class> &table, int depth = 0, int cnt = 0) {
    if(cnt > 0) {
        for(int i = 0; i < depth; ++i) os << ' ';
    }
    os << '[';
    depth++;
    int res = 0;
    int cnt2 = 0;
    for(const auto &v : table) {
        if(cnt2 > 0) os << (res == depth ? ' ' : '\n');
        res = print_table(os, v, depth, cnt2++);
    }
    os << ']';
    if(depth == 1) os << std::endl;
    return res;
}

}  // namespace algorithm

#endif
