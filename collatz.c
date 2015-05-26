#include <stdio.h>

int main() {
    long end = 0; 
    long tmp = 0; 
    int i; 
    for (i=1000001; i>2; i--) {
        long chain = 0; 
        long n = i;
        while (n != 1) {
            n = n%2==0 ? n/2 : n*3+1; 
            chain++; 
        } 
        if (chain > tmp) {
            tmp = chain;
            end = i; 
        }
    }
    printf("%ld %ld\n", end, tmp); 
    return 0; 
}

