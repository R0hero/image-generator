#pragma once
#include <cstdint>
#include <random>

#include "image_generator/canvas.hpp"
#include "image_generator/geometry.hpp"

class Lichtenberg {
    public: 
        Lichtenberg(int starting_x, int starting_y, uint64_t seed, Canvas& canvas);
        Vec findDirection();
        Vec randomDirection();
        double calculateWeight(const double& dist);
        Point computeTrunkTarget();
        void testDrawStraightLine(const Point& start, const Point& end);

    private:
        int starting_x_, starting_y_;
        static constexpr double temp_length = 200.0;
        uint64_t seed_;
        std::mt19937_64 generator_;
        Canvas& canvas_;
};