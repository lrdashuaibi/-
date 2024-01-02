#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    char *name; 
    int id; 
    struct TreeNode *left; // 左子节点
    struct TreeNode *right; // 右子节点
    bool left_threaded; // 左线索标记
    bool right_threaded; // 右线索标记
} TreeNode;

void preorderTraversal(TreeNode *root) {
    if (root != NULL) {
        printf("%s ", root->name);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->name);
        inorderTraversal(root->right);
    }
}
void postorderTraversal(TreeNode *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%s ", root->name);
    }
}

TreeNode *newNode(char *name, int id) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->name = name;
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    node->left_threaded = false;
    node->right_threaded = false;
    return node;
}

// 中序遍历线索化二叉树
void inorderThreading(TreeNode *root, TreeNode **prev) {
    if (root != NULL) {
        inorderThreading(root->left, prev);
        if (root->left == NULL) {
            root->left = *prev;
            root->left_threaded = true;
        }
        if (*prev != NULL && (*prev)->right == NULL) {
            (*prev)->right = root;
            (*prev)->right_threaded = true;
        }
        *prev = root;
        inorderThreading(root->right, prev);
    }
}

// 将二叉树线索化
void threadTree(TreeNode *root) {
    TreeNode *prev = NULL;
    inorderThreading(root, &prev);
    prev->right = NULL;
    prev->right_threaded = true;
}

int main() {
    // 创建二叉树
    TreeNode *root = newNode("Plant 1", 1);
    root->left = newNode("Plant 2", 2);
    root->right = newNode("Plant 3", 3);
    root->left->left = newNode("Plant 4", 4);
    root->left->right = newNode("Plant 5", 5);
    root->right->left = newNode("Plant 6", 6);
    root->right->right = newNode("Plant 7", 7);

    // 将二叉树线索化
    threadTree(root);

    // 输出先序、中序、后序遍历结果
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
