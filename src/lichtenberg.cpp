#include "image_generator/lichtenberg.hpp"

#include "image_generator/canvas.hpp"

Lichtenberg::Lichtenberg(int starting_x, int starting_y, uint64_t seed, Canvas& canvas) : starting_x_(starting_x), starting_y_(starting_y), seed_(seed), generator_(seed_), canvas_(canvas) {

}