
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_READER 100
#define MAX_WRITER 100

int data, rcount;
sem_t mutex, writeblock;

void init_values() {
    data = rand();
    rcount = 0;
    sem_init(&mutex, 0, 1);
    sem_init(&writeblock, 0, 1);
}

void* reader_thread(void* farg) {
    unsigned long int pid = (pthread_t)farg;
    sem_wait(&mutex);
    rcount = rcount + 1;
    if (rcount == 1)
        sem_wait(&writeblock);
    sem_post(&mutex);

    printf("[READER TID %lu] : Read data %d\n", pid, data);

    // for (long i = 0; i < 1e9; i++)
    //     ;

    sem_wait(&mutex);
    rcount = rcount - 1;
    if (rcount == 0)
        sem_post(&writeblock);
    sem_post(&mutex);

    return NULL;
}

void* writer_thread(void* farg) {
    sem_wait(&writeblock);
    unsigned long int pid = (pthread_t)farg;
    data = rand();
    printf("[WRITER TID %lu] : Write data %d\n", pid, data);

    // for (long i = 0; i < 1e9; i++)
    //     ;

    sem_post(&writeblock);

    return NULL;
}

int rw() {
    // initialize the values
    init_values();

    pthread_t readers[MAX_READER];
    pthread_t writers[MAX_WRITER];

    // create the readers and writers
    for (int i = 0; i < MAX_WRITER; i++) {
        pthread_create(writers + i, NULL, writer_thread, writers + i);
        pthread_create(readers + i, NULL, reader_thread, readers + i);
    }

    // join the threads
    for (int i = 0; i < MAX_READER; i++) {
        pthread_join(readers[i], NULL);
        pthread_join(writers[i], NULL);
    }
    // for (int i = 0; i < MAX_WRITER; i++) {
    //     pthread_join(writers[i], NULL);
    // }

    return EXIT_SUCCESS;
}