#include "gtest/gtest.h"
#include "../src/InputProcessor.h"

TEST(left_sum_right_sum, sums_equal)
{
    InputProcessor ip;
    EXPECT_TRUE(ip.isElementExisting("1233"));
    EXPECT_TRUE(ip.isElementExisting("6133"));
    EXPECT_TRUE(ip.isElementExisting("121"));
    EXPECT_TRUE(ip.isElementExisting("0"));
    EXPECT_TRUE(ip.isElementExisting("01"));
    EXPECT_TRUE(ip.isElementExisting("10"));
    EXPECT_TRUE(ip.isElementExisting("1"));
}

TEST(left_sum_right_sum, not_exists)
{
    InputProcessor ip;
    EXPECT_FALSE(ip.isElementExisting("123"));
    EXPECT_FALSE(ip.isElementExisting("12"));
    EXPECT_FALSE(ip.isElementExisting("421"));
}

TEST(output, output)
{
    std::stringstream o_stream;
    std::stringstream ex_o_stream;
    ex_o_stream << "No" << std::endl;
    ex_o_stream << "Yes" << std::endl;
    std::stringstream i_stream;
    i_stream << "2" << std::endl;
    i_stream << "3" << std::endl;
    i_stream << "123" << std::endl;
    i_stream << "4" << std::endl;
    i_stream << "1233" << std::endl;
    InputProcessor ip;
    ip.process(o_stream, i_stream);
    EXPECT_EQ(ex_o_stream.str(), o_stream.str());
}