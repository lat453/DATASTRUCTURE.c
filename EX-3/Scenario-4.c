#include <stdio.h>
#include <stdlib.h>

struct Node {
    int inquiryId;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void addInquiry(int id) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->inquiryId = id;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void resolveInquiry() {
    if (front == NULL) {
        printf("No inquiries to resolve\n");
        return;
    }
    struct Node* temp = front;
    printf("Resolving inquiry %d\n", temp->inquiryId);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void displayInquiries() {
    if (front == NULL) {
        printf("No inquiries in queue\n");
        return;
    }
    struct Node* temp = front;
    printf("Current inquiries: ");
    while (temp != NULL) {
        printf("%d ", temp->inquiryId);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    addInquiry(1);
    addInquiry(2);
    addInquiry(3);
    displayInquiries();
    resolveInquiry();
    displayInquiries();
    addInquiry(4);
    displayInquiries();
    resolveInquiry();
    displayInquiries();
    return 0;
}
