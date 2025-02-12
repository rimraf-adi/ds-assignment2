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

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

void init(Queue *q) {
    q->front = q->rear = NULL;
}

boolean isEmpty(Queue *q) { 
    return q->front == NULL;
}

boolean isFull(Queue *q) { 
    return FALSE;
}

StatusCode enqueue(Queue *q, itemtype item) {
    StatusCode status = FAILURE;
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        newNode->item = item;
        newNode->next = NULL;
        if (isEmpty(q)) q->front = q->rear = newNode;
        else q->rear->next = newNode, q->rear = newNode;
        status = SUCCESS;
    }
    return status;
}

StatusCode dequeue(Queue *q, itemtype *item) {
    StatusCode status = FAILURE;
    if (!isEmpty(q)) {
        *item = q->front->item;
        Node *temp = q->front;
        q->front = q->front->next;
        if (!q->front) q->rear = NULL;
        free(temp);
        status = SUCCESS;
    }
    return status;
}

int main() {
    Queue q;
    init(&q);
    for (int i = 1; i <= MAX; i++) enqueue(&q, i);
    itemtype item;
    while (!isEmpty(&q)) dequeue(&q, &item), printf("%d\n", item);
    return 0;
}
