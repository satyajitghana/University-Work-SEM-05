#pragma once

#include <vector>

class scheduling_algo {
   public:
    virtual void read_values() = 0;
    virtual std::vector<unsigned> get_turn_around_times() = 0;
    virtual double get_avg_tat() = 0;
};