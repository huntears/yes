//
// Created by huntears on 1/30/21.
//

#ifndef _VEC4_HPP_
#define _VEC4_HPP_

#include <cmath>

#include "Vec3.hpp"
#include "Vec2.hpp"

template<typename T>
class Vec4
{
public:
    Vec4(T x = 0, T y = 0, T z = 0, T w = 0): x(x), y(y), z(z), w(w) {}

    Vec4(const Vec4 &obj): Vec4(obj.x, obj.y, obj.z, obj.w) {}

    Vec4(const Vec4 *obj): Vec4(*obj) {}

    Vec4(const Vec3<T> &obj, T w = 0): Vec4(obj.x, obj.y, obj.z, w) {}

    T x;
    T y;
    T z;
    T w;

    Vec4& operator = (const Vec4 &obj)
    {
        x = obj.x;
        y = obj.y;
        z = obj.z;
        w = obj.w;
        return *this;
    }

    Vec4 operator + (const Vec4 &obj)
    {
        Vec4 res;
        res.x = x + obj.x;
        res.y = y + obj.y;
        res.z = z + obj.z;
        res.w = w + obj.w;
        return res;
    }

    Vec4 operator - (const Vec4 &obj)
    {
        Vec4 res;
        res.x = x - obj.x;
        res.y = y - obj.y;
        res.z = z - obj.z;
        res.w = w - obj.w;
        return res;
    }

    Vec4 operator * (const Vec4 &obj)
    {
        Vec4 res;
        res.x = x * obj.x;
        res.y = y * obj.y;
        res.z = z * obj.z;
        res.w = w * obj.w;
        return res;
    }

    Vec4 operator / (const Vec4 &obj)
    {
        Vec4 res;
        res.x = x / obj.x;
        res.y = y / obj.y;
        res.z = z / obj.z;
        res.w = w / obj.w;
        return res;
    }

    Vec4 operator + (const T &obj)
    {
        Vec4 res;
        res.x = x + obj;
        res.y = y + obj;
        res.z = z + obj;
        res.w = w + obj;
        return res;
    }

    Vec4 operator - (const T &obj)
    {
        Vec4 res;
        res.x = x - obj;
        res.y = y - obj;
        res.z = z - obj;
        res.w = w - obj;
        return res;
    }

    Vec4 operator * (const T &obj)
    {
        Vec4 res;
        res.x = x * obj;
        res.y = y * obj;
        res.z = z * obj;
        res.w = w * obj;
        return res;
    }

    Vec4 operator / (const T &obj)
    {
        Vec4 res;
        res.x = x / obj;
        res.y = y / obj;
        res.z = z / obj;
        res.w = w / obj;
        return res;
    }

    friend std::ostream& operator <<(std::ostream &os, const Vec4 &obj)
    {
        os << "<" << obj.x << ", " << obj.y << ", " << obj.z << ", " << obj.w << ">";
        return os;
    }

    bool operator == (const Vec4 &obj)
    {
        return x == obj.x && y == obj.y && z == obj.z && w == obj.w;
    }

    bool operator != (const Vec4 &obj)
    {
        return x != obj.x || y != obj.y || z != obj.z || w != obj.w;
    }

    T dot(const Vec4 &obj)
    {
        return x * obj.x + y * obj.y + z * obj.z + w * obj.w;
    }

    T lengthSquared()
    {
        return x * x + y * y + z * z + w * w;
    }

    T length()
    {
        return std::sqrt(lengthSquared());
    }

    void normalize()
    {
        *this = *this / length();
    }

    void abs()
    {
        x = std::abs(x);
        y = std::abs(y);
        z = std::abs(z);
        w = std::abs(w);
    }

    T distance(const Vec4 &obj)
    {
        return (*this - obj).length();
    }

    Vec3<T> xyz()
    {
        return Vec3<T>(
                x,
                y,
                z
        );
    }

    Vec2<T> xy()
    {
        return Vec2<T>(
                x,
                y
        );
    }
};

#endif /* _VEC4_HPP_ */
