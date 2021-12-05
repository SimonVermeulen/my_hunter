/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** utils function to modify/interact with elements
*/

#include "../../include/my_hunter.h"

to_display_t *get_last_element(display_list_t *list)
{
    to_display_t *current = list->head;

    while (current)
        current = current->next;
    return (current);
}

to_display_t *get_from_index(display_list_t *list, unsigned int index)
{
    to_display_t *current = list->head;
    int i = 0;

    while (current) {
        if (i == index)
            return (current);
        i++;
        current = current->next;
    }
    return (NULL);
}

void display_active_nodes(display_list_t *list, sfRenderWindow *window)
{
    to_display_t *current = list->head;

    while (current) {
        if (current->is_active == 1)
            sfRenderWindow_drawSprite(window, current->sprite, NULL);
        current = current->next;
    }
}

void set_position(display_list_t *list, unsigned int index, sfVector2f pos)
{
    to_display_t *to_set_pos = NULL;

    to_set_pos = get_from_index(list, index);
    sfSprite_setPosition(to_set_pos->sprite, pos);
}
