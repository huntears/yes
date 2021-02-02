#include <iostream>

#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"
#include "Vec.hpp"
#include "Mat.hpp"

int main(void)
{
    Vec<int> wtf({1, 2, 3});
    std::cout << "Vec : " << wtf << std::endl;
    Vec<float> issou({2.0, 4.0});
    Vec<float> wat({0.0, 0.0});

    std::cout << "Distance: " << issou.distance(wat) << std::endl;

    Mat<int, 10> oui;
    Mat<int, 10> non;
    Mat<double, 4> identity;

    std::cout << "Mat10: " << std::endl <<
        oui - non << std::endl;

    std::cout << "Mat4 Identity: " << std::endl <<
        identity << std::endl;
    return 0;
}
