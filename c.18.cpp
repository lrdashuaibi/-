#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* create() 
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 0;
    head->prev = head;
    head->next = head;
    return head;
}

void insertNode(struct Node* head, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = head->prev;
    newNode->next = head;

    head->prev->next = newNode;
    head->prev = newNode;
}

void deleteNode(struct Node* node) //删除 
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

struct Node* intersection(struct Node* setA, struct Node* setB) //合并 
{
    struct Node* result = create();
    struct Node* nodeA = setA->next;
    while (nodeA != setA) 
	{
        struct Node* nodeB = setB->next;

        while (nodeB != setB) {
            if (nodeA->data == nodeB->data) {
                insertNode(result, nodeA->data);
                break;
            }

            nodeB = nodeB->next;
        }

        nodeA = nodeA->next;
    }
    return result;
}

// 求集合的并集
struct Node* unionSet(struct Node* setA, struct Node* setB) {
    struct Node* result = create();
    struct Node* nodeA = setA->next;

    while (nodeA != setA) {
        insertNode(result, nodeA->data);
        nodeA = nodeA->next;
    }

    struct Node* nodeB = setB->next;

    while (nodeB != setB) 
	{
        struct Node* node = setA->next;
        int found = 0;

        while (node != setA) 
		{
            if (node->data == nodeB->data) 
			{
                found = 1;
                break;
            }

            node = node->next;
        }

        if (!found) {
            insertNode(result, nodeB->data);
        }

        nodeB = nodeB->next;
    }

    return result;
}

void print(struct Node* head) 
{
    struct Node* current = head->next;

    while (current != head) 
	{
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void free(struct Node* head) 
{
    struct Node* current = head->next;

    while (current != head) 
	{
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() 
{
    struct Node* setA1 = create();
    insertNode(setA1, 1);
    insertNode(setA1, 2);
    insertNode(setA1, 3);
    insertNode(setA1, 4);
    insertNode(setA1, 5);

    struct Node* setB1 = create();
    insertNode(setB1, 3);
    insertNode(setB1, 4);
    insertNode(setB1, 5);
    insertNode(setB1, 6);
    insertNode(setB1, 7);
    printf("集合A：");
    print(setA1);
    printf("集合B：");
    print(setB1);
    struct Node* intersectionSet1 = intersection(setA1, setB1);
    printf("交集：");
    print(intersectionSet1);
    struct Node* unionSet1 = unionSet(setA1, setB1);
    printf("并集：");
    print(unionSet1);
    free(setA1);
    free(setB1);
    free(intersectionSet1);
    free(unionSet1);

    // 测试用例2
    struct Node* setA2 = create();
    insertNode(setA2, 8);
    insertNode(setA2, 9);
    insertNode(setA2, 10);
    insertNode(setA2, 11);
    insertNode(setA2, 12);

    struct Node* setB2 = create();
    insertNode(setB2, 10);
    insertNode(setB2, 11);
    insertNode(setB2, 12);
    insertNode(setB2, 13);
    insertNode(setB2, 14);

    printf("集合A：");
    print(setA2);
    printf("集合B：");
    print(setB2);
    struct Node* intersectionSet2 = intersection(setA2, setB2);
    printf("交集：");
    print(intersectionSet2);
    struct Node* unionSet2 = unionSet(setA2, setB2);
    printf("并集：");
    print(unionSet2);
    free(setA2);
    free(setB2);
    free(intersectionSet2);
    free(unionSet2);

    return 0;
}
