#include <stdio.h>

typedef struct {
    int x;
    int y;
} knight_move;

int main() {

    knight_move moves[] = { 1,2, 2,1, 1,-2, 2,-1, -1,2, -2,1, -1,-2, -2,-1 };

    for (int i=0; i<sizeof(moves)/sizeof(moves[0]); i++) {
        printf("%d %d\n", moves[i].x, moves[i].y); 
    }

    return 0;
}
