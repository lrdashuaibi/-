#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct Node {
    int value;                 // �ڵ�ֵ
    struct Node* left;         // ���ӽڵ�ָ��
    struct Node* right;        // ���ӽڵ�ָ��
} Node;

// �������
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

// �������
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

// �������
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

    // ��ȡ�ڵ���Ϣ������������
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

    // �������
    preorder(&nodes[0]);
    printf("\n");

    // �������
    inorder(&nodes[0]);
    printf("\n");

    // �������
    postorder(&nodes[0]);
    printf("\n");

    free(nodes);
    return 0;
}
