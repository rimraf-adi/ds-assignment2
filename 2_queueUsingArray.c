#include <stdio.h>
#define MAX 5

typedef enum { FALSE, TRUE } boolean;
typedef enum { SUCCESS, FAILURE } StatusCode;
typedef int itemtype;

typedef struct queue {
    int front;
    int rear;
    int count;
    itemtype items[MAX];
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

boolean isEmpty(Queue *q) {return (q->count == 0) ? TRUE : FALSE;}


boolean isFull(Queue *q) {return (q->count == MAX) ? TRUE : FALSE;}

StatusCode enqueue(Queue *q, itemtype item) {
    if (isFull(q)) return FAILURE;

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = item;
    q->count++;

    return SUCCESS;
}

StatusCode dequeue(Queue *q, itemtype *item) {
    if (isEmpty(q)) return FAILURE;

    *item = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;

    return SUCCESS;
}

//boilerplate code
int main() {
    Queue q;
    init(&q);

    for (int i = 1; i <= MAX; i++) enqueue(&q, i);

    itemtype item;
    
    while (!isEmpty(&q)) {
        dequeue(&q, &item);
        printf("%d\n", item);
    }

    return 0;
}
