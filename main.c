#include <stdio.h>
#include <stdlib.h>
#include "include/linkedlist.h"+
#include "include/debug.h"
#include <stdint.h>

typedef linked_list_t llist_t;

int main() {
    typedef struct student {
        const char *name;
        const int16_t birth_year, birth_month, birth_day;
    } student_t;

    llist_t *students = linked_list_new();

    student_t anton = {.name = "Anton Schoenfeld", .birth_year = 2007, .birth_month = 4, .birth_day = 13};
    student_t marlon = {.name = "Marlon Rosenfeld", .birth_year = 2007, .birth_month = 5, .birth_day = 32};
    student_t gianni = {.name = "Gianluca Stoy", .birth_year = 2006, .birth_month = 8, .birth_day = 21};

    linked_list_add(students, &anton);
    linked_list_add(students, &marlon);
    linked_list_remove(students);
    linked_list_add(students, &gianni);

    linked_list_insert(students, &marlon);

    for (linked_list_to_first(students); linked_list_has_access(students); linked_list_next(students)) {
        student_t *s = linked_list_get(students);
        printf("Student: %s | Birthday: %i.%i.%i\n", s->name, s->birth_day, s->birth_month, s->birth_year);
    }

    linked_list_free(students);
    return EXIT_SUCCESS;
}