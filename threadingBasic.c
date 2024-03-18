#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5


void *threadFunction(void *arg) {
    int thread_id = *((int *)arg);
    printf("Hello from thread %d\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_args[i] = i;
        int result = pthread_create(&threads[i], NULL, threadFunction, &thread_args[i]);
        if (result) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }


    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed\n");

    return 0;
}
