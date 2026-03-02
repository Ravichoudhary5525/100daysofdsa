#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create List
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
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    // Move pointer of longer list
    if(len1 > len2) {
        for(int i = 0; i < len1 - len2; i++)
            ptr1 = ptr1->next;
    } else {
        for(int i = 0; i < len2 - len1; i++)
            ptr2 = ptr2->next;
    }

    // Traverse together
    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1->data == ptr2->data) {
            printf("%d", ptr1->data);
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection");

    return 0;
}
