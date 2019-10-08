#include "array_list.h"

#include <stdio.h>
#include <stdlib.h>

// set the buffer to 256 elements
#define BUFFER 256

array_list* init_array_list(void (*free_item)(void*)) {
    array_list* mylist;
    if ((mylist = malloc(sizeof *mylist)) != NULL) {
        mylist->at = array_list_at;
        mylist->add = array_list_add;
        mylist->buffered_length = BUFFER;
        mylist->free_item = free_item;
        mylist->data = malloc(mylist->buffered_length * sizeof(*mylist->data));
        if (mylist->data == NULL) {
            return NULL;
        }

        return mylist;
    }

    return NULL;
}

void* array_list_at(struct array_list* mylist, int idx) {
    if (mylist != NULL) {
        if (idx >= mylist->length) {
            perror("idx out of bounds\n");
            return NULL;
        }

        return mylist->data[idx];
    }

    return NULL;
}

int array_list_add(struct array_list* mylist, void* data) {
    if (mylist != NULL) {
        if (mylist->length >= mylist->buffered_length) {
            mylist->buffered_length += BUFFER;
            mylist->data = realloc(mylist->data, (mylist->buffered_length) * sizeof(*mylist->data));
        }

        mylist->data[mylist->length++] = data;

        return 1;
    }

    return -1;
}

void free_array_list_items(array_list* list) {
    for (int i = 0; i < list->length; i++) {
        list->free_item(list->at(list, i));
    }
    list->length = 0;
    list->buffered_length = 0;
}

void free_array_list(array_list* list) {
    free_array_list_items(list);
    free(list);
}
