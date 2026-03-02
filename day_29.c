Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createList(n);

    int k;
    scanf("%d", &k);

    if(head == NULL || head->next == NULL || k == 0) {
        while(head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        return 0;
    }

    int len = getLength(head);
    k = k % len;

    if(k == 0) {
        while(head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        return 0;
    }

    // Step 1: Make circular
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head;   // circular link

    // Step 2: Find new tail (len - k - 1)
    int steps = len - k;
    struct Node* newTail = head;

    for(int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;

    // Break circular link
    newTail->next = NULL;

    // Print rotated list
    temp = newHead;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
