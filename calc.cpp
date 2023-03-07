#include "calc.hpp"

#include <cmath>

using std::to_string;

// Variable Init
Calc::Calc() {
    setAB = false;
    mySetValue = false;
    operandChange = false;
    myFinish = false;
    myError = false;
    myOperator = 0;
    oouControl = 1;
    dotControl = 0;
    myA = "0";
    myB = "0";
    myM = "0";
}

// Basic Function
string Calc::myShow() {
    if (!operandChange) {
        return myA + " ";
    } else {
        return myB + " ";
    }
}

string Calc::myExecution(string myCommand) {
    string myStep = "";
    string myOutput = "";
    if (myCommand == "c") {
        setAB = false;
        mySetValue = false;
        try {
            switch (myOperator) {
            case 1:
                myA = to_string(stod(myA) + stod(myB));
                break;
            case 2:
                myA = to_string(stod(myA) - stod(myB));
                break;
            case 3:
                myA = to_string(stod(myA) * stod(myB));
                break;
            }
            myB = "0";
            if (!myFinish) {
                if (myA.length() < 14) {
                    myStep = "a";
                } else {
                    myStep = "e";
                }
            } else {
                operandChange = false;
                myOperator = 0;
                myStep = "f";
            }
        } catch (...) {
            myStep = "e";
        }
    }
    if (myCommand == "f" || myStep == "f") {
        switch (oouControl) {
        case 0:
            if (!operandChange) {
                myA = to_string(stod(myA) * pow(10, dotControl));
                myA = to_string(floor(stod(myA)));
                myA = to_string(stod(myA) / pow(10, dotControl));
            } else {
                myB = to_string(stod(myB) * pow(10, dotControl));
                myB = to_string(floor(stod(myB)));
                myB = to_string(stod(myB) / pow(10, dotControl));
            }
            break;
        case 1:
            if (!operandChange) {
                myA = to_string(stod(myA) * pow(10, dotControl));
                myA = to_string(ceil(stod(myA)));
                myA = to_string(stod(myA) / pow(10, dotControl));
            } else {
                myB = to_string(stod(myB) * pow(10, dotControl));
                myB = to_string(ceil(stod(myB)));
                myB = to_string(stod(myB) / pow(10, dotControl));
            }
            break;
        case 2:
            if (!operandChange) {
                myA = to_string(stod(myA) * pow(10, dotControl));
                myA = to_string(round(stod(myA)));
                myA = to_string(stod(myA) / pow(10, dotControl));
            } else {
                myB = to_string(stod(myB) * pow(10, dotControl));
                myB = to_string(round(stod(myB)));
                myB = to_string(stod(myB) / pow(10, dotControl));
            }
            break;
        }
        if (myFinish) {
            if (myA.length() < 14) {
                myStep = "a";
            } else {
                myStep = "e";
            }
        }
    }
    if (myCommand == "e" || myStep == "e") {
        myError = true;
        myOutput = "E ";
    }
    if (myStep == "a") {
        myOutput = myA + " ";
    }
    return myOutput;
}

void Calc::myReset() {
    setAB = true;
    if (mySetValue || myFinish) {
        mySetValue = false;
        myFinish = false;
        if (!operandChange) {
            myA = "0";
        } else {
            myB = "0";
        }
    }
}

// Control Function
void Calc::setOouControl(int myValue) {
    oouControl = myValue;
}

void Calc::setDotControl(int myValue) {
    dotControl = myValue;
}

string Calc::myClear() {
    setAB = false;
    mySetValue = false;
    operandChange = false;
    myFinish = false;
    myError = false;
    myOperator = 0;
    myA = "0";
    myB = "0";
    return myShow();
}

string Calc::myNegative() {
    string myOutput = "E ";
    if (!myError) {
        if (!operandChange) {
            if (myA != "0") {
                myA = to_string(stod(myA) * -1);
            }
        } else {
            if (myB != "0") {
                myB = to_string(stod(myB) * -1);
            }
        }
        myOutput = myShow();
    }
    return myOutput;
}

string Calc::memoryRead() {
    string myOutput = "E ";
    if (!myError) {
        myReset();
        mySetValue = true;
        if (!operandChange) {
            myA = myM;
        } else {
            myB = myM;
        }
        myOutput = myShow();
    }
    return myOutput;
}

void Calc::memoryWrite() {
    if (!myError) {
        if (!operandChange) {
            myM = to_string(stod(myM) + stod(myA));
        } else {
            myM = to_string(stod(myM) + stod(myB));
        }
    }
}

string Calc::powTwo() {
    string myOutput = "E ";
    if (!myError) {
        mySetValue = true;
        if (!operandChange) {
            myA = to_string(pow(stod(myA), 2));
        } else {
            myB = to_string(pow(stod(myB), 2));
        }
        myExecution("f");
        myOutput = myShow();
    }
    return myOutput;
}

string Calc::mySqrt() {
    string myOutput = "E ";
    if (!myError) {
        try {
            mySetValue = true;
            if (!operandChange) {
                myA = to_string(sqrt(stod(myA)));
            } else {
                myB = to_string(sqrt(stod(myB)));
            }
            myExecution("f");
            myOutput = myShow();
        } catch (...) {
            myOutput = myExecution("e");
        }
    }
    return myOutput;
}

string Calc::sendNumber(string mySend) {
    string myOutput = "E ";
    if (!myError) {
        myReset();
        mySetValue = true;
        if (!operandChange && myA.length() < 13) {
            if (myA == "0") {
                myA = "";
            }
            myA.append(mySend);
        } else if (operandChange && myB.length() < 13) {
            if (myB == "0") {
                myB = "";
            }
            myB.append(mySend);
        }
        myOutput = myShow();
    }
    return myOutput;
}

string Calc::sendOperator(int mySend) {
    string myOutput = "E ";
    if (!myError) {
        myFinish = false;
        if (!operandChange) {
            setAB = false;
            mySetValue = false;
            operandChange = true;
            myOutput = myA;
        } else if (setAB) {
            myOutput = myExecution("c");
        }
        if (!myError) {
            myOperator = mySend;
        }
    }
    return myOutput;
}

string Calc::getResult() {
    string myOutput = "E ";
    if (!myError) {
        myFinish = true;
        myOutput = myShow();
    }
    return myOutput;
}
