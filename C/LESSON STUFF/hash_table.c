#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

unsigned int hashFunction(char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key;
        key++;
    }
    return hash % TABLE_SIZE;
}

void insert(HashTable* ht, char* key, int value) {
    unsigned int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int search(HashTable* ht, char* key) {
    unsigned int index = hashFunction(key);
    Node* temp = ht->table[index];
    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Not found
}

void deleteKey(HashTable* ht, char* key) {
    unsigned int index = hashFunction(key);
    Node* temp = ht->table[index];
    Node* prev = NULL;
    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                ht->table[index] = temp->next;
            }
            free(temp->key);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = ht->table[i];
        while (temp) {
            printf("(%s, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    HashTable ht = {0};
    insert(&ht, "apple", 10);
    insert(&ht, "banana", 20);
    insert(&ht, "orange", 30);

    printf("Hash Table:\n");
    printHashTable(&ht);

    printf("Value for 'apple': %d\n", search(&ht, "apple"));
    deleteKey(&ht, "banana");
    printf("After Deleting 'banana':\n");
    printHashTable(&ht);

    return 0;
}