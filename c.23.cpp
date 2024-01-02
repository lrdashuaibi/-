#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct 
{
    int data[MAX_SIZE];
    int top;  
} Stack;
void initStack(Stack *s) 
{
    s->top = -1;
}
void push(Stack *s, int num) {
    s->data[++s->top] = num;
}
int pop(Stack *s) 
{
    return s->data[s->top--];
}
void Binary(int n) 
{
    Stack s;
    initStack(&s);    
    while (n != 0) 
	{
        push(&s, n % 2);
        n /= 2;
    }
    printf("������: ");
    while (s.top != -1) 
	{
        printf("%d", pop(&s));
    }
    printf("\n");
}

// ʮ����ת��Ϊ�˽���
void Octal(int n) {
    Stack s;
    initStack(&s);
    
    while (n != 0) {
        push(&s, n % 8);
        n /= 8;
    }
    
    printf("�˽���: ");
    while (s.top != -1) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

// ʮ����ת��Ϊʮ������
void Hexadecimal(int n) {
    Stack s;
    initStack(&s);
    
    while (n != 0) {
        int remainder = n % 16;
        if (remainder < 10) {
            push(&s, remainder);
        } else {
            push(&s, remainder + 'A' - 10);
        }
        n /= 16;
    }
    
    printf("ʮ������: ");
    while (s.top != -1) {
        int digit = pop(&s);
        if (digit < 10) {
            printf("%d", digit);
        } else {
            printf("%c", digit + 'A' - 10);
        }
    }
    printf("\n");
}
int main() {
    int decimal;
    printf("������һ��ʮ������: ");
    scanf("%d", &decimal);
    Binary(decimal);
    Octal(decimal);
    Hexadecimal(decimal);

    return 0;
}
