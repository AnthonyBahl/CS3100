// To Compile:
// gcc -pthread -o sd semdemo.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int count = 0;

pthread_mutex_t mutex;

sem_t sem;

// critical section
void* incVal(){
    for (int i = 0; i < 10000000; i++)
    {
        // Lock
        // pthread_mutex_lock(&mutex);

        // Wait for semiphore to be >= 0. Then decrement value of semaphore
        sem_wait(&sem);

        count++; //global data

        // Unlock
        //pthread_mutex_unlock(&mutex);

        // Increment value of semaphore
        sem_post(&sem);
    }
}

int main(){

    pthread_t t1, t2, t3, t4;

    // Initialize
    //pthread_mutex_init(&mutex, NULL);
    sem_init(&sem, 0, 1);    // Initialized as 1

    pthread_create(&t1, NULL, incVal, NULL);
    pthread_create(&t2, NULL, incVal, NULL);
    pthread_create(&t3, NULL, incVal, NULL);
    pthread_create(&t4, NULL, incVal, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    // Destroy
    //pthread_mutex_destroy(&mutex);
    sem_destroy(&sem);

    printf("\nCount value is: %d\n", count);

    return 0;
}