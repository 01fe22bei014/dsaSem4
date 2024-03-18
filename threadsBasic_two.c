#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void myTurn()
{
    while(1)
    {
       for(int i=0 ; i<5 ; i++)
        {
            sleep(1);
        printf("my turn %d \n",i);
        }
    }
    return NULL;
}

void* yourTurn(void *arg)
{
    while(1)
    {

        for(int i=0;i<3;i++)
    {
        sleep(2);
        printf("your turn %d \n",i);
    }
    }

}

int main()
{
    pthread_t newThread;
    pthread_create(&newThread,NULL,yourTurn,NULL);
    myTurn();
    pthread_join(newThread,NULL);

    return 0;


}
