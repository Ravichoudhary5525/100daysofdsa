#include <stdio.h>
#include <stdlib.h>

// comparator for sorting
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int start[n], end[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &end[i]);
    }

    // Sort start and end times
    qsort(start, n, sizeof(int), cmp);
    qsort(end, n, sizeof(int), cmp);

    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;

    // Traverse
    while (i < n && j < n) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    printf("%d", maxRooms);

    return 0;
}
