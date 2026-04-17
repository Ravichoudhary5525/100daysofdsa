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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adj = (struct Node**)malloc((V + 1) * sizeof(struct Node*));

    for (int i = 1; i <= V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

// DFS
void DFS(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            DFS(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int visited[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
