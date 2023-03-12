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
void Calc::cStringFormat() {
    while (myA.find(".") != string::npos && myA.back() == '0') {
        myA.pop_back();
    }
    if (myA.back() == '.') {
        myA.pop_back();
    }
}

string Calc::myShow() {
    cStringFormat();
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
        if (myOperator != 4 || myB != "0") {
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
            case 4:
                myA = to_string(stod(myA) / stod(myB));
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
        } else {
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
                myA = to_string(round(stod(myA)));
                myA = to_string(stod(myA) / pow(10, dotControl));
            } else {
                myB = to_string(stod(myB) * pow(10, dotControl));
                myB = to_string(round(stod(myB)));
                myB = to_string(stod(myB) / pow(10, dotControl));
            }
            break;
        case 2:
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
    if (!myError) {
        cStringFormat();
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

string Calc::setDotControl(int myValue) {
    dotControl = myValue;
    return to_string(dotControl);
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

string Calc::backSpace() {
    string myOutput = "E ";
    if (!myError) {
        if (!operandChange) {
            myA.pop_back();
            if (myA == "") {
                myA = "0";
            }
        } else {
            myB.pop_back();
            if (myB == "") {
                myB = "0";
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
        if (!operandChange && stod(myA) > 0) {
            myA = to_string(sqrt(stod(myA)));
        } else if (operandChange && stod(myB) > 0) {
            myB = to_string(sqrt(stod(myB)));
        } else {
            myOutput = myExecution("e");
        }
        if (!myError) {
            mySetValue = true;
            myExecution("f");
            myOutput = myShow();
        }
    }
    return myOutput;
}

string Calc::sendNumber(string mySend) {
    string myOutput = "E ";
    if (!myError) {
        myReset();
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
            myOutput = myA + " ";
        } else if (setAB) {
            myOutput = myExecution("c");
        }
        if (!myError) {
            myOperator = mySend;
        }
    }
    return myOutput;
}

string Calc::sendDot() {
    string myOutput = "E ";
    if (!myError) {
        myReset();
        if (!operandChange && myA.length() < 12) {
            if (myA.find(".") == string::npos) {
                myA.append(".");
            }
        } else if (operandChange && myB.length() < 12) {
            if (myB.find(".") == string::npos) {
                myB.append(".");
            }
        }
        myOutput = myShow();
    }
    return myOutput;
}

string Calc::getResult() {
    string myOutput = "E ";
    if (!myError) {
        myFinish = true;
        myOutput = myExecution("c");
    }
    return myOutput;
}
