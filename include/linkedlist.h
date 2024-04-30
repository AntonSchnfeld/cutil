//
// Created by ASUS on 30.04.2024.
//

#ifndef UNTITLED2_LINKEDLIST_H
#define UNTITLED2_LINKEDLIST_H

#include <stdio.h>

typedef struct linked_list linked_list_t;

/**
 * Creates a new <b>linked_list_t</b> with a size of 0.
 * @return a pointer to the new <b>linked_list_t</b>
 * @author Anton Schoenfeld
 */
linked_list_t *linked_list_new(void);
/**
 * Gets the size of a <b>linked_list_t</b>.
 * @param list pointer to a <b>linked_list_t</b>
 * @return the size of <b>list</b>
 * @author Anton Schoenfeld
 */
size_t linked_list_size(linked_list_t *list);
/**
 * Adds <b>data</b> to the end of <b>list</b> and sets the current pointer to the new data. If
 * <b>list</b> is NULL 1 is returned. If the list is empty, the first and last pointers
 * as well as the current pointer will point to <b>data</b>.
 * @param list pointer to a <b>linked_list_t</b>
 * @param data pointer to the data that will be stored
 * @return 1 if the operation is successful, 0 if it is not
 * @author Anton Schoenfeld
 */
int linked_list_add(linked_list_t *list, void *data);
/**
 * Inserts <b>data</b> before the current pointer and sets the current pointer to the new data.
 * If <b>list</b> is NULL 1 is returned. If the list is empty, the first and last pointers
 * as well as the current pointer will point to <b>data</b>.
 * @param list pointer to a <b>linked_list_t</b>
 * @param data pointer to the data that will be stored
 * @return 1 if the operation is successful, 0 if it is not
 * @author Anton Schoenfeld
 */
int linked_list_insert(linked_list_t *list, void *data);
/**
 * Checks whether <b>list</b> is empty or NULL.
 * @param list pointer to a <b>linked_list_t</b>
 * @return 1 if <b>list</b> is empty or NULL, otherwise 0
 * @author Anton Schoenfeld
 */
int linked_list_is_empty_or_null(linked_list_t *list);
/**
 * Frees all of <b>list</b>s data, but not <b>list</b> itself.
 * @param list a pointer to a <b>linked_list_t</b>
 * @return 1 if the operation is successful, 0 if it is not
 * @author Anton Schoenfeld
 */
int linked_list_clear(linked_list_t *list);
/**
 * Sets the current pointer of <b>list</b> to the last element in <b>list</b>.
 * @param list a pointer to a <b>linked_list_t</b>
 * @return 1 if the operation is successful, 0 if it is not
 * @author Anton Schoenfeld
 */
int linked_list_to_last(linked_list_t *list);
/**
 * Sets the current pointer of <b>list</b> to the first element in <b>list</b>.
 * @param list a pointer to a <b>linked_list_t</b>
 * @return 1 if the operation is successful, 0 if it is not
 * @author Anton Schoenfeld
 */
int linked_list_to_first(linked_list_t *list);
/**
 * Checks whether the current pointer of <b>list</b> is still within the scope of <b>list</b>.
 * @param list a pointer to a <b>linked_list_t</b>
 * @return 1 if the operation is successful, 0 if it is not
 * @author Anton Schoenfeld
 */
int linked_list_has_access(linked_list_t *list);
/**
 * Removes the element the current pointer of <b>list</b> is pointing to and frees it.
 * The current pointer is moved to the element before the current pointer.
 * @param list a pointer to a <b>linked_list_t</b>
 * @return 1 if the operation is successful, 0 if it is not
 * @author Anton Schoenfeld
 */
int linked_list_remove(linked_list_t *list);
/**
 * Moves the current pointer of <b>list</b> to the next element. If there is no next element, the pointer will
 * go out of the scope of <b>list</b>.
 * @param list a pointer to a <b>linked_list_t</b>
 * @return 1 if the operation is successful, 0 if it is not
 * @author Anton Schoenfeld
 */
int linked_list_next(linked_list_t *list);
/**
 * Moves the current pointer of <b>list</b> to the previous element. If there is no previous element, the pointer
 * will go out of the scope of <b>list</b>.
 * @param list
 * @return 1 if the operation is successful, 0 if it is not
 * @author Anton Schoenfeld
 */
int linked_list_previous(linked_list_t *list);
/**
 * Checks whether <b>list</b> contains no elements.
 * @param list a pointer to a <b>linked_list_t</b>
 * @return 1 if <b>list</b> is empty, 0 otherwise
 * @author Anton Schoenfeld
 */
int linked_list_is_empty(linked_list_t *list);
/**
 * Frees <b>list</b> and all of the data it contains.
 * @param list a pointer to a <b>linked_list_t</b>
 * @author Anton Schoenfeld
 */
void linked_list_free(linked_list_t *list);
/**
 * Gets the data at the current pointer of <b>list</b>.
 * @param list a pointer to a <b>linked_list_t</b>
 * @return the data at the current pointer of <b>list</b>
 * @author Anton Schoenfeld
 */
void *linked_list_get(linked_list_t *list);

#endif //UNTITLED2_LINKEDLIST_H
