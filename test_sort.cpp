#include "gtest/gtest.h"

#include <array>

#include "sort.hpp"

TEST(TestSort, empty)
{
    std::array<int, 0> array{};
    sort(array);
    EXPECT_EQ(array.size(), 0);
}