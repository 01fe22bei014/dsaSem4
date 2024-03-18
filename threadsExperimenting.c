#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include<error.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel=0;


void *fuelFilling(void *arg)
{
    for(int i=0 ; i<5  ; i++)
    {
        pthread_mutex_lock(&mutexFuel);
        fuel+=15;
        printf("filled fuel %d \n",fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);
        sleep(1);
    }

}


void car(void *arg)
{
        pthread_mutex_lock(&mutexFuel);
        while(fuel<40)
        {
        printf("no fuel waiting  \n");
        pthread_cond_wait(&condFuel,&mutexFuel);
        }
        fuel-=40;
        printf("got fuel now left %d\n",fuel);
        pthread_mutex_unlock(&mutexFuel);
}


int main()
{
    pthread_t th[2];
    pthread_mutex_init(&mutexFuel,NULL);
    pthread_mutex_init(&condFuel,NULL);
    for(int i=0;i<2;i++)
    {
        if(i==1)
        {
            if(pthread_create(&th[i],NULL,&fuelFilling,NULL)!=0)
            {
                perror("failed to create thread");
            }

        }
        else{
            if(pthread_create(&th[i],NULL,&car,NULL)!=0)
            {
                perror("failed to create thread");

            }
        }
    }
    for(int i =0;i<2;i++)
    {
        if(pthread_join(th[i],NULL)!=0)
        {
            perror("failed to join thread");
        }

    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_mutex_destroy(&condFuel);
    return 0;
}
