#pragma once
#include <cstdint>
#include <vector>
#include <string>

#include "image_generator/color.hpp"

class Canvas {
    public:
        Canvas(int width, int height);
        // member functions
        void setPixel(int x, int y, const Color& c);
        Color getPixel(int x, int y) const;
        bool save(const std::string& filename);
    private:
        void checkBounds(int x, int y) const;
        int width_, height_;
        std::vector<uint8_t> pixels_;
};