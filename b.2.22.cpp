#include <stdio.h>
#include <stdlib.h>
int visited[99][99];
int e, r, q, w;
int n, m; 
int a[99][99];
int count=0;
int flag(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m && visited[x][y] == 0 && a[x][y] == 0)	
        return 1;

    return 0;
}
int find(int x, int y) {
    if (x == q && y == w) {
        visited[x][y] = 1;
        return 1;
    }
    if (flag(x, y)) {
        visited[x][y] = 1;
        if (find(x, y + 1)) {
        	count++;
            return 1;
        }
        if (find(x + 1, y)) {
        	count++;
            return 1;
        }
        visited[x][y] = 0;
        return 0;
    }
    return 0;
}
int main() 
{
    scanf("%d %d", &n, &m);
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }	
    scanf("%d %d %d %d", &e, &r, &q, &w);
    int dis =find(e, r);
    printf("%d", count);
    return 0;
}
