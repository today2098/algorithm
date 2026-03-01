// competitive-verifier: UNITTEST GTEST_RESULT
#include "../../../algorithm/DataStructure/UnionFind/union_find.hpp"

#include <gtest/gtest.h>

namespace {

TEST(UnionFindTest, Basic) {
    algorithm::UnionFind uf(5);

    EXPECT_EQ(5, uf.vn());
    EXPECT_EQ(5, uf.gn());
    EXPECT_TRUE(uf.is_same(0, 0));
    EXPECT_FALSE(uf.is_same(0, 1));

    EXPECT_TRUE(uf.unite(0, 1));
    EXPECT_FALSE(uf.unite(0, 1));

    EXPECT_EQ(4, uf.gn());
    EXPECT_TRUE(uf.is_same(0, 1));
    EXPECT_FALSE(uf.is_same(0, 2));
    EXPECT_EQ(2, uf.size(0));
    EXPECT_EQ(2, uf.size(1));
    EXPECT_EQ(1, uf.size(2));

    uf.reset();

    EXPECT_EQ(5, uf.gn());
    EXPECT_FALSE(uf.is_same(0, 1));
    EXPECT_EQ(1, uf.size(0));
    EXPECT_EQ(1, uf.size(1));
}

}  // namespace
