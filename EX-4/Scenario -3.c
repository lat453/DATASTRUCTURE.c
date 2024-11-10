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
        return '\0';
    }
    return s->arr[(s->top)--];
void reverseString(char* str) {
    struct Stack s;
    initStack(&s);
    
    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }
    
    int i = 0;
    while (!isEmpty(&s)) {
        str[i++] = pop(&s);
    }
    str[i] = '\0'; 
}

int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';
    
    reverseString(str);
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}
