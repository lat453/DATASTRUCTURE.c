#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Node {
    char username[50];
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

unsigned int hashFunction(const char *username) {
    unsigned int hash = 0;
    while (*username) {
        hash = (hash * 31) + *username;
        username++;
    }
    return hash % TABLE_SIZE;
}

Node* createNode(const char *username) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->username, username);
    newNode->next = NULL;
    return newNode;
}

int searchUsername(const char *username) {
    unsigned int index = hashFunction(username);
    Node *current = hashTable[index];
    while (current) {
        if (strcmp(current->username, username) == 0) return 1;
        current = current->next;
    }
    return 0;
}

void insertUsername(const char *username) {
    if (searchUsername(username)) {
        printf("Username already exists.\n");
        return;
    }
    unsigned int index = hashFunction(username);
    Node *newNode = createNode(username);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("Username added successfully.\n");
}

void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = hashTable[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of users to register: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char username[50];
        printf("Enter username: ");
        scanf("%s", username);
        insertUsername(username);
    }

    char search[50];
    printf("Enter username to search: ");
    scanf("%s", search);
    if (searchUsername(search)) printf("Username exists.\n");
    else printf("Username not found.\n");

    freeHashTable();
    return 0;
}
