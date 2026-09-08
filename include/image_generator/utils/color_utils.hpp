#pragma once
#include "image_generator/color.hpp"

inline Color lerpColor(const Color& a, const Color& b, double t) {
    uint8_t lerp_r = static_cast<uint8_t>(a.r + (b.r - a.r ) * t);
    uint8_t lerp_g = static_cast<uint8_t>(a.g + (b.g - a.g ) * t);
    uint8_t lerp_b = static_cast<uint8_t>(a.b + (b.b - a.b ) * t);
    Color c(lerp_r, lerp_g, lerp_b);
    return c;
}