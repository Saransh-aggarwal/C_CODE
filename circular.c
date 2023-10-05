#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertNodeAtBeginning(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        struct Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        newNode->next = head;
        current->next = newNode;
        head = newNode;
    }
}
void insertNodeAtMiddle(int data, int position)
{
    struct Node *newNode = createNode(data);

    if (position <= 0)
    {
        printf("Invalid position for insertion.\n");
        free(newNode);
        return;
    }
    if (head == NULL && position == 1)
    {
        head = newNode;
        head->next = head;
        return;
    }
    struct Node *temp = head;

    for (int i = 0; i < position - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertNodeAtEnd(int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }
    else
    {

        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void printList()
{
    struct Node *current = head;
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

void deleteNode(int key)
{
    struct Node *current = head, *prev = NULL;
    if (current != NULL && current->data == key)
    {

        if (current->next == head)
        {

            free(current);
            head = NULL;
        }
        else
        {
            // If there are multiple nodes, update the head and unlink the node
            struct Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = current->next;
            head = current->next;
            free(current);
        }

        return;
    }
    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Node with key %d not found.\n", key);
        return;
    }
    prev->next = current->next;
    free(current);
}
int main()
{
    // Insert nodes at the beginning
    insertNodeAtBeginning(10);
    insertNodeAtBeginning(20);
    insertNodeAtBeginning(30);

    // Print the circular linked list
    printf("Circular Linked List after insert at beginning:\n");
    printList();

    // Insert node at the middle (position 2)
    insertNodeAtMiddle(25, 2);

    // Print the circular linked list
    printf("\nCircular Linked List after insert at middle:\n");
    printList();

    // Insert node at the end
    insertNodeAtEnd(40);

    // Print the circular linked list
    printf("\nCircular Linked List after insert at end:\n");
    printList();

    return 0;
}