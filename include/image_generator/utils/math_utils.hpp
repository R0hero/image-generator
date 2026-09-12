#pragma once
#include <cstdint>

inline int normalizeToRange(int value, int min_value, int max_value, int max_target, int min_target) {
    if (max_target <= min_target) {
        throw std::invalid_argument("min_target cannot be greater than or equal to max_target");
    }
    if (max_value <= min_value) {
        throw std::invalid_argument("min_value cannot be greater than or equal to max_value");
    }
    if (value < min_value || value > max_value) {
        throw std::invalid_argument("value cannot be outside min_value and max_value ranges");
    }
    int64_t numerator = static_cast<int64_t>(max_target - min_target) * (value - min_value);
    int norm = static_cast<int>(numerator / (max_value - min_value) + min_target);
    return norm;
}