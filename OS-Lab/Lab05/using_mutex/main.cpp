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
    int buf_idx;
    int N;

    pthread_mutex_t mutex;
    pthread_cond_t c_cond, p_cond;

    bool is_empty = false;
    bool is_full = false;

    buffer_t(const int N);
} buffer(10);

buffer_t::buffer_t(const int N = 10) : N(N) {
    c_cond = PTHREAD_COND_INITIALIZER;
    p_cond = PTHREAD_COND_INITIALIZER;
    mutex = PTHREAD_MUTEX_INITIALIZER;
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
        pthread_mutex_lock(&buffer.mutex);
        buffer.is_full = buffer.data.size() == buffer.N;
        if (buffer.is_full) {
            pthread_cond_wait(&buffer.p_cond, &buffer.mutex); /* wait for the consumer */
        }
        int item = produce_item();
        buffer.data.push_back(item);
        pthread_mutex_unlock(&buffer.mutex);
        pthread_cond_signal(&buffer.c_cond); /* signal the consumer */
    }

    pthread_exit(NULL);
}

void* consumer(void* args) {
    for (int i = 0; i < buffer.N; i++) {
        pthread_mutex_lock(&buffer.mutex);
        buffer.is_empty = buffer.data.size() == 0;
        if (buffer.is_empty) {
            pthread_cond_wait(&buffer.c_cond, &buffer.mutex); /* wait for the producer */
        }
        int item = buffer.data.back();
        consume_item(item);
        buffer.data.pop_back();
        pthread_mutex_unlock(&buffer.mutex);
        pthread_cond_signal(&buffer.p_cond); /* singal the producer */
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
