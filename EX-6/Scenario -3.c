#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}


int partition(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


void quickSort(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void displayBooks(char *arr[], int n) {
    printf("Sorted Book Titles:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    
    
    char **books = (char **)malloc(n * sizeof(char *));
    if (books == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    
    printf("Enter the titles of the books:\n");
    char buffer[100];
    for (int i = 0; i < n; i++) {
        printf("Book %d: ", i + 1);
        scanf(" %[^\n]", buffer); // Read a line of input
        books[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (books[i] != NULL) {
            strcpy(books[i], buffer);
        }
    }
    
    
    quickSort(books, 0, n - 1);
    
    
    displayBooks(books, n);
    
    
    for (int i = 0; i < n; i++) {
        free(books[i]);
    }
    free(books);
    
    return 0;
}
