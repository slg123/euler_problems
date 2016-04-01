#include <stdio.h>
#include <stdlib.h>

#define NELEMS 20

void generate_array(int *a, int sz);
void bubble_sort(int *ar);
void selection_sort(int *ar);
void swap(int i, int j, int *ar);
void display(int *ar); 

int main() {

    int arr[NELEMS];

    generate_array(arr, NELEMS); 

    display(arr); 
    bubble_sort(arr);
    display(arr); 

    int arr2[NELEMS];
    generate_array(arr2, NELEMS); 

    display(arr2);
    selection_sort(arr2);
    display(arr2);

    return 0;
}

void generate_array(int *a, int sz) {
    int i;
    for (i=0; i<sz; i++) {
        a[i] = rand() % 99 + 1; 
    }
}

void bubble_sort(int *a) {
    int i;
    int j;
    for (i=NELEMS-1; i>1; i--) {
        for (j=0; j<i; j++) {
            if (a[j] > a[j+1]) {
                swap(j, j+1, a);
            }
        }
    }
}

void selection_sort(int *a) {
    int i;
    int j;
    int min;
    for (i=0; i<NELEMS-1; i++) {
        min = i;
        for (j=i+1; j<NELEMS; j++) {
            if (a[j] < a[min]) {
                min = j;
                swap(i, j, a);
            }
        }
    }
}

void swap(int i, int j, int *a) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void display(int *a) {
    int i;
    for (i=0; i<NELEMS; i++) {
        printf("%d ", a[i]);
    }
    printf("\n"); 
}
