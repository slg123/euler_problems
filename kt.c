#include <stdio.h>

const int N = 8;

void initialize_board(int a[N][N]); 
void print_board(int a[N][N]);

typedef struct {
    int x;
    int y;
} knight_move;

int main() {

    knight_move moves[] = { 1,2, 2,1, 1,-2, 2,-1, -1,2, -2,1, -1,-2, -2,-1 };

    for (int i=0; i<sizeof(moves)/sizeof(moves[0]); i++) {
        printf("%d %d\n", moves[i].x, moves[i].y); 
    }

    printf("%d %d\n", moves[0].x, moves[0].y);
 
    int ar[N][N]; 
    int x = 1; /* starting row */
    int y = 1; /* starting column */

    initialize_board(ar);
    print_board(ar); 

    ar[x][y] = 1;
    print_board(ar); 
    
    //r = r + moves[2].x;
    //c = c + moves[2].y;
    x = 3;
    y = 2;

    ar[x][y] = 2;
    print_board(ar);

    x = 5;
    y = 1;

    ar[x][y] = 3;
    print_board(ar);

    return 0;
}

void initialize_board(int a[N][N]) {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            a[i][j] = 0;
        }
    }
}

void print_board(int a[N][N]) {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            printf(" %d", a[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n\n"); 
}
