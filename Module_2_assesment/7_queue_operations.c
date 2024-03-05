// 7) Write a C program to insert/delete and count the number of elements in a queue.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

// Declare queue of size 20
int queue[SIZE];
int front = -1;
int rear = -1;

// Function to add elements to the queue
void enqueue(int value) {
    if (rear == SIZE-1) {
        printf("The queue is full\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

// Function to remove elements from the queue
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

// Function to check if queue is empty or not
void isEmpty() {
    (front == -1) ? printf("Yes\n") : printf("No\n");
}

// Function to check if queue is full or not
void isFull() {
    (rear == SIZE-1) ? printf("Yes\n") : printf("No\n");
}

// Function to check the number of elements present in the queue
int numberOfElements() {
    if (front == -1)
        return 0;
    return rear-front+1;
}

// Function to display the elements present in the queue
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printf("initialize a queue!\n");
    printf("Check the queue is empty or not ? ");
    isEmpty();
    printf("Number of elements in queue : %d\n", numberOfElements());
    printf("insert some elements into the queue :\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("Queue elements are : ");
    display();
    printf("Number of elements in queue : %d\n",numberOfElements());
    printf("Delete two elements from the said queue :\n");
    dequeue();
    dequeue();
    printf("Queue elements are : ");
    display();
    printf("Number of elements in queue : %d\n",numberOfElements());
    printf("Insert another element into the queue :\n");
    enqueue(4);
    printf("Queue elements are : ");
    display();
    printf("Number of elements in queue : %d\n",numberOfElements());
    return 0;
}

/*
OUTPUT:
initialize a queue!
Check the queue is empty or not ? Yes
Number of elements in queue : 0
insert some elements into the queue :
Queue elements are : 1 2 3
Number of elements in queue : 3
Delete two elements from the said queue :     
Queue elements are : 3
Number of elements in queue : 1
Insert another element into the queue :       
Queue elements are : 3 4
Number of elements in queue : 2
*/

