// 8) Write a C program to Find whether an array is a subset of another array

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main() {
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};

    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);

    bool flag;

    // First for loop is used to traverse the second array
    for (int i = 0; i < len2; i++) {
        flag = false;
        // Second for loop is used to traverse the first array
        for (int j = 0; j < len1; j++) {
            if (arr2[i] == arr1[j]){
                flag = true;
                break;
            }
        }
        // If condition is used to terminate the loop if the value is not present in the first array
        if (flag == false)
            break;
    }

    if (flag == true)
        printf("arr2[] is a subset of arr1[]\n");
    else
        printf("arr2[] is not a subset of arr1[]\n");
    return 0;
}

/*
OUTPUT:
arr2[] is a subset of arr1[]
*/
