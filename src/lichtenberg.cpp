#include "image_generator/lichtenberg.hpp"

#include "image_generator/canvas.hpp"
#include "image_generator/geometry.hpp"

Lichtenberg::Lichtenberg(int starting_x, int starting_y, uint64_t seed, Canvas& canvas) : starting_x_(starting_x), starting_y_(starting_y), seed_(seed), generator_(seed_), canvas_(canvas) {

}

Vec Lichtenberg::findDirection() {
    // define directional vectors for each side of the canvas
    Vec topVector = Vec(0, 1);
    Vec leftVector = Vec(1, 0);
    Vec rightVector = Vec(-1, 0);
    Vec lowerVector = Vec(0, -1);

    // define distance to each side of the canvas
    int distToLeft = starting_x_;
    int distToRight = starting_x_ - canvas_.getWidth();
    int distToTop = starting_y_;
    int distToBottom = starting_y_ - canvas_.getHeight();

    
}
