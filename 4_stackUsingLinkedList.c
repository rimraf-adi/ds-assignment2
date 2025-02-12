#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

typedef enum { FALSE, TRUE } boolean;
typedef enum { SUCCESS, FAILURE } StatusCode;
typedef int itemtype;

typedef struct Node {
    itemtype item;
    struct Node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

void init(Stack *s) {
    s->top = NULL;
}

boolean isEmpty(Stack *s) { 
    return (s->top == NULL) ? TRUE : FALSE;
}

boolean isFull(Stack *s) { 
    return FALSE;
}

StatusCode push(Stack *s, itemtype item) {
    StatusCode status = FAILURE;
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        newNode->item = item;
        newNode->next = s->top;
        s->top = newNode;
        status = SUCCESS;
    }
    return status;
}

StatusCode pop(Stack *s, itemtype *item) {
    StatusCode status = FAILURE;
    if (!isEmpty(s)) {
        *item = s->top->item;
        Node *temp = s->top;
        s->top = s->top->next;
        free(temp);
        status = SUCCESS;
    }
    return status;
}

int main() {
    Stack s;
    init(&s);
    for (int i = 1; i <= MAX; i++) push(&s, i);
    itemtype item;
    while (!isEmpty(&s)) pop(&s, &item), printf("%d\n", item);
    return 0;
}
