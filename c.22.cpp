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
    
    printf("请输入序列：");
    scanf("%s", sequence);
    
    printf("请输入字符集：");
    scanf("%s", charset);
    
    if (isValid(sequence, charset)) 
	{
        printf("是合法的出栈序列。\n");
    } else {
        printf("不是合法的出栈序列。\n");
    }
    
    return 0;
}
