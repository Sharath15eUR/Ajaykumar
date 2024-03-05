/* 
6) Insert value in sorted way in a sorted doubly linked list. 
Given a sorted doubly linked list and a value to insert, 
write a function to insert the value in sorted way.
*/

#include<stdio.h>
#include<stdlib.h>

// Structure of the node with two pointers
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *curr = NULL;

// Function to insert the nodes in sorted order
void insertSorted(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = value;

    // If the list is empty then insert the node first and make it head
    if (head == NULL) {
        head = newNode;
        curr = newNode;
    }
    else {
        /*
            In this funtion we are not traversing from head node each time to insert the newNode in sorted order.
            After inserting a node in the required position we will point the curr pointer to the newly inserted node.
            Next time if we insert a newNode we will not start from the head node instead we will start from the previously inserted node.
            Since it is a doubly linked list we can move on both directions.
        */
        while (curr != NULL) {
            // If only one node is present and value is >= the curr node
            if ((curr->next == NULL) && (newNode->data >= curr->data)) {
                curr->next = newNode;
                newNode->prev = curr;
                curr = newNode;
                break;
            }
            // If only one node is present and value is <= the curr node
            else if ((curr->prev == NULL) && (newNode->data <= curr->data)) {
                curr->prev = newNode;
                newNode->next = curr;
                head = newNode; // head pointer is set to newNode because the node is inserted to the beginning of the list
                curr = newNode;
                break;
            }
            // When 2 or more nodes present and the value is equal
            else if (curr->data == newNode->data) {
                struct node *ptr = curr->next;
                curr->next = newNode;
                newNode->next = ptr;
                newNode->prev = curr;
                ptr->prev = newNode;
                curr = newNode;
                break;
            }
            // if curr node is <= data and data <= next node
            else if ((newNode->data >= curr->data) && (newNode->data <= curr->next->data)) {
                struct node *ptr = curr->next;
                curr->next = newNode;
                newNode->next = ptr;
                newNode->prev = curr;
                ptr->prev = newNode;
                curr = newNode;
                break;
            }
            // if data is <= curr node and data >= previous node
            else if ((newNode->data <= curr->data) && (newNode->data >= curr->prev->data)) {
                struct node *ptr = curr->prev;
                ptr->next = newNode;
                newNode->prev = ptr;
                newNode->next = curr;
                curr->prev = newNode;
                curr = newNode;
                break;
            }
            
            // If the curr node's value is < data then move the curr pointer to next node.
            if (curr->data < newNode->data) {
                curr = curr->next;
            }
            // If the curr node's value is > data then move the curr pointer to previous node.
            else {
                curr = curr->prev;
            }
        } 
    }
}

// Function to print the doubly linkedlist starting from head node.
void printList() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    insertSorted(5);
    insertSorted(3);
    insertSorted(8);
    insertSorted(10);
    insertSorted(12);
    printf("Before inserting 9 : \n");
    printList();
    insertSorted(9);  // 9 is inserted in the sorted linked list
    printf("After inserting 9 : \n");
    printList();
    return 0;
}

/*
OUTPUT:
Before inserting 9 : 
3 5 8 10 12 
After inserting 9 : 
3 5 8 9 10 12 
*/


