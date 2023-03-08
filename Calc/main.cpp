#include <iostream>

#include "calc.hpp"

int main() {
    Calc myCalc;
    myCalc.setDotControl(3);
    std::cout << myCalc.sendNumber("2") << std::endl;
    std::cout << myCalc.myNegative() << std::endl;
    std::cout << myCalc.mySqrt() << std::endl;
    std::cout << myCalc.sendNumber("1") << std::endl;
    return 0;
}
