#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2880"

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#include "../src/DataStructure/segment_set.hpp"
#include "../src/Utils/debug.hpp"

int main() {
    int n;
    int m;
    int q;
    std::cin >> n >> m >> q;

    std::vector<std::tuple<int, int, int> > vt(m);
    for(auto &[d, a, b] : vt) std::cin >> d >> a >> b;
    std::sort(vt.begin(), vt.end());

    std::vector<std::tuple<int, int, int, int> > query(q);
    for(int i = 0; i < q; ++i) {
        auto &[e, s, t, idx] = query[i];
        std::cin >> e >> s >> t;
        idx = i;
    }
    std::sort(query.begin(), query.end());

    debug(vt);
    debug(query);

    std::vector<bool> ans(q);
    algorithm::SegmentSet<int> segment_set;
    int i = 0;
    for(const auto &[e, s, t, idx] : query) {
        while(i < m) {
            const auto &[d, a, b] = vt[i];
            if(d >= e) break;
            segment_set.insert(a, b);
            i++;
        }
        debug(e, segment_set);

        ans[idx] = (s >= t or segment_set.contains(s, t) == 2);
    }

    for(auto elem : ans) std::cout << (elem ? "Yes" : "No") << "\n";
}
