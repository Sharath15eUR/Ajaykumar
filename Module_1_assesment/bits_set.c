//2. Write a C program to count the number of bits set in a number.
#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, bitCount = 0;
    printf("Enter a number : ");
    scanf("%d",&n);
    
    // Bitwise RIGHT SHIFT, AND operator is used for solving this problem
    // The for loop repeats for 32 times because the size of an integer is 4 bytes (32-bits)
    for (int i = 0; i < 32; i++) {
        // This if condition is used to find whether the LSB is set to 1
        if (((n >> i) & 1) == 1) {
            // If the LSB is 1 then increase the bitCount
            bitCount++;
        }
    }
    printf("Count of set bits for %d = %d", n, bitCount);
    return 0;
}
