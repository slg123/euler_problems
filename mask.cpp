#include <iostream>

using namespace std;

void show_octet(int size, int octet[]); 
void fill_octet(int size, int octet[], int value);

int first_octet[32] = {}; 
int second_octet[24] = {}; 
int third_octet[16] = {}; 
int fourth_octet[8] = {}; 

int main() {

    // mask size of fourth octet
    int fourth_octet_size = 8;

    fill_octet(fourth_octet_size, fourth_octet, 1); 
    show_octet(fourth_octet_size, fourth_octet); 

    // mask size of third octet
    int third_octet_size  = 16;

    fill_octet(third_octet_size, third_octet, 1); 
    show_octet(third_octet_size, third_octet); 

    // mask size of second octet
    int second_octet_size  = 24;

    fill_octet(second_octet_size, second_octet, 1); 
    show_octet(second_octet_size, second_octet); 

    // mask size of first octet
    int first_octet_size  = 32;

    fill_octet(first_octet_size, first_octet, 1); 
    show_octet(first_octet_size, first_octet); 

    // test badval
    fill_octet(first_octet_size, first_octet, 2); 

    return 0;
}

void fill_octet(int size, int octet[], int value) {
    if (value == 1 || value == 0) {
        for (int i=0; i<size; i++) {
            octet[i] = value;
        }
    } else {
        cout << "invalid value: " << value << endl;
    }
}

void show_octet(int size, int octet[]) {
    for (int i=0; i<size; i++) {
        cout << octet[i];
    }
    cout << endl;
}



