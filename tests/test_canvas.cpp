#include <catch2/catch_test_macros.hpp>

#include "image_generator/canvas.hpp"

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