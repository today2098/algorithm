#include "../../../algorithm/DataStructure/UnionFind/union_find.hpp"

#include <gtest/gtest.h>

namespace {

TEST(UnionFindTest, Basic) {
    algorithm::UnionFind uf(5);

    EXPECT_EQ(uf.vn(), 5);
    EXPECT_EQ(uf.gn(), 5);
    EXPECT_TRUE(uf.is_same(0, 0));
    EXPECT_FALSE(uf.is_same(0, 1));

    EXPECT_TRUE(uf.unite(0, 1));
    EXPECT_FALSE(uf.unite(0, 1));

    EXPECT_EQ(uf.gn(), 4);
    EXPECT_TRUE(uf.is_same(0, 1));
    EXPECT_FALSE(uf.is_same(0, 2));
    EXPECT_EQ(uf.size(0), 2);
    EXPECT_EQ(uf.size(1), 2);
    EXPECT_EQ(uf.size(2), 1);

    uf.reset();

    EXPECT_EQ(uf.gn(), 5);
    EXPECT_FALSE(uf.is_same(0, 1));
    EXPECT_EQ(uf.size(0), 1);
    EXPECT_EQ(uf.size(1), 1);
}

}  // namespace
