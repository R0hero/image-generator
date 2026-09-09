#include <stdexcept>

#include "image_generator/canvas.hpp"
#include "image_generator/color.hpp"
#include "image_generator/colormap.hpp"
#include "image_generator/utils/math_utils.hpp"
#include "image_generator/utils/color_utils.hpp"

int main() {
    int width = 500;
    int height = 500;
    Canvas canvas(width, height);

    for (int x = 0; x <= width-1; x++) {
        for (int y = 0; y <= height-1; y++) {
            // test for if canvas is being filled with the same colors no matte the size of the canvas
            // Color c(0, normalizeToRange(x, 0, width, 0, 255), normalizeToRange(y, 0, height, 0, 255));
            
            // test for if the interpolation in lerpColor works as expected
            // Color a(0, normalizeToRange(x, 0, width, 0, 255), 0);
            // Color b(normalizeToRange(x, 0, width, 0, 255), 0, normalizeToRange(y, 0, height, 0, 255));
            // Color c = lerpColor(a, b, 0.4);
            
            double t = static_cast<double>(x) / (width - 1);
            Color a(253, 231, 37);
            Color b(94, 201, 98);
            Color c(33, 145, 140);
            Color d(59, 82, 139);
            Color e(68, 1, 84);
            std::vector<Color> colors = {a, b, c, d, e};
            Colormap colormap(colors);
            Color sampled_color = colormap.sample(t);

            canvas.setPixel(x, y, sampled_color);
        };
    };

    if (!canvas.save("output/output.png")) {
        throw std::runtime_error("Failed to save image");
    }

    return 0;
}