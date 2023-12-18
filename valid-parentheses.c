struct Stack {
    char *arr;
    int top;
    int capacity;
};

void initialize(struct Stack *stack, int initialCapacity) {
    stack->arr = (char *)malloc(initialCapacity * sizeof(char));
    stack->top = -1;
    stack->capacity = initialCapacity;
}

void resize(struct Stack *stack) {
    stack->capacity *= 2;
    stack->arr = (char *)realloc(stack->arr, stack->capacity * sizeof(char));
}

bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, char val) {
    if (stack->top == stack->capacity - 1) {
        resize(stack);
    }
    stack->arr[++stack->top] = val;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->arr[stack->top--];
}

char peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->arr[stack->top];
}

bool isValid(char *s) {
    struct Stack stack;
    initialize(&stack, 10);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(&stack, s[i]);
        } else {
            if (isEmpty(&stack)) {
                return false;
            }
            char top_ch = pop(&stack);
            if ((s[i] == '}' && top_ch != '{') ||
                (s[i] == ')' && top_ch != '(') ||
                (s[i] == ']' && top_ch != '[')) {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}