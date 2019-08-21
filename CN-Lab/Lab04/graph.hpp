#pragma once

#include <vector>

// Weighted DiGraph using Adjacency List
class Graph {
    public:
        Graph(int);
        std::vector<std::vector<std::pair<int, double>>> adj_list;
        std::vector<std::vector<int>> adj_matrix;

        const int order;

        void clear_graph();
        void add_edge(int src, int dest, double weight);

        bool is_empty() { return adj_list.empty(); };

        void print_graph();

};