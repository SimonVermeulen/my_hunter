/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** functions to delete elements/list
*/

#include "../include/my_hunter.h"
#include <stdlib.h>

void free_element(to_display_t *element)
{
    if (element->animated_element)
        free (element->animated_element);
    sfTexture_destroy(element->texture);
    sfSprite_destroy(element->sprite);
    free(element);
}

void destroy_element(display_list_t *list, int index)
{
    to_display_t *index_element = NULL;

    index_element = get_from_index(list, index);
    if (index == 0) {
        if (index_element->next)
            list->head = index_element->next;
        free_element(index_element);
    } else {
        if (index < 0 || index > list->nb_elements)
            return;
        if (index == list->nb_elements - 1) {
            get_from_index(list, index - 1)->next = NULL;
            free_element(index_element);
        } else {
            get_from_index(list, index - 1)->next = index_element->next;
            free_element(index_element);
        }
    }
    list->nb_elements--;
}

void destroy_list(to_display_t *current)
{
    if (current->next) {
        current = current->next;
        destroy_list(current);
        free_element(current);
    }
}
