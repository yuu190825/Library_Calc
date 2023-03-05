#include "calc.hpp"

Calc::Calc() {
    setAB = false;
    mySetValue = false;
    operandChange = false;
    finish = false;
    error = false;
    myOperator = 0;
    oouControl = 1;
    dotControl = 0;
    a = "0";
    b = "0";
    m = "0";
}
