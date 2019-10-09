#include <iostream>
#include <sstream>
#include <typeinfo>
#include <utility>
#include <vector>

#include <pthread.h>

#include "priority_schedule.hpp"
#include "round_robin.hpp"
#include "scheduling_algo.hpp"

void* worker_thread(void* schd_obj) {
    scheduling_algo* sa = static_cast<scheduling_algo*>(schd_obj);

    // compute the stuff
    double* avg_tat = new double;
    *avg_tat = sa->get_avg_tat();

    std::stringstream out;
    out << std::endl;
    out << "TAT CALCULATED FOR " << typeid(*static_cast<scheduling_algo*>(schd_obj)).name() << " BY TID " << pthread_self() << " : " << *avg_tat << std::endl;

    std::cout << out.str();

    return static_cast<void*>(avg_tat);
}

int main(int argc, char** argv) {
    using namespace std;

    pthread_t thr_id[2];
    auto ps_tid = &thr_id[0];
    auto rrs_tid = &thr_id[1];

    round_robin_schedule* RRS = nullptr;
    priority_schedule* PS = nullptr;

    unsigned nproc;
    cout << "Enter the number of processes : ";
    cin >> nproc;
    PS = new priority_schedule(nproc);
    RRS = new round_robin_schedule(nproc);

    // read the values - main thread
    cout << "Priority Scheduling" << endl;
    PS->read_values();
    cout << "Round Robin Scheduling" << endl;
    RRS->read_values();

    // create the threads
    pthread_create(ps_tid, NULL, worker_thread, PS);
    pthread_create(rrs_tid, NULL, worker_thread, RRS);

    void *ps_avg_tat, *rrs_avg_tat;

    // join the threads
    pthread_join(*ps_tid, &ps_avg_tat);
    pthread_join(*rrs_tid, &rrs_avg_tat);

    cout << endl;

    cout << "PS AVG TAT : " << *static_cast<double*>(ps_avg_tat) << endl;
    cout << "RRS AVG TAT : " << *static_cast<double*>(rrs_avg_tat) << endl;

    // destroy these
    delete static_cast<double*>(ps_avg_tat);
    delete static_cast<double*>(rrs_avg_tat);

    return EXIT_SUCCESS;
}
