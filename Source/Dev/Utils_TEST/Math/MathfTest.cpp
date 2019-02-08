#include "Math/Mathf.hpp"

#include <gtest/gtest.h>

namespace chill
{
namespace test
{
TEST(MathfTest, clamp)
{
    EXPECT_EQ(0.6f, Mathf::clamp(0.0f, 1.0f, 0.6f));
    EXPECT_EQ(1.0f, Mathf::clamp(0.0f, 1.0f, 2.0f));
    EXPECT_EQ(-0.5f, Mathf::clamp(-1.0f, 1.0f, -0.5f));
    EXPECT_EQ(-1.0f, Mathf::clamp(-1.0f, 1.0f, -2.0f));
    
    // The user should never use the clamp method like this.
    EXPECT_EQ(10.0f, Mathf::clamp(10.0f, 5.0f, -5.0f));
    EXPECT_EQ(5.0f, Mathf::clamp(10.0f, 5.0f, 6.0f));
}

TEST(MathfTest, max)
{
    EXPECT_EQ(10.0f, Mathf::max(10.0f, 5.0f));
    EXPECT_EQ(10.0f, Mathf::max(5.0f, 10.0f));
    EXPECT_EQ(-5.0f, Mathf::max(-10.0f, -5.0f));
    EXPECT_EQ(-5.0f, Mathf::max(-5.0f, -10.0f));
}

TEST(MathfTest, min)
{
    EXPECT_EQ(5.0f, Mathf::min(10.0f, 5.0f));
    EXPECT_EQ(5.0f, Mathf::min(5.0f, 10.0f));
    EXPECT_EQ(-10.0f, Mathf::min(-10.0f, -5.0f));
    EXPECT_EQ(-10.0f, Mathf::min(-5.0f, -10.0f));
}
} // namespace test
} // namespace chill
