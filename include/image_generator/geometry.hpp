#pragma once
#include <cstdint>
#include <cmath>

struct Vec; 

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {

    };

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    int getX() const {
        return x;
    }
    
    int getY() const {
        return y;
    }

    Vec toVec() const;
};

struct Vec {
    double x;
    double y;

    Vec(double x, double y) : x(x), y(y) {

    };

    Vec operator+(const Vec& other) const {
        return Vec(x + other.x, y + other.y);
    }

    Vec operator*(double scalar) const {
        return Vec(x * scalar, y * scalar);
    }

    Vec operator/(double scalar) const {
        return Vec(x / scalar, y / scalar);
    }

    double length() const {
        return std::sqrt(std::pow(x,2)+std::pow(y,2));
    }

    Point toPoint() const;
};