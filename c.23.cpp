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
    printf("二进制: ");
    while (s.top != -1) 
	{
        printf("%d", pop(&s));
    }
    printf("\n");
}

// 十进制转换为八进制
void Octal(int n) {
    Stack s;
    initStack(&s);
    
    while (n != 0) {
        push(&s, n % 8);
        n /= 8;
    }
    
    printf("八进制: ");
    while (s.top != -1) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

// 十进制转换为十六进制
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
    
    printf("十六进制: ");
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
    printf("请输入一个十进制数: ");
    scanf("%d", &decimal);
    Binary(decimal);
    Octal(decimal);
    Hexadecimal(decimal);

    return 0;
}
