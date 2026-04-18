#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[1001];
int visited[1001];

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = adj[u];
    adj[u] = n;

    n = (struct Node*)malloc(sizeof(struct Node));
    n->data = u;
    n->next = adj[v];
    adj[v] = n;
}

// DFS
void DFS(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            DFS(temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
