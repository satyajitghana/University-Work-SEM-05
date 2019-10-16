#include "priority_schedule.hpp"

#include <iostream>
#include <limits>
#include <numeric>
#include <sstream>
#include <vector>

std::vector<unsigned> priority_schedule::get_turn_around_times() {
    // Arrival Times are assumed to be 0 for all the processes

    std::vector<unsigned> queue(this->cpu_burst_time.begin(), this->cpu_burst_time.end());
    std::vector<unsigned> completion_times(this->cpu_burst_time.size());

    unsigned systime = 0;

    bool done = false;
    while (!done) {
        done = true;

        // get the next most priority
        int temp_max = std::numeric_limits<int>::min();
        int temp_max_i = 0;
        for (int i = 0; i < queue.size(); i++) {
            bool cond = ((int)queue[i] != 0)                // process not exhausted
                        && ((int)priority[i] >= temp_max);  // and has higher priority
            // std::cout << "COND : " << ((int)queue[i] >= temp_max) << std::endl;
            if (cond) {
                // std::cout << "FOUND ANOTHER temp_MAX" << std::endl;
                temp_max = priority.at(i);
                temp_max_i = i;
                done = false;
            }
        }
        if (!done) {
            // std::cout << "temp_MAX : " << priority.at(temp_max_i) << std::endl;
            systime += queue.at(temp_max_i);
            // std::cout << "SYSTIME : " << systime << std::endl;
            queue.at(temp_max_i) = 0;
            completion_times.at(temp_max_i) = systime;
        }
    }

    std::stringstream out;

    out << std::endl;

    out << "CT FOR PS : [ ";
    for (auto TAT : completion_times) {
        out << TAT << " , ";
    }
    out << "]" << std::endl;

    std::cout << out.str();

    return completion_times;
}

double priority_schedule::get_avg_tat() {
    std::vector<unsigned> tat = this->get_turn_around_times();

    return std::accumulate(tat.begin(), tat.end(), 0) / (double)tat.size();
}

void priority_schedule::read_values() {
    std::cout << "Enter the CPU Burst Times : ";

    for (auto& btime : this->cpu_burst_time) {
        std::cin >> btime;
    }

    std::cout << "Enter the Priorities : ";
    for (auto& priority : this->priority) {
        std::cin >> priority;
    }
}
