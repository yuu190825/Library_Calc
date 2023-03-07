#include <iostream>

#include "calc.hpp"

int main() {
    Calc myCalc;
    myCalc.setDotControl(3);
    std::cout << myCalc.sendNumber("1") << std::endl;
    std::cout << myCalc.sendOperator(4) << std::endl;
    std::cout << myCalc.sendNumber("0") << std::endl;
    std::cout << myCalc.getResult() << std::endl;
    return 0;
}
