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

// Kahn's Algorithm
void topoSort(struct Graph* graph) {
    int indegree[graph->V];

    // Initialize indegree
    for (int i = 0; i < graph->V; i++)
        indegree[i] = 0;

    // Calculate indegree
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adj[i];
        while (temp) {
            indegree[temp->data]++;
            temp = temp->next;
        }
    }

    int queue[MAX];
    int front = 0, rear = 0;

    // Push nodes with indegree 0
    for (int i = 0; i < graph->V; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node* temp = graph->adj[v];
        while (temp) {
            indegree[temp->data]--;

            if (indegree[temp->data] == 0)
                queue[rear++] = temp->data;

            temp = temp->next;
        }

        count++;
    }

    // Check cycle
    if (count != graph->V)
        printf("\nCycle exists (No Topological Sort)");
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
