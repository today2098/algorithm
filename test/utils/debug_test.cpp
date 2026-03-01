// competitive-verifier: UNITTEST GTEST_RESULT
#define DEBUG
#include "../../algorithm/utils/debug.hpp"

#include <gtest/gtest.h>

#include <format>
#include <list>
#include <regex>
#include <sstream>

namespace {

TEST(DebugTest, Basic) {
    std::stringstream ss;
    auto clear = [&]() {
        ss.str("");
        ss.clear();
    };

    {
        algorithm::debug::print(ss, 1);
        EXPECT_EQ("1", ss.view());
        clear();

        algorithm::debug::print(ss, 0.10);
        EXPECT_EQ("0.1", ss.view());
        clear();

        algorithm::debug::print(ss, 'a');
        EXPECT_EQ("a", ss.view());
        clear();

        algorithm::debug::print(ss, "Hello, World!");
        EXPECT_EQ("Hello, World!", ss.view());
        clear();

        algorithm::debug::print(ss, {1, 2, 3});
        EXPECT_EQ("[1 2 3]", ss.view());
        clear();
    }

    {
        int a = 1e9;
        algorithm::debug::print(ss, a);
        EXPECT_EQ(std::format("{}", a), ss.view());
        clear();

        long long b = 1e18;
        algorithm::debug::print(ss, b);
        EXPECT_EQ(std::format("{}", b), ss.view());
        clear();

        double c = 0.10;
        algorithm::debug::print(ss, c);
        EXPECT_EQ(std::format("{}", c), ss.view());
        clear();
    }

    {
        std::list<int> l({1, 2, 3});
        algorithm::debug::print(ss, l);
        EXPECT_EQ("[1 2 3]", ss.view());
        clear();

        std::vector<int> v({1, 2, 3});
        algorithm::debug::print(ss, v);
        EXPECT_EQ("[1 2 3]", ss.view());
        clear();

        std::map<std::string, int> mp({{"abc", 1}, {"fgh", 2}, {"def", 3}});
        algorithm::debug::print(ss, mp);
        EXPECT_EQ("[{abc, 1} {def, 3} {fgh, 2}]", ss.view());
        clear();
    }

    {
        char str[] = "Hello, World!";
        algorithm::debug::print(ss, str);
        EXPECT_STREQ(str, ss.str().c_str());
        clear();

        std::string s = "hoge";
        algorithm::debug::print(ss, s);
        EXPECT_EQ(s, ss.view());
        clear();

        std::string_view sv = "piyo";
        algorithm::debug::print(ss, sv);
        EXPECT_EQ(sv, ss.view());
        clear();
    }

    {
        std::stack<int> st({1, 2, 3});
        algorithm::debug::print(ss, st);
        EXPECT_EQ("[3 2 1]", ss.view());
        clear();

        std::queue<int> que({1, 2, 3});
        algorithm::debug::print(ss, que);
        EXPECT_EQ("[1 2 3]", ss.view());
        clear();

        std::priority_queue<int> pque;
        pque.push(1);
        pque.push(3);
        pque.push(2);
        algorithm::debug::print(ss, pque);
        EXPECT_EQ("[3 2 1]", ss.view());
        clear();
    }

    {
        std::pair<int, std::string> p({1, "Hello, World!"});
        algorithm::debug::print(ss, p);
        EXPECT_EQ("{1, Hello, World!}", ss.view());
        clear();

        std::tuple<int, std::string, double> t({1, "Hello, World!", 0.10});
        algorithm::debug::print(ss, t);
        EXPECT_EQ("{1, Hello, World!, 0.1}", ss.view());
        clear();
    }

    {
        std::initializer_list<int> il({1, 2, 3});
        algorithm::debug::print(ss, il);
        EXPECT_EQ("[1 2 3]", ss.view());
        clear();
    }

    {
        algorithm::debug::debug_internal(ss, __LINE__, "1, \"Hello, World !\", 0.10", 1, "Hello, World!", 0.10);
        SCOPED_TRACE(ss.str());
        auto r = std::regex(R"(^\([\s*\d+]{8}\) \[L141\] \(empty\)\n$)");
        EXPECT_TRUE(std::regex_match(ss.str(), std::regex(R"(^\([\s*\d+]{8}\) \[L134\] \(1, \"Hello, World !\", 0.10\): \(1, Hello, World!, 0.1\)\n$)")));
        clear();
    }

    {
        algorithm::debug::debug_internal(ss, __LINE__);
        SCOPED_TRACE(ss.str());
        auto r = std::regex(R"(^\([\s*\d+]{8}\) \[L142\] \(empty\)\n$)");
        EXPECT_TRUE(std::regex_match(ss.str(), r));
        clear();
    }
}

}  // namespace
