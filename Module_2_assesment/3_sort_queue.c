// 3) Write a C program to sort the elements of a queue in ascending order.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

// Declaring the queue in an array
int queue[SIZE];
int front = -1, rear = -1;

// Function to add data to the queue
void enqueue(int data) {
    if (rear == SIZE-1) {
        printf("Queue is full\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
    }
}

// Function to remove data from queue
int dequeue() {
    if (front == -1) {
        printf("The queue is empty\n");
    }
    else {
        int temp = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return temp;
    }
}

// Function to print the queue
void printQueue() {
    if (front == -1)
        printf("The queue is empty\n");
    else {
        for (int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Function to sort the queue
void sortQueue() {
    int size = rear-front;
    int temp[size];

    // This loop is used to dequeue(remove) data from 'queue' and add it in the 'temp' array
    for (int i = 0; i <= size; i++) {
        temp[i] = dequeue();
    }

    // Selection sort is used to sort the temp array
    for (int i = 0; i <= size-1; i++) {
        int minIndex = i;
        for (int j = i+1; j <= size; j++) {
            if (temp[i] > temp[j])
                minIndex = j;
        }
        if (minIndex != i) {
            int val = temp[i];
            temp[i] = temp[minIndex];
            temp[minIndex] = val;
        }
    }

    // The elements are added to the queue in sorted order
    for (int i = 0; i <= size; i++) {
        enqueue(temp[i]);
    }

}

int main() {
    enqueue(4);
    enqueue(2);
    enqueue(7);
    enqueue(5);
    enqueue(1);
    printf("Queue before sorting\n");
    printQueue();
    sortQueue();
    printf("Queue after sorting\n");
    printQueue();
    return 0;
}

/*
OUTPUT:
Queue before sorting
4 2 7 5 1 
Queue after sorting
1 2 4 5 7
*/