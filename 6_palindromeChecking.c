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

int isPalindrome(char* str) {
    int len = strlen(str);
    struct Stack stack;
    initStack(&stack);
    
    for (int i = 0; i < len / 2; i++) {
        push(&stack, str[i]);
    }
    
    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;
    
    for (int i = start; i < len; i++) {
        if (str[i] != pop(&stack)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (isPalindrome(str)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
    
    return 0;
}
