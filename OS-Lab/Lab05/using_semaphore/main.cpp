#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <vector>

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_SIZE 5

struct buffer_t {
    std::vector<int> data;
    sem_t empty;
    sem_t full;
    sem_t mutex;
    int N;

    buffer_t(const int N);
} buffer(10);

buffer_t::buffer_t(const int N = 10) : N(N) {
    sem_init(&(this->empty), 0, N);
    sem_init(&(this->full), 0, 0);
    sem_init(&(this->mutex), 0, 1);
}

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(0, std::numeric_limits<int>::max());

int produce_item() {
    const int item = dist(mt);
    printf("Produced : %d\n", item);
    return item;
}

void consume_item(const int& item) {
    printf("Consumed : %d\n", item);
}

void* producer(void* args) {
    for (int i = 0; i < buffer.N; i++) {
        sem_wait(&buffer.empty);
        sem_wait(&buffer.mutex);
        int item = produce_item();
        buffer.data.push_back(item);
        sem_post(&buffer.mutex);
        sem_post(&buffer.full);
    }

    pthread_exit(NULL);
}

void* consumer(void* args) {
    for (int i = 0; i < buffer.N; i++) {
        sem_wait(&buffer.full);
        sem_wait(&buffer.mutex);
        int item = buffer.data.back();
        consume_item(item);
        buffer.data.pop_back();
        sem_post(&buffer.mutex);
        sem_post(&buffer.empty);
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    pthread_t t_producer, t_consumer;

    pthread_create(&t_producer, NULL, producer, NULL);
    pthread_create(&t_consumer, NULL, consumer, NULL);

    pthread_join(t_producer, NULL);
    pthread_join(t_consumer, NULL);
}
