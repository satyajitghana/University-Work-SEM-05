#pragma once

#include "graph.hpp"

class RoutingTable {
    public:
        RoutingTable(int nodes);
        RoutingTable(std::vector<std::vector<int>>& adj_matrix);
        Graph nodes;

        std::vector<std::vector<int>> dist_matrix;

        void apply_bellman_ford();
        void print_routing_table();
};
