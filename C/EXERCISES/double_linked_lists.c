#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

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

void insertAtSpecificPoint(Node** head, int position, int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If inserting at the beginning (position 1)
    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;  // Update head to the new node
        return;
    }

    Node* curr = *head;

    // Traverse to the position where the node should be inserted
    for (int i = 1; i < position - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Out of bounds\n");
        free(newNode);  // Free memory in case of failure
        return;
    }

    // Insert the new node after `curr`
    newNode->next = curr->next;  // New node points to the next node
    if (curr->next != NULL) {
        curr->next->prev = newNode;  // Set the prev pointer of the next node to newNode
    }
    curr->next = newNode;  // Update the current node's next pointer to newNode
    newNode->prev = curr;  // Set the new node's prev pointer to the current node
}  

void deleteNode(Node** head, Node* del) {
    if (*head == NULL || del == NULL) return;
    if (*head == del) *head = del->next;
    if (del->next != NULL) del->next->prev = del->prev;
    if (del->prev != NULL) del->prev->next = del->next;
    free(del);
}

void printList(Node* head) {
    Node* last;
    printf("Traversal in forward direction: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        last = head;
        head = head->next;
    }
    printf("NULL\n");
    printf("Traversal in reverse direction: ");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 30);
    printf("Created Double Linked List:\n");
    printList(head);
    insertAtSpecificPoint(&head, 2, 50);
    printList(head);
    return 0;
}