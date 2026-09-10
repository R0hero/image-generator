#include <stdexcept>
#include <vector>

#include "image_generator/canvas.hpp"
#include "image_generator/color.hpp"
#include "image_generator/colormap.hpp"
#include "image_generator/utils/math_utils.hpp"
#include "image_generator/utils/color_utils.hpp"

int main() {
    int width = 500;
    int height = 200;
    Canvas canvas(width, height);

    Colormap colormap = Colormap::viridis();

    for (int x = 0; x <= width-1; x++) {
        for (int y = 0; y <= height-1; y++) {
            double t = static_cast<double>(x) / (width - 1);
            Color sampled_color = colormap.sample(t);

            canvas.setPixel(x, y, sampled_color);
        };
    };

    if (!canvas.save("output/output.png")) {
        throw std::runtime_error("Failed to save image");
    }

    return 0;
}