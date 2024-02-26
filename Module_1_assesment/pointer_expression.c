// 4) Write an equivalent pointer expression for fetching the value of array element a[i][j][k][2]
#include <stdio.h>

int main() {
    // 4-D array declaration and initialization
    int a[1][2][4][5] = {
        {
            {
                {0, 1, 2, 3, 4},
                {5, 6, 7, 8, 9},
                {10, 11, 12, 13, 14},
                {15, 16, 17, 18, 19}
            }
        }
    };

    int i = 0, j = 0, k = 3;
    // Accessing the value of array element a[i][j][k][2] using pointer arithmetic
    int value = *(*(*(*(a + i) + j) + k) + 2);
    printf("Value of a[%d][%d][%d][2]: %d\n", i, j, k, value);
    return 0;
}
