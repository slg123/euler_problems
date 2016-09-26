#include <cstdlib>
#include <ctime>
#include <iostream>


long long rowSumMatrix(long long ar[6][6]) {
    long long sum = 0;
    for (long long r = 0; r < 6; r++) {
        for (long long c = 0; c < 6; c++) {
            sum += ar[r][c];
        }
    
    }
    return sum;
}

long long colSumMatrix(long long ar[6][6]) {
    long long sum = 0;
    for (long long c = 0; c < 6; c++) {
        for (long long r = 0; r < 6; r++) {
            sum += ar[r][c];
        }
    }
    return sum;
}

long long ullrand() {
    unsigned long long rand1 = abs(rand());
    unsigned long long rand2 = abs(rand());
    rand1 = rand1 << (sizeof(int)*8);
    unsigned long long randULL = (rand1 | rand2);
    return randULL/10; // do this else number is too large to sum for std long long type
}
    

int main() {

    std::cout << ullrand() << std::endl;

    long long NMSECS = 100000000;

    long long m[6][6] = {}; 

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            m[i][j] = ullrand(); 
        }
    }

    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }

    /*long long m[6][6] = 
    {
        { 30000000, 300000000, 2, 9, 6, 22 },
        { 99999999, 9, 9, 9, 9, 9, }, 
        { 9, 9, 9, 9, 9,  9 }, 
        { 8, 9, 9, 9, 9,  9 }, 
        { 9, 9, 9, 9, 9,  9 }, 
        { 6, 9, 9, 9, 9,  9 } 
    };*/

    //
    //  row order
    //
    std::cout << "testing " << NMSECS << " row order sums: " << std::endl; 

    std::clock_t start;
    start = std::clock();

    for (long long i = 0; i < NMSECS; i++) {
        rowSumMatrix(m);
    }
    std::cout << NMSECS << " row order sums completed in : " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) 
        << " milliseconds." << std::endl;

    //
    // column order
    //
    std::cout << "testing " << NMSECS << " column order sums: " << std::endl; 

    std::clock_t start_col;
    start_col = std::clock();

    for (long long i = 0; i < NMSECS; i++) {
        colSumMatrix(m);
    }
    std::cout << NMSECS << " column order sums completed in : " << (std::clock() - start_col) / (double)(CLOCKS_PER_SEC / 1000) 
        << " milliseconds." << std::endl;

    std::cout << "row    major order sum: " << rowSumMatrix(m) << std::endl;
    std::cout << "column major order sum: " << colSumMatrix(m) << std::endl;

    return 0;
}
