#pragma once

#include <vector>

#include "scheduling_algo.hpp"

class priority_schedule : public scheduling_algo {
   public:
    priority_schedule(unsigned nprocesses) : nprocesses(nprocesses), cpu_burst_time(nprocesses), priority(nprocesses){};

    unsigned nprocesses;
    std::vector<unsigned> cpu_burst_time;
    std::vector<unsigned> priority;

    void read_values();
    std::vector<unsigned> get_turn_around_times();
    double get_avg_tat();
};
