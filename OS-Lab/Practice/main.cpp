#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define N_PHIL 5

struct philosopher_t {
    int idx;
    sem_t* fork_left;
    sem_t* fork_right;
    sem_t* mutex;
};

sem_t forks[N_PHIL];
sem_t mutex_p;

philosopher_t philosophers[N_PHIL];

void init_phils() {
    sem_init(&mutex_p, 0, 1);
    for (int i = 0; i < N_PHIL; i++) {
        sem_init(forks + i, 0, 1);
    }

    // initialize the phils
    for (int i = 0; i < N_PHIL; i++) {
        philosophers[i].fork_left = &(forks[i]);
        philosophers[i].fork_right = &(forks[(i + 1) % N_PHIL]);
        philosophers[i].mutex = &mutex_p;
        philosophers[i].idx = i;
    }
}

void eat(int i) {
    printf("Philosopher %d is eating\n", i);
}

void think(int i) {
    printf("Philosopher %d is thinking\n", i);
}

void hungry(int i) {
    printf("Philosopher %i is hungry\n", i);
}

void* phil_thread(void* varg) {
    philosopher_t curr_phil = *(philosopher_t*)varg;

    hungry(curr_phil.idx);

    sem_wait(curr_phil.mutex);
    sem_wait(curr_phil.fork_left);
    sem_wait(curr_phil.fork_right);
    eat(curr_phil.idx);
    sem_post(curr_phil.fork_right);
    sem_post(curr_phil.fork_left);
    sem_post(curr_phil.mutex);

    think(curr_phil.idx);

    return NULL;
}

int main(int argc, char* argv[]) {
    init_phils();

    pthread_t phils[N_PHIL];
    for (int i = 0; i < N_PHIL; i++) {
        pthread_create(phils + i, NULL, phil_thread, philosophers + i);
    }

    for (int i = 0; i < N_PHIL; i++) {
        pthread_join(phils[i], NULL);
    }
    return EXIT_SUCCESS;
}