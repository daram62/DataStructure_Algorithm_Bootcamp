// 문자열 입력받은 후 str/char 계산 후 그 문자열 거꾸로 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void){
    char str[10] = " ";
    int i =0, len =0;
    
    printf("문자열 입력 ==> ");
    scanf("%s",str);

    printf("sizeof(str)/sizeof(char) : %ld\n",sizeof(str)/sizeof(char));
    len = strlen(str);
    printf("len: %d\n",len);

    for(i=len-1;i>=0;i--){
        printf("%c",str[i]);
    }
    printf("\n");
}