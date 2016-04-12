#include <stdio.h>

#define N 10
void print_array(int a[N]);

int main() {
    int i, p, q, t, id[N];
    for (i=0; i<N; i++) {
        id[i] = i;
    }
    print_array(id); 
    while (scanf("%d %d\n", &p, &q) == 2) {
        if (id[p] == id[q]) continue;
        for (t = id[p], i=0; i<N; i++) {
            if (id[i] == t) {
                id[i] = id[q];
            }
        }
        print_array(id); 
        printf(" %d %d\n", p, q);
    }
    return 0;
}

void print_array(int a[N]) {
    for (int i=0; i<N; i++) {
        printf(" %d ", a[i]);
    }
    printf("\n");
}
