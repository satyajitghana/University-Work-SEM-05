#include <array>
#include <iostream>
#include <memory>
#include <string>

#include <pthread.h>
#include <semaphore.h>

struct philosopher {
    pthread_t thread;
    int position;
    sem_t *fork_left, *fork_right;
    sem_t *mutex;
    std::string name;

    philosopher() {}
    philosopher(const std::string name);
};

philosopher::philosopher(const std::string name) : name(name) {}

constexpr int const num_phil = 5;

void initialize_sem_t(std::array<sem_t, num_phil> &forks, sem_t &mutex) {
    for (auto &fork : forks) {
        sem_init(&fork, 0, 1);
    }

    sem_init(&mutex, 0, forks.size() - 1);
}

void create_philosophers(std::array<philosopher, num_phil> &philosophers, std::array<std::string, num_phil> names, std::array<sem_t, num_phil> &forks, sem_t &mutex) {
    for (int i = 0; i < philosophers.size(); i++) {
        philosophers.at(i) = philosopher(names.at(i));
        philosophers.at(i).fork_left = &forks.at(i);
        philosophers.at(i).fork_right = &forks.at((i + 1) % forks.size());
        philosophers.at(i).position = i;
        philosophers.at(i).mutex = &mutex;
    }
}

void hungry(std::string name) {
    std::cout << ("Philosopher " + name + " is HUNGRY !\n");
}

void think(std::string name) {
    std::cout << ("Philosopher " + name + " is thinking 🤔 . . .\n");
}

void eat(std::string name) {
    std::cout << ("Philosopher " + name + " is eating\n");
}

void *philosopher_thread(void *args) {
    philosopher *curr = static_cast<philosopher *>(args);

    //  try twice for the fork
    for (int i = 0; i < 2; i++) {
        hungry(curr->name);

        sem_wait(curr->mutex);
        sem_wait(curr->fork_left);
        sem_wait(curr->fork_right);
        eat(curr->name);
        sem_post(curr->fork_left);
        sem_post(curr->fork_right);
        sem_post(curr->mutex);
    }

    think(curr->name);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    std::array<std::string, 5> names{"meow", "boww", "roar", "hiss", "howl"};

    std::array<sem_t, num_phil> forks;
    sem_t mutex;

    // initialize_sem_t the forks and the mutex
    initialize_sem_t(forks, mutex);

    std::array<philosopher, num_phil> philosophers;

    // create the philosophers
    create_philosophers(philosophers, names, forks, mutex);

    // run the philosophers
    for (int i = 0; i < num_phil; i++) {
        pthread_create(&philosophers.at(i).thread, NULL, philosopher_thread, &philosophers.at(i));
    }

    // wait for them to finish
    for (int i = 0; i < num_phil; i++) {
        pthread_join(philosophers.at(i).thread, NULL);
    }
}
