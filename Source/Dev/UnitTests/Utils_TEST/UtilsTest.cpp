/**
* @file     UtilsTest.cpp
* @author   Marek Cernak
* @date     2/7/2019
*
* @brief Utils module tests
*/

#include "Math/Vector2.hpp"
#include <gtest/gtest.h>
#include <memory>

namespace gdt
{
    namespace test
    {
        /**
        * @brief Base class for graphics unit tests.
        */
        class CUtilsTestBase : public ::testing::Test {

        protected:

            /*
            * @brief Define ctor for to initialize for the whole test suite.
            */
            CUtilsTestBase()
            {}

            /*
            * @brief Define dtor to cleanup after the whole test suite finishes.
            */
            ~CUtilsTestBase(){}

            /*
            * @brief Setup before each test.
            */
            void SetUp() override
            {
            }

            /*
            * @brief Cleanup after each test.
            */
            void TearDown() override
            {}

        protected:
        };

        // This is just an example on how to write test method.
        // Google mock tutorial: https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md
        // Google test tutorial: https://github.com/google/googletest/blob/master/googletest/docs/primer.md
        TEST_F(CUtilsTestBase, ExampleTest)
        {
        }
    }
}
