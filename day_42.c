#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
struct Queue {
    int arr[MAX];
    int front, rear;
};

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Queue functions
void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isEmptyQueue(struct Queue *q) {
    return (q->front == -1);
}

void enqueue(struct Queue *q, int x) {
    if (q->rear == MAX - 1)
        return;

    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = x;
}

int dequeue(struct Queue *q) {
    int val = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return val;
}

// Stack functions
void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmptyStack(struct Stack *s) {
    return (s->top == -1);
}

void push(struct Stack *s, int x) {
    if (s->top == MAX - 1)
        return;
    s->arr[++s->top] = x;
}

int pop(struct Stack *s) {
    return s->arr[s->top--];
}

// Reverse queue using stack
void reverseQueue(struct Queue *q) {
    struct Stack s;
    initStack(&s);

    while (!isEmptyQueue(q))
        push(&s, dequeue(q));

    while (!isEmptyStack(&s))
        enqueue(q, pop(&s));
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    reverseQueue(&q);

    while (!isEmptyQueue(&q))
        printf("%d ", dequeue(&q));

    return 0;
}
