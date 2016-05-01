#include <stdio.h>
#include <string.h>

#define N 8

void initialize_board(char board[N][N]);
void display_board(char board[N][N]); 
void display_queen_moves(char board[N][N]); 
char *to_algebraic(int x, int y); 
void display_algebraic_chessboard(char board[N][N]);
void queen_move(char board[N][N]);
void move(char next_move[], char chess_piece, char board[N][N]); 

int main() {
    char board[N][N]; 
    char chess_piece = 'q'; 

    initialize_board(board); 
    board[3][3] = 'q'; 
    display_board(board); 
    display_queen_moves(board); 
    display_board(board); 
    display_queen_moves(board); 
    display_board(board); 
    display_algebraic_chessboard(board); 
    printf("\n\n"); 

    char next_move[2];
    printf("move?: "); 
    scanf("%c %c", &next_move[0], &next_move[1]);
    next_move[2] = '\0'; 

    move(next_move, chess_piece, board);
    display_board(board); 
   
    return 0;
}

//
// get the algebraic position of a chess piece, eg. e4, a1, h8.
//
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

//int *from_algebraic(char *current) {
//
//    int matrix_position[2]; 
//
//    char rows[N] = { '8', '7', '6', '5', '4', '3', '2', '1' };
//    char cols[N] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
//
//    return matrix_position;
//}


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

void display_board(char board[N][N]) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            printf("%c", board[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n"); 
}

// placeholder for queen moves - currently unimplemented. 
void queen_move(char board[N][N]) {
    int queen_xmoves[] = { 1, 2, 3, 4, 5, 6, 7, 8, -1, -2, -3, -4, -5, -6, -7, -8 };
    int queen_ymoves[] = { 1, 2, 3, 4, 5, 6, 7, 8, -1, -2, -3, -4, -5, -6, -7, -8 }; 
}

void move(char *next_move, char chess_piece, char board[N][N]) {
    int i, j;

    //
    // replace the former location of the chess piece with a '.' character
    // to denote that it is now an empty square.
    //
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (board[i][j] == chess_piece) {
                board[i][j] == '.'; 
            }
        }
    }

    int next_x, next_y; 

    //
    // place the chess piece in the next location supplied by the user.
    //
    next_x = next_move[0]; 
    next_y = next_move[1]; 

    board[next_x][next_y] = chess_piece; 
}









