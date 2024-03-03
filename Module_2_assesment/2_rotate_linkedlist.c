// 2) Write a C program to rotate a doubly linked list by N nodes. 

#include<stdio.h>
#include<stdlib.h>

// Structure of the node
struct node {
    char data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;

// Function to create a new node
struct node* createNode(char value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
// Circular doubly linked list is used
void insertAtEnd(char value) {
    struct node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else {
        struct node *curr = head;

        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = newNode;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = curr;
    }
}

// Function to print the list starting from the head pointer
void printList() {
    struct node *curr = head;
    do
    {
        if (curr->next != head){
            printf("%c->", curr->data);
        }
        else {
            printf("%c", curr->data);
        }
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

// Function to rotate the linked list
void rotateList(struct node **head, int n) {
    if ((head == NULL) || (n == 0)) {
        return;
    }
    // While loop is used to move the head pointer upto 'n' nodes
    // so when printing the list we get the rotated order
    while (n != 0) {
        *head = (*head)->next;
        n--;
    }
}

int main() {
    insertAtEnd('a');
    insertAtEnd('b');
    insertAtEnd('c');
    insertAtEnd('d');
    insertAtEnd('e');
    printf("Before rotating the doubly linked list\n");
    printList();
    int n = 2;
    rotateList(&head, n);
    printf("After rotating the doubly linked list by %d nodes\n", n);
    printList();
    return 0;
}

/*
OUTPUT:
Before rotating the doubly linked list
a->b->c->d->e
After rotating the doubly linked list by 2 nodes
c->d->e->a->b
*/