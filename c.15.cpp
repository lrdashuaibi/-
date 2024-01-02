#include <stdio.h>
int main() {
    int nums[100000];
    int n;
    printf("输入长度：");
    scanf("%d", &n);
    printf("输入数字：");
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &nums[i]);
    }
    int count = 0;
    for (int i = 1; i < n-1; i++) 
	{
        if ((nums[i] > nums[i-1] && nums[i] > nums[i+1]) || (nums[i] < nums[i-1] && nums[i] < nums[i+1])) 
		{
            continue;
        } 
		else 
		{
            count++;
        }
    }
    if (count == 0) 
	{
        printf("是摆动序列。\n");
    } else {
        printf("非摆动序列，需要删除 %d 个元素。\n", count);
    }
    return 0;
} 
