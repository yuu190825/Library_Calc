#ifndef calc_hpp
#define calc_hpp

#include <stdio.h>
#include <string>

using std::string;

class Calc {
    // Variable
    bool setAB;
    bool mySetValue;
    bool operandChange;
    bool myFinish;
    bool myError;
    int myOperator;
    int oouControl;
    int dotControl;
    string myA;
    string myB;
    string myM;
    
    // Basic Function
    string myShow();
    string myExecution(string myCommand);
    void myReset();
    
public:
    // init
    Calc();
    
    // Control Function
    void setOouControl(int value);
    void setDotControl(int value);
    void myClear();
};

#endif /* calc_hpp */
