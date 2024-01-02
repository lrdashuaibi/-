#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定义栈结构
struct Stack {
    int top;
    double* items;
};

// 创建栈
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->items = (double*)malloc(capacity * sizeof(double));

    return stack;
}

// 判断栈是否为空
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// 入栈
void push(struct Stack* stack, double item) {
    stack->items[++stack->top] = item;
}

// 出栈
double pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return stack->items[stack->top--];
}

// 获取栈顶元素
double peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return stack->items[stack->top];
}

// 判断一个字符是否为运算符
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// 判断一个字符的优先级
int getPriority(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

// 执行运算
double executeOperation(double operand1, double operand2, char operator) 
{
    switch (operator) 
	{
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return pow(operand1, operand2);
        default:
            return 0.0;
    }
}

// 计算表达式的结果
double calculateExpression(char* expression) {
    struct Stack* operandStack = createStack(100);
    struct Stack* operatorStack = createStack(100);

    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] == ' ') {
            i++;
            continue;
        } else if (isdigit(expression[i]) || expression[i] == '.' || (expression[i] == '-' && (i == 0 || isOperator(expression[i-1])))) {
            double operand = 0.0;
            int isFloat = 0;
            int floatFactor = 1;
            int isNegative = 0;

            if (expression[i] == '-') {
                isNegative = 1;
                i++;
            }

            while (expression[i] != '\0' && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    isFloat = 1;
                    i++;
                    continue;
                }

                if (isFloat) {
                    operand = operand + (expression[i] - '0') / pow(10, floatFactor);
                    floatFactor++;
                } else {
                    operand = operand * 10 + (expression[i] - '0');
                }

                i++;
            }

            if (isNegative) {
                operand = -operand;
            }

            push(operandStack, operand);
        } else if (isOperator(expression[i])) {
            while (!isEmpty(operatorStack) && getPriority(expression[i]) <= getPriority(peek(operatorStack))) {
                double operand2 = pop(operandStack);
                double operand1 = pop(operandStack);
                char operator = pop(operatorStack);
                double result = executeOperation(operand1, operand2, operator);

                push(operandStack, result);
            }

            push(operatorStack, expression[i]);
            i++;
        } else if (expression[i] == '(') {
            push(operatorStack, expression[i]);
            i++;
        } else if (expression[i] == ')') {
            while (!isEmpty(operatorStack) && peek(operatorStack) != '(') {
                double operand2 = pop(operandStack);
                double operand1 = pop(operandStack);
                char operator = pop(operatorStack);
                double result = executeOperation(operand1, operand2, operator);

                push(operandStack, result);
            }

            if (!isEmpty(operatorStack) && peek(operatorStack) == '(') {
                pop(operatorStack);
            }

            i++;
        } else {
            printf("Error: Invalid character in expression\n");
            exit(EXIT_FAILURE);
        }
    }

    while (!isEmpty(operatorStack)) {
        double operand2 = pop(operandStack);
        double operand1 = pop(operandStack);
        char operator = pop(operatorStack);
        double result = executeOperation(operand1, operand2, operator);

        push(operandStack, result);
    }

    double finalResult = pop(operandStack);

    free(operandStack->items);
    free(operatorStack->items);
    free(operandStack);
    free(operatorStack);

    return finalResult;
}

int main() {
    char expression1[] = "3 + 4 * 2 / (1 - 5)^2";
    double result1 = calculateExpression(expression1);
    printf("Result: %.3f\n", result1);

    char expression2[] = "-2.3 + 4.56 * 3.1";
    double result2 = calculateExpression(expression2);
    printf("Result: %.3f\n", result2);

    return 0;
}
