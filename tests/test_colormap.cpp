#include <catch2/catch_test_macros.hpp>

#include "image_generator/colormap.hpp"

TEST_CASE("Colormap::sample returns correct color at boundaries with 2 colors", "[colormap][sample]") {
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
        REQUIRE(result.r == 127);
        REQUIRE(result.g == 127);
        REQUIRE(result.b == 127);
    }
}

TEST_CASE("Colormap::sample returns correct color at boundaries with 3 colors", "[colormap][sample]") {
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

    SECTION("t=0.25 returns interpolation of first and second color") {
        Color result = cmap.sample(0.25);
        REQUIRE(result.r == 127);
        REQUIRE(result.g == 127);
        REQUIRE(result.b == 127);
    }
}

TEST_CASE("Colormap::sample returns correct colors between segments with 5 colors", "[colormap][sample]") {
    Colormap cmap({Color(0,0,0), Color(64,64,64), Color(128,128,128), Color(192,192,192), Color(255,255,255)});

    SECTION("t=0.2 returns color in first segment") {
        Color result = cmap.sample(0.2);
        REQUIRE(result.r == 51);
        REQUIRE(result.g == 51);
        REQUIRE(result.b == 51);
    }

    SECTION("t=0.4 returns color in second segment") {
        Color result = cmap.sample(0.4);
        REQUIRE(result.r == 102);
        REQUIRE(result.g == 102);
        REQUIRE(result.b == 102);
    }
    
    SECTION("t=0.6 returns color in third segment") {
        Color result = cmap.sample(0.6);
        REQUIRE(result.r == 153);
        REQUIRE(result.g == 153);
        REQUIRE(result.b == 153);
    }
    
    SECTION("t=0.8 returns color in fourth segment") {
        Color result = cmap.sample(0.8);
        REQUIRE(result.r == 204);
        REQUIRE(result.g == 204);
        REQUIRE(result.b == 204);
    }
}

TEST_CASE("Colormap::sample returns correct colors outside boundaries", "[colormap][sample]") {
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

TEST_CASE("Colormap throws error if defined with 1 color", "[colormap]") {
    REQUIRE_THROWS_AS(Colormap({Color(0,0,0)}), std::invalid_argument);
}