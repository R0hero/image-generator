#pragma once
#include <cstdint>
#include <vector>
#include <string>

#include <image_generator/color.hpp>

class Canvas {
    public:
        Canvas(int width, int height);
        // member functions
        void setPixel(int x, int y, const Color& c);
        bool save(const std::string& filename);
    private:
        int width_, height_;
        std::vector<uint8_t> pixels_;
};