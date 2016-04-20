#include <stdio.h>
#include <limits.h>

int is_prime(unsigned long long n); 
unsigned long long prime_distance(unsigned long long prev, unsigned long long curr);

int main() {
    unsigned long long curr=0;
    unsigned long long prev=0;
    unsigned long long prime_gap=0;

    for (unsigned long long i=0; i<ULLONG_MAX; i++) {
        if (is_prime(i)) {
            curr = i;
            prime_gap = prime_distance(prev, curr);
            if (prime_gap > 100) {
                printf("prime gap > 100 for %llu and %llu: %llu\n", prev, curr, prime_gap); 
            }
            prev = curr;
        }
    }
    return 0;
}

int is_prime(unsigned long long n) {
    for (unsigned long long i=2; i<n; i++) {
        if (n%i == 0 && i != n) { 
            return 0;
        } 
    }
    return 1;
}

unsigned long long prime_distance(unsigned long long prev, unsigned long long curr) {
    unsigned long long dist;
    dist = curr - prev;
    return dist;
}

