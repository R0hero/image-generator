#include <image_generator/colormap.hpp>
#include <vector>

Colormap::Colormap(const std::vector<Color>& colors) : colors_(colors) {

}

Color Colormap::sample(double t) const {

}