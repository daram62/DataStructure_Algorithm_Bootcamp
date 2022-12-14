#include <stdio.h>

int main()
{
    int arr[3][5];
    int *ptr;
    int i,j,x,y;
    ptr = arr;


    for(i=0; i<3; i++){
        for(j=0; j<5; j++){   
            *(ptr+i*5+j) = i*5+j;
        }
    }

    for(i=0; i<15 ;i++){
        x= i/5;
        y= i%5;
        printf("arr[%d][%d] = %d\n",x,y,arr[x][y]);
    }
    return 0;
}