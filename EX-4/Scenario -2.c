#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = c;
}

char pop(struct Stack* s) {
    if (isEmpty(s)) {
        return '\0'; // Return a null character if the stack is empty
    }
    return s->arr[(s->top)--];
}

int isOpeningDelimiter(char c) {
    return c == '(' || c == '{' || c == '[';
}

int isClosingDelimiter(char c) {
    return c == ')' || c == '}' || c == ']';
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int checkSyntax(const char* code) {
    struct Stack s;
    initStack(&s);
    
    for (int i = 0; code[i] != '\0'; i++) {
        char currentChar = code[i];
        
        if (isOpeningDelimiter(currentChar)) {
            push(&s, currentChar);
        } 
        else if (isClosingDelimiter(currentChar)) {
            if (isEmpty(&s)) {
                printf("Syntax error: unmatched closing delimiter '%c' at position %d\n", currentChar, i + 1);
                return 0;
            }
            char topChar = pop(&s);
            if (!isMatchingPair(topChar, currentChar)) {
                printf("Syntax error: mismatched delimiter '%c' at position %d\n", currentChar, i + 1);
                return 0;
            }
        }
    }
    
    if (!isEmpty(&s)) {
        printf("Syntax error: unmatched opening delimiter '%c'\n", s.arr[s.top]);
        return 0;
    }
    
    return 1; // No syntax errors
}

int main() {
    char code[MAX];
    
    printf("Enter the code: ");
    fgets(code, sizeof(code), stdin);
    
    if (checkSyntax(code)) {
        printf("Syntax is correct\n");
    }
    
    return 0;
}
