#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Book {
    char title[100];
    char author[100];
    char isbn[20]; 
    struct Book* left;
    struct Book* right;
};


struct Book* createBook(char* isbn, char* title, char* author) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->isbn, isbn);
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->left = newBook->right = NULL;
    return newBook;
}

struct Book* insertBook(struct Book* root, struct Book* newBook) {
    if (root == NULL) {
        return newBook;
    }
    
    
    if (strcmp(newBook->isbn, root->isbn) < 0) {
        root->left = insertBook(root->left, newBook);
    } else if (strcmp(newBook->isbn, root->isbn) > 0) {
        root->right = insertBook(root->right, newBook);
    }
    
    return root;
}

struct Book* searchBook(struct Book* root, char* isbn) {
    if (root == NULL || strcmp(root->isbn, isbn) == 0) {
        return root;
    }
    
    if (strcmp(isbn, root->isbn) < 0) {
        return searchBook(root->left, isbn);
    }
    
    return searchBook(root->right, isbn);
}
void inOrderTraversal(struct Book* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("ISBN: %s\nTitle: %s\nAuthor: %s\n\n", root->isbn, root->title, root->author);
    inOrderTraversal(root->right);
}


struct Book* minValueNode(struct Book* node) {
    struct Book* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
struct Book* deleteBook(struct Book* root, char* isbn) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(isbn, root->isbn) < 0) {
        root->left = deleteBook(root->left, isbn);
    } else if (strcmp(isbn, root->isbn) > 0) {
        root->right = deleteBook(root->right, isbn);
    } else {
        if (root->left == NULL) {
            struct Book* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Book* temp = root->left;
            free(root);
            return temp;
        }
        
        struct Book* temp = minValueNode(root->right);
        strcpy(root->isbn, temp->isbn);
        strcpy(root->title, temp->title);
        strcpy(root->author, temp->author);
        root->right = deleteBook(root->right, temp->isbn);
    }
    return root;
}

int main() {
    struct Book* root = NULL;
    
    
    root = insertBook(root, createBook("978-3-16-148410-0", "The Great Gatsby", "F. Scott Fitzgerald"));
    root = insertBook(root, createBook("978-0-7432-7356-5", "To Kill a Mockingbird", "Harper Lee"));
    root = insertBook(root, createBook("978-1-4028-9462-6", "1984", "George Orwell"));
    
    
    printf("Inventory (in-order):\n");
    inOrderTraversal(root);
    
    
    char searchIsbn[] = "978-0-7432-7356-5";
    struct Book* foundBook = searchBook(root, searchIsbn);
    if (foundBook != NULL) {
        printf("Book found: \nISBN: %s\nTitle: %s\nAuthor: %s\n\n", foundBook->isbn, foundBook->title, foundBook->author);
    } else {
        printf("Book with ISBN %s not found.\n\n", searchIsbn);
    }

    
    char deleteIsbn[] = "978-3-16-148410-0";
    root = deleteBook(root, deleteIsbn);
    printf("Inventory after deletion (in-order):\n");
    inOrderTraversal(root);
    
    return 0;
}
