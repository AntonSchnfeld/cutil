//
// Created by ASUS on 30.04.2024.
//

#ifndef UNTITLED2_LINKEDLIST_H
#define UNTITLED2_LINKEDLIST_H

#include <stdio.h>

typedef struct linked_list linked_list_t;


linked_list_t *linked_list_new(void);
size_t linked_list_size(linked_list_t *list);
int linked_list_add(linked_list_t *list, void *data);
int linked_list_insert(linked_list_t *list, void *data);
int linked_list_is_empty_or_null(linked_list_t *list);
int linked_list_clear(linked_list_t *list);
int linked_list_to_last(linked_list_t *list);
int linked_list_to_first(linked_list_t *list);
int linked_list_has_access(linked_list_t *list);
int linked_list_remove(linked_list_t *list);
int linked_list_next(linked_list_t *list);
int linked_list_before(linked_list_t *list);
int linked_list_is_empty(linked_list_t *list);
void linked_list_free(linked_list_t *list);
void *linked_list_get(linked_list_t *list);

#endif //UNTITLED2_LINKEDLIST_H
