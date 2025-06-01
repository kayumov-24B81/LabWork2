#include <gtest/gtest.h>
#include "dummy.cpp"

TEST(dummytest, dummytest1)
{
    EXPECT_TRUE(dummyf);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
