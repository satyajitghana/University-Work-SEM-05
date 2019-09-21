#include <iostream>
#include <vector>
#include <numeric>

struct round_robin_schedule {
    round_robin_schedule(unsigned nprocesses) : nprocesses(nprocesses), cpu_burst_time(nprocesses), time_slice(nprocesses) {};

    unsigned nprocesses;
    std::vector<unsigned> cpu_burst_time;
    unsigned time_slice;

    void read_values();
    std::vector<unsigned> get_turn_around_times();
    double get_avg_tat();
};

void round_robin_schedule::read_values() {
    std::cout << "Enter the CPU Burst Times : ";

    for (auto& btime : this -> cpu_burst_time) {
        std::cin >> btime;
    }

    std::cout << "Enter the Time Slice : ";
    std::cin >> this -> time_slice;
}

double round_robin_schedule::get_avg_tat() {
    std::vector<unsigned> tat = this -> get_turn_around_times();
    return std::accumulate(tat.begin(), tat.end(), 0) / (double)tat.size();
}

/**
 * Calculates the Turn Around Times for the processes in the structure
*/
std::vector<unsigned> round_robin_schedule::get_turn_around_times() {
    std::vector<unsigned> queue(this -> cpu_burst_time.begin(), this -> cpu_burst_time.end());
    std::vector<unsigned> completion_times(this -> cpu_burst_time.size());

    unsigned sys_time = 0;

    bool done = true;
    do {
        // assume you are done at start
        done = true;
        // give each of the elements in the queue an equal share of time_slice
        unsigned i = 0;
        for (auto& cpu_time : queue) {
            if (cpu_time != 0) { // this also means you are not done
                done = false;
                unsigned current_time = cpu_time >= this -> time_slice ? this -> time_slice : cpu_time;
                sys_time += current_time;
                cpu_time -= current_time;

                std::cout << "Current Time " << current_time << " ";
                std::cout << "System Time " << sys_time << ";" << std::endl;

                if (cpu_time == 0) { // you are done with this process
                    completion_times[i] = sys_time;
                    std::cout << "Done With Proc " << i << " at " << sys_time << "\n";
                }
            }
            i++;
        }
    } while (!done);

    std::cout << std::endl;
    
    std::cout << "[ CT : ";
    for (auto TAT : completion_times) {
        std::cout << TAT << " , ";
    }
    std::cout << "]"<< std::endl;

    return completion_times;
}

struct priority_schedule {
    priority_schedule(unsigned nprocesses) : nprocesses(nprocesses), cpu_burst_time(nprocesses), priority(nprocesses) {};

    unsigned nprocesses;
    std::vector<unsigned> cpu_burst_time;
    std::vector<unsigned> priority;

    void read_values();
    std::vector<unsigned> get_turn_around_times();
};

std::vector<unsigned> priority_schedule::get_turn_around_times() {
    std::vector<unsigned> queue(this ->cpu_burst_time.begin(), this->cpu_burst_time.end());
    std::vector<unsigned> completion_times(this -> cpu_burst_time.size());
    bool seen[100] = {};

    bool done = false;
    while (!done) {
        done = true;

        // get the next most priority
        int max = -100000;
        for (int i = 0 ; i < this -> cpu_burst_time.size() ; i++) {
            if (!seen[i] and queue.at(i) != 0) {
                done = false;
                // get the next priority process

            }
        }
    }
    return std::nullptr_t;
}

void priority_schedule::read_values() {
    std::cout << "Enter the CPU Burst Times : ";

    for (auto& btime : this -> cpu_burst_time) {
        std::cin >> btime;
    }

    std::cout << "Enter the Priorities : ";
    for (auto& priority : this -> priority) {
        std::cin >> priority;
    }
}

int main(int, char**) {
    using namespace std;

    round_robin_schedule* RRS = nullptr;
    priority_schedule* PS = nullptr;

    unsigned nproc;

    // cout << "Priority Scheduling" << endl;
    // cout << "Enter the number of processes : ";
    // cin >> nproc;
    // PS = new priority_schedule(nproc);
    // PS -> read_values();

    cout << endl;
    cout << "Round Robin Scheduling" << endl;
    cout << "Enter the number of processes : ";
    cin >> nproc;
    RRS = new round_robin_schedule(nproc);
    RRS -> read_values();

    double avg_tat = RRS -> get_avg_tat();
    std::cout << "Average TAT : " << avg_tat << std::endl;

}
