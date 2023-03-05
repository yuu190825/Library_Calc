#ifndef calc_hpp
#define calc_hpp

#include <stdio.h>
#include <string>

using std::string;

class Calc {
    bool setAB;
    bool mySetValue;
    bool operandChange;
    bool finish;
    bool error;
    int myOperator;
    int oouControl;
    int dotControl;
    string a;
    string b;
    string m;
    
public:
    Calc();
};

#endif /* calc_hpp */
