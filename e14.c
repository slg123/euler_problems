#include <stdio.h>
#include <stdlib.h>

long get_collatz_chain( long n );

int main() 
{
    long final = 0;
    long tmp = 0;
    long len = 0; 

    long i; 
    for (i = 2; i < 1000001; i++) {
        len = get_collatz_chain(i); 
        if ( len > tmp ) { 
            tmp = len; 
            final = i;
        }
    }
    printf("%ld\n", final); 
    return 0; 
}

long get_collatz_chain( long n ) 
{
    long count = 0; 
    while (n != 1) {
        if (n%2 == 0) {
            n = n/2;
        } else {
            n = (n*3) + 1;
        }
        count++;
    }
    return count;
}

