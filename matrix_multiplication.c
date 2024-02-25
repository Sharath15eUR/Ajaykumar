// 5) Write a C program to Multiply two matrix (n*n) using pointers. 

#include <stdio.h>
#include <stdlib.h>

int main() {
    int  i, j, k, row = 3, col = 3;
    int matrix1[3][3] = {
            {2,3,4},
            {5,6,7},
            {8,9,1}
        };
    
    int matrix2[3][3] = {
            {9,8,7},
            {6,5,4},
            {3,2,1}
        };
    int result[3][3] = {0};

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            for (k = 0; k < col; k++) {
                // Pointer expression for multiplying the matrices
                *(*(result+i)+j) += (*(*(matrix1 + i) + k)) * (*(*(matrix2 + k) + j));
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(*(result+i)+j));
        }
        printf("\n");
    }
    return 0;
}
