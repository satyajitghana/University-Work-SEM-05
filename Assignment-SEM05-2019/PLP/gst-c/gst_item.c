#include "gst_item.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

float get_slab_tax(int slab_id) {
    return slab_tax[slab_id];
}

double get_mrp(gst_item* item) {
    assert(item != NULL);

    return item->price + get_slab_tax(item->gst_slab_id) * item->price;
}

void* create_gst_item(int item_id, int slab_id, double price) {
    gst_item* item;
    if ((item = malloc(sizeof *item)) != NULL) {
        item->item_id = item_id;
        item->gst_slab_id = slab_id;
        item->price = price;
        return item;
    }

    return NULL;
}

void free_gst_item(void* item) {
    gst_item* myitem = item;

    free(myitem);
}
