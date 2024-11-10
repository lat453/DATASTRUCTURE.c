#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int peek(struct Stack* s) {
    return s->arr[s->top];
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluatePostfix(char* expression) {
    struct Stack s;
    initStack(&s);
    int i = 0;
    
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            push(&s, expression[i] - '0');
        }
        else if (isOperator(expression[i])) {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;
            
            switch (expression[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            push(&s, result);
        }
        i++;
    }
    
    return pop(&s);
}

int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    
    return 0;
}
