#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int adjMatrix[MAX][MAX]; // 邻接矩阵
bool visited[MAX]; // 标记是否访问过
void dfs(int start, int end, int path[], int len) {
    visited[start] = true;
    path[len++] = start;

    if (start == end) { // 找到一条路径
        printf("Path: ");
        for (int i = 0; i < len; i++) {
            printf("%d ", path[i]);
        }
        printf("\nLength: %d\n", len - 1);
    } else {
        for (int i = 0; i < MAX; i++) {
            if (adjMatrix[start][i] != 0 && !visited[i]) {
                dfs(i, end, path, len);
            }
        }
    }
    visited[start] = false; // 还原状态
}
int main() {
    // 输入邻接矩阵
    printf("Please input the adjacency matrix:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    // 输出所有顶点对之间的路径和长度
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i != j) {
                int path[MAX];
                dfs(i, j, path, 0);
            }
        }
    }

    return 0;
}
