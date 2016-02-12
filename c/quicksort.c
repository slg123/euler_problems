#include <stdio.h>
#include <stdlib.h>
 
void quick_sort (int *a, int n) {
    int i, j, p, t;    // i, j, pivot, temp
    if (n < 2)
        return;         // just return if it's a tiny array
    p = a[n / 2];       // pivot point of the array

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
    quick_sort(a, i);
    quick_sort(a + i, n - i);
}

int main (void) {
    const int ARRAYSIZE=20000;
    int a[ARRAYSIZE];
    int i;
    for (i=0; i<ARRAYSIZE; i++) {
        a[i] = rand() % 10000000; 
    }

    int n = sizeof a / sizeof a[0];
    printf("building array of %d numbers\n", ARRAYSIZE); 
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");

    quick_sort(a, n);

    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
