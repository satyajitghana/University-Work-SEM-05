#include "routing_table.hpp"

#include <limits>
#include <iostream>

RoutingTable::RoutingTable(int nodes) : nodes(nodes), dist_matrix(nodes) { }

RoutingTable::RoutingTable(std::vector<std::vector<int>>& adj_matrix) : RoutingTable(adj_matrix.size()) { }

void RoutingTable::print_routing_table() {
    int i = 0;
    for (auto& row : this -> dist_matrix) {
        std::cout << "SRC NODE " <<  i << " TO -> [ ";
        int j = 0;
        for (auto& node : row) {
            std::cout << j << " : " << node << " , ";
            j++;
        }
        std::cout << " ]" << std::endl;
        i++;
    }
}

void RoutingTable::apply_bellman_ford() {
    dist_matrix.clear();
    dist_matrix.resize(this -> nodes.order);

    for (int src = 0 ; src < this -> dist_matrix.size() ; src++) {

        auto& curr_dist = dist_matrix.at(src);

        curr_dist.resize(this -> nodes.order);

        // set distance from src to every destination as infinity
        for (auto& node : dist_matrix.at(src)) {
            node = std::numeric_limits<int>::max();
        }
        // distance from source to source is 0
        curr_dist.at(src) = 0;

        // relax all edges V-1 times
        for (int k = 0 ; k < this -> nodes.order - 1 ; k++) {
            for (int i = 0 ; i < this -> nodes.order ; i++) {
                for (int j = 0 ; j < this -> nodes.order ; j++) {
                    curr_dist.at(j) = std::min(curr_dist.at(i) + this -> nodes.adj_matrix.at(i).at(j) , curr_dist.at(j));
                }
            }
        }
        
    }
}