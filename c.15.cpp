#include <stdio.h>
int main() {
    int nums[100000];
    int n;
    printf("���볤�ȣ�");
    scanf("%d", &n);
    printf("�������֣�");
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
        printf("�ǰڶ����С�\n");
    } else {
        printf("�ǰڶ����У���Ҫɾ�� %d ��Ԫ�ء�\n", count);
    }
    return 0;
} 
