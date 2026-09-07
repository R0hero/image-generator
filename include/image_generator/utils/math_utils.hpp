#pragma once
#include <cstdint>

inline int normalizeToRange(int value, int min_value, int max_value, int max_target, int min_target) {
    int64_t numerator = static_cast<int64_t>(max_target - min_target) * (value - min_value);
    int norm = static_cast<int>(numerator / (max_value - min_value) + min_target);
    return norm;
}