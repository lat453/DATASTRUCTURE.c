#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id; 
    char name[50];
    struct Student* left;
    struct Student* right;
};


struct Student* createStudent(int id, char* name) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->left = newStudent->right = NULL;
    return newStudent;
}

struct Student* insertStudent(struct Student* root, struct Student* newStudent) {
    if (root == NULL) {
        return newStudent;
    }
    
    if (newStudent->id < root->id) {
        root->left = insertStudent(root->left, newStudent);
    } else if (newStudent->id > root->id) {
        root->right = insertStudent(root->right, newStudent);
    }
    
    return root;
}


struct Student* searchStudent(struct Student* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }
    
    if (id < root->id) {
        return searchStudent(root->left, id);
    }
    
    return searchStudent(root->right, id);
}


void inOrderTraversal(struct Student* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("ID: %d, Name: %s\n", root->id, root->name);
    inOrderTraversal(root->right);
}

int main() {
    struct 
    root = insertStudent(root, createStudent(102, "Alice"));
    root = insertStudent(root, createStudent(105, "Bob"));
    root = insertStudent(root, createStudent(101, "Charlie"));
    root = insertStudent(root, createStudent(103, "David"));
    
  
    printf("All Students (in ascending order of IDs):\n");
    inOrderTraversal(root);
    
    int searchID = 105;
    struct Student* foundStudent = searchStudent(root, searchID);
    if (foundStudent != NULL) {
        printf("\nStudent found:\nID: %d, Name: %s\n", foundStudent->id, foundStudent->name);
    } else {
        printf("\nStudent with ID %d not found.\n", searchID);
    }
    
    return 0;
}
