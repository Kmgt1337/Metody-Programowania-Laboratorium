#include <iostream>
#include "Funkcje.hpp"

int main()
{
    int t[] = {1,2,3,-1,4,2};
    double p[] = {.5,.25};
    double a[] = {4.,2.,1.};
    int d[] = {1,2,3,4};
    double s=5;
    std::cout << f_wielomian(5,t,3) << std::endl;
    std::cout << *f_maximum(6,t) << std::endl;
    std::cout << f_newton(15,6) << std::endl;
    std::cout << f_suma_wazona(s,p,p+2,a);
    std::cout << ", " << s << std::endl;
    std::cout << f_srednia_warunkowa(s,&test_false,d,d+4);
    std::cout << ", " << s << std::endl;
    std::cout << f_srednia_warunkowa(s,&test_true,d,d+4);
    std::cout << ", " << s << std::endl;
    return 0;
} 