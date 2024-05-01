//
// Created by ASUS on 01.05.2024.
//

#ifndef CUTIL_ARRAYLIST_H
#define CUTIL_ARRAYLIST_H
#include <stdlib.h>

typedef struct array_list array_list_t;

array_list_t *array_list_new(void);
int array_list_set(array_list_t *list, size_t idx, void *data);
int array_list_add(array_list_t *list, void *data);
int array_list_remove(array_list_t *list, size_t idx);
int array_list_clear(array_list_t *list);
int array_list_is_empty(array_list_t *list);
int array_list_is_empty_or_null(array_list_t *list);
size_t array_list_size(array_list_t *list);
void *array_list_get(array_list_t *list, size_t idx);
void array_list_free(array_list_t *list);

#endif //CUTIL_ARRAYLIST_H
