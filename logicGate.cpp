#include <iostream>

using namespace std;

class LogicGate {
    public:
        int doAndGateOperation(int a, int b); 
        int doOrGateOperation(int a, int b); 
        int doNorGateOperation(int a, int b); 
};

LogicGate::doAndGateOperation(int a, int b) {
    if ((a == 1) && (b == 1)) {
        return 1;
    } else {
        return 0;
    }
}

LogicGate::doOrGateOperation(int a, int b) {
    if ((a == 1) || (b == 1)) {
        return 1;
    } else {
        return 0;
    }
}

LogicGate::doNorGateOperation(int a, int b) {
    if ((a == 0) && (b == 0)) {
        return 1;
    } else {
        return 0;
    }
}

void testGates() {

    LogicGate andGate;
    LogicGate orGate;
    LogicGate norGate;

    int val_a[4] = { 0, 0, 1, 1 };
    int val_b[4] = { 0, 1, 0, 1 };
    
    for (int i=0; i<4; i++) {
        cout << "AND gate: " << val_a[i] << " " << val_b[i] << " :" << 
                andGate.doAndGateOperation(val_a[i], val_b[i]) << endl;
    }
    cout << "\n\n\n"; 

    for (int i=0; i<4; i++) {
        cout << "OR  gate: " << val_a[i] << " " << val_b[i] << " :" <<
                orGate.doOrGateOperation(val_a[i], val_b[i]) << endl;
    }
    cout << "\n\n\n"; 

    for (int i=0; i<4; i++) {
        cout << "NOR gate: " << val_a[i] << " " << val_b[i] << " :" << 
                norGate.doNorGateOperation(val_a[i], val_b[i]) << endl;
    }

}

int main() 
{
    int a = 1;
    int b = 0; 

    LogicGate andGate;
    LogicGate orGate; 
    LogicGate norGate; 

    int and_result = andGate.doAndGateOperation(a, b); 
    int or_result  = orGate.doOrGateOperation(a, b); 
    int nor_result = norGate.doNorGateOperation(a, b);

    cout << and_result << endl;
    cout << or_result << endl; 
    cout << nor_result << endl; 

    /* test all gates */
    testGates(); 

    return 0;
}


