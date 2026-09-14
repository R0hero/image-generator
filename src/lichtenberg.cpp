#include "image_generator/lichtenberg.hpp"

#include "image_generator/canvas.hpp"
#include "image_generator/geometry.hpp"

Lichtenberg::Lichtenberg(int starting_x, int starting_y, uint64_t seed, Canvas& canvas) : starting_x_(starting_x), starting_y_(starting_y), seed_(seed), generator_(seed_), canvas_(canvas) {

}

double Lichtenberg::calculateWeight(const double& dist) {
    return 1 / (dist + 1e-10);
}

Vec Lichtenberg::findDirection() {
    // define directional vectors for each side of the canvas
    Vec vectorTop = Vec(0, 1);
    Vec vectorLeft = Vec(1, 0);
    Vec vectorRight = Vec(-1, 0);
    Vec vectorBottom = Vec(0, -1);

    // define distance to each side of the canvas
    int distToLeft = starting_x_;
    int distToRight = canvas_.getWidth() - starting_x_;
    int distToTop = starting_y_;
    int distToBottom = canvas_.getHeight() - starting_y_;

    // calculate weights
    double weightLeft = calculateWeight(distToLeft);
    double weightRight = calculateWeight(distToRight);
    double weightTop = calculateWeight(distToTop);
    double weightBottom = calculateWeight(distToBottom);

    Vec weightedSum = (vectorLeft * weightLeft) + (vectorRight * weightRight) + (vectorTop * weightTop) + (vectorBottom * weightBottom);
}
