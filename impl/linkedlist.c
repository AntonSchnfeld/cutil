#include "../include/datastructures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Linked List Functions


typedef struct list_node {
    struct list_node *next, *previous;
    void *data;
} list_node_t;

typedef struct linked_list {
    list_node_t *first, *last, *current;
    size_t size;
} linked_list_t;

static list_node_t *list_node_new(void *data) {
    list_node_t *node = malloc(sizeof(list_node_t));
    node->next = NULL;
    node->previous = NULL;
    node->data = data;
    return node;
}

int linked_list_add(linked_list_t *list, void *data) {
    if (list == NULL) return false;
    list_node_t *node = list_node_new(data);
    if (node == NULL) return false;

    if (linked_list_is_empty(list)) {
        list->first = node;
        list->last = node;
        list->current = node;
        list->size = 1;
        return true;
    }
    list_node_t *last = list->last;
    last->next = node;
    node->previous = last;
    list->last = node;
    list->size++;
    list->current = list->last;
    return true;
}

int linked_list_insert(linked_list_t *list, void *data) {
    if (linked_list_is_empty_or_null(list)) return false;

    list_node_t *node = list_node_new(data);

    if (list->size == 0) {
        list->first = node;
        list->current = node;
        list->last = node;
        list->size++;
        return true;
    } else if (list->current == list->first) {
        list_node_t *temp_first = list->first;
        list->first = node;
        node->next = temp_first;
        temp_first->previous = node;
        list->current = list->first;
        list->size++;
        return true;
    }

    list_node_t *temp_current = list->current;
    node->next = temp_current;
    node->previous = temp_current->previous;
    temp_current->previous->next = node;
    temp_current->previous = node;
    list->current = node;
    list->size++;

    return true;
}

int linked_list_remove(linked_list_t *list) {
    if (linked_list_is_empty_or_null(list)) return false;

    if (list->size == 1) {
        linked_list_clear(list);
        return true;
    } else if (list->current == list->last) {
        list_node_t *temp = list->last;
        list->last = temp->previous;
        list->last->next = NULL;
        free(temp);
        list->current = list->last;
        list->size--;
        return true;
    } else if (list->current == list->first) {
        list_node_t *temp = list->first;
        list->first = temp->next;
        list->first->previous = NULL;
        free(temp);
        list->current = list->first;
        list->size--;
        return true;
    }

    list_node_t *current = list->current;
    list_node_t *before_current = current->previous;
    list_node_t *after_current = current->next;

    before_current->next = after_current;
    after_current->previous = before_current;

    free(current);
    list->size--;

    return true; // Success
}

linked_list_t *linked_list_new(void) {
    linked_list_t *list = malloc(sizeof(linked_list_t));
    if (list == NULL) {
        return NULL; // Failed to allocate memory
    }
    list->first = NULL;
    list->last = NULL;
    list->current = NULL;
    list->size = 0;
    return list;
}

void linked_list_free(linked_list_t *list) {
    list_node_t *cur = list->first;
    list_node_t *temp = cur->next;

    while ((cur = temp) != NULL) {
        temp = cur->next;
        free(cur);
    }

    free(list->first);
    free(list);
}

int linked_list_clear(linked_list_t *list) {
    if (list == NULL) return false;
    if (linked_list_is_empty(list)) return false;
    list_node_t *cur = list->first;
    list_node_t *temp = cur->next;
    while ((cur = temp) != NULL) {
        temp = cur->next;
        free(cur);
    }
    list->size = 0;
    return true;
}

inline int linked_list_is_empty(linked_list_t *list) {
    return list->size == 0 || (list->first == NULL && list->last == NULL);
}

inline int linked_list_is_empty_or_null(linked_list_t *list) {
    return list == NULL || linked_list_is_empty(list);
}

inline int linked_list_next(linked_list_t *list) {
    if (linked_list_is_empty_or_null(list)) return false;
    if (list->current == NULL) return false;
    list->current = list->current->next;
    return true;
}

inline int linked_list_before(linked_list_t *list) {
    if (list == NULL) return false;
    if (linked_list_is_empty(list)) return false;
    list_node_t *temp = list->current;
    if (temp != list->first) list->current = temp->previous;
    return true;
}

inline int linked_list_to_first(linked_list_t *list) {
    if (list == NULL) return false;
    if (linked_list_is_empty(list)) return false;
    list->current = list->first;
    return true;
}

inline int linked_list_to_last(linked_list_t *list) {
    if (list == NULL) return false;
    if (linked_list_is_empty(list)) return false;
    list->current = list->last;
    return true;
}

inline void *linked_list_get(linked_list_t *list) {
    if (linked_list_is_empty_or_null(list)) return NULL;
    return list->current->data;
}

inline int linked_list_has_access(linked_list_t *list) {
    return !linked_list_is_empty_or_null(list) && list->current != NULL;
}

inline size_t linked_list_size(linked_list_t *list) {
    return list->size;
}