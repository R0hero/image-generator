#include <stdexcept>

#include "image_generator/canvas.hpp"
#include "image_generator/color.hpp"
#include "image_generator/utils/math_utils.hpp"
#include "image_generator/utils/color_utils.hpp"

int main() {
    int width = 500;
    int height = 500;
    Canvas canvas(width, height);

    for (int x = 0; x <= width-1; x++) {
        for (int y = 0; y <= height-1; y++) {
            // Color c(0, normalizeToRange(x, 0, width, 0, 255), normalizeToRange(y, 0, height, 0, 255));
            Color a(0, normalizeToRange(x, 0, width, 0, 255), 0);
            Color b(normalizeToRange(x, 0, width, 0, 255), 0, normalizeToRange(y, 0, height, 0, 255));
            Color c = lerpColor(a, b, 0.4);
            canvas.setPixel(x, y, c);
        };
    };

    if (!canvas.save("output/output.png")) {
        throw std::runtime_error("Failed to save image");
    }

    return 0;
}