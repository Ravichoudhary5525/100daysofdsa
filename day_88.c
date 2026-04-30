#include <stdio.h>
#include <stdlib.h>

// Sort function (qsort comparator)
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place cows with minimum distance dist
int canPlace(int arr[], int n, int k, int dist) {
    int count = 1; // first cow
    int last = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - last >= dist) {
            count++;
            last = arr[i];
        }
        if (count >= k)
            return 1;
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Step 1: sort
    qsort(arr, n, sizeof(int), cmp);

    int low = 1;
    int high = arr[n - 1] - arr[0];
    int ans = 0;

    // Binary search on answer
    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(arr, n, k, mid)) {
            ans = mid;
            low = mid + 1;  // try bigger
        } else {
            high = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}
