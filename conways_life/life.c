#include <stdio.h>
#include <stdlib.h>

#define MAXROW 20
#define MAXCOL 60

typedef enum state { 
    DEAD, 
    ALIVE 
} State;

typedef enum boolean {
     FALSE, 
     TRUE 
} Boolean;

typedef State Grid[MAXROW+2][MAXCOL+2];

void CopyMap(Grid map, Grid newmap);
Boolean UserSaysYes(void); 
void Initialize(Grid map); 
int NeighborCount(Grid map, int row, int column); 
void WriteMap(Grid map); 
void Error(char *);
void Warning(char *); 

void main(void) {
    int row, col;
    Grid map;
    Grid newmap;
    Initialize(map);
    WriteMap(map);

    printf("This is the initial configuration you have chosen.\n"
           "Press <Enter> to continue.\n"); 

    while (getchar() != '\n')
        ;
    do {
        for (row=1; row<=MAXROW; row++) 
            for (col=1; col <= MAXCOL; col++) 
                switch(NeighborCount(map, row, col)) {
                    case 0:
                    case 1:
                        newmap[row][col] = DEAD;
                        break;
                    case 2:
                        newmap[row][col] = map[row][col];
                        break;
                    case 3:       
                        newmap[row][col] = ALIVE;
                        break;
                    case 4:       
                    case 5:       
                    case 6:       
                    case 7:       
                    case 8:       
                        newmap[row][col] = DEAD;
                        break;
                }

        CopyMap(map, newmap);
        WriteMap(map);
        printf("Do you wish to continue viewing the generations?"); 
    } while (UserSaysYes());
}

int NeighborCount(Grid map, int row, int col) {
    int i;
    int j;
    int count = 0;
    for (i=row-1; i<=row+1; i++) 
        for (j=col-1; j<=col+1; j++) 
            if (map[i][j] == ALIVE)
                count++;

    if (map[row][count] == ALIVE)
        count--;

    return count;
}

void Initialize(Grid map) {
    int row, col;
    printf("This program is a simulation of the game of Life.\n"
           "The grid has a size of %d rows and %d columns.\n", MAXROW, MAXCOL); 

    for (row=0; row<=MAXROW+1; row++) 
        for (col=0; col<=MAXCOL+1; col++) 
            map[row][col] = DEAD;  /* set all cells to empty, including the hedge/border */

    printf("On each line give a pair of coordinates for a living cell.\n"
           "Terminate the list with the special pair 0 0.\n"); 

    scanf("%d %d", &row, &col);

    while (row != 0 || col != 0) {
        if (row >= 1 && row <= MAXROW && col >= 1 && col <= MAXCOL)
            map[row][col] = ALIVE;
        else
            printf("Values are not within range.n"); 
        scanf("%d %d", &row, &col);
    }

    while (getchar() != '\n') /* throw out remaining characters */ 
        ;
}

void WriteMap(Grid map) {
    int row, col;
    putchar('\n'); 
    putchar('\n'); 
    for (row=1; row<=MAXROW; row++) {
        for (col=1; col<=MAXCOL; col++) 
            if (map[row][col] == ALIVE)
                putchar('*');
            else
                putchar('-'); 
        putchar('\n'); 
    }
}

void CopyMap(Grid map, Grid newmap) {
    int row, col;
    for (row=0; row<=MAXROW+1; row++) 
        for (col=0; col<=MAXCOL+1; col++) 
            map[row][col] = newmap[row][col];
}

Boolean UserSaysYes(void) {
    int c;
    printf(" (y,n)? ");
    do {
        while ((c = getchar()) == '\n')
            ;
        if (c == 'y' || c == 'Y' || c == 'n' || c == 'N')
            return (c == 'y' || c == 'Y');
        printf("Please respond by typing y or n\n"); 
    } while (1); 
}

void Error(char *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

  
