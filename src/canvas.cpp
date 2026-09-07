#include <image_generator/color.hpp>
#include <image_generator/canvas.hpp>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

Canvas::Canvas(int width, int height) : width_(width), height_(height), pixels_(width * height * 3) {

}
void Canvas::setPixel(int x, int y, const Color& c) {

}
void Canvas::save(const std::string& filename) {
    
}