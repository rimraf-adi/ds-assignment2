#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int array[MAX_SIZE];
    int top;
};

struct Queue {
    struct Stack stack;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

void initQueue(struct Queue* q) {
    initStack(&q->stack);
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack* s, int value) {
    if (!isFull(s)) {
        s->array[++s->top] = value;
    }
}

int pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->array[s->top--];
    }
    return -1;
}

void enqueue(struct Queue* q, int value) {
    push(&q->stack, value);
}

int dequeueHelper(struct Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }
    int topElement = pop(s);
    if (isEmpty(s)) {
        return topElement;
    }
    int dequeuedElement = dequeueHelper(s);
    push(s, topElement);
    return dequeuedElement;
}

int dequeue(struct Queue* q) {
    return dequeueHelper(&q->stack);
}

int main() {
    struct Queue q;
    initQueue(&q);
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    
    enqueue(&q, 4);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    
    return 0;
}
