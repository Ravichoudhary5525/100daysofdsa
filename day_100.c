#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[]) {
    int n = right - left + 1;
    Pair temp[n];

    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++; // smaller element found
        } else {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void mergeSort(Pair arr[], int left, int right, int count[]) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

int main() {
    int n;
    scanf("%d", &n);

    Pair arr[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    // Output result
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}
