#include <iostream>

#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"
#include "Vec.hpp"
#include "Mat.hpp"

int main(void)
{
    Vec<float, 2> issou(4.0, 5.0);
    Vec<float, 2> wat(0.0, 0.0);

    std::cout << "Distance: " << issou.distance(wat) << std::endl;

    Vec<float, 3> bruh(0.0, 1.0, 2.0);
    Vec<float, 4> ah(bruh, 3.0);

    std::cout << "Vec4: " << std::endl <<
        ah << std::endl;

    Mat<int, 10> oui;
    Mat<int, 10> non;
    Mat<double, 4> identity;

    std::cout << "Mat10: " << std::endl <<
        oui - non << std::endl;

    std::cout << "Mat4 Identity: " << std::endl <<
        identity << std::endl;

    return 0;
}
