#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct HuffmanNode {
    char data;              
    double freq;            
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

HuffmanNode* create(char data, double freq) 
{
    HuffmanNode* node = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void swap(HuffmanNode** a, HuffmanNode** b) 
{
    HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}
void sort(HuffmanNode** nodes, int size) 
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (nodes[j]->freq > nodes[j + 1]->freq) {
                swap(&nodes[j], &nodes[j + 1]);
            }
        }
    }
}
HuffmanNode* build(char data[], double freq[], int size) {
    HuffmanNode *left, *right, *parent;
    HuffmanNode** nodes = (HuffmanNode**) malloc(size * sizeof(HuffmanNode*));
    for (int i = 0; i < size; i++) {
        nodes[i] = create(data[i], freq[i]);
    }

    sort(nodes, size);

    while (size > 1) {
        left = nodes[0];
        right = nodes[1];
        parent = create('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        nodes[0] = parent;
        for (int i = 1; i < size - 1; i++) 
		{
            nodes[i] = nodes[i + 1];
        }
        size--;
        sort(nodes, size);
    }

    HuffmanNode* root = nodes[0];
    free(nodes);
    return root;
}

void generate(HuffmanNode* root, char* code, int index) {
    if (root->left != NULL) {
        code[index] = '0';
        generate(root->left, code, index + 1);
    }

    if (root->right != NULL) {
        code[index] = '1';
        generate(root->right, code, index + 1);
    }

    if (root->left == NULL && root->right == NULL) {
        code[index] = '\0';
        printf("%c: %s\n", root->data, code);
    }
}

int main() {
    char data[] = {'A', 'B', 'C', 'D', 'E'};
    double freq[] = {0.03, 0.06, 0.09, 0.15, 0.17};
    int size = sizeof(data) / sizeof(data[0]);

    HuffmanNode* root = build(data, freq, size);

    char code[100];
    generate(root, code, 0);

    return 0;
}
