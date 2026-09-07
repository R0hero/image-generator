#include "image_generator/canvas.hpp"
#include "image_generator/color.hpp"

int main() {
    int width = 100;
    int height = 100;
    Canvas canvas(width, height);

    for (int x = 0; x =< width-1; x++) {
        for (int y = 0; y =< height-1; y++) {
            Color c;
            c.r = x;
            c.g = 0;
            c.b = y;

            canvas.setPixel(x, y, c);
        };
    };

    return 0;
}