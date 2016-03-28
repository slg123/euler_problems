#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>

void fill_bitarray(int *ar, int sz); 
int compare(const void *a, const void *b);

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
    fclose(output); 

    FILE *input;
    input = fopen("number_list.dat", "r"); 
    unsigned long *ar; 
    ar = (unsigned long *) malloc(LIST_SIZE * sizeof(unsigned long)); 
    for (i=0; i<LIST_SIZE; i++) {
        fscanf(input, "%lu", &ar[i]); 
    }
    printf("very large array created.\n"); 

    qsort(ar, LIST_SIZE, sizeof(unsigned long), compare);  

    printf("very large array sorted.\n"); 

    fclose(input); 

    FILE *sorted_output;
    sorted_output = fopen("number_list.sorted", "w");
    for (i=0; i<LIST_SIZE; i++) {
        fprintf(sorted_output, "%lu\n", ar[i]); 
    }
    free(ar); 
    fclose(sorted_output); 

    return 0;
}

void fill_bitarray(int *ar, int sz) {
    int i;
    for (i=0; i<sz; i++) {
        ar[i] = rand() % 9 + 1;
    }
}

int compare(const void *a, const void *b) {
    const unsigned long long *x = a, *y = b; 
    if (*x > *y) {
        return 1;
    } else {
        return (*x < *y) ? -1 : 0;
    }
}
