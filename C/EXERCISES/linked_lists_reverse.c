#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node in the linked list
typedef struct Node 
{
    int data;              // Data part of the node
    struct Node* next;     // Pointer to the next node in the list
} Node;

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = data;                        // Assign the data to the new node
    newNode->next = NULL;                        // Set the next pointer of the new node to NULL

    if (*head == NULL) {                         // Check if the list is empty
        *head = newNode;                         // Make the new node the head of the list
        return;
    }

    Node* temp = *head;                          // Temporary pointer to traverse the list
    while (temp->next != NULL) {                 // Traverse to the last node in the list
        temp = temp->next;
    }
    temp->next = newNode;                        // Link the last node to the new node
}

// Function to print the linked list
void printList(Node* head) 
{
    while (head != NULL) {                       // Traverse the list
        printf("%d -> ", head->data);            // Print the data of each node
        head = head->next;
    }
    printf("NULL\n");                            // Indicate the end of the list
}

void reverseList(Node** head)
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to reverse the linked list
Node* reverse(Node* head) {
    Node* prev = NULL;           // Initialize the previous pointer to NULL
    Node* curr = head;    // Set the current pointer to the head of the list

    // Traverse the list until the current pointer is NULL
    while (curr != NULL) {  
        Node* next = curr->next; // Store the next node
        curr->next = prev;      // Reverse the current node's pointer
        prev = curr;           // Move the previous pointer forward
        curr = next;          // Move the current pointer forward
    }

    return prev;  // Return the new head of the reversed list
}

int main() 
{
    Node* head = NULL;                           // Initialize the head of the linked list to NULL

    // Insert elements into the linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // // Print the original linked list
    // printf("Linked List: ");
    // printList(head);

    // // Reverse the linked list
    // head = reverse(head);

    // // Print the reversed linked list
    // printf("Reversed Linked List: ");
    // printList(head);

    reverseList(&head);
    printList(head);
    return 0;
}
