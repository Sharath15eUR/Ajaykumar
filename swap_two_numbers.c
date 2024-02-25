// 3) Write a C program to swap two numbers. Use a function pointer to do this operation. 
#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int num1 = 84, num2 = 25;

    // Define a function pointer and point it to the swap function
    void (*ptr)(int *, int *);
    ptr = swap;

    // Call the function using function pointer
    ptr(&num1, &num2);

    printf("Output after swapping : ");
    printf("%d %d\n", num1, num2);

    return 0;
}

// Function to swap two integers
void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
