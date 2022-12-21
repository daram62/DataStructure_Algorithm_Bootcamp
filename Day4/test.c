#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int elem;

int stack_top = -1;
int stack_size = 100000;
elem *stack;
int i = 0;

int size()
{
    return stack_top+1;
}

int empty()
{
    if (stack_top == -1){
        return 1;
    }
    return 0;
}

void push(elem item)
{   
    stack[++stack_top] =item;
}

elem pop()
{
    if(empty()){// 위랑 같음 !empty() 은 0이라는 뜻
        return -1;
    }
    else{
        return stack[stack_top--];
    }
}

elem top()
{   
    if(empty()){ // 얘도
        return -1;
    }
    else{
        return *(stack+stack_top);
    }
}

int main(void)
{
	int action = 0;
    int num=0;
	elem newElem = 0;
    char command[10000] ;
    scanf("%d",&num);
    int i ;
    stack = (int*)malloc(stack_size*sizeof(int));

    for(i=0;i<num;i++){    
		scanf("%s",command);
        if (!strcmp(command,"push"))
            action = 1;
        else if (!strcmp(command,"pop"))
            action = 2;
        else if (!strcmp(command,"top"))
            action = 3;
        else if (!strcmp(command,"size"))
            action = 4;
        else if (!strcmp(command,"empty"))
            action = 5;

		switch(action)
		{
		case 1:
			scanf("%d", &newElem);
			push(newElem);
            break;
		case 2:
			printf("%d\n", pop());
			break;
		case 3:
			printf("%d\n", top());
			break;
		case 4:
			printf("%d\n", size());
			break;
		case 5:
            printf("%d\n",empty());
            break;
		}
    }
}