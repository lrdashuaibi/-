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
    if (val == -1) {  // 输入-1表示空结点
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
    printf("请输入一棵二叉树（使用先序遍历输入，空结点使用-1表示）：\n");
    TreeNode* root = createTree();
    
    bool isFull = isFullBinaryTree(root);
    bool isComplete = isCompleteBinaryTree(root);
    
    if (isFull) {
        printf("是满二叉树，");
    } else {
        printf("不是满二叉树，");
    }
    
    if (isComplete) {
        printf("是完全二叉树。\n");
    } else {
        printf("不是完全二叉树。\n");
    }
    return 0;
}
