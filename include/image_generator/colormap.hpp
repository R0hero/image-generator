#pragma once
#include "image_generator/color.hpp"
#include <vector>

class Colormap {
    public:
        Colormap(const std::vector<Color>& colors);
        // member functions
        Color sample(double t) const;
    private:
        std::vector<Color> colors_;
};