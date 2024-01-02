#include <stdio.h>
typedef struct 
{
    int data;
} TreeNode;

int findIndex(TreeNode tree[], int size, int value) 
{
    for (int i = 0; i < size; i++) 
	{
        if (tree[i].data == value) 
		{
            return i;
        }
    }
    return -1;
}
int find(TreeNode tree[], int size, int node1, int node2) 
{
    int index1 = findIndex(tree, size, node1);
    int index2 = findIndex(tree, size, node2);
    while (index1 != index2) {
        if (index1 > index2) {
            index1 /= 2;
        } else {
            index2 /= 2;
        }
    }
    return tree[index1].data;
}

int main() {
    TreeNode tree[] = { {0}, {1}, {2}, {3}, {4}, {5}, {6} };
    int size = sizeof(tree) / sizeof(tree[0]);
    int node1 = 4;
    int node2 = 6;
    int ancestor = find(tree, size, node1, node2);
    printf("最近公共祖先的编号：%d，值：%d\n", ancestor, tree[ancestor].data);

    return 0;
}
