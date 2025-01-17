#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct StackNode {
    void* data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
    int size;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} Stack;

// Function to create a stack with threading support
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    pthread_mutex_init(&stack->mutex, NULL);
    pthread_cond_init(&stack->cond, NULL);
    return stack;
}

// Function to push an item onto the stack
void push(Stack* stack, void* data) {
    pthread_mutex_lock(&stack->mutex); // Lock before modifying the stack
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    printf("Pushed item onto stack. Current size: %d\n", stack->size);
    pthread_cond_signal(&stack->cond); // Signal any waiting threads
    pthread_mutex_unlock(&stack->mutex); // Unlock after modifying the stack
}

// Function to pop an item from the stack (waits if stack is empty)
void* pop(Stack* stack) {
    pthread_mutex_lock(&stack->mutex); // Lock before modifying the stack

    while (stack->size == 0) {
        printf("Stack is empty. Waiting for items...\n");
        pthread_cond_wait(&stack->cond, &stack->mutex); // Wait until a signal is received
    }

    StackNode* temp = stack->top;
    void* data = temp->data;
    stack->top = stack->top->next;
    stack->size--;
    free(temp);
    printf("Popped item. Current size: %d\n", stack->size);

    pthread_mutex_unlock(&stack->mutex); // Unlock after modifying the stack
    return data;
}

// Function to print the stack
void printStack(Stack* stack) {
    pthread_mutex_lock(&stack->mutex);
    StackNode* temp = stack->top;
    printf("Stack contents (top to bottom): ");
    while (temp) {
        printf("%d -> ", *((int*)temp->data)); // Assuming int data
        temp = temp->next;
    }
    printf("NULL\n");
    pthread_mutex_unlock(&stack->mutex);
}

int main() {
    Stack* stack = createStack();

    // Example usage with multiple threads
    int data1 = 10, data2 = 20, data3 = 30;

    // Push items
    push(stack, &data1);
    push(stack, &data2);
    push(stack, &data3);

    // Pop items
    void* item = pop(stack);
    printf("Popped: %d\n", *((int*)item));

    printStack(stack);

    return 0;
}