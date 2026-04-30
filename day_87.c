#include <stdio.h>

// Simple Bubble Sort (to sort first)
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    scanf("%d", &key);

    // Step 1: Sort array
    sort(arr, n);

    // Step 2: Binary Search
    int left = 0, right = n - 1;
    int found = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            found = mid;
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Output
    printf("%d", found);

    return 0;
}
