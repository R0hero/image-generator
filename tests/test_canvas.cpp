#include <catch2/catch_test_macros.hpp>

#include "image_generator/canvas.hpp"

TEST_CASE("Ensure canvas size is correct", "[canvas]") {
    Canvas canvas(500, 500);
    Color c(255,255,255);
    for (int x = 0; x <= 499; x++) {
        for (int y = 0; y <= 499; y++) {
            canvas.setPixel(x, y, c);
        };
    };
    
    SECTION("check largest possible pixels returns a color") {
        Color result = canvas.getPixel(499, 499);
        REQUIRE(result.r == c.r);
        REQUIRE(result.g == c.g);
        REQUIRE(result.b == c.b);
    }

    SECTION("check 1 over boundary returns error") {
        REQUIRE_THROWS_AS(canvas.getPixel(500, 500), std::invalid_argument);
    }
} 

TEST_CASE("Canvas::setPixel sets color and Canvas::getPixel returns same color", "[canvas]") {
    Canvas canvas(500, 500);
    Color c(100,100,100);
    
    SECTION("target pixel at (0, 0)") {
        canvas.setPixel(0, 0, c);
        Color result = canvas.getPixel(0, 0);
        
        REQUIRE(result.r == c.r);
        REQUIRE(result.g == c.g);
        REQUIRE(result.b == c.b); 
    }

    SECTION("target pixel at (150, 150)") {
        canvas.setPixel(150, 150, c);
        Color result = canvas.getPixel(150, 150);
        
        REQUIRE(result.r == c.r);
        REQUIRE(result.g == c.g);
        REQUIRE(result.b == c.b);
    }

    SECTION("target pixel at (500, 500)") {
        canvas.setPixel(500, 500, c);
        Color result = canvas.getPixel(500, 500);
        
        REQUIRE(result.r == c.r);
        REQUIRE(result.g == c.g);
        REQUIRE(result.b == c.b);
    }
}

TEST_CASE("Canvas::setPixel returns error when out of bounds", "[canvas]") {
    Canvas canvas(500, 500);
    Color c(0, 0, 0);

    SECTION("Set x-pixel at negative values") {
        REQUIRE_THROWS_AS(canvas.setPixel(-1, 0, c), std::invalid_argument);
    }

    SECTION("Set y-pixel at negative values") {
        REQUIRE_THROWS_AS(canvas.setPixel(0, -1, c), std::invalid_argument);
    }

    SECTION("Set x-pixel at too large values") {
        REQUIRE_THROWS_AS(canvas.setPixel(501, 0, c), std::invalid_argument);
    }

    SECTION("Set y-pixel at too large values") {
        REQUIRE_THROWS_AS(canvas.setPixel(0, 501, c), std::invalid_argument);
    }
}

TEST_CASE("Canvas::getPixel returns error when out of bounds", "[canvas]") {
    Canvas canvas(500, 500);
    Color c(0, 0, 0);

    SECTION("Get x-pixel at negative values") {
        REQUIRE_THROWS_AS(canvas.getPixel(-1, 0), std::invalid_argument);
    }

    SECTION("Get y-pixel at negative values") {
        REQUIRE_THROWS_AS(canvas.getPixel(0, -1), std::invalid_argument);
    }

    SECTION("Get x-pixel at too large values") {
        REQUIRE_THROWS_AS(canvas.getPixel(501, 0), std::invalid_argument);
    }

    SECTION("Get y-pixel at too large values") {
        REQUIRE_THROWS_AS(canvas.getPixel(0, 501), std::invalid_argument);
    }
}