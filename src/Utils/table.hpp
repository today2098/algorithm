#ifndef ALGORITHM_TABLE_HPP
#define ALGORITHM_TABLE_HPP 1

#include <vector>

namespace algorithm {

template <typename Type>
inline std::vector<Type> table(size_t n, Type val) { return std::vector<Type>(n, val); }

template <class... Args>
auto table(size_t n, Args &&...args) {
    auto val = table(std::forward<Args>(args)...);
    return std::vector<decltype(val)>(n, std::move(val));
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
