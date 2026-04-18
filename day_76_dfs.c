#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;
    return n;
}

struct Graph* createGraph(int V) {
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->V = V;
    g->adj = (struct Node**)malloc((V + 1) * sizeof(struct Node*));

    for (int i = 1; i <= V; i++)
        g->adj[i] = NULL;

    return g;
}

// Undirected edge
void addEdge(struct Graph* g, int u, int v) {
    struct Node* n = createNode(v);
    n->next = g->adj[u];
    g->adj[u] = n;

    n = createNode(u);
    n->next = g->adj[v];
    g->adj[v] = n;
}

// DFS
void DFS(struct Graph* g, int v, int visited[]) {
    visited[v] = 1;

    struct Node* temp = g->adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            DFS(g, temp->data, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* g = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    int visited[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    // Start DFS from node 1
    DFS(g, 1, visited);

    // Check if all nodes visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}
