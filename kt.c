#include <stdio.h>

const int N = 8;

void initialize_board(int a[N][N]); 
void print_board(int a[N][N]);
void walk_board(int a[N][N]);
int  visited(int a[N][N], int x, int y);

typedef struct {
    int x;
    int y;
} knight_move;

int main() {
    int ar[N][N]; 
    int x = 1;
    int y = 1;
    ar[x][y] = 1;

    initialize_board(ar);
    print_board(ar); 
    walk_board(ar); 

    return 0;
}

void walk_board(int a[N][N]) {
    knight_move moves[] = { 1,2, 2,1, 1,-2, 2,-1, -1,2, -2,1, -1,-2, -2,-1 };
    int x = 1;
    int y = 1;
    int m = 1;
    while (m <= 64) {
        for (int i=0; i<sizeof(moves)/sizeof(moves[0]); i++) {
            x = x+moves[i].x;
            y = y+moves[i].y;
            if (visited(a, x, y)) {
                printf("visited %d %d\n", x, y); 
            }
            a[x][y] = m;
            m++;
            print_board(a);
        }
    }
}

int visited(int a[N][N], int x, int y) {
    if (a[x][y] == 0) {
        return 0;
    }
    return 1;
}


void initialize_board(int a[N][N]) {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            a[i][j] = 0;
        }
    }
}

void print_board(int a[N][N]) {
    int width = 3;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            printf("%*d", width, a[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n\n"); 
}
