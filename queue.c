#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void intializeStack(struct Stack *stack);
int isFull(struct Stack *stack);
int isEmpty(struct Stack *stack);
void push(struct Stack *stack, int element);
int pop(struct Stack *stack);
void displayStack(struct Stack *stack);

int main() {
    struct Stack stack;
    int choice, element;

    intializeStack(&stack);   // Corrected

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");   // Corrected
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push:");
                scanf("%d", &element);
                push(&stack, element);
                break;

            case 2:
                element = pop(&stack);
                if (element != -1)
                    printf("Popped element:%d\n", element);
                break;

            case 3:
                displayStack(&stack);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void intializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX - 1;   // Corrected
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;        // Added
}

void push(struct Stack *stack, int element) {
    if (isFull(stack)) {
        printf("Error: Stack overflow. Cannot push element.\n");
        return;
    }

    stack->arr[++stack->top] = element;
    printf("Element pushed:%d\n", element);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow. Cannot pop element.\n");
        return -1;
    }

    return stack->arr[stack->top--];
}

void displayStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements:");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

OUTPUT:
 stack option menu 
1.push
2.pop
3.display
4.display
enter your choice1
enter element to push10
element pushed 10

 stack option menu 
1.push
2.pop
3.display
4.display
enter your choice1
enter element to push20
element pushed 20

 stack option menu 
1.push
2.pop
3.display
4.display
enter your choice2
poped element:20

 stack option menu 
1.push
2.pop
3.display
4.display
enter your choice2
poped element:10

 stack option menu 
1.push
2.pop
3.display
4.display
enter your choice3
stack is empty
 stack option menu 
1.push
2.pop
3.display
4.display
enter your choice3
stack is empty
 stack option menu 
1.push
2.pop
3.display
4.display
enter your choice4
