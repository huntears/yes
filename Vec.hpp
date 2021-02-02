//
// Created by huntears on 2/1/21.
//

#ifndef LIBYES_VEC_HPP
#define LIBYES_VEC_HPP

#include <cmath>

#include "Vec3.hpp"
#include "Vec2.hpp"

template<typename T, int N>
class Vec
{
public:
    Vec(T data[N]): data(data), {} //ça je suis moyen sur lol

    Vec(const Vec &obj): Vec(obj.data) {}

    Vec(const Vec *obj): Vec(*obj) {}

    Vec(const Vec<T> &obj, T data = 0): Vec(obj.data) {}

    T data[N];

    Vec &operator =(const Vec &obj)
    {
        for (int i = 0; i < N; i++)
            data[i] = obj.data[i];
        return *this;
    }

    Vec operator + (const Vec &obj)
    {
        Vec res;
        for (int i = 0; i < N; i++)
            res.data[i] = data[i] + obj.data[i];
        return res;
    }

    Vec operator - (const Vec &obj)
    {
        Vec res;
        for (int i = 0; i < N; i++)
                res.data[i] = data[i] - obj.data[i];
        return res;
    }

    Vec operator * (const Vec &obj)
    {
        Vec res;
        for (int i = 0; i < N; i++)
            res.data[i] = data[i] * obj.data[i];
        return res;
    }

    Vec operator / (const Vec &obj)
    {
        Vec res;
        for (int i = 0; i < N; i++)
            res.data[i] = data[i] / obj.data[i];
        return res;
    }

    Vec operator + (const T &obj)
    {
        Vec4 res;
        for (int i = 0; i < N; i++)
            res.data[i] = data[i] + obj;
        return res;
    }

    Vec operator - (const T &obj)
    {
        Vec4 res;
        for (int i = 0; i < N; i++)
            res.data[i] = data[i] - obj;
        return res;
    }

    Vec operator * (const T &obj)
    {
        Vec4 res;
        for (int i = 0; i < N; i++)
            res.data[i] = data[i] * obj;
        return res;
    }

    Vec operator / (const T &obj)
    {
        Vec4 res;
        for (int i = 0; i < N; i++)
            res.data[i] = data[i] / obj;
        return res;
    }

    friend std::ostream& operator <<(std::ostream &os, const Vec &obj)
    {
        os << "<" << obj.x << ", " << obj.y << ", " << obj.z << ", " << obj.w << ">";
        return os;
    }

    bool operator == (const Vec &obj)
    {
        return x == obj.x && y == obj.y && z == obj.z && w == obj.w;
    }

    bool operator != (const Vec &obj)
    {
        return x != obj.x || y != obj.y || z != obj.z || w != obj.w;
    }

    T dot(const Vec &obj)
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

    T distance(const Vec &obj)
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

#endif //LIBYES_VEC_HPP
