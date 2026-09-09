#include "image_generator/colormap.hpp"
#include "image_generator/utils/color_utils.hpp"
#include <vector>
#include <algorithm>

Colormap::Colormap(const std::vector<Color>& colors) : colors_(colors) {

}

Color Colormap::sample(double t) const {
    int sections = colors_.size() - 1;
    int segment_index = static_cast<int>(t * sections);
    segment_index = std::min(segment_index, sections - 1);
    double local_t = t * sections - segment_index;

    Color color = lerpColor(colors_[segment_index], colors_[segment_index+1], local_t);
    return color;
}

// static colormaps
Colormap Colormap::viridis() {
    std::vector<Color> colors = {
        Color(253, 231, 37), 
        Color(94, 201, 98), 
        Color(33, 145, 140), 
        Color(59, 82, 139), 
        Color(68, 1, 84)
    };
    return Colormap(colors);
}

Colormap Colormap::inferno() {
    std::vector<Color> colors = {
        Color(0, 0, 4),
        Color(87, 16, 110),
        Color(188, 55, 84),
        Color(249, 142, 9),
        Color(252, 255, 164)
    };
    return Colormap(colors);
}

Colormap Colormap::magma() {
    std::vector<Color> colors = {
        Color(0,0,4),
        Color(81, 18, 124),
        Color(183, 55, 121),
        Color(252, 137, 97),
        Color(252, 253, 191)
    };
    return Colormap(colors);
}

Colormap Colormap::plasma() {
    std::vector<Color> colors = {
        Color(13, 8, 135),
        Color(126, 3, 168),
        Color(204, 71, 120),
        Color(248, 149, 64),
        Color(240, 249, 33)
    };
    return Colormap(colors);
}

Colormap Colormap::cividis() {
    std::vector<Color> colors = {
        Color(0, 32, 81),
        Color(60, 77, 110),
        Color(127, 124, 117),
        Color(187, 175, 113),
        Color(253, 234, 69)
    };
    return Colormap(colors);
}

Colormap Colormap::grays() {
    std::vector<Color> colors = {
        Color(0, 0, 0),
        Color(255, 255, 255)
    };
    return Colormap(colors);
}

Colormap Colormap::electric() {
    std::vector<Color> colors = {
        Color(163, 0, 255),
        Color(111, 0, 255),
        Color(86, 0, 255),
        Color(0, 120, 255),
        Color(0, 159, 255)
    };
    return Colormap(colors);
}