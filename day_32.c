Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10

  #include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    top++;
    stack[top] = value;
}

// Pop function
void pop() {
    if(top >= 0)
        top--;
}

int main() {

    int n;
    scanf("%d", &n);

    // Push elements
    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(value);
    }

    int m;
    scanf("%d", &m);

    // Pop m elements
    for(int i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack (top to bottom)
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
