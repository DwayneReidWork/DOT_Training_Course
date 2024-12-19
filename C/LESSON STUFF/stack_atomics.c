#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>

typedef struct StackNode {
    void* data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    _Atomic(StackNode*) top; // Atomic top pointer
    _Atomic int size;        // Atomic size counter
} Stack;

// Function to create a stack with atomic variables
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    atomic_store(&stack->top, NULL);
    atomic_store(&stack->size, 0);
    return stack;
}

// Function to push an item onto the stack
void push(Stack* stack, void* data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;

    StackNode* currentTop;
    do {
        currentTop = atomic_load(&stack->top); // Load current top atomically
        newNode->next = currentTop;           // Point new node to current top
    } while (!atomic_compare_exchange_weak(&stack->top, &currentTop, newNode)); // CAS operation

    atomic_fetch_add(&stack->size, 1); // Atomically increment size
    printf("Pushed item onto stack. Current size: %d\n", atomic_load(&stack->size));
}

// Function to pop an item from the stack
void* pop(Stack* stack) {
    StackNode* currentTop;
    StackNode* nextTop;

    do {
        currentTop = atomic_load(&stack->top); // Load current top atomically
        if (!currentTop) {
            printf("Stack is empty. Nothing to pop.\n");
            return NULL;
        }
        nextTop = currentTop->next; // Set the next node as the new top
    } while (!atomic_compare_exchange_weak(&stack->top, &currentTop, nextTop)); // CAS operation

    void* data = currentTop->data;
    free(currentTop);
    atomic_fetch_sub(&stack->size, 1); // Atomically decrement size
    printf("Popped item. Current size: %d\n", atomic_load(&stack->size));
    return data;
}

// Function to print the stack
void printStack(Stack* stack) {
    StackNode* temp = atomic_load(&stack->top);
    printf("Stack contents (top to bottom): ");
    while (temp) {
        printf("%d -> ", *((int*)temp->data)); // Assuming int data
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Stack* stack = createStack();

    // Push items
    int data1 = 10, data2 = 20, data3 = 30;
    push(stack, &data1);
    push(stack, &data2);
    push(stack, &data3);

    // Pop items
    void* item = pop(stack);
    printf("Popped: %d\n", *((int*)item));

    printStack(stack);

    return 0;
}