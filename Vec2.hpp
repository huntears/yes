//
// Created by huntears on 1/30/21.
//

#ifndef _VEC2_HPP_
#define _VEC2_HPP_

#include <cmath>

template<typename T>
class Vec2
{
public:
    Vec2(T x = 0, T y = 0): x(x), y(y) {}

    Vec2(const Vec2 &obj): Vec2(obj.x, obj.y) {}

    Vec2(const Vec2 *obj): Vec2(*obj) {}

    T x;
    T y;

    Vec2& operator = (const Vec2 &obj)
    {
        x = obj.x;
        y = obj.y;
        return *this;
    }

    Vec2 operator + (const Vec2 &obj)
    {
        Vec2 res;
        res.x = x + obj.x;
        res.y = y + obj.y;
        return res;
    }

    Vec2 operator - (const Vec2 &obj)
    {
        Vec2 res;
        res.x = x - obj.x;
        res.y = y - obj.y;
        return res;
    }

    Vec2 operator * (const Vec2 &obj)
    {
        Vec2 res;
        res.x = x * obj.x;
        res.y = y * obj.y;
        return res;
    }

    Vec2 operator / (const Vec2 &obj)
    {
        Vec2 res;
        res.x = x / obj.x;
        res.y = y / obj.y;
        return res;
    }

    Vec2 operator + (const T &obj)
    {
        Vec2 res;
        res.x = x + obj;
        res.y = y + obj;
        return res;
    }

    Vec2 operator - (const T &obj)
    {
        Vec2 res;
        res.x = x - obj;
        res.y = y - obj;
        return res;
    }

    Vec2 operator * (const T &obj)
    {
        Vec2 res;
        res.x = x * obj;
        res.y = y * obj;
        return res;
    }

    Vec2 operator / (const T &obj)
    {
        Vec2 res;
        res.x = x / obj;
        res.y = y / obj;
        return res;
    }

    friend std::ostream& operator <<(std::ostream &os, const Vec2 &obj)
    {
        os << "<" << obj.x << ", " << obj.y << ">";
        return os;
    }

    bool operator == (const Vec2 &obj)
    {
        return x == obj.x && y == obj.y;
    }

    bool operator != (const Vec2 &obj)
    {
        return x != obj.x || y != obj.y;
    }

    T dot(const Vec2 &obj)
    {
        return x * obj.x + y * obj.y;
    }

    T lengthSquared()
    {
        return x * x + y * y;
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
    }

    T distance(const Vec2 &obj)
    {
        return (*this - obj).length();
    }
};

#endif /* _VEC2_HPP_ */
