#include "image_generator/geometry.hpp"

#include <cmath>

Vec Point::toVec() const {
    return Vec(static_cast<double>(x), static_cast<double>(y));
}

Point Vec::toPoint() const {
    return Point(static_cast<int>(std::round(x)), static_cast<int>(std::round(y)));
}