package main

import "fmt"

//
// Knights Tour - walk a knight piece along a solved tour of an 8x8 chessboard.
//
// example usage: 
//     ./KnightsTour | head -8
//
//      0 59 38 33 30 17  8 63
//     37 34 31 60  9 62 29 16
//     58  1 36 39 32 27 18  7
//     35 48 41 26 61 10 15 28
//     42 57  2 49 40 23  6 19
//     47 50 45 54 25 20 11 14
//     56 43 52  3 22 13 24  5
//     51 46 55 44 53  4 21 12
//


// The size of the chessboard is NxN. 
const N = 8

func main() {
    // chessboard of NxN squares
    ar := [N][N]int{}

    // all potential x and y moves 
    xm := []int{ 2, 1, -1, -2, -2, -1,  1,  2 }
    ym := []int{ 1, 2,  2,  1, -1, -2, -2, -1 }

    //
    // Initialize board with values of -1 to denote unvisited squares.
    //
    for i := 0; i<N; i++ {
        for j := 0; j<N; j++ {
            ar[i][j] = -1
        }
    }

    // Mark the starting square, 0,0 as value 0.
    ar[0][0] = 0


    if (walk_board(0, 0, 1, ar, xm, ym) == false) {
        fmt.Printf("No solution.\n")
    } else {
        print_board(ar)
    }
}

//
// walk_board - walk a Knight chess piece on a solved knights
// tour of an 8x8 chessboard
//
func walk_board(x int, y int, m int, ar [N][N]int, xm[] int, ym[] int) (bool) {
    var next_x int
    var next_y int

    if (m == N*N) {
        return true
    }

    for i := 0; i<N; i++ {
        next_x = x + xm[i]
        next_y = y + ym[i]
        if (can_move(next_x, next_y, ar)) {
            ar[next_x][next_y] = m
            if (walk_board(next_x, next_y, m+1, ar, xm, ym) == true) {
                print_board(ar)
                return true
            } else {
                ar[next_x][next_y] = -1
            }
        }
    }
    return false
}

//
// The knight may move only if the target square is set
// back to -1 via backtracking or if the square is unexplored.
//
func can_move(x int, y int, ar [N][N] int) (bool) {
    return(x>=0 && x<N && y>=0 && y<N && ar[x][y] == -1)
}

//
// Print an NxN chessboard. 
//
func print_board(ar [N][N]int) {
    for i := 0; i<N; i++ {
        for j := 0; j<N; j++ {
            if (i%2==j%2) {
                fmt.Printf("\u001b[7m")
            }
            fmt.Printf("%3d", ar[i][j])
            fmt.Printf("\u001b[0m")
        }
        fmt.Printf("\n")
    }
}
