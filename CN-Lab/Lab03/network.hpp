#pragma once

#include <math.h>
#include <vector>

#include "graph.hpp"

class Network {
   public:
    Network(int nodes);
    int n_nodes;
    std::vector<std::pair<int, int>> nodes_pos;
    std::vector<int> node_ranges;
    Graph neighbour_table;

    void set_node_ranges(std::vector<int>& ranges);
    void generate_random_nodes_with_dimensions(int length, int breadth);
    void print_nodes_pos();
    void print_neighbour_table();

    template <typename T>
    static double calc_dist(std::pair<T, T>, std::pair<T, T>);

   private:
    void gen_fully_connected_network(std::vector<int>& ranges);
};