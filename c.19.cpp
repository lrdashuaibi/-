#include <stdio.h>
#include <stdlib.h>
typedef struct Node 
{
    int data;
    struct Node* next;
} ListNode;

void insertNode(ListNode** head, int data) 
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) 
	{
        *head = newNode;
    } 
		else 
	{
        ListNode* current = *head;
        while (current->next != NULL) 
		{
            current = current->next;
        }
        current->next = newNode;
    }
}

void sp(ListNode* head, ListNode** odd, ListNode** even) 
{
    ListNode* current = head;
    ListNode* oddTail = NULL;
    ListNode* evenTail = NULL;
    int count = 1;

    while (current != NULL) 
	{
        if (count % 2 == 1) 
		{
            if (*odd == NULL) 
			{
                *odd = current;
                oddTail = current;
            } 
				else 
			{
                oddTail->next = current;
                oddTail = current;
            }
        } 
			else 
		{
            if (*even == NULL) 
			{
                *even = current;
                evenTail = current;
            } 
				else 
			{
                evenTail->next = current;
                evenTail = current;
            }
        }

        current = current->next;
        count++;
    }

    if (oddTail != NULL) 
	{
        oddTail->next = NULL;
    }
    if (evenTail != NULL) 
	{
        evenTail->next = NULL;
    }
}

void print(ListNode* head) 
{
    ListNode* current = head;
    while (current != NULL) 
	{
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free(ListNode* head) 
{
    ListNode* current = head;
    while (current != NULL)
	{
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    ListNode* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);
    insertNode(&head, 7);
    insertNode(&head, 8);
    insertNode(&head, 9);
    insertNode(&head, 10);
    ListNode* odd = NULL;
    ListNode* even = NULL;
    sp(head, &odd, &even);

    printf("L1: ");
    print(odd);
    printf("L2: ");
    print(even);

    free(odd);
    free(even);

    return 0;
}
