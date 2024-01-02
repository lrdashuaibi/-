#include<stdio.h>
#include<string.h>
#define N 110

typedef struct PII{
    int x;
    int y;
}PII;
PII q[N*N];
int head, tail;

int n, m;
int g[N][N], s[N][N];

int bfs(){
    memset(s, -1, sizeof(s));
    s[1][1] = 0;
    q[++tail].x = 1, q[tail].y = 1;

    int vx[4] = { -1, 0, 1, 0 }, vy[4] = { 0, 1, 0, -1 };

    while(head <= tail){
        PII h = q[head++];

        for(int i = 0; i < 4; i++){
            int x = h.x + vx[i], y = h.y + vy[i];
            if(x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] == 0 && s[x][y] == -1){
                s[x][y] = s[h.x][h.y] + 1;
                q[++tail].x = x, q[tail].y = y;
            }
        }
    }

    return s[n][m];
}

int main(){
	int q,w;
	scanf("%d %d",&q,&w);

    for(int i = 1; i <= q; i++)
        for(int j = 1; j <= w; j++)
            scanf("%d", &g[i][j]);

    int e,r;
    scanf("%d %d",&e,&r);
    scanf("%d %d", &n, &m);
    printf("%d", bfs());

    return 0;
}
/*ÊäÈëÑùÀý 
5 5
0 1 0 0 0
0 1 0 0 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
1 1 3 3
*/
