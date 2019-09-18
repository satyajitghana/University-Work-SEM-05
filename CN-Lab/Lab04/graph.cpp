#include "graph.hpp"

#include <iostream>

Graph::Graph(int nodes) : adj_list(nodes), order(nodes), adj_matrix(nodes) {
    for (auto& row : adj_matrix) {
        row.resize(nodes);
        for (auto& node : row) {
            node = 0;
        }
    }
}

void Graph::add_edge(int src, int dest, double weight) {
    if (src >= adj_list.size() || dest >= adj_list.size()) {
        throw "Tried to Add Edge for Vertex that does not exist";
    }

    adj_list.at(src).push_back({dest, weight});

    adj_matrix.at(src).at(dest) = weight;
}

void Graph::clear_graph() {
    this -> adj_list.clear(); this -> adj_list.resize(order);
    for (auto& row : adj_matrix) {
        for (auto& node : row) {
            node = 0;
        }
    }
};

void Graph::print_graph() {
    std::cout << "GRAPH" << std::endl;
    int i = 0;
    for (auto& row : adj_list) {
        std::cout << "NODE " << i << " -> ";
        for (auto& ele : row) {
            std::cout << ele.first << " : " << ele.second << " , ";
        }
        std::cout << std::endl;
        i++;
    }
}