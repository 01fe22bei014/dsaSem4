#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define ITERATIONS 1000000


int sharedCounetr=0;
pthread_mutex_t mutex;


void *incrementThread(void *arg)
{
    for(int i=0 ; i<ITERATIONS ; i++)
    {
        pthread_mutex_lock(&mutex);
        sharedCounetr++;
        pthread_mutex_unlock(&mutex);

    }

}

int main()
{
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex,NULL);

    for(int i=0;i<NUM_THREADS;i++)
    {
        if(pthread_create(&threads[i],NULL,incrementThread,NULL)!=0)
        {
            printf("fail");
        }


    }

    for(int i=0;i<NUM_THREADS;i++)
    {
        if(pthread_join(threads[i],NULL)!=0)
        {
            printf("fail");
        }

    }

    pthread_mutex_destroy(&mutex);

    printf("final answewr is %d ",sharedCounetr);


}
