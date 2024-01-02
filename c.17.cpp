#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* create(int n) 
{
    struct Node* head = NULL;
    struct Node* current = NULL;

    for (int i = 1; i <= n; i++) 
	{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL) 
		{
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }
    current->next = head; 
    return head;
}

void j(int n, int m) 
{
    struct Node* head = create(n);
    struct Node* current = head;
    for (int i = 1; i < m - 1; i++) 
	{
        current = current->next;
    }
    printf("����̭���˵�˳��");
    while (n > 1) 
	{
        struct Node* temp = current->next; 
        current->next = temp->next; 
        printf("%d ", temp->data);
        free(temp); 

        current = current->next; 
        n--; 
    }
    printf("\n���ʣ�µ��ˣ�%d\n", current->data);
    free(current); 
}

int main() {
    int n = 10; 
    int m = 3;
    j(n, m);
    
    return 0;
}
