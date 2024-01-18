#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int *arr;
    int top;
    int capacity;
};

void initialize(struct Stack *stack, int initialCapacity) {
    stack->arr = (int*)malloc(initialCapacity * sizeof(int));
    stack->top = -1;
    stack->capacity = initialCapacity;
}

void resize(struct Stack *stack) {
    stack->capacity *= 2;
    stack->arr = (int*)realloc(stack->arr, stack->capacity * sizeof(int));
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1; // returns 1 or 0
}

void push(struct Stack *stack, int val) {
    if (stack->top == stack->capacity - 1) {
        resize(stack);
    }
    stack->arr[++stack->top] = val;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; 
    }
    return stack->arr[stack->top];
}

int main() {
    struct Stack stack;
    initialize(&stack, 5);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Top element: %d\n", peek(&stack));

    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    free(stack.arr); // Free the memory

    return 0;
}
