#include <stdexcept>
#include <vector>

#include "image_generator/canvas.hpp"
#include "image_generator/color.hpp"
#include "image_generator/colormap.hpp"
#include "image_generator/geometry.hpp"
#include "image_generator/lichtenberg.hpp"
#include "image_generator/utils/math_utils.hpp"
#include "image_generator/utils/color_utils.hpp"

int main() {
    int width = 800;
    int height = 800;
    Canvas canvas(width, height);
    int starting_x = 400;
    int starting_y = 400;
    uint64_t seed = 12312323;
    Lichtenberg lichtenberg(starting_x, starting_y, seed, canvas);
    Point target = lichtenberg.computeTrunkTarget();
    lichtenberg.testDrawStraightLine(Point(starting_x, starting_y), target);

    if (!canvas.save("output/output.png")) {
        throw std::runtime_error("Failed to save image");
    }

    return 0;
}