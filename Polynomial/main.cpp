#include <iostream>
#include "Polynomial.h"

using namespace Charles;

int main(){
    Term a(1,2),b(2,3);
    int x = 4;
    Term c = a*b;
    double d = c.Value(5);
    c.Print();
    std::cout << std::endl << d << std::endl;
    return 0;
}