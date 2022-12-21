/* 백준 10818 N개의 정수가 주어진다. 
이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.*/

#include <stdio.h>
#include <string.h>

int main(){
    int n,i,max,min;
    int num=0;
    scanf("%d",&n);
    scanf("%d",&num);
    max=num;
    min=num;
    for(i=0;i<n-1;i++){
        scanf("%d",&num);
        if(num>max)
            max=num;
        else if(num<min)
            min=num;
    }
    printf("%d %d",min,max);
}
