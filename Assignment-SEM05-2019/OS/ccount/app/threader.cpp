#include "threader.hpp"

#include <pthread.h>
#include <iostream>
#include <map>
#include <memory>

#include "file_ops.hpp"

std::vector<pthread_t> bromine::threader::gen_worker_threads(void* (*thread_fun)(void*), std::vector<void*> fargs) {
    std::vector<pthread_t> worker_threads(fargs.size());

    for (int i = 0; i < (int)worker_threads.size(); i++) {
        pthread_create(&worker_threads[i], NULL, thread_fun, fargs[i]);
    }

    return worker_threads;
}

std::vector<void*> bromine::threader::get_threads_results(std::vector<pthread_t> threads) {
    auto results = std::vector<void*>(threads.size());

    for (int i = 0; i < (int)threads.size(); i++) {
        pthread_join(threads[i], &results[i]);
    }

    return results;
}