#pragma once
#include "image_generator/color.hpp"
#include <vector>

class Colormap {
    public:
        Colormap(const std::vector<Color>& colors);
        // member functions
        Color sample(double t) const;

        // static colormaps
        static Colormap viridis();
        static Colormap inferno();
        static Colormap magma();
        static Colormap plasma();
        static Colormap cividis();
        
    private:
        std::vector<Color> colors_;
};