
#include <stdio.h>
#include <stdlib.h>

int banker() {
    // P0, P1, P2, P3, P4 are the Process names here

    int n_proc, n_res;
    n_proc = 5;  // Number of processes
    n_res = 3;   // Number of resources
    // allocation matrix
    int alloc[5][3] = {{0, 1, 0},
                       {2, 0, 0},
                       {3, 0, 2},
                       {2, 1, 1},
                       {0, 0, 2}};

    // max need of each process
    int max[5][3] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};

    // available resources
    int avail[3] = {3, 3, 2};

    // safe sequence
    int safe_seq[5];
    int safe_seq_idx = 0;

    int need[5][3];

    // calculated the need matrix
    for (int i = 0; i < n_proc; i++) {
        for (int j = 0; j < n_res; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    bool done[5] = {};  // initialized by false by default

    for (int k = 0; k < n_proc; k++) {
        for (int proc = 0; proc < n_proc; proc++) {
            if (done[proc]) {
                continue;
            }
            int cur_proc = proc;
            bool is_safe = true;
            for (int res = 0; res < n_res; res++) {
                if (need[proc][res] > avail[res]) {
                    is_safe = false;
                    break;
                }
            }

            if (is_safe) {
                safe_seq[safe_seq_idx++] = cur_proc;
                for (int res = 0; res < n_res; res++) {
                    avail[res] += alloc[cur_proc][res];
                }
                done[cur_proc] = true;
            }
        }
    }

    printf("SAFE SEQ -> ");
    for (int i = 0; i < safe_seq_idx; i++) {
        printf("P%d -> ", safe_seq[i]);
    }
    printf("END\n");

    return EXIT_SUCCESS;
}