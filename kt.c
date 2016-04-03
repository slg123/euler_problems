#include <stdio.h>

typedef struct {
    int x;
    int y;
} knight_move;

const int N = 8;

void initialize_board(int a[N][N]); 
void print_board(int a[N][N]);

int main() {

    knight_move moves[] = { 1,2, 2,1, 1,-2, 2,-1, -1,2, -2,1, -1,-2, -2,-1 };

    for (int i=0; i<sizeof(moves)/sizeof(moves[0]); i++) {
        printf("%d %d\n", moves[i].x, moves[i].y); 
    }
 
    int ar[N][N]; 

    initialize_board(ar);
    print_board(ar); 

    return 0;
}

void initialize_board(int a[N][N]) {
    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            a[i][j] = 0;
        }
    }
}

void print_board(int a[N][N]) {
    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            printf(" %d", a[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n\n"); 
}
