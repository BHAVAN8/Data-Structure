#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function Prototypes
struct Node *createNode(int data);
void insertAtEnd(struct Node **head, int data);
void insertAtPosition(struct Node **head, int data, int position);
int searchElement(struct Node *head, int data);
void deleteElement(struct Node **head, int position);
void displayList(struct Node *head);

int main()
{
    struct Node *head = NULL;
    int choice, data, position, result;

    while (1)
    {
        printf("\n===== Singly Linked List Operations =====\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Position\n");
        printf("3. Search Element\n");
        printf("4. Delete Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;

        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position (0-based index): ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;

        case 3:
            printf("Enter element to search: ");
            scanf("%d", &data);
            result = searchElement(head, data);

            if (result != -1)
                printf("Element found at position %d\n", result);
            else
                printf("Element not found.\n");
            break;

        case 4:
            printf("Enter position to delete (0-based index): ");
            scanf("%d", &position);
            deleteElement(&head, position);
            break;

        case 5:
            displayList(head);
            break;

        case 6:
        {
            struct Node *temp;
            while (head != NULL)
            {
                temp = head;
                head = head->next;
                free(temp);
            }
            printf("Exiting...\n");
            return 0;
        }

        default:
            printf("Invalid choice!\n");
        }
    }
}

// Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert at end
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at position
void insertAtPosition(struct Node **head, int data, int position)
{
    if (position < 0)
    {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = createNode(data);

    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Search element
int searchElement(struct Node *head, int data)
{
    int position = 0;

    while (head != NULL)
    {
        if (head->data == data)
            return position;

        head = head->next;
        position++;
    }

    return -1;
}

// Delete element
void deleteElement(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (position < 0)
    {
        printf("Invalid position.\n");
        return;
    }

    struct Node *temp = *head;

    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        printf("Element deleted successfully.\n");
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    printf("Element deleted successfully.\n");
}

// Display list
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
    OUTPUT:
    ===== Singly Linked List =====
1. Insert at End
2. Insert at Position
3. Search Element
4. Delete Element
5. Display List
6. Exit
Enter your choice: 1
Enter value: 10
Node inserted successfully.

===== Singly Linked List =====
1. Insert at End
2. Insert at Position
3. Search Element
4. Delete Element
5. Display List
6. Exit
Enter your choice: 2
Enter value: 20
Enter position: 1
Node inserted successfully.

===== Singly Linked List =====
1. Insert at End
2. Insert at Position
3. Search Element
4. Delete Element
5. Display List
6. Exit
Enter your choice: 3
Enter element to search: 20
Element found at position 1

===== Singly Linked List =====
1. Insert at End
2. Insert at Position
3. Search Element
4. Delete Element
5. Display List
6. Exit
Enter your choice: 4
Enter element to delete: 1
Element not found.

===== Singly Linked List =====
1. Insert at End
2. Insert at Position
3. Search Element
4. Delete Element
5. Display List
6. Exit
Enter your choice: 5
Linked List: 20 -> 10 -> 20 -> NULL

===== Singly Linked List =====
1. Insert at End
2. Insert at Position
3. Search Element
4. Delete Element
5. Display List
6. Exit
Enter your choice: 6
Exiting program...



