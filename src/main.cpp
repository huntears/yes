#include <iostream>

#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"

int main(void)
{
    Vec2<float> issou(4.0, 5.0);
    Vec2<float> wat(0.0, 0.0);

    std::cout << "Distance: " << issou.distance(wat) << std::endl;

    Vec3<float> bruh(0.0, 1.0, 2.0);
    Vec4<float> ah(bruh, 3.0);

    std::cout << "Vec4: " << std::endl <<
        ah.x << std::endl <<
        ah.y << std::endl <<
        ah.z << std::endl <<
        ah.w << std::endl;

    return 0;
}
