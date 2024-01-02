#include <stdio.h>
#include <limits.h>
void find(int coins[], int num, int a) 
{
    int min[a+1];
    int lastCoin[a+1];
    min[0] = 0;
    for (int i = 1; i <= a; i++) 
	{
        min[i] = INT_MAX;
        for (int j = 0; j < num; j++) 
		{
            if (coins[j] <= i && (1 + min[i-coins[j]]) < min[i]) 
			{
                min[i] = 1 + min[i-coins[j]];
                lastCoin[i] = coins[j];
            }
        }
    }

    printf("找零 %d 分，使用的硬币为：", a);
    while (a > 0) {
        printf("%d 分 ", lastCoin[a]);
        a -= lastCoin[a];
    }
    printf("硬币。\n");
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int num = sizeof(coins) / sizeof(coins[0]);
    
    find(coins, num, 32);
    find(coins, num, 50);
    
    return 0;
}
