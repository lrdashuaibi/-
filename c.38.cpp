#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

void reverse(char* str) 
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
void remove(char* str) 
{
    int len = strlen(str);
    int i = 0;
    while (i < len && str[i] == '0') 
	{
        i++;
    }
    if (i == len) {
        str[0] = '0';
        str[1] = '\0';
    } else {
        for (int j = i; j <= len; j++) {
            str[j - i] = str[j];
        }
    }
}

char* add(char* num1, char* num2) 
{
    int len1 = strlen(num1), len2 = strlen(num2);
    char* result = (char*) malloc((MAX + 1) * sizeof(char));
    int carry = 0, i = 0, j = 0, k = 0;
    while (i < len1 || j < len2) {
        int n1 = (i < len1) ? (num1[i] - '0') : 0;
        int n2 = (j < len2) ? (num2[j] - '0') : 0;
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        result[k++] = (sum % 10) + '0';
        i++;
        j++;
    }
    if (carry > 0) {
        result[k++] = carry + '0';
    }
    result[k] = '\0';
    reverse(result);
    remove(result);

    return result;
}

char* subtract(char* num1, char* num2) 
{
    int len1 = strlen(num1), len2 = strlen(num2);
    char* result = (char*) malloc((MAX + 1) * sizeof(char));
    int borrow = 0, i = len1 - 1, j = len2 - 1, k = 0;

    while (i >= 0 || j >= 0) {
        int n1 = (i >= 0) ? (num1[i] - '0') : 0;
        int n2 = (j >= 0) ? (num2[j] - '0') : 0;
        int diff = n1 - n2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[k++] = diff + '0';
        i--;
        j--;
    }
    result[k] = '\0';

    reverse(result);
    remove(result);

    return result;
}

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1), len2 = strlen(num2);
    int* temp = (int*) calloc((len1 + len2), sizeof(int));
    char* result = (char*) malloc((MAX + 1) * sizeof(char));
    int i, j, k;

    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            int n1 = num1[i] - '0', n2 = num2[j] - '0';
            temp[i + j + 1] += n1 * n2;
        }
    }

    int carry = 0;
    for (k = len1 + len2 - 1; k >= 0; k--) {
        int sum = temp[k] + carry;
        carry = sum / 10;
        result[k] = (sum % 10) + '0';
    }
    result[len1 + len2] = '\0';

    reverse(result);
    remove(result);
    free(temp);
    return result;
}
int main() {
    char num1[MAX], num2[MAX];
    printf("请输入第一个大数：");
    scanf("%s", num1);
    printf("请输入第二个大数：");
    scanf("%s", num2);

    printf("它们的加法结果为：%s\n", add(num1, num2));
    printf("它们的减法结果为：%s\n", subtract(num1, num2));
    printf("它们的乘法结果为：%s\n", multiply(num1, num2));

    return 0;
}
