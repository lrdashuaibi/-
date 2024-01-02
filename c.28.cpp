#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
TreeNode* createTree() 
{
    int val;
    scanf("%d", &val);
    if (val == -1) {  // ����-1��ʾ�ս��
        return NULL;
    }
    
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = val;
    root->left = createTree();
    root->right = createTree();
    
    return root;
}

bool isFullBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    
    if (root->left != NULL && root->right != NULL) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }
    
    return false;
}

bool isCompleteBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    
    TreeNode* queue[100];
    int front = 0;
    int rear = 0;
    bool flag = false; 
    
    queue[rear++] = root;
    while (front < rear) {
        TreeNode* node = queue[front++];
        if (node == NULL) {
            flag = true;
        } else {

            if (flag) {
                return false;
            }
            
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }
    
    return true;
}

int main() {
    printf("������һ�ö�������ʹ������������룬�ս��ʹ��-1��ʾ����\n");
    TreeNode* root = createTree();
    
    bool isFull = isFullBinaryTree(root);
    bool isComplete = isCompleteBinaryTree(root);
    
    if (isFull) {
        printf("������������");
    } else {
        printf("��������������");
    }
    
    if (isComplete) {
        printf("����ȫ��������\n");
    } else {
        printf("������ȫ��������\n");
    }
    return 0;
}
