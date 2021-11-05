// To Compile:
// gcc -pthread -o mycond mycond.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int balance = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void* incfn(void* args){

    for(int i = 0; i < 7; i++){
        balance += 50;
    }

}

int main() {
    pthread_t t1, t2;

    printf("Proces ID:$ld\n", getpid());

    pthread_mutex()
}