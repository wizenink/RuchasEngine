#include "gtest/gtest.h"

int positive(const int number);

TEST(PositiveTest,Positive)
{
    EXPECT_EQ(1,positive(2));
}

TEST(PositiveTest,NotPositive)
{
    EXPECT_EQ(0,positive(-1));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
