#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node {
    float data;
    struct Node* next;
};

// Insert into bucket in sorted order (insertion sort)
void sortedInsert(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* curr = *head;
        while (curr->next != NULL && curr->next->data < value) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    // Create n buckets
    struct Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = (int)(n * arr[i]);
        sortedInsert(&buckets[idx], arr[i]);
    }

    // Concatenate buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[index++] = temp->data;
            temp = temp->next;
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}
