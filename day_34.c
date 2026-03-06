#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push
void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

// Pop
int pop() {
    if(top == NULL) {
        return -1;
    }

    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int main() {

    char exp[100];
    fgets(exp, sizeof(exp), stdin);

    int i = 0;

    while(exp[i] != '\0') {

        // If digit
        if(isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        // If operator
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {

            int b = pop();
            int a = pop();
            int result;

            if(exp[i] == '+')
                result = a + b;
            else if(exp[i] == '-')
                result = a - b;
            else if(exp[i] == '*')
                result = a * b;
            else
                result = a / b;

            push(result);
        }

        i++;
    }

    printf("%d", pop());

    return 0;
}
