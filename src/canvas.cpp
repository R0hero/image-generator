#include <cstdint>
#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <image_generator/color.hpp>

class Canvas {
    public:
        Canvas(int width, int height) : width_(width), height_(height), pixels_(width * height * 3) {
            
        };
        // member functions
        void setPixel(int x, int y, Color c) {

        };
    private:
        int width_, height_;
        std::vector<uint8_t> pixels_;
};