// 1. Write a C program to determine the given number is odd or even using Bitwise operators. 
#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    /*
    The bitwise AND operator is used to find whether the number is odd or even.
    5 = 0 1 0 1
    1 = 0 0 0 1
    & = 0 0 0 1 => 1 (therefore the number is odd) 

    6 = 0 1 1 0
    1 = 0 0 0 1
    & = 0 0 0 0 => 0 (therefore the number is even)
    */
    if ((n&1) == 0) {
        printf("The number is EVEN");
    }
    else {
        printf("The number is ODD");
    }

    return 0;
}

