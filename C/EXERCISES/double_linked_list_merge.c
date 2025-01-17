#include <stdio.h>
#include <stdlib.h>

// Define the Node structure as before
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Insert a node at the front of the list
void insertAtFront(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to merge two sorted doubly linked lists
Node* merge_sorted_list(Node* a, Node* b) {
    Node* result = NULL;

    // Base cases: if either list is empty, return the other list
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }

    // Recursively merge the lists by comparing the data
    if (a->data <= b->data) {
        result = a;
        result->next = merge_sorted_list(a->next, b);  // Recursively merge the rest of list a and list b
        if (result->next != NULL) {
            result->next->prev = result;  // Set the prev pointer of the next node
        }
    } else {
        result = b;
        result->next = merge_sorted_list(a, b->next);  // Recursively merge list a and the rest of list b
        if (result->next != NULL) {
            result->next->prev = result;  // Set the prev pointer of the next node
        }
    }

    return result;
}

// Function to print the list
void printList(Node* head) {
    Node* last;
    printf("Traversal in forward direction: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        last = head;
        head = head->next;
    }
    printf("NULL\n");

    // Print the list in reverse direction
    printf("Traversal in reverse direction: ");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Create the first sorted list: 1 -> 3 -> 5
    insertAtFront(&head1, 5);
    insertAtFront(&head1, 3);
    insertAtFront(&head1, 1);

    // Create the second sorted list: 2 -> 4 -> 6
    insertAtFront(&head2, 6);
    insertAtFront(&head2, 4);
    insertAtFront(&head2, 2);

    printf("First Sorted List:\n");
    printList(head1);

    printf("Second Sorted List:\n");
    printList(head2);

    // Merge the two sorted lists
    Node* mergedHead = merge_sorted_list(head1, head2);

    printf("Merged Sorted List:\n");
    printList(mergedHead);

    return 0;
}