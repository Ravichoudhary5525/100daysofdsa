#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node** adj;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    // Add v to u's list
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    // Add u to v's list
    newNode = createNode(u);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

// Print graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);

        struct Node* temp = graph->adj[i];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
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

    printGraph(graph);

    return 0;
}
