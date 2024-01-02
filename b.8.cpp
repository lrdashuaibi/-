#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int adjMatrix[MAX][MAX]; // �ڽӾ���
bool visited[MAX]; // ����Ƿ���ʹ�
void dfs(int start, int end, int path[], int len) {
    visited[start] = true;
    path[len++] = start;

    if (start == end) { // �ҵ�һ��·��
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
    visited[start] = false; // ��ԭ״̬
}
int main() {
    // �����ڽӾ���
    printf("Please input the adjacency matrix:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    // ������ж����֮���·���ͳ���
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
