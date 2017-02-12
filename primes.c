#include <stdio.h>
#include <stdlib.h>

int isPrime(int);

int main() {

    const int MAX = 10000000;

    int *primes = malloc(MAX*sizeof(int)); 
    
    int i;
    for (i=0; i<MAX; i++) {
        if (isPrime(i)) {
            primes[i] = i; 
            printf(" %d ", primes[i]);
        }
    }

    return 0;
}

int isPrime(int n) {
    if ((n == 2) || (n == 3)) { return 1; }
    if ((n % 2 == 0) || (n % 3 == 0)) { return 0; }

    int i = 5;
    int w = 2;

    while ((i * i) <= n) {
        if (n % i == 0) {
            return 0;
        }
        i += w;
        w = 6 - w;
    }

    return 1;
}

