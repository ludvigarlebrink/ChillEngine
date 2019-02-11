#include "Math/Mathf.hpp"

#include <gtest/gtest.h>

namespace chill
{
namespace test
{
TEST(MathfTest, clamp)
{
    EXPECT_EQ(0.6f, Mathf::Clamp(0.0f, 1.0f, 0.6f));
    EXPECT_EQ(1.0f, Mathf::Clamp(0.0f, 1.0f, 2.0f));
    EXPECT_EQ(-0.5f, Mathf::Clamp(-1.0f, 1.0f, -0.5f));
    EXPECT_EQ(-1.0f, Mathf::Clamp(-1.0f, 1.0f, -2.0f));
    
    // The user should never use the clamp method like this.
    EXPECT_EQ(10.0f, Mathf::Clamp(10.0f, 5.0f, -5.0f));
    EXPECT_EQ(5.0f, Mathf::Clamp(10.0f, 5.0f, 6.0f));
}

TEST(MathfTest, max)
{
    EXPECT_EQ(10.0f, Mathf::Max(10.0f, 5.0f));
    EXPECT_EQ(10.0f, Mathf::Max(5.0f, 10.0f));
    EXPECT_EQ(-5.0f, Mathf::Max(-10.0f, -5.0f));
    EXPECT_EQ(-5.0f, Mathf::Max(-5.0f, -10.0f));
}

TEST(MathfTest, min)
{
    EXPECT_EQ(5.0f, Mathf::Min(10.0f, 5.0f));
    EXPECT_EQ(5.0f, Mathf::Min(5.0f, 10.0f));
    EXPECT_EQ(-10.0f, Mathf::Min(-10.0f, -5.0f));
    EXPECT_EQ(-10.0f, Mathf::Min(-5.0f, -10.0f));
}
} // namespace test
} // namespace chill
