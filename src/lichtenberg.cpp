#include "image_generator/lichtenberg.hpp"

#include <numbers>
#include <cstdlib>

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

    if (weightedSum.length() < 1e-9) {
        return randomDirection();
    } 
    return weightedSum / weightedSum.length();
}

Vec Lichtenberg::randomDirection() {
    std::uniform_real_distribution<double> angleDist(0.0, 2 * std::numbers::pi);
    double angle = angleDist(generator_);
    return Vec(std::cos(angle), std::sin(angle));
}

double Lichtenberg::calculateLength(const Vec& direction) {
    // define distance to each side of the canvas
    int distToLeft = starting_x_;
    int distToRight = canvas_.getWidth() - 1 - starting_x_;
    int distToTop = starting_y_;
    int distToBottom = canvas_.getHeight() - 1 - starting_y_;
    
    double tx = (direction.x > 0) ? distToRight / direction.x : distToLeft / -direction.x;
    double ty = (direction.y > 0) ? distToBottom / direction.y : distToTop / -direction.y;

    double maxLength = std::min(tx, ty);

    std::uniform_real_distribution<double> lengthDist(0.65, 0.97);
    double length = lengthDist(generator_);
    return maxLength * length;
}

Point Lichtenberg::computeTrunkTarget() {
    Vec direction = findDirection();
    double trunkLength = calculateLength(direction);
    Point start(starting_x_, starting_y_);
    Vec targetVec = start.toVec() + (direction * trunkLength);
    return targetVec.toPoint();
}

void Lichtenberg::testDrawStraightLine(const Point& start, const Point& end) {
    // calculate absolute differences
    int diffX = std::abs(end.x - start.x);
    int diffY = std::abs(end.y - start.y);

    int stepX = (start.x < end.x) ? 1 : -1;
    int stepY = (start.y < end.y) ? 1 : -1;

    int err = diffX - diffY;

    Point pixelToColor = Point(start.x, start.y);
    
    while(true) {
        canvas_.setPixel(pixelToColor.x, pixelToColor.y, Color(128,128,128));

        if (pixelToColor.x == end.x && pixelToColor.y == end.y) {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -diffY) {
            err = err - diffY;
            pixelToColor = pixelToColor + Point(stepX, 0);
        }
        if (e2 < diffX) {
            err = err + diffX;
            pixelToColor = pixelToColor + Point(0, stepY);
        }
    }
}