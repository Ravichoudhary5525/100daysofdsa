#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    return stack[top--];
}

// Precedence
int precedence(char x) {
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {

    char infix[100], postfix[100];
    int j = 0;

    scanf("%s", infix);

    for(int i = 0; i < strlen(infix); i++) {

        char ch = infix[i];

        // If operand
        if(isalnum(ch)) {
            postfix[j++] = ch;
        }

        // If operator
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while(top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}
