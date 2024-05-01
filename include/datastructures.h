//
// Created by ASUS on 29.04.2024.
//

#ifndef UNTITLED2_DATASTRUCTURES_H
#define UNTITLED2_DATASTRUCTURES_H

#include "linkedlist.h"
#include <stdlib.h>
#include "arraylist.h"

typedef struct binary_tree_node {
    void *data;
    struct binary_tree_node *left, *right;
} tree_node_t;

typedef struct binary_tree {
    tree_node_t *root;
    size_t size;
} binary_tree_t;

typedef struct set {
    void *data;
    size_t size;
} set_t;

int binary_tree_add(tree_node_t *node, void *data);
int binary_tree_add_node(tree_node_t *node, tree_node_t *data);
binary_tree_t *binary_tree_new(void);
void binary_tree_free(binary_tree_t *tree);

int set_add(set_t *s, void *data);
int set_remove(set_t *s, size_t idx);
set_t *set_new(void);
void set_free(set_t *s);

#endif //UNTITLED2_LINKEDLIST_H
