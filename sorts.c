#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NELEMS 1000
#define NUM_SORTS 1000

typedef void(*func_t) (int *ar, int n); 

void initialize_array (int *a, int n); 
void generate_array (int *a, int n);
func_t bubble_sort (int *a, int n); 
func_t selection_sort (int *a, int n); 
func_t quicksort (int *a, int n); 
void display (int *ar); 

func_t functions[] = { (func_t)bubble_sort, (func_t)selection_sort, (func_t)quicksort };

int main() {

    for (int i=0; i<sizeof(functions)/sizeof(functions[0]); i++) {

        int arr[NELEMS]; 
  
        clock_t begin, end;

        initialize_array(arr, NELEMS); 
        generate_array(arr, NELEMS); 

        begin = clock();

        // call bubble_sort, selection_sort and quicksort with NELEMS elements
        for (int j=0; j<NUM_SORTS; j++) {
            functions[i](arr, NELEMS);
        }

        end = clock(); 

        printf("%.3f seconds.\n", (double)(end - begin)/CLOCKS_PER_SEC);
        display(arr); // show the last 20 sorted

    }

    return 0;
}

void initialize_array (int *a, int n) {
    for (int i=0; i<n; i++) {
        a[i] = 0;
    }
}

void generate_array (int *a, int n) {
    for (int i=0; i<n; i++) {
        a[i] = rand() % 999 + 1; 
    }
}

func_t bubble_sort (int *a, int n) {
    int i, j, t;
    for (i=n-1; i>1; i--) {
        for (j=0; j<i; j++) {
            if (a[j] > a[j+1]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

func_t selection_sort (int *a, int n) {
    int i, j, m, t;
    for (i=0; i<n; i++) {
        for (j=i, m=i; j<n; j++) {
            if (a[j] < a[m]) {
                m=j;
            }
        }
        t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

func_t quicksort (int *a, int n) {
    int i, j, p, t;
    if (n<2) 
        return 0;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quicksort(a, i);
    quicksort(a + i, n - i);
}

void display (int *a) {
    for (int i=NELEMS-20; i<NELEMS; i++) {
        printf("%d ", a[i]);
    }
    printf("\n"); 
}
