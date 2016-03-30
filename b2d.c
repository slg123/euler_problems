#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long sum(int *ar, int sz); 

int main() {
    int ARRAY_SIZE = 32;
    //int ARRAY_SIZE = 8;
    int bitarray[ARRAY_SIZE];

    int i;
    for (i=0; i<ARRAY_SIZE; i++) {
        bitarray[i] = rand() % 2; 
    }

    for (i=0; i<ARRAY_SIZE; i++) {
        printf("%d", bitarray[i]);
    }
    printf("\n"); 

    unsigned long long nval = sum(bitarray, ARRAY_SIZE); 

    printf("%llu\n", nval); 

    return 0;
}

unsigned long long sum(int *ar, int sz) {
    int i;
    unsigned long long s;
    unsigned long long posn = sz; 
    for (i=0; i<sz; i++) {
        posn--; 
        if (ar[i] == 1) {
            s += pow(2, posn); 
        }
    }
    return s;
}
