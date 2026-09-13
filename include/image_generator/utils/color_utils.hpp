#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

#include "image_generator/color.hpp"

inline Color lerpColor(const Color& a, const Color& b, double t) {
    t = std::clamp(t, 0.0, 1.0);
    uint8_t lerp_r = static_cast<uint8_t>(a.r + (b.r - a.r ) * t);
    uint8_t lerp_g = static_cast<uint8_t>(a.g + (b.g - a.g ) * t);
    uint8_t lerp_b = static_cast<uint8_t>(a.b + (b.b - a.b ) * t);
    Color c(lerp_r, lerp_g, lerp_b);
    return c;
}

inline std::ostream& operator<<(std::ostream& os, const Color& color) {
    os << "Color(" <<static_cast<int>(color.r) << ", " << static_cast<int>(color.g) << ", " << static_cast<int>(color.b) << ")";
    return os;
}

inline Color hexToColor(const std::string& c) {
    if (!(c.size() == 7)) {
        throw std::invalid_argument("input is not correct hex color");
    }
    if (!(c.substr(0,1) == "#")) {
        throw std::invalid_argument("input is not correct hex color");
    }
    uint8_t r, g, b;
    try {
        r = std::stoi(c.substr(1,2), nullptr, 16);
        g = std::stoi(c.substr(3,2), nullptr, 16);
        b = std::stoi(c.substr(5,2), nullptr, 16);
    } catch (const std::invalid_argument&) {
        throw std::invalid_argument("input is not correct hex color");
    }

    return Color(r, g, b);
}