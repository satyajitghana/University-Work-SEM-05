#pragma once

struct array_list {
    void** data;
    void* (*at)(struct array_list*, int idx);
    int (*add)(struct array_list*, void* data);
    void (*free_item)(void* data);
    int length;
    int buffered_length;
};

typedef struct array_list array_list;

array_list* init_array_list(void (*)(void*));

void* array_list_at(struct array_list*, int idx);

int array_list_add(struct array_list*, void* data);

void free_array_list_items(array_list*);

void free_array_list(array_list*);
