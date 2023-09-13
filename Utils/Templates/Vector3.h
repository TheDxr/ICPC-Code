#pragma once
#include <cmath>

template <typename T = int>
class Vector3 {
public:
    T x;
    T y;
    T z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(T xVal, T yVal, T zVal) : x(xVal), y(yVal), z(zVal) {}
};


template <typename T>
T dot(const Vector3<T>& v1, const Vector3<T>& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template <typename T>
Vector3<T> cross(const Vector3<T>& v1, const Vector3<T>& v2) {
    return Vector3<T>(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    );
}

template <typename T>
T length(const Vector3<T>& v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template <typename T>
Vector3<T> normalize(const Vector3<T>& v) {
    T len = length(v);
    if (len == 0) {
        return v; // 避免除以零
    }
    return Vector3<T>(v.x / len, v.y / len, v.z / len);
}