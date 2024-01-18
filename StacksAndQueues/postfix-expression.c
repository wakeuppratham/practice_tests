#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack {
    int *arr;
    int top;
    int capacity;
};

void initialize(struct Stack *stack, int initialCapacity) {
    stack->arr = (int *)malloc(initialCapacity * sizeof(int));
    stack->top = -1;
    stack->capacity = initialCapacity;
}

void resize(struct Stack *stack) {
    stack->capacity *= 2;
    stack->arr = (int *)realloc(stack->arr, stack->capacity * sizeof(int));
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int val) {
    if (stack->top == stack->capacity - 1) {
        resize(stack);
    }
    stack->arr[++stack->top] = val;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top--];
}

int isNumeric(char ch) {
    return isdigit(ch);
}

int evaluatePostfix(struct Stack *st, char *str) {
    int i = 0;

    while (str[i] != '\0' && str[i] != '?') {
        char currentChar = str[i];

        if (isNumeric(currentChar)) {
            int operand = 0;
            while (isNumeric(str[i])) {
                operand = operand * 10 + (str[i] - '0');
                i++;
            }
            push(st, operand);
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            int operand2 = pop(st);
            int operand1 = pop(st);

            switch (currentChar) {
                case '+':
                    push(st, operand1 + operand2);
                    break;
                case '-':
                    push(st, operand1 - operand2);
                    break;
                case '*':
                    push(st, operand1 * operand2);
                    break;
                case '/':
                    push(st, operand1 / operand2);
                    break;
                default:
                    exit(EXIT_FAILURE);
            }

            i++;
        } else {
            i++;
        }
    }

    return pop(st);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char str[100];
        scanf(" %[^\n]", str); // to read spaces too

        struct Stack st;
        initialize(&st, 10);

        int result = evaluatePostfix(&st, str);
        printf("%d\n", result);

        free(st.arr);
    }

    return 0;
}
