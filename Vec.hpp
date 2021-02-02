//
// Created by huntears on 2/1/21.
//

#ifndef LIBYES_VEC_HPP
#define LIBYES_VEC_HPP

#include <cmath>
#include <vector>

#include "Vec3.hpp"
#include "Vec2.hpp"

template<typename T>
class Vec
{
private:
    const int size;
public:
    const int getSize() const {
        return size;
    }

public:
    Vec(const std::initializer_list<T> &init): data {init}, size(init.size()) {} //ça je suis moyen sur lol

    Vec(const std::vector<T> &init): data{init}, size(init.size()) {}

    Vec(const Vec &obj): Vec(obj.data) {}

    Vec(const Vec *obj): Vec(*obj) {}

    std::vector<T> data;

    Vec &operator =(const Vec &obj)
    {
        for (int i = 0; i < size; i++)
            data[i] = obj.data[i];
        return *this;
    }

    Vec operator + (const Vec &obj)
    {
        Vec res(data);
        for (int i = 0; i < size; i++)
            res.data[i] = data[i] + obj.data[i];
        return res;
    }

    Vec operator - (const Vec &obj)
    {
        Vec res(data);
        for (int i = 0; i < size; i++)
                res.data[i] = data[i] - obj.data[i];
        return res;
    }

    Vec operator * (const Vec &obj)
    {
        Vec res(data);
        for (int i = 0; i < size; i++)
            res.data[i] = data[i] * obj.data[i];
        return res;
    }

    Vec operator / (const Vec &obj)
    {
        Vec res(data);
        for (int i = 0; i < size; i++)
            res.data[i] = data[i] / obj.data[i];
        return res;
    }

    Vec operator + (const T &obj)
    {
        Vec res(data);
        for (int i = 0; i < size; i++)
            res.data[i] = data[i] + obj;
        return res;
    }

    Vec operator - (const T &obj)
    {
        Vec res(data);
        for (int i = 0; i < size; i++)
            res.data[i] = data[i] - obj;
        return res;
    }

    Vec operator * (const T &obj)
    {
        Vec res(data);
        for (int i = 0; i < size; i++)
            res.data[i] = data[i] * obj;
        return res;
    }

    Vec operator / (const T &obj)
    {
        Vec res(data);
        for (int i = 0; i < size; i++)
            res.data[i] = data[i] / obj;
        return res;
    }

    friend std::ostream& operator <<(std::ostream &os, const Vec &obj)
    {
        os << "<";
        for (int i = 0; i < obj.getSize(); i++) {
            os << obj.data[i];
            if (i != obj.getSize() - 1)
                os << ", ";
        }
        os << ">";
        return os;
    }

    bool operator == (const Vec &obj)
    {
        for (int i = 0; i < size; i++)
            if (data[i] != obj.data[i])
                return false;
        return true;
    }

    bool operator != (const Vec &obj)
    {
        for (int i = 0; i < size; i++)
            if (data[i] == obj.data[i])
                return false;
        return true;
    }

    T dot(const Vec &obj)
    {
        T dotProduct = 0;
        for (int i = 0; i < size; i++)
            dotProduct += data[i] * obj.data[i];
        return dotProduct;
    }

    Vec cross(const Vec &obj)
    {
        if (obj.data.size() != 3)
            throw "Cross product only possible with Vec3";
        return Vec(
                {data[1] * obj.data[2] - obj.data[1] * data[2],
                 data[2] * obj.data[0] - obj.data[2] * data[0],
                 data[0] * obj.data[1] - obj.data[0] * data[1]}
        );
    }

    T lengthSquared()
    {
        T toReturn = 0;
        for (int i = 0; i < size; i++)
            toReturn += data[i] * data[i];
        return toReturn;
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
        for (int i = 0; i < size; i++)
            data[i] = std::abs(data[i]);
    }

    T distance(const Vec &obj)
    {
        return (*this - obj).length();
    }

};

#endif //LIBYES_VEC_HPP
