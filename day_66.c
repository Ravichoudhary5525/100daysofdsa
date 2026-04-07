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

// DFS for cycle detection
int dfs(struct Graph* graph, int v, int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        int adjNode = temp->data;

        if (!visited[adjNode]) {
            if (dfs(graph, adjNode, visited, recStack))
                return 1;
        }
        else if (recStack[adjNode]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

// Check cycle
int hasCycle(struct Graph* graph) {
    int visited[graph->V];
    int recStack[graph->V];

    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, recStack))
                return 1;
        }
    }

    return 0;
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

    if (hasCycle(graph))
        printf("YES");
    else
        printf("NO");

    return 0;
}
