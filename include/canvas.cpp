#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

class Canvas {
    public:
        Canvas(int width, int height);
    private:
        int width_, height;
};