#include <stdio.h>
#include <stdlib.h>

struct Node {
    int rideId;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void addRideRequest(int id) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->rideId = id;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void serveRideRequest() {
    if (front == NULL) {
        printf("No ride requests to serve\n");
        return;
    }
    struct Node* temp = front;
    printf("Serving ride request %d\n", temp->rideId);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void displayRequests() {
    if (front == NULL) {
        printf("No pending ride requests\n");
        return;
    }
    struct Node* temp = front;
    printf("Pending ride requests: ");
    while (temp != NULL) {
        printf("%d ", temp->rideId);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    addRideRequest(501);
    addRideRequest(502);
    addRideRequest(503);
    displayRequests();
    serveRideRequest();
    displayRequests();
    addRideRequest(504);
    displayRequests();
    serveRideRequest();
    displayRequests();
    return 0;
}
