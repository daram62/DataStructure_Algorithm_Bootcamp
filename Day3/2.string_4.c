#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[30] = "There is no free lunch";

    char *ptr = strtok(s1, " "); // 공백 문자를 기준으로 문자열 자름

    while(ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
    }

    return 0;
}