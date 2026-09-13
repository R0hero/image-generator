#pragma once
#include <cstdint>
#include <random>

#include "image_generator/canvas.hpp"

class Lichtenberg {
    public: 
        Lichtenberg(int starting_x, int starting_y, uint64_t seed, Canvas& canvas);
    private:
        int starting_x_, starting_y_;
        uint64_t seed_;
        std::mt19937_64 generator_;
        Canvas& canvas_;
};