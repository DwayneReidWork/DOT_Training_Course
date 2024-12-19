//#include "stack_functions.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5 // See usage with pushWithLimit()

typedef struct StackNode 
{
    void* data;
    struct StackNode* next;
} StackNode;

typedef struct Stack 
{
    StackNode* top;
    int size;
} Stack;

// Creates an empty stack
Stack* createStack() 
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Checks if given stack is empty
int isStackEmpty(Stack* stack) 
{
    return stack->size == 0;
}

// Function to check if the stack is full
int isStackFull(Stack* stack) 
{
    return stack->size >= MAX_STACK_SIZE;
}

// Adds a new node to the top of the stack
void push(Stack* stack, void* data) 
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));

    newNode->data = data;
    newNode->next = stack->top; // Fills in ->next to be the previous top address
    // This ensures proper linking to the next node down the stack

    stack->top = newNode; // Reassigns top of stack to newNode address
    stack->size++;

    printf("Pushed item onto stack. Current size: %d\n", stack->size);
}

// Function to push an item onto the stack with overrun prevention
void pushWithLimit(Stack* stack, void* data) 
{
    if (isStackFull(stack)) 
    {
        printf("Stack overrun prevented! Cannot push item. Current size: %d\n", stack->size);
        return;
    }

    // Note that this code can be replaced with push()
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    printf("Pushed item onto stack. Current size: %d\n", stack->size);
}

// Function to pop a single item from the stack
void* pop(Stack* stack) 
{
    if (!stack->top) 
    {
        printf("Stack is empty. Nothing to pop.\n");
        return NULL;
    }
    
    // Isolate the top node in preparation for deletion
    StackNode* temp = stack->top;

    // Retrieve data from top node
    void* data = temp->data;

    // Retrieve the address of the next node in the stack (node beneath top)
    stack->top = stack->top->next;
    stack->size--;

    // Free the node and return the data
    free(temp);
    return data;
}

// Function to pop `n` items from the stack
void popMultiple(Stack* stack, int n) 
{
    printf("Attempting to pop %d items from the stack...\n", n);
    for (int i = 0; i < n; i++) 
    {
        // pop() returns memory address of the data
        void* data = pop(stack);
        if (!data) 
        {
            printf("Stopped at item %d: Stack is empty.\n", i + 1);
            break;
        } 
        else 
        {
            printf("Popped item: %d\n", *((int*)data)); // Assuming int data
        }
    }
    printf("Remaining stack size: %d\n", stack->size);
}

// Function to remove all items from the stack
void clearStack(Stack* stack) 
{
    printf("Clearing the stack...\n");
    while (stack->top) 
    {
        void* data = pop(stack);
        if (data) {
            printf("Removed item: %d\n", *((int*)data)); // Assuming int data
        }
    }
    printf("Stack cleared. Current size: %d\n", stack->size);
}

// Function to destroy the stack
//double pointer is for pointing to the pointer that is pointing to the stack!
void destroyStack(Stack** stackRef) 
{
    if (!stackRef || !(*stackRef)) return;

    printf("Destroying the stack...\n");

    // Clear all items
    Stack* stack = *stackRef;
    while (stack->top) 
    {
        pop(stack); // Remove each node
    }

    // Free the stack itself
    free(stack);
    *stackRef = NULL;

    printf("Stack destroyed.\n");
}

// Function to print stack details for debugging
void printStackDetails(Stack* stack) 
{
    printf("Stack Size: %d\n", stack->size);
    printf("Stack Top: %p\n", (void*)stack->top);
}