/*  비밀지도 문제 
    비밀지도는 숫자로 암호화, 지도는 한 변의 길이가 n인 정사각형 배열 형태, 각 칸은 공백 또는 벽으로 구성
    전체 지도는 두장의 지도 겹쳐서 얻을 수 있음. 지도1,지도2 각각 정수 배열로 암호화
    암호화된 배열은 각 가로줄에서 벽을 1, 공백을 0으로 부호화했을 때 얻어지는 이진수에 해당하는 값의 배열
    
    네오가 비상금 얻을 수 있도록 비밀지도 암호 해독*/

#include <stdio.h>

void f(int n);

int main(){
    int i,n = 0;
    int arr1[10] = {0, };
    int arr2[10] = {0, };
    int final[10] = {0, };
    int atoi ( const char* str );

    printf("지도의 한 변의 길이를 입력해주세요 : ");
    scanf("%d",&n);
    
    printf("\n첫 번째 지도를 배열 형태로 입력해주세요 : ");
    for(i= 0;i<n;i++)
        scanf("%d",&arr1[i]);      
    
    printf("\n두 번째 지도를 배열 형태로 입력해주세요 : ");
    for(i= 0;i<n;i++)
        scanf("%d",&arr2[i]);

    for (int i =0; i<n; i++)
    {   final[i]= arr1[i] | arr2[i]; 
        f(final[i]);
        printf(", ");
    }
}

void f(int n){
    if(n>1)
        f(n/2);
    if(n%2 ==1)
        printf("#");
    else
        printf(" ");
}