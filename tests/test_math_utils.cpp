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

TEST_CASE("normalizeToRange inputs not aligning properly", "[math_utils][normalizeToRange]") {
    SECTION("min_target larger than max_target") {
        REQUIRE_THROWS_AS(normalizeToRange(0,0,10,0,100), std::invalid_argument);
    }

    SECTION("max_target equal to min_target") {
        REQUIRE_THROWS_AS(normalizeToRange(0,0,10,100,100), std::invalid_argument);
    }

    SECTION("min_value larger than max_value") {
        REQUIRE_THROWS_AS(normalizeToRange(0,10,0,100,0), std::invalid_argument);
    }

    SECTION("max_value equal to min_value") {
        REQUIRE_THROWS_AS(normalizeToRange(0,10,10,100,0), std::invalid_argument);
    }

    SECTION("value outside range in min_value and max_value") {
        REQUIRE_THROWS_AS(normalizeToRange(-2,0,10,100,0), std::invalid_argument);
        REQUIRE_THROWS_AS(normalizeToRange(12,0,10,100,0), std::invalid_argument);
    }
}

TEST_CASE("normalizeToRange handles overflow of int", "[math_utils][normalizeToRange]") {
    REQUIRE(normalizeToRange(1000000, 0, 1000000, 2000000000, 0) == 2000000000);
}

TEST_CASE("normalizeToRange handles negative values", "[math_utils][normalizeToRange]") {
    REQUIRE(normalizeToRange(0, -10, 10, 100, 0) == 50);
}