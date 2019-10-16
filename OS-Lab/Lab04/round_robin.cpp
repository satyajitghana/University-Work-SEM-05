#include "round_robin.hpp"

#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

void round_robin_schedule::read_values() {
    std::cout << "Enter the CPU Burst Times : ";

    for (auto& btime : this->cpu_burst_time) {
        std::cin >> btime;
    }

    std::cout << "Enter the Time Slice : ";
    std::cin >> this->time_slice;
}

double round_robin_schedule::get_avg_tat() {
    std::vector<unsigned> tat = this->get_turn_around_times();
    return std::accumulate(tat.begin(), tat.end(), 0) / (double)tat.size();
}

/**
 * Calculates the Turn Around Times for the processes in the structure
*/
std::vector<unsigned> round_robin_schedule::get_turn_around_times() {
    std::vector<unsigned> queue(this->cpu_burst_time.begin(), this->cpu_burst_time.end());
    std::vector<unsigned> completion_times(this->cpu_burst_time.size());

    unsigned sys_time = 0;

    bool done = true;
    do {
        // assume you are done at start
        done = true;
        // give each of the elements in the queue an equal share of time_slice
        unsigned i = 0;
        for (auto& cpu_time : queue) {
            if (cpu_time != 0) {  // this also means you are not done
                done = false;
                unsigned current_time = cpu_time >= this->time_slice ? this->time_slice : cpu_time;
                sys_time += current_time;
                cpu_time -= current_time;

                // std::cout << "Current Time " << current_time << " ";
                // std::cout << "System Time " << sys_time << ";" << std::endl;

                if (cpu_time == 0) {  // you are done with this process
                    completion_times[i] = sys_time;
                    // std::cout << "Done With Proc " << i << " at " << sys_time << "\n";
                }
            }
            i++;
        }
    } while (!done);

    std::stringstream out;

    out << std::endl;

    out << "CT FOR RRS : [ ";
    for (auto TAT : completion_times) {
        out << TAT << " , ";
    }
    out << "]" << std::endl;

    std::cout << out.str();

    return completion_times;
}
