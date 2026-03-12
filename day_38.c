#include <stdio.h>
#include <string.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return front == -1;
}

// Size
int size() {
    if(empty()) return 0;
    return rear - front + 1;
}

// Push front
void push_front(int x) {
    if(front == -1) {
        front = rear = 0;
        dq[front] = x;
    } else if(front > 0) {
        dq[--front] = x;
    }
}

// Push back
void push_back(int x) {
    if(front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    dq[rear] = x;
}

// Pop front
void pop_front() {
    if(empty()) return;

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

// Pop back
void pop_back() {
    if(empty()) return;

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

// Get front
void getFront() {
    if(empty())
        printf("-1\n");
    else
        printf("%d\n", dq[front]);
}

// Get back
void getBack() {
    if(empty())
        printf("-1\n");
    else
        printf("%d\n", dq[rear]);
}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        char op[20];
        scanf("%s", op);

        if(strcmp(op,"push_front")==0) {
            int x;
            scanf("%d",&x);
            push_front(x);
        }

        else if(strcmp(op,"push_back")==0) {
            int x;
            scanf("%d",&x);
            push_back(x);
        }

        else if(strcmp(op,"pop_front")==0) {
            pop_front();
        }

        else if(strcmp(op,"pop_back")==0) {
            pop_back();
        }

        else if(strcmp(op,"front")==0) {
            getFront();
        }

        else if(strcmp(op,"back")==0) {
            getBack();
        }

        else if(strcmp(op,"size")==0) {
            printf("%d\n", size());
        }

        else if(strcmp(op,"empty")==0) {
            printf("%d\n", empty());
        }
    }

    return 0;
}
