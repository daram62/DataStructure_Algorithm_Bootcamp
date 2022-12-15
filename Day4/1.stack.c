#include <stdio.h>
#include <stdlib.h>
typedef int elem;

int stack_top = -1;
int stack_size = 0;
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
    //stack_top ++;
    //*(stack+stack_top)=item;
    stack[++stack_top] =item;
    }
}

elem pop()
{
    if(empty()){// 위랑 같음 !empty() 은 0이라는 뜻
        printf("Stack is empty!\n");
        return -1;
    }
    else{
        //int num;
        //num =*(stack+stack_top)--;// 해봐야함!!!
        //stack_top --;
        //return num;}
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
	int action = 0;
	elem newElem = 0;
	printf("Size of stack: ");
	scanf("%d", &stack_size);
	rewind(stdin);
	// dynamic allocation

    int i ;
    calloc(stack_size,sizeof(int));
    stack = (int*)calloc(stack_size,sizeof(int));

	while(1)
	{
		printf("\nChoose action: \n");
		printf("1: push(), 2: pop(), 3: top(), 4: size(), 5: empty(), 6: end\n>>> ");
		scanf("%d", &action);
		rewind(stdin);

		switch(action)
		{
		case 1:
			printf("Element to push: ");
			scanf("%d", &newElem);
			rewind(stdin);
			push(newElem);
            printf("저장된 스택: ");
			print();
			printf("\n");
            break;
		case 2:
			printf("pop(): %d\n", pop());
            printf("저장된 스택: ");
			print();
			printf("\n");
			break;
		case 3:
			printf("top(): %d\n", top());
            printf("저장된 스택: ");
			print();
			printf("\n");
			break;
		case 4:
			printf("size(): %d\n", size());
            printf("저장된 스택: ");
			print();
			printf("\n");
			break;
		case 5:
            if(empty()==0)
                printf("empty(): Not empty\n");
            else   
                printf("empty(): Empty\n");
            printf("저장된 스택: ");
			print();
			printf("\n");
			break;
		case 6:
			printf("End the program\n");
			exit(0);
		default:
			printf("Wrong option: %d\n", action);
		}
	}
}