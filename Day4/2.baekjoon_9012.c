// 백준 9012번 괄호
// ( 나오면 푸시, ) 나오면 팝 그래서
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{   
    int n,i,j,check;
    int stack_size = 50;
    char *stack;

    calloc(stack_size,sizeof(char));
    stack = (char*)calloc(stack_size,sizeof(char));
    
    scanf("%d",&n); //사이즈 오브 스택 받기
    for(i=0;i<n;i++){
        int top = -1;
        int check = 1;
        scanf("%s",stack); // 괄호 명령 받기
        for (j=0;j<strlen(stack);j++) //괄호 개수만큼 반복문 돌리기
            if (stack[j] == '('){
                top+=1;
                }
            else if(stack[j]==')'){
                if (top==-1)
                    check = 0;
                top-=1;
                }
        if(top * check == -1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
