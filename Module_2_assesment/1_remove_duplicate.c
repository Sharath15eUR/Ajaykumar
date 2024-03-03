/*
Write a C program to remove duplicate element from sorted Linked List. 
Input: 
2 -> 3 -> 3 -> 4 
Output: 
2 -> 3 -> 4
*/

#include<stdio.h>
#include<stdlib.h>

// Structure of the node
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

// Function to create a new node
struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = value;
    return newNode;
}

// Function to insert the node to the end of the linkedlist
void insertAtEnd(int value) {
    struct node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Function to print the linkedlist
void printList() {
    struct node *curr = head;
    while (curr) {
        if (curr->next != NULL){
            printf("%d->",curr->data);
        }
        else {
            printf("%d\n",curr->data);
        }
        curr = curr->next;
    }
}

// Function to remove duplicate nodes from the linked list
void removeDuplicates(struct node **head) {
    struct node *curr = *head;
    while (curr->next != NULL) {
        // If the current node value and next node value is different move the pointer to next node
        if (curr->data != curr->next->data) {
            curr = curr->next;
        }
        // If the nodes values are same then remove the next node from the list
        else {
            struct node *temp = curr->next;
            curr->next = temp->next;
            temp->next = NULL;
            // Free the memory of the removed node
            free(temp);
        }
    }
}

int main() {
    insertAtEnd(2);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(3);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    printf("Before removing duplicates\n");
    printList();
    printf("After removing duplicates\n");
    removeDuplicates(&head);
    printList();
    return 0;
}

/*
OUTPUT:
Before removing duplicates
2->2->3->3->3->4->5
After removing duplicates
2->3->4->5
*/