#include <iostream>

#include "network.hpp"

int main(int, char**) {
    using namespace std;

    Network mynet(10);

    // Generate the Random Nodes
    mynet.generate_random_nodes_with_dimensions(10, 50);

    mynet.print_nodes_pos();

    vector<int> ranges(10);
    cout << "Enter the Ranges for the 10 Nodes : ";
    for (int i = 0; i < 10; i++)
        cin >> ranges[i];

    // Set the Node Ranges given by the user and calculate the neighbour table
    mynet.set_node_ranges(ranges);

    mynet.print_neighbour_table();
}

// 10 Random Nodes Generated
// NODE 0 : (0, 26)
// NODE 1 : (5, 49)
// NODE 2 : (3, 47)
// NODE 3 : (7, 37)
// NODE 4 : (4, 30)
// NODE 5 : (7, 22)
// NODE 6 : (1, 38)
// NODE 7 : (8, 30)
// NODE 8 : (7, 9)
// NODE 9 : (0, 13)
// Enter the Ranges for the 10 Nodes : 10 20 10 10 10 10 10 10 10 10
// GRAPH
// NODE 0 -> 0 : 0 , 4 : 5.65685 , 5 : 8.06226 , 7 : 8.94427 ,
// NODE 1 -> 1 : 0 , 2 : 2.82843 , 3 : 12.1655 , 4 : 19.0263 , 6 : 11.7047 , 7 : 19.2354 ,
// NODE 2 -> 1 : 2.82843 , 2 : 0 , 6 : 9.21954 ,
// NODE 3 -> 3 : 0 , 4 : 7.61577 , 6 : 6.08276 , 7 : 7.07107 ,
// NODE 4 -> 0 : 5.65685 , 3 : 7.61577 , 4 : 0 , 5 : 8.544 , 6 : 8.544 , 7 : 4 ,
// NODE 5 -> 0 : 8.06226 , 4 : 8.544 , 5 : 0 , 7 : 8.06226 ,
// NODE 6 -> 2 : 9.21954 , 3 : 6.08276 , 4 : 8.544 , 6 : 0 ,
// NODE 7 -> 0 : 8.94427 , 3 : 7.07107 , 4 : 4 , 5 : 8.06226 , 7 : 0 ,
// NODE 8 -> 8 : 0 , 9 : 8.06226 ,
// NODE 9 -> 8 : 8.06226 , 9 : 0 ,
