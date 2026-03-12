#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify Up
void heapifyUp(int i) {
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert
void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Peek
void peek() {
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

// Extract Min
void extractMin() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size-1];
    size--;

    heapifyDown(0);
}

int main() {

    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {

        char op[20];
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        }

        else if(strcmp(op, "extractMin") == 0) {
            extractMin();
        }

        else if(strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}
