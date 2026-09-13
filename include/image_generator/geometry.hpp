#pragma once
#include <cstdint>

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {

    };

    Vec toVec() const;
};

struct Vec {
    double x;
    double y;

    Vec(double x, double y) : x(x), y(y) {

    };

    Point toPoint() const;
};