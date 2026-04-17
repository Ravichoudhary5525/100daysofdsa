#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix[MAX] = {0};   // stores prefix sums
    int index[MAX];          // stores first index
    int size = 0;

    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0
        if (sum == 0)
            maxLen = i + 1;

        // Check if sum seen before
        int found = -1;
        for (int j = 0; j < size; j++) {
            if (prefix[j] == sum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            int len = i - index[found];
            if (len > maxLen)
                maxLen = len;
        } else {
            prefix[size] = sum;
            index[size] = i;
            size++;
        }
    }

    printf("%d", maxLen);

    return 0;
}
