#include <stdio.h>
#include <string.h>

// Manacher算法
char* longestPalindrome_Manacher(char* s) {
    int n = strlen(s);
    char t[2 * n + 3];
    t[0] = '^';
    for (int i = 0; i < n; i++) {
        t[2 * i + 1] = '#';
        t[2 * i + 2] = s[i];
    }
    t[2 * n + 1] = '#';
    t[2 * n + 2] = '$';

    int p[2 * n + 3];
    memset(p, 0, sizeof(p));
    int center = 0, right = 0;
    int max_len = 0, max_center = 0;
    for (int i = 1; i < 2 * n + 2; i++) {
        if (i < right) {
            p[i] = p[2 * center - i] < (right - i) ? p[2 * center - i] : (right - i);
        }
        while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
        if (p[i] > max_len) {
            max_len = p[i];
            max_center = i;
        }
    }

    int start = (max_center - max_len) / 2;
    s[start + max_len] = '\0';
    return s + start;
}

// 暴力匹配算法
char* longestPalindrome_BruteForce(char* s) {
    int n = strlen(s);
    int max_len = 0, start = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int is_palindrome = 1;
            for (int k = i, l = j; k < l; k++, l--) {
                if (s[k] != s[l]) {
                    is_palindrome = 0;
                    break;
                }
            }
            if (is_palindrome && j - i + 1 > max_len) {
                max_len = j - i + 1;
                start = i;
            }
        }
    }

    s[start + max_len] = '\0';
    return s + start;
}

int main() {
    char s[] = "ATGCCTAGGTGAGTTAC";

    char* result_Manacher = longestPalindrome_Manacher(s);
    printf("Manacher算法结果：%s\n", result_Manacher);

    char* result_BruteForce = longestPalindrome_BruteForce(s);
    printf("暴力匹配算法结果：%s\n", result_BruteForce);

    return 0;
}
