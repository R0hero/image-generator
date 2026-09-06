#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <image_generator/color.hpp>

class Canvas {
    public:
        Canvas(int width, int height);
        // member functions
        void setPixel(int x, int y, struct color) {

        }
    private:
        int width_, height;
};