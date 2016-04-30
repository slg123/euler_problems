#include <stdio.h>
#include <string.h>

#define N 8

void initialize_board(char board[N][N]);
void print_board(char board[N][N]); 
void display_queen_moves(char board[N][N]); 
char *to_algebraic(int x, int y); 
void display_algebraic_chessboard(char board[N][N]);

int main() {
    char board[N][N]; 

    int queen_xmoves[] = { 1, 2, 3, 4, 5, 6, 7, 8, -1, -2, -3, -4, -5, -6, -7, -8 };
    int queen_ymoves[] = { 1, 2, 3, 4, 5, 6, 7, 8, -1, -2, -3, -4, -5, -6, -7, -8 }; 

    initialize_board(board); 
    board[3][3] = 'q'; 
    print_board(board); 
    display_queen_moves(board); 
    print_board(board); 
    display_queen_moves(board); 
    print_board(board); 
    display_algebraic_chessboard(board); 
    printf("\n\n"); 

    return 0;
}

char *to_algebraic(int x, int y) {

    char rows[N] = { '8', '7', '6', '5', '4', '3', '2', '1' };
    char cols[N] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

    char *algebraic_position;
    char pos[2]; 

    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (i==x && j==y) {
                pos[0] = cols[j];
                pos[1] = rows[i];
            }
        }
    }
    algebraic_position = pos; 
    algebraic_position[2] = '\0'; 
    return algebraic_position;

}

void display_algebraic_chessboard(char board[N][N]) {

    char rows[N] = { '8', '7', '6', '5', '4', '3', '2', '1' };
    char cols[N] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            printf("%c%c", cols[j], rows[i]); 
        }
        printf("\n"); 
    }
}


void display_queen_moves(char board[N][N]) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (board[i][j] == 'q') {
                printf("\nqueen is located at square: %s\n", to_algebraic(i, j)); 
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
