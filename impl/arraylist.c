//
// Created by ASUS on 01.05.2024.
//

#include "../include/arraylist.h"
#include<stdbool.h>
#include<string.h>

#ifndef CUTIL_ARRAY_LIST_GROWTH
#define CUTIL_ARRAY_LIST_GROWTH 1.5
#endif
#ifndef CUTIL_ARRAY_LIST_SIZE
#define CUTIL_ARRAY_LIST_SIZE 10
#endif

struct array_list {
    void **data;
    size_t size, data_length;
};

array_list_t *array_list_new(void) {
    array_list_t *list = malloc(sizeof(array_list_t));
    if (list == NULL) return NULL;
    list->data = NULL;
    list->size = 0;
    list->data_length = 0;
    return list;
}

inline size_t array_list_size(array_list_t *list) {
    if (list == NULL) return 0;
    return list->size;
}

inline int array_list_set(array_list_t *list, size_t idx, void *data) {
    if (list == NULL) return false;
    if (idx >= list->size) return false;
    list->data[idx] = data;
    return true;
}

static int array_list_resize(array_list_t *list) {
    if (list->size == 0) list->size = CUTIL_ARRAY_LIST_SIZE;
    size_t new_length = (size_t)(list->data_length * CUTIL_ARRAY_LIST_GROWTH);
    void **new_data = realloc(list->data, sizeof(void *) * new_length);
    if (new_data == NULL) return false;
    list->data = new_data;
    list->data_length = new_length;
    return true;
}

int array_list_add(array_list_t *list, void *data) {
    if (list == NULL) return false;
    if (list->size >= list->data_length && !array_list_resize(list)) return false;

    list->data[list->size] = data;
    list->size++;
    return true;
}

int array_list_remove(array_list_t *list, size_t idx) {
    if (array_list_is_empty_or_null(list)) return false;
    if (idx >= list->size) return false;
    free(list->data[idx]);
    list->size--;
    // Move every element after the removed one back by one
    memmove(&list->data[idx], &list->data[idx + 1], sizeof(void *) * (list->size - idx - 1));
    return true;
}

int array_list_clear(array_list_t *list) {
    if (list == NULL) return false;
    for (size_t i = 0; i < list->size; ++i) {
        free(list->data[i]);
    }
    list->size = 0;
    return true;
}

inline int array_list_is_empty(array_list_t *list) {
    return list->size == 0;
}

inline int array_list_is_empty_or_null(array_list_t *list) {
    return list == NULL || array_list_is_empty(list);
}

inline void *array_list_get(array_list_t *list, size_t idx) {
    if (array_list_is_empty_or_null(list)) return NULL;
    if (idx >= list->size) return NULL;
    return list->data[idx];
}

void array_list_free(array_list_t *list) {
    array_list_clear(list);
    free(list->data);
    free(list);
}