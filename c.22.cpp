#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct 
{
    char data[MAX_SIZE];
    int top; 
} Stack;

void initStack(Stack *s) 
{
    s->top = -1;
}

void push(Stack *s, char c)
{
    s->data[++s->top] = c;
}
char pop(Stack *s) 
{
    return s->data[s->top--];
}
int isValid(char* sequence, char* charset) 
{
    int i, j = 0;
    Stack s;
    initStack(&s);    
    for (i = 0; i < strlen(sequence); i++) {
        push(&s, sequence[i]);
        while (s.top >= 0 && s.data[s.top] == charset[j]) {
            pop(&s);
            j++;
        }
    }
    
    return s.top == -1 && j == strlen(charset);
}

int main() 
{
    char sequence[MAX_SIZE];
    char charset[MAX_SIZE];
    
    printf("���������У�");
    scanf("%s", sequence);
    
    printf("�������ַ�����");
    scanf("%s", charset);
    
    if (isValid(sequence, charset)) 
	{
        printf("�ǺϷ��ĳ�ջ���С�\n");
    } else {
        printf("���ǺϷ��ĳ�ջ���С�\n");
    }
    
    return 0;
}
