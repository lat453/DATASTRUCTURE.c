#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void addCustomer(int id) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = id;
}

void serveCustomer() {
    if (front == -1 || front > rear) {
        printf("No customers to serve\n");
        return;
    }
    printf("Serving customer %d\n", queue[front++]);
    if (front > rear) front = rear = -1;
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("No customers in queue\n");
        return;
    }
    printf("Customers in queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    addCustomer(1);
    addCustomer(2);
    addCustomer(3);
    displayQueue();
    serveCustomer();
    displayQueue();
    addCustomer(4);
    displayQueue();
    serveCustomer();
    displayQueue();
    return 0;
}
