#include <stdio.h>
#include <stdlib.h>

// Interval structure
struct Interval {
    int start, end;
};

// Sort by start time
int cmp(const void *a, const void *b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(struct Interval), cmp);

    // Step 2: Merge
    struct Interval result[n];
    int idx = 0;

    result[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[idx].end) {
            // merge
            if (arr[i].end > result[idx].end)
                result[idx].end = arr[i].end;
        } else {
            idx++;
            result[idx] = arr[i];
        }
    }

    // Output merged intervals
    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}
