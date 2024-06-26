/**** 1. Friend **********/

#include <iostream>
#include "rectClass.hpp"
#include "circleClass.hpp"

rectClass duplicate(rectClass x)
{
    rectClass c;
    /*  1. Using Methods  */
    // c.changeLength(x.length());
    // c.changeWidth(x.width());

    /* 2. Operator overloading for '=' */
    // c = x;

    /* Using friend Mechanism */
    c.l = x.l;
    c.w = x.w;

    return c;
}

int main()
{
    rectClass r1(10, 20), r2;
    r2 = duplicate(r1);
    std::cout << "Rectangle area = " << r2.area() << std::endl;

    circleClass c;   // c is a circle that has the rect r1 fitted inside it
    std::cout << "Circle area = " << 2 * c.area(r1) << std::endl;

    return 0;
}
