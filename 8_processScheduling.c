#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int array[MAX_SIZE];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

int isFull(struct Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(struct Queue* q, int value) {
    if (!isFull(q)) {
        if (q->front == -1) q->front = 0;
        q->array[++q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    if (!isEmpty(q)) {
        int value = q->array[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        return value;
    }
    return -1;
}

void processScheduling(int tasks[], int n) {
    struct Queue q;
    initQueue(&q);
    
    for (int i = 0; i < n; i++) {
        enqueue(&q, tasks[i]);
    }
    
    printf("Task execution order: ");
    while (!isEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");
}

int main() {
    int tasks[] = {1, 2, 3, 4, 5};
    int n = sizeof(tasks) / sizeof(tasks[0]);
    
    processScheduling(tasks, n);
    
    return 0;
}
