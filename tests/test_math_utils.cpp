#include <catch2/catch_test_macros.hpp>

#include "image_generator/utils/math_utils.hpp"

TEST_CASE("normalizeToRange returning correct values", "[math_utils][normalizeToRange]") {
    SECTION("return min_value") {
        REQUIRE(normalizeToRange(0, 0, 3, 10, 0) == 0);
    }

    SECTION("return max_value") {
        REQUIRE(normalizeToRange(3, 0, 3, 10, 0) == 10);
    }

    SECTION("return middle value") {
        REQUIRE(normalizeToRange(5, 0, 10, 100, 0) == 50);
    }

    SECTION("return two thirds value") {
        REQUIRE(normalizeToRange(6, 0, 9, 99, 0) == 66);
    }
}