#include <iostream>

#include "calc.hpp"

int main() {
    Calc myCalc;
    std::cout << myCalc.sendNumber("2") << std::endl;
    std::cout << myCalc.sendNumber("2") << std::endl;
    std::cout << myCalc.backSpace() << std::endl;
    return 0;
}
