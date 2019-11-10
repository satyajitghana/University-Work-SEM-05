#include <stdio.h>

#include "array_list.h"
#include "gst_item.h"

#define MAX_ITEMS 10000000

int main(int argc, char **argv) {
    // testing
    array_list *list = init_array_list(free_gst_item);

    /**
     * A Single loop of 100000 objects, sequencial access
    */
    for (int i = 0; i < MAX_ITEMS; i++) {
        int item_id = i;
        int gst_slab_id = i % 5;
        double price = 1000.5f;

        gst_item *item = create_gst_item(item_id, gst_slab_id, price);

        list->add(list, item);
    }

    double total_amt = 0.0f;

    // calculate the GST'ed price
    for (int i = 0; i < MAX_ITEMS; i++) {
        gst_item *item = list->at(list, i);
        total_amt += get_mrp(item);
    }

    free_array_list(list);

    printf("TOTAL_ITEMS : %d\nTOTAL AMOUNT : %.10f\n", MAX_ITEMS, total_amt);

    fflush(stdout);

    return 0;
}
