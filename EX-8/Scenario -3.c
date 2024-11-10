#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Article {
    char title[100];
    char content[500];
    struct Article *next;
} Article;

Article *hashTable[TABLE_SIZE];

unsigned int hashFunction(const char *title) {
    unsigned int hash = 0;
    while (*title) {
        hash = (hash * 31) + *title;
        title++;
    }
    return hash % TABLE_SIZE;
}

Article* createArticle(const char *title, const char *content) {
    Article *newArticle = (Article *)malloc(sizeof(Article));
    strcpy(newArticle->title, title);
    strcpy(newArticle->content, content);
    newArticle->next = NULL;
    return newArticle;
}

void insertArticle(const char *title, const char *content) {
    unsigned int index = hashFunction(title);
    Article *newArticle = createArticle(title, content);
    newArticle->next = hashTable[index];
    hashTable[index] = newArticle;
}

Article* searchArticle(const char *title) {
    unsigned int index = hashFunction(title);
    Article *current = hashTable[index];
    while (current) {
        if (strcmp(current->title, title) == 0) return current;
        current = current->next;
    }
    return NULL;
}

void displayArticle(Article *article) {
    printf("Title: %s\nContent: %s\n", article->title, article->content);
}

void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Article *current = hashTable[i];
        while (current) {
            Article *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of articles to add: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char title[100], content[500];
        printf("Enter Title and Content for article %d:\n", i + 1);
        scanf(" %[^\n] %[^\n]", title, content);
        insertArticle(title, content);
    }

    char searchTitle[100];
    printf("Enter title to search: ");
    scanf(" %[^\n]", searchTitle);
    Article *article = searchArticle(searchTitle);
    if (article) displayArticle(article);
    else printf("Article not found.\n");

    freeHashTable();
    return 0;
}
