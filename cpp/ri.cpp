#include <iostream>

using namespace std;
void display(); 
void displayNewArray();
void rotate(); 

int ar[4][4] = {{ 0, 1, 2, 3 },
                { 4, 5, 6, 7 },
                { 8, 9, 10, 11 },
                { 12, 13, 14, 15 }};

int newar[4][4] = {{}, {}, {}, {}};

int main() {
    display();
    rotate();
    displayNewArray();
    return 0; 
}

void display() {
    int i, j;
    for (i=0; i<=3; i++) {
        for (j=0; j<=3; j++) {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void displayNewArray() {
    int i, j;
    for (i=0; i<=3; i++) {
        for (j=0; j<=3; j++) {
            cout << newar[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotate() {
    int i, j, s;
    for (i=0; i<=3; i++) {
        for (j=0, s=3; j<=3, s>=0; j++, s--) {
            newar[i][j] = ar[s][i];
        }
    }
}

