#pragma once

#include <vector>

#include "scheduling_algo.hpp"

class round_robin_schedule : public scheduling_algo {
   public:
    round_robin_schedule(unsigned nprocesses) : nprocesses(nprocesses), cpu_burst_time(nprocesses), time_slice(nprocesses){};

    unsigned nprocesses;
    std::vector<unsigned> cpu_burst_time;
    unsigned time_slice;

    void read_values();
    std::vector<unsigned> get_turn_around_times();
    double get_avg_tat();
};