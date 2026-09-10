#include "image_generator/colormap.hpp"

#include <vector>
#include <algorithm>
#include <string>

#include "image_generator/utils/color_utils.hpp"

Colormap::Colormap(const std::vector<Color>& colors) : colors_(colors) {

}

Color Colormap::sample(double t) const {
    t = std::clamp(t, 0.0, 1.0);
    int sections = colors_.size() - 1;
    int segment_index = static_cast<int>(t * sections);
    segment_index = std::min(segment_index, sections - 1);
    double local_t = t * sections - segment_index;

    Color color = lerpColor(colors_[segment_index], colors_[segment_index+1], local_t);
    return color;
}

// static colormaps
// source: https://hauselin.github.io/colorpalettejs/ (viridis to cividis)
Colormap Colormap::viridis() {
    std::vector<Color> colors = {
        hexToColor("#fde725"), 
        hexToColor("#5ec962"), 
        hexToColor("#21918c"), 
        hexToColor("#3b528b"), 
        hexToColor("#440154")
    };
    return Colormap(colors);
}

Colormap Colormap::inferno() {
    std::vector<Color> colors = {
        hexToColor("#fcffa4"),
        hexToColor("#f98e09"),
        hexToColor("#bc3754"),
        hexToColor("#57106e"),
        hexToColor("#000004")
    };
    return Colormap(colors);
}

Colormap Colormap::magma() {
    std::vector<Color> colors = {
        hexToColor("#fcfdbf"),
        hexToColor("#fc8961"),
        hexToColor("#b73779"),
        hexToColor("#51127c"),
        hexToColor("#000004")
    };
    return Colormap(colors);
}

Colormap Colormap::plasma() {
    std::vector<Color> colors = {
        hexToColor("#f0f921"),
        hexToColor("#f89540"),
        hexToColor("#cc4778"),
        hexToColor("#7e03a8"),
        hexToColor("#0d0887")
    };
    return Colormap(colors);
}

Colormap Colormap::cividis() {
    std::vector<Color> colors = {
        hexToColor("#002051"),
        hexToColor("#3c4d6e"),
        hexToColor("#7f7c75"),
        hexToColor("#bbaf71"),
        hexToColor("#fdea45")
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

// source: https://www.color-hex.com/color-palette/6061
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