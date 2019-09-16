#include <iostream>

#include "routing_table.hpp"

// Distance Vector Routing
int main(int, char**) {
    using namespace std;
    int order;
    cout << "Enter the Order of the Matrix : ";
    cin >> order;
    cout << "Enter the Adjacency Matrix : " << endl;
    
    vector<vector<int>> adj_mat;

    for (int i = 0 ; i < order ; i++) {
        std::vector<int> row(order);
        for (int j = 0 ; j < order ; j++) {
            cin >> row[j];
        }
        adj_mat.push_back(row);
    }

    // create the routing table
    RoutingTable routing_table(adj_mat);

    // calculate the shortest paths
    routing_table.apply_bellman_ford();

    // print the table
    routing_table.print_routing_table();

}
