#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueueCall(int callId) {
    if (rear == MAX - 1) {
        printf("Call queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = callId;
}

void dequeueCall() {
    if (front == -1 || front > rear) {
        printf("No calls to serve\n");
        return;
    }
    printf("Serving call %d\n", queue[front++]);
    if (front > rear) front = rear = -1;
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("No calls in queue\n");
        return;
    }
    printf("Current call queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueueCall(101);
    enqueueCall(102);
    enqueueCall(103);
    displayQueue();
    dequeueCall();
    displayQueue();
    enqueueCall(104);
    displayQueue();
    dequeueCall();
    displayQueue();
    return 0;
}
