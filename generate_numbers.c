#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void fill_bitarray(int *ar, int sz); 

int main() {

    const int LIST_SIZE = 1000000;

    int bitarray[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    int sz = sizeof(bitarray) / sizeof(bitarray[0]); 

    FILE *output;
    output = fopen("number_list.dat", "w");

    int i;
    for (i=0; i<LIST_SIZE; i++) {
        fill_bitarray(bitarray, sz); 
        fprintf(output, "%d%d%d%d%d%d%d%d%d%d\n", bitarray[0], bitarray[1], bitarray[2],
                                     bitarray[3], bitarray[4], bitarray[5], bitarray[6],
                                     bitarray[7], bitarray[8], bitarray[9]); 
    }

    return 0;
}

void fill_bitarray(int *ar, int sz) {
    int i;
    for (i=0; i<sz; i++) {
        if (ar[0] == 0) {
            ar[0] = rand() % 10 + 1;
        }
        ar[i] = rand() % 10; 
    }
}
