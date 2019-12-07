#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_M 10

int buffer_m[MAX_M];
int buffer_m_idx = 0;

pthread_mutex_t mutex_m;
pthread_cond_t full_m, empty_m;

void init_m() {
    mutex_m = PTHREAD_MUTEX_INITIALIZER;
    full_m = PTHREAD_COND_INITIALIZER;
    empty_m = PTHREAD_COND_INITIALIZER;
}

int produce_item_m() {
    int item = rand();
    printf("produced : %d\n", item);
    return item;
}

void consume_item_m(int item) {
    printf("consumed : %d\n", item);
}

void* producer_m(void* farg) {
    for (int i = 0; i < MAX_M; i++) {
        pthread_mutex_lock(&mutex_m);
        if (buffer_m_idx == MAX_M)
            pthread_cond_wait(&empty_m, &mutex_m);
        int item = produce_item_m();
        buffer_m[buffer_m_idx++] = item;
        pthread_mutex_unlock(&mutex_m);
        pthread_cond_signal(&full_m);
    }
    return NULL;
}

void* consumer_m(void* farg) {
    for (int i = 0; i < MAX_M; i++) {
        pthread_mutex_lock(&mutex_m);
        if (buffer_m_idx == 0)
            pthread_cond_wait(&full_m, &mutex_m);
        int item = buffer_m[--buffer_m_idx];
        consume_item_m(item);
        pthread_mutex_unlock(&mutex_m);
        pthread_cond_signal(&empty_m);
    }
    return NULL;
}

int pc_mutex() {
    init_m();

    pthread_t producer, consumer;
    pthread_create(&producer, NULL, producer_m, NULL);
    pthread_create(&consumer, NULL, consumer_m, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    return EXIT_SUCCESS;
}