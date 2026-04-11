#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Edge edges[m];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    int dist[n];

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Relax edges (V-1 times)
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
