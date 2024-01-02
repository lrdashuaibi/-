#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct Node {
    int value;                 // 节点值
    struct Node* left;         // 左子节点指针
    struct Node* right;        // 右子节点指针
} Node;

// 先序遍历
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

// 中序遍历
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

// 后序遍历
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

int main() {
    int n;
    scanf("%d", &n);

    Node* nodes = (Node*)malloc(n * sizeof(Node));

    // 读取节点信息并构建二叉树
    for (int i = 0; i < n; i++) {
        int value, leftIndex, rightIndex;
        scanf("%d %d %d", &value, &leftIndex, &rightIndex);
        nodes[i].value = value;
        if (leftIndex != -1) {
            nodes[i].left = &nodes[leftIndex];
        } else {
            nodes[i].left = NULL;
        }
        if (rightIndex != -1) {
            nodes[i].right = &nodes[rightIndex];
        } else {
            nodes[i].right = NULL;
        }
    }

    // 先序遍历
    preorder(&nodes[0]);
    printf("\n");

    // 中序遍历
    inorder(&nodes[0]);
    printf("\n");

    // 后序遍历
    postorder(&nodes[0]);
    printf("\n");

    free(nodes);
    return 0;
}
