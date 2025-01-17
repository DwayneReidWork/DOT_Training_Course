#include "c_linked_list_functions.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createCircularList(int n) {
    if (n <= 0) return NULL;

    Node* head = (Node*)malloc(sizeof(Node));
    Node* temp = head;

    for (int i = 1; i <= n; i++) {
        temp->data = i; // Assign data
        if (i == n) {   // Last node points back to head
            temp->next = head;
        } else {
            temp->next = (Node*)malloc(sizeof(Node));
            temp = temp->next;
        }
    }
    return head;
}

void printCircularList(Node* head, int n) {
    Node* temp = head;
    for (int i = 0; i < n; i++) { // Prevent infinite loops
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("... (back to head)\n");
}

Node* createNodesRecursively(Node* head, int current, int n) {
    if (current > n) return head; // Base case: stop recursion
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = current;

    // Link last node back to head to close the circle
    if (current == n) {
        newNode->next = head; // Circular link
    } else {
        newNode->next = createNodesRecursively(head, current + 1, n);
    }

    return newNode;
}

void traverseCircularList(Node* head, int steps) {
    if (!head) return;

    Node* temp = head;
    for (int i = 0; i < steps; i++) { // Traverses for 'steps' iterations
        printf("Step %d: %d\n", i + 1, temp->data);
        temp = temp->next;
    }
}

Node* findFirstOccurrence(Node* head, int value) {
    if (!head) return NULL;

    Node* temp = head;
    do {
        if (temp->data == value) {
            return temp; // Return node if value is found
        }
        temp = temp->next;
    } while (temp != head);

    return NULL; // Value not found
}

Node* createNode(const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, const char* value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void sortCircularList(Node* head, int (*compare)(const char*, const char*)) {
    if (!head || head->next == head) return;

    int swapped;
    Node* ptr1;
    Node* last = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != last && ptr1->next != head) {
            if (compare(ptr1->data, ptr1->next->data) > 0) {
                // Swap data
                char temp[50];
                strcpy(temp, ptr1->data);
                strcpy(ptr1->data, ptr1->next->data);
                strcpy(ptr1->next->data, temp);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        last = ptr1;
    } while (swapped);
}

int compareStrings(const char* a, const char* b) {
    return strcmp(a, b);
}

Node* deleteNode(Node* head, int key) {
    if (!head) return NULL;

    Node* current = head;
    Node* prev = NULL;

    // Special case: Deleting the head node
    while (current->data != key) {
        if (current->next == head) {
            printf("Value %d not found in the list.\n", key);
            return head; // Value not found
        }
        prev = current;
        current = current->next;
    }

    // If the node to delete is the head
    if (current == head) {
        prev = head;
        while (prev->next != head) {
            prev = prev->next; // Move to the last node
        }
        if (head->next == head) { // Only one node exists
            free(head);
            return NULL;
        }
        prev->next = head->next;
        head = head->next;
        free(current);
    }
    // If the node to delete is not the head
    else {
        prev->next = current->next;
        free(current);
    }

    return head;
}

Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (!head || position == 1) { // Insert at the head
        if (!head) { // List is empty
            newNode->next = newNode;
            return newNode;
        }
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        return newNode; // New head
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node* removeAllNodes(Node* head) {
    if (!head) return NULL;

    Node* current = head;
    Node* temp;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);

    printf("All nodes have been removed.\n");
    return NULL; // Return NULL since the list is now empty
}

void destroyCircularList(Node** headRef) {
    if (!headRef || !(*headRef)) return;

    Node* current = *headRef;
    Node* temp;

    // Free all nodes in a circular manner
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != *headRef);

    *headRef = NULL; // Set head to NULL to indicate destruction
    printf("Circular Linked List has been destroyed.\n");
}