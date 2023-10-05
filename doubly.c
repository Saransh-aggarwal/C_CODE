#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;  // Pointer to the first node in the doubly linked list

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertNodeAtBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to insert a node at the middle of the doubly linked list
void insertNodeAtMiddle(int data, int position) {
    struct Node* newNode = createNode(data);

    if (position <= 0) {
        printf("Invalid position for insertion.\n");
        free(newNode);
        return;
    }

    if (head == NULL && position == 1) {
        head = newNode;
        return;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position for insertion.\n");
        free(newNode);
        return;
    }

    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertNodeAtEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        newNode->prev = current;
        current->next = newNode;
    }
}

// Function to print the doubly linked list
void printList() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void delete(int key)
{
    struct Node *current = head, *prev = NULL;
 
    while (current != NULL && current->data != key)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Node with key %d not found.\n", key);
        return;
    }
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }
    
    
    free(current);
}

int main() {
    // Insert nodes at the beginning
    insertNodeAtBeginning(10);
    insertNodeAtBeginning(20);
    insertNodeAtBeginning(30);

    // Print the doubly linked list
    printf("Doubly Linked List after insert at beginning:\n");
    printList();

    // Insert node at the middle (position 2)
    insertNodeAtMiddle(25, 2);

    // Print the doubly linked list
    printf("\nDoubly Linked List after insert at middle:\n");
    printList();

    // Insert node at the end
    insertNodeAtEnd(40);

    // Print the doubly linked list
    printf("\nDoubly Linked List after insert at end:\n");
    printList();
    
    delete(25);
    printList();

    return 0;
}
