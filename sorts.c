#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NELEMS 10000
#define NUM_SORTS 10000

void initialize_array(int *a, int sz); 
void generate_array(int *a, int sz);
void bubble_sort(int *ar);
void selection_sort(int *ar);
void swap(int i, int j, int *ar);
void display(int *ar); 

int main() {

    clock_t begin_bubblesort, end_bubblesort;

    printf("running %d sort operations of %d array elements using bubble sort...\n", NUM_SORTS, NELEMS); 

    begin_bubblesort = clock();
    int arr[NELEMS];
    for (int i=0; i<NUM_SORTS; i++) {
        generate_array(arr, NELEMS); 
        bubble_sort(arr);
    }
    end_bubblesort = clock(); 

    printf("%d %d element sorts took %.3f seconds.\n", NUM_SORTS, NELEMS, 
        (double)(end_bubblesort - begin_bubblesort)/CLOCKS_PER_SEC); 

    display(arr); 

    clock_t begin_selection_sort, end_selection_sort;

    printf("running %d sort operations of %d array elements using selection sort...\n", NUM_SORTS, NELEMS); 

    begin_selection_sort = clock();
    int arr2[NELEMS];
    for (int i=0; i<NUM_SORTS; i++) {
        generate_array(arr2, NELEMS); 
        selection_sort(arr2);
    }
    end_selection_sort = clock();

    printf("%d %d element sorts took %.3f seconds.\n", NUM_SORTS, NELEMS, 
        (double)(end_selection_sort - end_selection_sort)/CLOCKS_PER_SEC); 

    display(arr2); 

    return 0;
}

void initialize_array(int *a, int sz) {
    for (int i=0; i<sz; i++) {
        a[i] = 0;
    }
}

void generate_array(int *a, int sz) {
    for (int i=0; i<sz; i++) {
        a[i] = rand() % 99 + 1; 
    }
}

void bubble_sort(int *a) {
    int i, j;
    for (i=NELEMS-1; i>1; i--) {
        for (j=0; j<i; j++) {
            if (a[j] > a[j+1]) {
                swap(j, j+1, a);
            }
        }
    }
}

void selection_sort(int *a) {
    int i, j, min;
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

// display last 20 elements in sorted array, if desired.
void display(int *a) {
    for (int i=NELEMS-20; i<NELEMS; i++) {
        printf("%d ", a[i]);
    }
    printf("\n"); 
}
