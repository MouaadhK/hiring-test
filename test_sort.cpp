#include "gtest/gtest.h"

#include <array>
#include <cstdlib>

#include "sort.hpp"

TEST(TestSort, emptyArray)
{
    std::array<int, 0> array{};
    sort(array);
    EXPECT_EQ(array.size(), 0);
}

TEST(TestSort, singleElement)
{
    std::array array{1};
    sort(array);

    std::array expectedSortedArray{1};
    EXPECT_EQ(array, expectedSortedArray);
}

TEST(TestSort, taskExample)
{
    std::array array{2, 2, 1, 0, 1, 0, 1, 1, 0, 2, 2, 1, 1, 1, 2, 0, 0, 1, 1, 0, 1, 0, 1, 2, 0, 0, 0, 1, 1, 2};
    sort(array);

    std::array expectedSortedArray{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2};
    EXPECT_EQ(array, expectedSortedArray);
}

TEST(TestSort, alreadySorted)
{
    std::array array{0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2};
    sort(array);

    std::array expectedSortedArray{0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2};
    EXPECT_EQ(array, expectedSortedArray);
}

TEST(TestSort, flippedArray)
{
    std::array array{2, 2, 1, 1, 1, 0, 0, 0, 0, 0};
    sort(array);

    std::array expectedSortedArray{0, 0, 0, 0, 0, 1, 1, 1, 2, 2};
    EXPECT_EQ(array, expectedSortedArray);
}

TEST(TestSort, randomOrder)
{
    std::array array{0, 2, 1, 2, 0, 1, 2};
    sort(array);

    std::array expectedSortedArray{0, 0, 1, 1, 2, 2, 2};
    EXPECT_EQ(array, expectedSortedArray);
}

TEST(TestSort, largeArray)
{
    std::array<int, 10000> array{0};

    std::srand(0); // const seed to have the same random sequence for every run of the unit test

    for (auto &element : array)
    {
        element = std::rand() % 3; // values between 0 and 2 inclusive
    }

    sort(array);

    int lastElement = -1;
    for (const auto &element : array)
    {
        EXPECT_LE(lastElement, element);
        lastElement = element;
    }
}