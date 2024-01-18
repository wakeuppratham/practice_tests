
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

void initialize(Stack *stack, int initialCapacity) {
    stack->data = (int *)malloc(initialCapacity * sizeof(int));
    stack->top = -1;
    stack->capacity = initialCapacity;
}

void resize(Stack *stack) {
    stack->capacity *= 2;
    stack->data = (int *)realloc(stack->data, stack->capacity * sizeof(int));
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        resize(stack);
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        // printf("Stack underflow.\n");
        return -1; 
    }
    return stack->data[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        // printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

void freeStack(Stack *stack) {
    free(stack->data);
}



typedef struct {
    Stack st1;
    Stack st2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
    initialize(&queue->st1,5);
    initialize(&queue->st2,5);
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->st1.top == obj->st1.capacity - 1) {
        resize(&obj->st1);
    }

    push(&obj->st1, x);
}

int myQueuePop(MyQueue* obj) {
    if (isEmpty(&obj->st2)) { 
        // push elements from stack1 to stack2
        while (!isEmpty(&obj->st1)) {
            push(&obj->st2, pop(&obj->st1));
        }
    }

    if (isEmpty(&obj->st2)) {
        return -1; 
    }

    return pop(&obj->st2);
}


int myQueuePeek(MyQueue* obj) {
    if (isEmpty(&obj->st2)) { 
        // Transfer elements from st1 to st2
        while (!isEmpty(&obj->st1)) {
            push(&obj->st2, pop(&obj->st1));
        }
    }

    if (isEmpty(&obj->st2)) {
        return -1; 
    }
    
    int peekedValue = peek(&obj->st2);

    return peekedValue;
}


bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(&obj->st1) && isEmpty(&obj->st2);
}


void myQueueFree(MyQueue* obj) {
    freeStack(&obj->st1);
    freeStack(&obj->st2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/