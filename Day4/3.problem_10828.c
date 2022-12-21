#include <stdio.h>
#include <stdlib.h>
typedef int elem;

int stack_top = -1;
int stack_size = 100;
elem *stack;
int i = 0;

int size()
{    return stack_top+1;}

int empty()
{
    if (stack_top == -1){
        return 1;
    }
    return 0;
}

int full()
{
    if(stack_top+1 == stack_size){
        return 1;
    }
    return 0;
}

void push(elem item)
{   
    if(full()){ //==1안해도, 0이 아니면 실행됨
        printf("Stack is full!\n");
    }
    else{
    stack[++stack_top] =item;
    }
}

elem pop()
{
    if(empty()){// 위랑 같음 !empty() 은 0이라는 뜻
        printf("Stack is empty!\n");
        return -1;
    }
    else
        return stack[stack_top--];
}

elem top()
{   
    if(empty()){ // 얘도
        printf("Stack is empty!\n");
        return -1;
    }
    else{
        return *(stack+stack_top);
    }
}

void print()
{
    if(empty()==1){
        printf("Stack is empty!\n");
    }
    else{
        for(i=stack_top; i>-1; i--){
        printf("%d ",*(stack+i));
        }
    }
}

int main(void)
{
	char action[100];
	elem newElem = 0;
    int command =0 ;
	scanf("%d", &command);

    calloc(stack_size,sizeof(int));
    stack = (int*)calloc(stack_size,sizeof(int));

    for (int i=0;i<command;i++){
        scanf("%s", &action);
        printf("%s\n",action);
        if(action == "push"){
            printf("Element to push: ");
			scanf("%d", &newElem);
			push(newElem);
            printf("저장된 스택: ");
			print();
			printf("\n");
            break;
        }
        else if(action=="pop"){
            printf("pop(): %d\n", pop());
            printf("저장된 스택: ");
			print();
			printf("\n");
			break;
        }
        else if(action=="size"){
            printf("size(): %d\n", size());
            printf("저장된 스택: ");
			print();
			printf("\n");
			break;
        }
        else if(action=="empty"){
             if(empty()==0)
                printf("empty(): Not empty\n");
            else   
                printf("empty(): Empty\n");
            printf("저장된 스택: ");
			print();
			printf("\n");
			break;
        }
        else if(action=="top"){
            printf("top(): %d\n", top());
            printf("저장된 스택: ");
			print();
			printf("\n");
			break;
        }
    }
}