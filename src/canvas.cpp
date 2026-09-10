#include <image_generator/canvas.hpp>

#include <string>
#include <cstdint>

#include <image_generator/color.hpp>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

Canvas::Canvas(int width, int height) : width_(width), height_(height), pixels_(width * height * 3) {

}
void Canvas::setPixel(int x, int y, const Color& c) {
    int row_pixels = y * width_ * 3;
    int index = row_pixels + x * 3;
    pixels_[index] = c.r; pixels_[index+1] = c.g; pixels_[index+2] = c.b;
}
bool Canvas::save(const std::string& filename) {
    int component_count = 3;
    int stride_expression = width_*component_count;
    int status = stbi_write_png(filename.c_str(), width_, height_, component_count, pixels_.data(), stride_expression);
    if (status == 0) {
        return false;
    }
    return true;
}