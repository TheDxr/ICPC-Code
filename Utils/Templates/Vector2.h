#pragma once
#include <cmath>

template <typename T = int>
class Vector2 {
public:
    T x;
    T y;
    Vector2() : x(0), y(0) {}
    Vector2(T xVal, T yVal) : x(xVal), y(yVal) {}
};


template <typename T>
T dot(const Vector2<T>& v1, const Vector2<T>& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}


template <typename T>
T cross(const Vector2<T>& v1, const Vector2<T>& v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

template <typename T>
T length(const Vector2<T>& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
Vector2<T> normalize(const Vector2<T>& v) {
    T len = length(v);
    if (len == 0) {
        return v; // 避免除以零
    }
    return Vector2<T>(v.x / len, v.y / len);
}