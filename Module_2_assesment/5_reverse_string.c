// 5) Reverse the given string using stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20

// Declare stack of size 20
char stack[SIZE];
int top = -1;

void push(char letter) {
    if (top == SIZE-1) 
        printf("Stack is full\n");
    else {
        top++;
        stack[top] = letter;
    }
}

char pop() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        char temp = stack[top];
        top--;
        return temp;
    }
}

void reverseString(char arr[], int length) {
    // Push all the elements from array to stack
    for (int i = 0; i < length; i++) {
        push(arr[i]);
    }
    // Pop all the elements back from stack to array
    for (int i = 0; i < length; i++) {
        arr[i] = pop();
    }
}

void printString(char arr[], int length) {
    for (int i = 0 ; i < length; i++) {
        printf("%c",arr[i]);
    }
    printf("\n");
}

int main() {
    char arr[] = "LetsLearn";
    int length = strlen(arr);
    printf("String before reversing :\n");
    printString(arr, length);
    reverseString(arr, length);
    printf("String after reversing :\n");
    printString(arr, length);
    return 0;
}

/*
OUTPUT:
String before reversing :
LetsLearn
String after reversing :
nraeLsteL
*/
