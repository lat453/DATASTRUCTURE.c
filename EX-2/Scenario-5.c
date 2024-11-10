#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

char pop(struct Node** head) {
    if (*head == NULL) return '\0';
    struct Node* temp = *head;
    char data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

int isEmpty(struct Node* head) {
    return head == NULL;
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int isBalanced(char* expression) {
    struct Node* stack = NULL;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            push(&stack, expression[i]);
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (isEmpty(stack)) return 0;
            char top = pop(&stack);
            if (!isMatchingPair(top, expression[i])) return 0;
        }
    }
    return isEmpty(stack);
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);
    if (isBalanced(expression))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
