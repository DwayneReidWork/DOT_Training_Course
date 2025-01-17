#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node in the linked list
typedef struct Node 
{
    int data;              // Data part of the node
    struct Node* next;     // Pointer to the next node
} Node;

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    // Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = data;                        // Set the data for the new node
    newNode->next = NULL;                        // Initialize the next pointer to NULL

    // If the list is empty, make the new node the head
    if (*head == NULL) {                         
        *head = newNode;                         
        return;
    }

    // Temporary pointer to traverse the list and find the last node
    Node* temp = *head;                          
    while (temp->next != NULL) {                 // Traverse to the last node
        temp = temp->next;
    }
    // Link the last node to the new node
    temp->next = newNode;                        
}

// Function to print the linked list
void printList(Node* head) 
{
    while (head != NULL) {                       // Traverse the list
        printf("%d -> ", head->data);            // Print the data of each node
        head = head->next;                       // Move to the next node
    }
    printf("NULL\n");                            // Indicate the end of the list
}

// Function to find the middle node using slow and fast pointers
Node* findMiddle2Ptrs(Node* head)
{
    Node* slow = head;  // Slow pointer initialized to head
    Node* fast = head;  // Fast pointer initialized to head
    while (fast != NULL && fast->next != NULL)  // Continue while fast and fast->next are not NULL
    {
        slow = slow->next;           // Move slow by 1 step
        fast = fast->next->next;     // Move fast by 2 steps
    }
    return slow;  // Return the middle node (slow pointer)
}

// Function to find the middle element of the linked list using a counter
int findMiddle(Node* head)
{
    int counter = 0;                             // Counter to count the number of nodes
    Node* temp = head;                           // Temporary pointer for traversal

    // Traverse the list to count the total number of nodes
    while (head != NULL) {                       
        counter++;
        head = head->next;
    }

    // Traverse to the middle node based on the counter value
    for (int i = 0; i < counter / 2; i++) {      // Traverse to the middle node
        temp = temp->next;
    }
    return temp->data;                           // Return the data of the middle node
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
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Find and print the middle element of the linked list using the counter method
    printf("Middle of Linked List (counter method): ");
    printf("%d\n", findMiddle(head));

    // Find and print the middle element using slow/fast pointer method
    printf("Middle of linked list (slow/fast pointer): ");
    Node* middle2Ptrs = findMiddle2Ptrs(head); 
    printf("%d", middle2Ptrs->data);             // Print the data of the middle node

    return 0;
}