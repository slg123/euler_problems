#include <iostream>

using namespace std;

class LogicGate {
    public:
        int doAndGateOperation(int a, int b); 
        int doOrGateOperation(int a, int b); 
};

LogicGate::doAndGateOperation(int a, int b) {
    int cmpa = a;
    int cmpb = b;
    if ((cmpa == 1) && (cmpb == 1)) {
        return 1;
    } else {
        return 0;
    }
}

LogicGate::doOrGateOperation(int a, int b) {
    int cmpa = a;
    int cmpb = b;
    if ((cmpa==1) || (cmpb == 1)) {
        return 1;
    } else {
        return 0;
    }
}

int main() 
{
    int a = 1;
    int b = 0; 

    LogicGate andGate;
    LogicGate orGate; 

    int and_result = andGate.doAndGateOperation(a, b); 
    int or_result = orGate.doOrGateOperation(a, b); 

    cout << and_result << endl;
    cout << or_result << endl; 

    return 0;
}


