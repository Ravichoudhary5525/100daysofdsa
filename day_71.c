#include <stdio.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];

    // Initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        int h = key % m;

        if (op[0] == 'I') {  // INSERT
            int j = 0;
            while (j < m) {
                int idx = (h + j * j) % m;

                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
                j++;
            }
        }
        else {  // SEARCH
            int found = 0;
            int j = 0;

            while (j < m) {
                int idx = (h + j * j) % m;

                if (table[idx] == key) {
                    found = 1;
                    break;
                }

                if (table[idx] == EMPTY)
                    break;

                j++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
