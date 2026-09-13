#include <catch2/catch_test_macros.hpp>

#include <sstream>

#include "image_generator/utils/color_utils.hpp"

TEST_CASE("lerpColor out of bounds", "[color_utils][lerpColor]") {
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

TEST_CASE("lerpColor interpolating between two colors", "[color_utils][lerpColor]") {
    Color a(0, 0, 0);
    Color b(255, 255, 255);

    SECTION("t=0.0 returns first color") {
        Color result = lerpColor(a, b, 0.0);
        REQUIRE(result.r == a.r);
        REQUIRE(result.g == a.g);
        REQUIRE(result.b == a.b);
    }

    SECTION("t=1.0 returns second color") {
        Color result = lerpColor(a, b, 1.0);
        REQUIRE(result.r == b.r);
        REQUIRE(result.g == b.g);
        REQUIRE(result.b == b.b);
    }

    SECTION("t=0.33 returns correctly interpolated color") {
        Color result = lerpColor(a, b, 0.33);
        REQUIRE(result.r == 84);
        REQUIRE(result.g == 84);
        REQUIRE(result.b == 84);
    }

    SECTION("t=0.5 returns middle color") {
        Color result = lerpColor(a, b, 0.5);
        REQUIRE(result.r == 127);
        REQUIRE(result.g == 127);
        REQUIRE(result.b == 127);
    }
}

TEST_CASE("hexToColor returning correct color", "[color_utils][hexToColor]") {
    SECTION("hexToColor return black") {
        Color c(0,0,0);
        Color result = hexToColor("#000000");
        REQUIRE(result.r == c.r);
        REQUIRE(result.g == c.g);
        REQUIRE(result.b == c.b);
    }

    SECTION("hexToColor return white") {
        Color c(255,255,255);
        Color result = hexToColor("#FFFFFF");
        REQUIRE(result.r == c.r);
        REQUIRE(result.g == c.g);
        REQUIRE(result.b == c.b);
    }

    SECTION("hexToColor return blue") {
        Color c(0,0,255);
        Color result = hexToColor("#0000FF");
        REQUIRE(result.r == c.r);
        REQUIRE(result.g == c.g);
        REQUIRE(result.b == c.b);
    }

    SECTION("hexToColor return yellow") {
        Color c(255,255,0);
        Color result = hexToColor("#FFFF00");
        REQUIRE(result.r == c.r);
        REQUIRE(result.g == c.g);
        REQUIRE(result.b == c.b);
    }

}

TEST_CASE("hexToColor returning error message on incorrect hex code", "[color_utils][hexToColor]") {
    SECTION("hex code too long") {
        REQUIRE_THROWS_AS(hexToColor("#0000000"), std::invalid_argument);
    }

    SECTION("hex code too short") {
        REQUIRE_THROWS_AS(hexToColor("#00000"), std::invalid_argument);
    }

    SECTION("hex code numbers exceeding base 16") {
        REQUIRE_THROWS_AS(hexToColor("#GGGGGG"), std::invalid_argument);
    }
}

TEST_CASE("operator<< formats Color correctly", "[color_utils][streamOperator]") {
    Color c(10,20,30);
    std::ostringstream oss;
    oss << c;
    REQUIRE(oss.str() == "Color(10, 20, 30)");
}