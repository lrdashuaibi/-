#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sentence(char *str) {
    int i, j, len;
    len = strlen(str);
    while (isspace(str[0])) 
	{
        memmove(str, str+1, len--);
    }
    while (len > 0 && isspace(str[len-1])) 
	{
        str[--len] = '\0';
    }
    for (i = j = 0; i < len; i++) 
	{
        if (isspace(str[i])) 
		{
            if (j > 0 && !isspace(str[j-1])) 
			{
                str[j++] = ' ';
            }
        } else {
            str[j++] = str[i];
        }
    }
    if (isspace(str[0])) {
        memmove(str, str+1, len--);
    }
}

int main() {
    char str1[] = "This is an example sentence.";
    char str2[] = " Hello world! ";
    sentence(str1);
    sentence(str2);
    printf("%s\n", str1); // Êä³ö£º"This is an example sentence."
    printf("%s\n", str2); // Êä³ö£º"Hello world!"
    return 0;
}

