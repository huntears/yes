#ifndef _MAT_HPP_
#define _MAT_HPP_

#include <iostream>

template<typename T, int N>
class Mat
{
public:
    T data[N][N];
 
    Mat()
    {
        this->identity();
    }

    Mat identity()
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                this->data[i][j] = i == j ? 1 : 0;
            }
        }
        return *this;
    }

    friend std::ostream& operator <<(std::ostream &os, Mat const &obj)
    {
        for (int i = 0; i < N; i++) {
            os << "[";
            for (int j = 0; j < N; j++) {
                os << obj.data[i][j];
                if (j != N - 1)
                    os << ", ";
            }
            if (i != N - 1)
                os << "]" << std::endl;
            else
                os << "]";
        }
        return os;
    }

    Mat operator +(Mat const &obj)
    {
        Mat<T, N> result;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result.data[i][j] = this->data[i][j] + obj.data[i][j];
            }
        }
        return result;
    }

    Mat operator -(Mat const &obj)
    {
        Mat<T, N> result;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result.data[i][j] = this->data[i][j] - obj.data[i][j];
            }
        }
        return result;
    }
};

#endif /* _MAT_HPP_ */
