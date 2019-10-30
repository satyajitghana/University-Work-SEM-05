#include "threader.hpp"

#include <pthread.h>
#include <iostream>
#include <map>
#include <memory>

#include "file_ops.hpp"

/**
 * generates worker threads
 * @param pointer to the thread function, arguments to the thread function
 * @return vector of threads
*/
std::vector<pthread_t> bromine::threader::gen_worker_threads(void* (*thread_fun)(void*), std::vector<void*> fargs) {
    // create a vector of worker threads
    std::vector<pthread_t> worker_threads(fargs.size());

    for (int i = 0; i < (int)worker_threads.size(); i++) {
        pthread_create(&worker_threads[i], NULL, thread_fun, fargs[i]);
    }

    return worker_threads;
}

/**
 * joins the generated threads and return the results
 * @param vector of threads
 * @return vector of void* which are the results from the threads
*/
std::vector<void*> bromine::threader::get_threads_results(std::vector<pthread_t> threads) {
    auto results = std::vector<void*>(threads.size());

    for (int i = 0; i < (int)threads.size(); i++) {
        pthread_join(threads[i], &results[i]);
    }

    return results;
}