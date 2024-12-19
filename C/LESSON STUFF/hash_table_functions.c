//#include "hash_table_functions.h"
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct HashNode 
{
    // void* pointer allows storage of any data because its pointing to a memory address
    void* key;
    void* value; // be careful recalling though!
    struct HashNode* next;
} HashNode;

typedef struct HashTable 
{
    HashNode* table[TABLE_SIZE];
} HashTable;


unsigned int hashFunction(int key) 
{
    return key % TABLE_SIZE;
}

HashTable* createHashTable() 
{
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        // Set each bucket entry to NULL
        ht->table[i] = NULL;
    }
    return ht;
}

void insertItems(HashTable* ht, int keys[], int values[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        unsigned int index = hashFunction(keys[i]);

        // Create a new node
        HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
        newNode->key = malloc(sizeof(int));
        //int pointer below points to key needs to be type cast to an int but then has to be dereferenced now that it has a value. [note the double parens]
        *((int*)newNode->key) = keys[i];
        newNode->value = malloc(sizeof(int));
        *((int*)newNode->value) = values[i];
        newNode->next = NULL;

        // Insert into hash table using chaining
        if (!ht->table[index]) 
        {
            ht->table[index] = newNode;
        } 
        else 
        {
            HashNode* temp = ht->table[index];
            while (temp->next) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insertItem(HashTable* ht, int key, int value) 
{
    unsigned int index = hashFunction(key);

    // Create a new node
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = malloc(sizeof(int));
    *((int*)newNode->key) = key;
    newNode->value = malloc(sizeof(int));
    *((int*)newNode->value) = value;
    newNode->next = NULL;

    // Insert into hash table
    if (!ht->table[index]) 
    {
        ht->table[index] = newNode;
    } else {
        HashNode* temp = ht->table[index];
        while (temp->next) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Key %d with value %d inserted successfully.\n", key, value);
}

void insertItemLinearProbing(HashTable* ht, int key, int value) 
{
    unsigned int index = hashFunction(key);

    // Use linear probing to find the next free value
    while (ht->table[index] != NULL) 
    {
        index = (index + 1) % TABLE_SIZE;
    }

    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = malloc(sizeof(int));
    *((int*)newNode->key) = key;
    newNode->value = malloc(sizeof(int));
    *((int*)newNode->value) = value;
    newNode->next = NULL;

    ht->table[index] = newNode;
    printf("Key %d with value %d inserted at index %d using linear probing.\n", key, value, index);
}

HashNode* findNthItem(HashTable* ht, int n) 
{
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        HashNode* temp = ht->table[i];
        while (temp) 
        {
            // Note the pre-increment
            if (++count == n) 
            {
                return temp; // Return the nth item
            }
            temp = temp->next;
        }
    }
    return NULL; // nth item not found
}

HashNode* findItem(HashTable* ht, int key) //by key
{
    unsigned int index = hashFunction(key);

    HashNode* temp = ht->table[index];
    while (temp) 
    {
        if (*((int*)temp->key) == key) 
        {
            return temp; // Key found
        }
        temp = temp->next;
    }
    return NULL; // Key not found
}

void removeItem(HashTable* ht, int key) //by key
{
    unsigned int index = hashFunction(key);

    HashNode* temp = ht->table[index];
    HashNode* prev = NULL;

    // Traverse linked list at this index
    while (temp) 
    {
        if (*((int*)temp->key) == key) 
        {
            // Remove the node
            if (prev) 
            {
                prev->next = temp->next;
            } else 
            {
                ht->table[index] = temp->next; // Head node removed
            }
            free(temp->key);
            free(temp->value);
            free(temp);
            printf("Key %d removed successfully.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found in the table.\n", key);
}

void removeAllItems(HashTable* ht) 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        HashNode* temp = ht->table[i];
        while (temp) {
            HashNode* toDelete = temp;
            temp = temp->next;

            free(toDelete->key);
            free(toDelete->value);
            free(toDelete);
        }
        ht->table[i] = NULL;
    }
    printf("All items have been removed from the hash table.\n");
}

void printHashTable(HashTable* ht) 
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Index %d: ", i);
        HashNode* temp = ht->table[i];
        while (temp) 
        {
            printf("(%d, %d) -> ", *((int*)temp->key), *((int*)temp->value));
            temp = temp->next;
        }
        printf("NULL\n");
    }
}