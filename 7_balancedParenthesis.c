#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    char array[MAX_SIZE];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack* s, char value) {
    if (!isFull(s)) {
        s->array[++s->top] = value;
    }
}

char pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->array[s->top--];
    }
    return '\0';
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char* expr) {
    struct Stack stack;
    initStack(&stack);
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&stack, expr[i]);
        } else {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), expr[i])) {
                return 0;
            }
        }
    }
    return isEmpty(&stack);
}

int main() {
    char expr[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", expr);
    
    if (isBalanced(expr)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    
    return 0;
}
