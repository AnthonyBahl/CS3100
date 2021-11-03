#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int count = 0;

pthread_mutex_t mutex;

// critical section
void* incVal(){
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        count++; //global data
        pthread_mutex_unlock(&mutex);
    }
}

int main(){

    pthread_t t1, t2, t3, t4;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, incVal, NULL);
    pthread_create(&t2, NULL, incVal, NULL);
    pthread_create(&t3, NULL, incVal, NULL);
    pthread_create(&t4, NULL, incVal, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    pthread_mutex_destroy(&mutex);

    printf("\nCount value is: %d\n", count);

    return 0;
}