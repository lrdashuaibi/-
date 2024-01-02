#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int v;
    struct node* pr;
    struct node* next;
} node;

node* create(int arr[], int size) 
{
    node *head, *p, *q;
    head = (node*)malloc(sizeof(node));
    head->v = -1;
    head->pr = NULL;
    p = head;

    for (int i = 0; i < size; i++) 
	{
        q = (node*)malloc(sizeof(node));
        q->v = arr[i];
        q->pr = p;
        p->next = q;
        p = q;
    }

    p->next = NULL;
    return head;
}

void print(node* head) 
{
    node* p = head->next;
    while (p != NULL) 
	{
        printf("%d ", p->v);
        p = p->next;
    }
    printf("\n");
}

int Sub(node* A, node* B) 
{
    if (B == NULL) 
	{
        return 1;
    }
    if (A == NULL) 
	{
        return 0;
	}
    if (A->v == B->v) 
	{
        return Sub(A->next, B->next);
    } else {
        return Sub(A->next, B);
    }
}

int main() {
    int aA[] = {1,3,5,7};
    int aB[] = {1,2,3};
    int sizeA = sizeof(aA) / sizeof(aA[0]);
    int sizeB = sizeof(aB) / sizeof(aB[0]);

    node* A = create(aA, sizeA);
    node* B = create(aB, sizeB);

    print(A);
    print(B);

    if (Sub(A->next, B->next)) {
        printf("是子序列。\n");
    } else {
        printf("不是子序列。\n");
    }

    return 0;
}
