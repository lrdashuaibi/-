#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int vertices[MAX];
    int edges[MAX][MAX];
    int vertex; 
    int edge; 
} Adj;

typedef struct ArcNode {
    int adjvex;
    struct ArcNode* next; 
} ArcNode;

typedef struct {
    int data; 
    ArcNode* first; 
} VertexNode;

typedef struct {
    VertexNode vertices[MAX]; 
    int vertex; 
    int edge;
} AdjacencyList;

void matrixToList(Adj* matrix, AdjacencyList* list) {
    list->vertex= matrix->vertex;
    list->edge = matrix->edge;
    
    for (int i = 0; i < matrix->vertex; i++) {
        list->vertices[i].data = matrix->vertices[i];
        list->vertices[i].first = NULL;
    }
    
    for (int i = 0; i < matrix->vertex; i++) {
        for (int j = 0; j < matrix->vertex; j++) {
            if (matrix->edges[i][j] != 0) {
                ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
                node->adjvex = j;
                node->next = list->vertices[i].first;
                list->vertices[i].first = node;
            }
        }
    }
}

void listToMatrix(AdjacencyList* list, Adj* matrix) {
    matrix->vertex = list->vertex;
    matrix->edge = list->edge;
    
    for (int i = 0; i < list->vertex; i++) {
        matrix->vertices[i] = list->vertices[i].data;
        for (int j = 0; j < list->vertex; j++) {
            matrix->edges[i][j] = 0;
        }
    }
    
    for (int i = 0; i < list->vertex; i++) {
        ArcNode* node = list->vertices[i].first;
        while (node != NULL) {
            matrix->edges[i][node->adjvex] = 1;
            node = node->next;
        }
    }
}
int main() {
    
    Adj matrix;
    matrix.vertex = 5;
    matrix.edge = 6;
    for (int i = 0; i < matrix.vertex; i++) {
        matrix.vertices[i] = i + 1;
        for (int j = 0; j < matrix.vertex; j++) {
            matrix.edges[i][j] = 0;
        }
    }
    matrix.edges[0][1] = matrix.edges[1][0] = 1;
    matrix.edges[0][2] = matrix.edges[2][0] = 1;
    matrix.edges[1][3] = matrix.edges[3][1] = 1;
    matrix.edges[2][3] = matrix.edges[3][2] = 1;
    matrix.edges[2][4] = matrix.edges[4][2] = 1;
    matrix.edges[3][4] = matrix.edges[4][3] = 1;
    
    printf("邻接矩阵：\n");
    for (int i = 0; i < matrix.vertex; i++) {
        for (int j = 0; j < matrix.vertex; j++) {
            printf("%d ", matrix.edges[i][j]);
        }
        printf("\n");
    }
    
    // 邻接矩阵转邻接表
    AdjacencyList list1;
    matrixToList(&matrix, &list1);
    
    printf("相应的邻接表：\n");
    for (int i = 0; i < list1.vertex; i++) {
        printf("%d -> ", list1.vertices[i].data);
        ArcNode* node = list1.vertices[i].first;
        while (node != NULL) {
            printf("%d ", list1.vertices[node->adjvex].data);
            node = node->next;
        }
        printf("\n");
    }
    
    // 初始化邻接表
    AdjacencyList list2;
    list2.vertex = 5;
    list2.edge = 6;
    for (int i = 0; i < list2.vertex; i++) {
        list2.vertices[i].data = i + 1;
        list2.vertices[i].first = NULL;
    }
    ArcNode* node1 = (ArcNode*)malloc(sizeof(ArcNode));
    node1->adjvex = 1;
    node1->next = NULL;
    list2.vertices[0].first = node1;
    ArcNode* node2 = (ArcNode*)malloc(sizeof(ArcNode));
    node2->adjvex = 2;
    node2->next = NULL;
    list2.vertices[0].first->next = node2;
    ArcNode* node3 = (ArcNode*)malloc(sizeof(ArcNode));
    node3->adjvex = 3;
    node3->next = NULL;
    list2.vertices[1].first = node3;
    ArcNode* node4 = (ArcNode*)malloc(sizeof(ArcNode));
    node4->adjvex = 3;
    node4->next = NULL;
    list2.vertices[2].first = node4;
    ArcNode* node5 = (ArcNode*)malloc(sizeof(ArcNode));
    node5->adjvex = 4;
    node5->next = NULL;
    list2.vertices[2].first->next = node5;
    ArcNode* node6 = (ArcNode*)malloc(sizeof(ArcNode));
    node6->adjvex = 4;
    node6->next = NULL;
    list2.vertices[3].first = node6;
    
    printf("邻接表：\n");
    for (int i = 0; i < list2.vertex; i++) {
        printf("%d -> ", list2.vertices[i].data);
        ArcNode* node = list2.vertices[i].first;
        while (node != NULL) {
            printf("%d ", list2.vertices[node->adjvex].data);
            node = node->next;
        }
        printf("\n");
    }
    
    // 邻接表转邻接矩阵
    Adj matrix2;
    listToMatrix(&list2, &matrix2);
    
    printf("相应的邻接矩阵：\n");
    for (int i = 0; i < matrix2.vertex; i++) {
        for (int j = 0; j < matrix2.vertex; j++) {
            printf("%d ", matrix2.edges[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
