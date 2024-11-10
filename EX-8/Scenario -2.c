#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Product {
    char productID[20];
    char name[50];
    float price;
    struct Product *next;
} Product;

Product *hashTable[TABLE_SIZE];

unsigned int hashFunction(const char *productID) {
    unsigned int hash = 0;
    while (*productID) {
        hash = (hash * 31) + *productID;
        productID++;
    }
    return hash % TABLE_SIZE;
}

Product* createProduct(const char *productID, const char *name, float price) {
    Product *newProduct = (Product *)malloc(sizeof(Product));
    strcpy(newProduct->productID, productID);
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->next = NULL;
    return newProduct;
}

void insertProduct(const char *productID, const char *name, float price) {
    unsigned int index = hashFunction(productID);
    Product *newProduct = createProduct(productID, name, price);
    newProduct->next = hashTable[index];
    hashTable[index] = newProduct;
}

Product* searchProduct(const char *productID) {
    unsigned int index = hashFunction(productID);
    Product *current = hashTable[index];
    while (current) {
        if (strcmp(current->productID, productID) == 0) return current;
        current = current->next;
    }
    return NULL;
}

void displayProduct(Product *product) {
    printf("Product ID: %s\nName: %s\nPrice: $%.2f\n", product->productID, product->name, product->price);
}

void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Product *current = hashTable[i];
        while (current) {
            Product *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of products to add: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char productID[20], name[50];
        float price;
        printf("Enter Product ID, Name, and Price for product %d:\n", i + 1);
        scanf("%s %s %f", productID, name, &price);
        insertProduct(productID, name, price);
    }

    char searchID[20];
    printf("Enter Product ID to search: ");
    scanf("%s", searchID);
    Product *product = searchProduct(searchID);
    if (product) displayProduct(product);
    else printf("Product not found.\n");

    freeHashTable();
    return 0;
}
