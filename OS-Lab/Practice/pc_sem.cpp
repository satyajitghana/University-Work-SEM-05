#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int buffer[MAX + 1];
int idx = 0;

sem_t mutex_pc;
sem_t full;
sem_t empty;

void init_vals() {
    sem_init(&mutex_pc, 0, 1);
    sem_init(&full, 0, MAX);
    sem_init(&empty, 0, 0);
}

int produce_item() {
    int item = rand();
    printf("produced : %d\n", item);
    return item;
}

void consume_item(int item) {
    printf("consumed : %d\n", item);
}

void* producer(void* farg) {
    for (int i = 0; i < MAX; i++) {
        sem_wait(&full);
        sem_wait(&mutex_pc);
        int item = produce_item();
        buffer[idx] = item;
        idx++;
        sem_post(&mutex_pc);
        sem_post(&empty);
    }

    return NULL;
}

void* consumer(void* farg) {
    for (int i = 0; i < MAX; i++) {
        sem_wait(&empty);
        sem_wait(&mutex_pc);
        int item = buffer[--idx];
        consume_item(item);
        sem_post(&mutex_pc);
        sem_post(&full);
    }

    return NULL;
}

int pc_sem() {
    init_vals();

    pthread_t producer_t, consumer_t;
    pthread_create(&producer_t, NULL, producer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);

    pthread_join(producer_t, NULL);
    pthread_join(consumer_t, NULL);

    return EXIT_SUCCESS;
}