#include "network.hpp"

#include <iostream>
#include <random>

Network::Network(int n_nodes) : n_nodes(n_nodes), neighbour_table(n_nodes), node_ranges(n_nodes), nodes_pos(n_nodes) {}

void Network::generate_random_nodes_with_dimensions(int length, int breadth) {
    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_int_distribution<int> l_dist(0, length);
    std::uniform_int_distribution<int> b_dist(0, breadth);

    this->nodes_pos.clear();

    for (int i = 0; i < this->n_nodes; i++) {
        nodes_pos.push_back({l_dist(random_engine), b_dist(random_engine)});
    }

    std::cout << this->n_nodes << " Random Nodes Generated" << std::endl;
}

void Network::print_nodes_pos() {
    int i = 0;
    for (auto& node : this->nodes_pos) {
        std::cout << "NODE " << i << " : (" << node.first << ", " << node.second << ")" << std::endl;
        i++;
    }
}

void Network::set_node_ranges(std::vector<int>& ranges) {
    if (ranges.size() != this->nodes_pos.size()) {
        throw "ranges length does not match nodes_pos length";
    }

    this->node_ranges.clear();

    this->node_ranges.assign(ranges.begin(), ranges.end());

    this->gen_fully_connected_network(this->node_ranges);
}

template <typename T>
double Network::calc_dist(std::pair<T, T> pos1, std::pair<T, T> pos2) {
    return std::sqrt(std::abs(
        ((pos1.first - pos2.first) * (pos1.first - pos2.first) + (pos1.second - pos2.second) * (pos1.second - pos2.second))));
}

// Generates the network from the given ranges
void Network::gen_fully_connected_network(std::vector<int>& ranges) {
    if (this->node_ranges.size() != this->nodes_pos.size()) {
        throw "WTF did you do ? and HTF did you do that ? i'm not even public ";
    }

    this->neighbour_table.clear_graph();

    for (int node_idx = 0; node_idx < this->nodes_pos.size(); node_idx++) {
        for (int node_jdx = 0; node_jdx < this->nodes_pos.size(); node_jdx++) {
            double dist = Network::calc_dist(this->nodes_pos.at(node_idx), this->nodes_pos.at(node_jdx));
            if (dist <= node_ranges.at(node_idx)) {
                this->neighbour_table.add_edge(node_idx, node_jdx, dist);
            }
        }
    }
}

void Network::print_neighbour_table() {
    if (this->node_ranges.empty()) {
        std::cout << "EMPTY" << std::endl;
        return;
    }

    this->neighbour_table.print_graph();
}
