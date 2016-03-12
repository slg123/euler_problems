#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b); 

int main() {

    int a[] = { 0, 1, 2, 3, 4, 5 };
    int b[] = { 3, 0, 99, 1, 7, -10 };
    int c[] = { 9, 1, 0, 77, 21, 19 }; 

    printf("%d\n", sorted(a)); 
    printf("%d\n", sorted(b)); 

    print_array(a, sizeof(a)/sizeof(int)); 
    print_array(b, sizeof(b)/sizeof(int)); 

    qsort(b, (sizeof(b)/sizeof(int)), sizeof(int), cmpfunc); 

    print_array(b, sizeof(b)/sizeof(int)); 

    if (!sorted(c)) {
        qsort(c, (sizeof(c)/sizeof(int)), sizeof(int), cmpfunc); 
    }
    print_array(c, sizeof(c)/sizeof(int)); 


    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); 
}

// is the array sorted? from programming pearls, 2nd edition
int sorted(int ar[]) {
    int i;
    int n = sizeof(ar)/sizeof(ar[0]);

    for (i=0; i<n-1; i++) {
        if (ar[i] > ar[i+1]) {
            return 0;
        }
    }
    return 1;
}

int print_array(int ar[], int sz) {
    int i;
    for (i=0; i < sz; i++) {
        printf(" %d ", ar[i]); 
    }
    printf("\n"); 
}
