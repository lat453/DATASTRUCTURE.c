#include <stdio.h>
#include <stdlib.h>

struct Node {
    int customerId;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueueCustomer(int id) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->customerId = id;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeueCustomer() {
    if (front == NULL) {
        printf("No customers to serve\n");
        return;
    }
    struct Node* temp = front;
    printf("Serving customer %d\n", temp->customerId);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("No customers in queue\n");
        return;
    }
    struct Node* temp = front;
    printf("Customers in queue: ");
    while (temp != NULL) {
        printf("%d ", temp->customerId);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueueCustomer(101);
    enqueueCustomer(102);
    enqueueCustomer(103);
    displayQueue();
    dequeueCustomer();
    displayQueue();
    enqueueCustomer(104);
    displayQueue();
    dequeueCustomer();
    displayQueue();
    return 0;
}
