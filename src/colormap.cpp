#include <image_generator/colormap.hpp>
#include <image_generator/utils/color_utils.hpp>
#include <vector>

Colormap::Colormap(const std::vector<Color>& colors) : colors_(colors) {

}

Color Colormap::sample(double t) const {
    int sections = colors_.size() - 1;
    int segment_index = static_cast<int>(t * sections);
    double local_t = t * sections - segment_index;

    Color color = lerpColor(colors_[segment_index], colors_[segment_index+1], local_t);
    return color;
}