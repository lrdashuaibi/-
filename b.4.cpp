#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct treenode
{
	int data;
	struct treenode *right;
	struct treenode *left;
};
struct treenode *cre(int a[100][3],int count,int n)
{
	if(count>=n||a[count][0]==-1)
	{
		return NULL;
	}
	struct treenode *root=(struct treenode *)malloc(sizeof(struct treenode ));
	root->right=root->left=NULL;
	root->data=a[count][0];
	if(a[count][1]!=-1)
	{
		root->left=cre(a,a[count][1]-1,n);
	}
	if(a[count][2]!=-1)
	{
		root->right=cre(a,a[count][2]-1,n);
	}
	
	return root;
}
void preorder(struct treenode *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct treenode *root)
{
	if(root!=NULL)
	{
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	}
}
void postorder(struct treenode *root)
{
	if(root!=NULL)
	{
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
	}
}
int main()
{
	int a[100][3];
    int n;
	int count=0;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]); 
		}
	}
	struct treenode *r=(struct treenode *)malloc(sizeof(struct treenode));
	r=cre(a,count,n);
	printf("前序遍历:\n");
	preorder(r);
	printf("\n");
	printf("中序遍历:\n");
	inorder(r);
	printf("\n");
	printf("后序遍历:\n");
	postorder(r);
	printf("\n");
	return 0;
}
/*
8 
1 2 3
2 4 5
3 6 7
4 8 -1
5 -1 -1
6 -1 -1
7 -1 -1
8 -1 -1
*/
