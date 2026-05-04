#include <stdio.h>

// Check if possible within maxTime
int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (time + arr[i] <= maxTime) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
        }

        if (painters > k)
            return 0;
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int low = maxVal, high = sum;
    int ans = sum;

    // Binary Search
    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;  // minimize
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}
