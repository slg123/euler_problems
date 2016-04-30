#include <stdio.h>
#include <string.h>

#define N 8

void initialize_board(char board[N][N]);
void print_board(char board[N][N]); 
void display_queen_moves(char board[N][N]); 
void to_algebraic(char board[N][N]);

int main() {
    char board[N][N]; 

    int queen_xmoves[] = { 1, 2, 3, 4, 5, 6, 7, 8, -1, -2, -3, -4, -5, -6, -7, -8 };
    int queen_ymoves[] = { 1, 2, 3, 4, 5, 6, 7, 8, -1, -2, -3, -4, -5, -6, -7, -8 }; 

    initialize_board(board); 
    board[3][3] = 'q'; 
    print_board(board); 
    display_queen_moves(board); 
    printf("\n"); 
    to_algebraic(board); 
    printf("\n\n"); 

    return 0;
}

void to_algebraic(char board[N][N]) {

    char ranks[N] = { 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a' };
    char files[N] = { '1', '2', '3', '4', '5', '6', '7', '8' };

    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            printf("%c%c", ranks[i], files[j]); 
        }
        printf("\n"); 
    }

    //int i, j, s, k;
    //for (i=1, s=N; i<N, s>=0; i++, s--) {
    //    for (j=0; j<N; j++) { 
    //        if (i>1) {
    //            printf("%c%c", ranks[s], files[j]); 
    //        }
    //    }
    //    printf("\n"); 
    //}

}

void display_queen_moves(char board[N][N]) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (board[i][j] == 'q') {
                printf("\nqueen is located at square: %d %d\n", i, j); 
            }
        }
    }
}

void initialize_board(char board[N][N]) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            board[i][j] = '.';
        }
    }
}

void print_board(char board[N][N]) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            printf("%c", board[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n"); 
}
