#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long sum(int *ar, int sz); 
void show_reversed_b2d(unsigned long long n); 

int main() {
    int ARRAY_SIZE = 32;
    //int ARRAY_SIZE = 8;
    int bitarray[ARRAY_SIZE];
    int reversed_bitarray[ARRAY_SIZE];

    int i;
    for (i=0; i<ARRAY_SIZE; i++) {
        bitarray[i] = rand() % 2; 
    }

    for (i=0; i<ARRAY_SIZE; i++) {
        printf("%d", bitarray[i]);
    }
    printf("\n"); 

    int j;
    for (i=ARRAY_SIZE-1; i>=0; i--) {
        reversed_bitarray[i] = bitarray[i];
        printf("%d", reversed_bitarray[i]); 
    }
    printf("\n");

    unsigned long long nval = sum(bitarray, ARRAY_SIZE); 

    printf("%llu\n", nval); 
    show_reversed_b2d(nval); 

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

void show_reversed_b2d(unsigned long long n) {
    while (n > 0) {
        if (n % 2 == 0) {
            printf("0");
        } else {
            printf("1");
        }
        n = n/2; 
    }
}
