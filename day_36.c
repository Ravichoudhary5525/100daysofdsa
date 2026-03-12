#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int val) {
    if(front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = val;
}

// Dequeue
void dequeue() {
    if(front == -1)
        return;

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    int m;
    scanf("%d", &m);

    // Perform dequeue operations
    for(int i = 0; i < m; i++) {
        int val = queue[front];
        dequeue();
        enqueue(val);   // rotate queue
    }

    // Display queue
    int i = front;
    while(1) {
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }

    return 0;
}
