#include <catch2/catch_test_macros.hpp>

#include "image_generator/colormap.hpp"

TEST_CASE("Colormap::sample returns correct color at boundaries with 2 colors", "[colormap]") {
    Colormap cmap({Color(0,0,0), Color(255,255,255)});

    SECTION("t=0.0 returns first color") {
        Color result = cmap.sample(0.0);
        REQUIRE(result.r == 0);
        REQUIRE(result.g == 0);
        REQUIRE(result.b == 0);
    }

    SECTION("t=1.0 returns second color") {
        Color result = cmap.sample(1.0);
        REQUIRE(result.r == 255);
        REQUIRE(result.g == 255);
        REQUIRE(result.b == 255);
    }

    SECTION("t=0.5 returns middle color") {
        Color result = cmap.sample(0.5);
        REQUIRE(result.r == 128);
        REQUIRE(result.g == 128);
        REQUIRE(result.b == 128);
    }
}

TEST_CASE("Colormap::sample returns correct color at boundaries with 3 colors", "[colormap]") {
    Colormap cmap({Color(0,0,0), Color(255,255,255), Color(0,0,0)});

    SECTION("t=0.0 returns first color") {
        Color result = cmap.sample(0.0);
        REQUIRE(result.r == 0);
        REQUIRE(result.g == 0);
        REQUIRE(result.b == 0);
    }

    SECTION("t=1.0 returns third color") {
        Color result = cmap.sample(1.0);
        REQUIRE(result.r == 0);
        REQUIRE(result.g == 0);
        REQUIRE(result.b == 0);
    }

    SECTION("t=0.5 returns second color") {
        Color result = cmap.sample(0.5);
        REQUIRE(result.r == 255);
        REQUIRE(result.g == 255);
        REQUIRE(result.b == 255);
    }

    SECTION("t=0.33 returns interpolation of first and second color") {
        Color result = cmap.sample(0.33);
        REQUIRE(result.r == 128);
        REQUIRE(result.g == 128);
        REQUIRE(result.b == 128);
    }
}

TEST_CASE("Colormap::sample returns correct colors outside boundaries", "[colormap]") {
    Colormap cmap({Color(0,0,0), Color(255,255,255)});
    
    SECTION("t=-0.2 returns first color") {
        Color result = cmap.sample(-0.2);
        REQUIRE(result.r == 0);
        REQUIRE(result.g == 0);
        REQUIRE(result.b == 0);
    }
    
    SECTION("t=1.2 returns last color") {
        Color result = cmap.sample(1.2);
        REQUIRE(result.r == 255);
        REQUIRE(result.g == 255);
        REQUIRE(result.b == 255);
    }
}