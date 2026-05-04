#include <stdio.h>
#include <stdlib.h>

struct Car {
    int pos;
    float time;
};

// Sort by position descending
int cmp(const void *a, const void *b) {
    return ((struct Car*)b)->pos - ((struct Car*)a)->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int position[n], speed[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    struct Car cars[n];

    // Compute time
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (float)(target - position[i]) / speed[i];
    }

    // Sort by position descending
    qsort(cars, n, sizeof(struct Car), cmp);

    int fleets = 0;
    float maxTime = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    printf("%d", fleets);

    return 0;
}
