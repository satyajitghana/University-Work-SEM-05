#pragma once

struct gst_item {
    int item_id;
    int gst_slab_id;
    double price;
};

typedef struct gst_item gst_item;

static float slab_tax[5] = {0.0, 0.05, 0.12, 0.18, 0.28};

float get_slab_tax(int slab_id);

double get_mrp(gst_item* item);

void* create_gst_item(int, int, double);

void free_gst_item(void*);
