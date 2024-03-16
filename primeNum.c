include<stdio.h>
include<stdlib.h>

int main()
{
    int number;
    int t=0;
    printf("enter number");
    scanf("%d",&number);

    while(num!=0)
    {

        for(int i=1 ; i<=number ; i++)
        {
            if(number/i==1)
            {

                t++;
            }


        }
        if(t==0)
        {

            printf("number is not prime");
        }
        else{
            printf("number is prime");
        }
    }

}
