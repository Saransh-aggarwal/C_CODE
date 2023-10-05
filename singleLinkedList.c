#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtMiddle(int data, int position)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node *temp = head;

    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("invalid");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void printList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
void delete(int key)
{
    struct Node *current = head, *prev = NULL;
    if (current != NULL && current->data == key)
    {
        head = current->next;
        free(current);
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
void reverse()
{
    struct Node *current = head, *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Function to perform Bubble Sort on a linked list
struct Node *bubbleSortLinkedList()
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    int swapped;
    struct Node *current;
    struct Node *temp = NULL;

    do
    {

        swapped = 0;
        current = head;

        while (current->next != temp)
        {
            if (current->data > current->next->data)
            {
                // Swap data
                int tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = 1;
            }

            current = current->next;
        }
        temp = current;

    } while (swapped);
}

int main()
{

    // Insert at the beginning
    insertAtBeginning(10);
    printList();

    // Insert at the middle (position 1)

    insertAtMiddle(20, 1);
    printList();

    // Insert at the end
    insertAtEnd(30);
    printList();

    printf("Reversed!!! \n");
    reverse();
    printList();

    printf("Sorted!!! \n");
    bubbleSortLinkedList();
    printList();
    return 0;
}