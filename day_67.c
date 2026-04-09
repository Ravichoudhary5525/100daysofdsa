#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

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

    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge (directed)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// DFS helper
void dfs(struct Graph* graph, int v, int visited[], int stack[], int* top) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(graph, temp->data, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[++(*top)] = v; // push to stack
}

// Topological sort
void topoSort(struct Graph* graph) {
    int visited[graph->V];
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    int stack[MAX];
    int top = -1;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, stack, &top);
        }
    }

    // Print stack (reverse order)
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Graph* graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topoSort(graph);

    return 0;
}
