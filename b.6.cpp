#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Graph {
    int numNodes;
    Node* adjList[MAX];
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph != NULL) {
        graph->numNodes = 0;
        for (int i = 0; i < MAX; i++) {
            graph->adjList[i] = NULL;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < MAX && dest >= 0 && dest < MAX) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = dest;
        newNode->next = graph->adjList[src];
        graph->adjList[src] = newNode;
    }
}

void DFS(Graph* graph, int node, int visited[]) {
    visited[node] = 1;
    
    Node* curr = graph->adjList[node];
    while (curr != NULL) {
        int neighbor = curr->data;
        
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited);
        }
        
        curr = curr->next;
    }
}

Graph* reverseGraph(Graph* graph) {
    Graph* reversedGraph = createGraph();
    for (int i = 0; i < graph->numNodes; i++) {
        Node* curr = graph->adjList[i];
        while (curr != NULL) {
            int src = curr->data;
            addEdge(reversedGraph, src, i);
            curr = curr->next;
        }
    }
    return reversedGraph;
}
int isStronglyConnected(Graph* graph) {
    int visited[MAX] = {0};
    DFS(graph, 0, visited);
    
    for (int i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            return 0;
        }
    }
    Graph* reversedGraph = reverseGraph(graph);
    
    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }
    
    DFS(reversedGraph, 0, visited);
    
    for (int i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            return 0;
        }
    }
    return 1;
}
int main() {
    Graph* graph = createGraph();
    graph->numNodes = 5;
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 2);
    if (isStronglyConnected(graph)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
