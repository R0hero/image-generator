#include <catch2/catch_test_macros.hpp>

#include "image_generator/utils/color_utils.hpp"

TEST_CASE("lerpColor out of bounds", "[color_utils]") {
    Color a(0, 0, 0);
    Color b(255, 255, 255);

    SECTION("t=-0.2 returns first color") {
        Color result = lerpColor(a, b, -0.2);
        REQUIRE(result.r == a.r);
        REQUIRE(result.g == a.g);
        REQUIRE(result.b == a.b);
    }

    SECTION("t=1.2 returns second color") {
        Color result = lerpColor(a, b, 1.2);
        REQUIRE(result.r == b.r);
        REQUIRE(result.g == b.g);
        REQUIRE(result.b == b.b);
    }
}