#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Circular Linked List structure
typedef struct
{
    Node *head;
} CircularLinkedList;

// Initialize the circular linked list
void initCircularLinkedList(CircularLinkedList *list)
{
    list->head = NULL;
}

// Add element
void addCircular(CircularLinkedList *list, int element)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = element;

    if (list->head == NULL)
    {
        list->head = new_node;
        new_node->next = new_node;
    }
    else
    {
        Node *current = list->head;

        while (current->next != list->head)
        {
            current = current->next;
        }

        current->next = new_node;
        new_node->next = list->head;
    }
}

// Remove element
void removeCircular(CircularLinkedList *list, int element)
{
    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = list->head;
    Node *prev = NULL;

    do
    {
        if (current->data == element)
        {
            // Only one node
            if (current == list->head && current->next == list->head)
            {
                list->head = NULL;
            }
            // Delete head node
            else if (current == list->head)
            {
                Node *last = list->head;

                while (last->next != list->head)
                {
                    last = last->next;
                }

                last->next = list->head->next;
                list->head = list->head->next;
            }
            // Delete other node
            else
            {
                prev->next = current->next;
            }

            free(current);
            printf("Element %d removed from the list.\n", element);
            return;
        }

        prev = current;
        current = current->next;

    } while (current != list->head);

    printf("Element %d not found.\n", element);
}

// Display list
void displayCircular(CircularLinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = list->head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);

    printf("\n");
}

// Find size
int sizeCircular(CircularLinkedList *list)
{
    if (list->head == NULL)
    {
        return 0;
    }

    int count = 0;
    Node *current = list->head;

    do
    {
        count++;
        current = current->next;
    } while (current != list->head);

    return count;
}

// Main function
int main()
{
    CircularLinkedList list;

    initCircularLinkedList(&list);

    addCircular(&list, 1);
    addCircular(&list, 2);
    addCircular(&list, 3);

    printf("Circular Linked List after adding elements:\n");
    displayCircular(&list);

    removeCircular(&list, 2);

    printf("Circular Linked List after removing element 2:\n");
    displayCircular(&list);

    printf("Size of Circular Linked List: %d\n", sizeCircular(&list));

    return 0;
}
