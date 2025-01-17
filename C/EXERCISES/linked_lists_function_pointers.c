#include <stdio.h>
#include <stdlib.h>

// Function to perform addition
int add(int a, int b)
{
    return a + b;  // Returns the sum of a and b
}

// Function to perform subtraction
int subtract(int a, int b)
{
    return a - b;  // Returns the difference between a and b
}

// Define the structure for a Node in the linked list
typedef struct Node
{
    int data;                  // Integer data stored in the node
    int (*operation)(int, int); // Function pointer to store an operation (e.g., add, subtract)
    struct Node* next;         // Pointer to the next node in the linked list
} Node;

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
    newNode->data = data;                        // Set the data for the new node
    newNode->next = NULL;                         // Set the next pointer to NULL

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the last node in the list
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the last node to the new node
    temp->next = newNode;
}

// Function to delete a node from the linked list by key (data)
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    // If the head node contains the key, remove it
    if (temp != NULL && temp->data == key) {
        *head = temp->next;    // Move the head pointer to the next node
        free(temp);            // Free the memory of the node
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found, exit the function
    if (temp == NULL) return;

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free the memory of the node
}

// Function to print the linked list
void printList(Node* head) {
    // Traverse the list and print each node's data
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");  // Indicate the end of the list
}

int main()
{
    // Create a node and assign an operation to it
    Node* node_1 = (Node*)malloc(sizeof(Node)); // Allocate memory for a node
    node_1->operation = add;  // Assign the 'add' operation to this node

    // Call the operation (addition of 5 and 2)
    printf("Result: %d", node_1->operation(5, 2));  // Should print 7

    return 0;
}