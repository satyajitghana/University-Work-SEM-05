#pragma once

#include <pthread.h>
#include <vector>

namespace bromine {
class threader {
   public:
    static std::vector<pthread_t> gen_worker_threads(void* (*thread_fun)(void*), std::vector<void*> fargs);
    static std::vector<void*> get_threads_results(std::vector<pthread_t>);
};
}  // namespace bromine