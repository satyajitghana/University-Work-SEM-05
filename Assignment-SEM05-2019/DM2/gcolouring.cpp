#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 9

void print_colors(int color[]);

bool is_safe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graph_coloring_recurse(bool graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;

    /* Consider this vertex v and try different colors */
    for (int c = 1; c <= m; c++) {
        /* Check if assignment of color c to v is fine*/
        if (is_safe(v, graph, color, c)) {
            color[v] = c;

            /* recur to assign colors to rest of the vertices */
            if (graph_coloring_recurse(graph, m, color, v + 1) == true)
                return true;

            /* If assigning color c doesn't lead to a solution 
			then remove it */
            color[v] = 0;
        }
    }

    /* If no color can be assigned to this vertex then return false */
    return false;
}

bool graph_coloring(bool graph[V][V], int m) {
    // Initialize all color values as 0. This initialization is needed
    // correct functioning of is_safe()
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call graph_coloring_recurse() for vertex 0
    if (graph_coloring_recurse(graph, m, color, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    // Print the solution
    print_colors(color);
    return true;
}

void print_colors(int color[]) {
    printf(
        "Solution Exists:"
        " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

// driver program to test above function
int main() {
    int m = 3;  // Number of colors

    bool graph[V][V] = {
        0,
        1,
        1,
        1,
        0,
        0,
        1,
        0,
        0,
        1,
        0,
        1,
        0,
        1,
        0,
        0,
        1,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        1,
        0,
        1,
        0,
        1,
        0,
        0,
        0,
        1,
        1,
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        1,
        0,
        0,
        1,
        0,
        1,
        0,
        1,
        0,
        0,
        1,
        0,
        0,
        1,
        1,
        1,
        0,
    };
    graph_coloring(graph, m);
    return 0;
}
