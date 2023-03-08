#include <iostream>

#include "calc.hpp"

int main() {
    Calc myCalc;
    std::cout << myCalc.sendNumber("0") << std::endl;
    std::cout << myCalc.sendDot() << std::endl;
    std::cout << myCalc.sendNumber("4") << std::endl;
    std::cout << myCalc.getResult() << std::endl;
    return 0;
}
