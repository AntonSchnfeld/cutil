#include <stdio.h>
#include <stdlib.h>
#include "include/linkedlist.h"+
#include "include/debug.h"
#include <stdint.h>
#include <string.h>

typedef linked_list_t llist_t;

int main() {
    typedef struct student {
        const char *name;
        int16_t birth_year, birth_month, birth_day;
    } student_t;

    llist_t *students = linked_list_new();

    // Creating some example students
    student_t *anton = malloc(sizeof(student_t));
    anton->name = "Anton Schoenfeld";
    anton->birth_year = 2007;
    anton->birth_month = 4;
    anton->birth_day = 13;
    student_t *marlon = malloc(sizeof(student_t));
    marlon->name = "Marlon Rosenfeld";
    marlon->birth_year = 2007;
    marlon->birth_month = 8;
    marlon->birth_day = 30;
    student_t *gianni = malloc(sizeof(student_t));
    gianni->name = "Gianluca Stoy";
    gianni->birth_year = 2006;
    gianni->birth_month = 8;
    gianni->birth_day = 21;
    student_t *marlon_copy = malloc(sizeof(student_t));
    memcpy(marlon_copy, marlon, sizeof(student_t));

    // Lets add them to the list
    linked_list_add(students, anton);
    linked_list_add(students, marlon);
    linked_list_remove(students); // marlon is freed here
    linked_list_add(students, gianni);

    // We insert the marlon_copy
    linked_list_insert(students, marlon_copy);

    // Looping through the linked list from front to back
    for (linked_list_to_first(students); linked_list_has_access(students); linked_list_next(students)) {
        student_t *s = linked_list_get(students);
        printf("Student: %s | Birthday: %i.%i.%i\n", s->name, s->birth_day, s->birth_month, s->birth_year);
    }

    // Looping through the linked list from back to front
    for (linked_list_to_last(students); linked_list_has_access(students); linked_list_previous(students)) {
        student_t *s = linked_list_get(students);
        printf("Student: %s | Birthday %i.%i.%i\n", s->name, s->birth_day, s->birth_month, s->birth_year);
    }

    // Frees students as well as all students contained in it
    linked_list_free(students);
    return EXIT_SUCCESS;
}