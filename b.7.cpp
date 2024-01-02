#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    char *name; 
    int id; 
    struct TreeNode *left; // ���ӽڵ�
    struct TreeNode *right; // ���ӽڵ�
    bool left_threaded; // ���������
    bool right_threaded; // ���������
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

// �������������������
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

// ��������������
void threadTree(TreeNode *root) {
    TreeNode *prev = NULL;
    inorderThreading(root, &prev);
    prev->right = NULL;
    prev->right_threaded = true;
}

int main() {
    // ����������
    TreeNode *root = newNode("Plant 1", 1);
    root->left = newNode("Plant 2", 2);
    root->right = newNode("Plant 3", 3);
    root->left->left = newNode("Plant 4", 4);
    root->left->right = newNode("Plant 5", 5);
    root->right->left = newNode("Plant 6", 6);
    root->right->right = newNode("Plant 7", 7);

    // ��������������
    threadTree(root);

    // ����������򡢺���������
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
