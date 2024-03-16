#include<stdio.h>

int main()
{
    int number;
    int result=1;
    printf("enter number");
    scanf("%d",&number);
     while(number!=0)
     {
         result=result*number;
         number--;
     }
     printf("%d",result);
}
