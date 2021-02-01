//
// Created by huntears on 1/30/21.
//

#ifndef _VEC3_HPP_
#define _VEC3_HPP_

#include <cmath>

#include "Vec2.hpp"

template<typename T>
class Vec3
{
public:
    Vec3(T x = 0, T y = 0, T z = 0): x(x), y(y), z(z) {}

    Vec3(Vec3 const &obj): Vec3(obj.x, obj.y, obj.z) {}

    Vec3(Vec3 const *obj): Vec3(*obj) {}

    T x;
    T y;
    T z;

    Vec3& operator = (Vec3 const &obj)
    {
        x = obj.x;
        y = obj.y;
        z = obj.z;
        return *this;
    }

    Vec3 operator + (Vec3 const &obj)
    {
        Vec3 res;
        res.x = x + obj.x;
        res.y = y + obj.y;
        res.z = z + obj.z;
        return res;
    }

    Vec3 operator - (Vec3 const &obj)
    {
        Vec3 res;
        res.x = x - obj.x;
        res.y = y - obj.y;
        res.z = z - obj.z;
        return res;
    }

    Vec3 operator * (Vec3 const &obj)
    {
        Vec3 res;
        res.x = x * obj.x;
        res.y = y * obj.y;
        res.z = z * obj.z;
        return res;
    }

    Vec3 operator / (Vec3 const &obj)
    {
        Vec3 res;
        res.x = x / obj.x;
        res.y = y / obj.y;
        res.z = z / obj.z;
        return res;
    }

    Vec3 operator + (T const &obj)
    {
        Vec3 res;
        res.x = x + obj;
        res.y = y + obj;
        res.z = z + obj;
        return res;
    }

    Vec3 operator - (T const &obj)
    {
        Vec3 res;
        res.x = x - obj;
        res.y = y - obj;
        res.z = z - obj;
        return res;
    }

    Vec3 operator * (T const &obj)
    {
        Vec3 res;
        res.x = x * obj;
        res.y = y * obj;
        res.z = z * obj;
        return res;
    }

    Vec3 operator / (T const &obj)
    {
        Vec3 res;
        res.x = x / obj;
        res.y = y / obj;
        res.z = z / obj;
        return res;
    }

    bool operator == (Vec3 const &obj)
    {
        return x == obj.x && y == obj.y && z == obj.z;
    }

    bool operator != (Vec3 const &obj)
    {
        return x != obj.x || y != obj.y || z != obj.z;
    }

    T dot(Vec3 const &obj)
    {
        return x * obj.x + y * obj.y + z * obj.z;
    }

    T lengthSquared()
    {
        return x * x + y * y + z * z;
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
    }

    T distance(Vec3 const &obj)
    {
        return (*this - obj).length();
    }

    Vec3 cross(Vec3 const &obj)
    {
        return Vec3(
                y * obj.z - obj.y * z,
                z * obj.x - obj.z * x,
                x * obj.y - obj.x * y
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

#endif /* _VEC3_HPP_ */
