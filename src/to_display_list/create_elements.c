/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** functions to create/initialize elements
*/

#include "../../include/my_hunter.h"
#include <unistd.h>
#include <stdlib.h>

to_display_t *init_element(animated_element_t *animated_element, char *path)
{
    to_display_t *new_element = NULL;

    new_element = malloc(sizeof(to_display_t));
    if (!new_element || !path)
        return (NULL);
    new_element->animated_element = animated_element;
    new_element->texture = sfTexture_createFromFile(path, NULL);
    if (!new_element->texture) {
        write(1, "Make sure to launch the game from its directory!\n", 50);
        exit(84);
    }
    new_element->sprite = sfSprite_create();
    new_element->is_active = 1;
    new_element->next = NULL;
    sfSprite_setTexture(new_element->sprite, new_element->texture, sfTrue);
    if (animated_element)
        sfSprite_setTextureRect(new_element->sprite, animated_element->rect);
    return (new_element);
}

void add_element(animated_element_t *animated_element, display_list_t *list,
    char *path, int index)
{
    to_display_t *index_element = NULL;
    to_display_t *new_element = NULL;

    new_element = init_element(animated_element, path);
    if (!index) {
        index_element = get_from_index(list, index);
        new_element->next = index_element;
        list->head = new_element;
    } else {
        if (index - 1 >= list->nb_elements)
            return;
        index_element = get_from_index(list, index - 1);
        index_element->next = new_element;
        if (index != list->nb_elements)
            new_element->next = index_element;
    }
    list->nb_elements++;
}

display_list_t *init_list(animated_element_t *animated_element,
    char *path)
{
    display_list_t *list = NULL;
    to_display_t *element = NULL;

    list = malloc(sizeof(display_list_t));
    if (!list || !path)
        return (NULL);
    element = init_element(animated_element, path);
    element->is_active = 0;

    list->head = element;
    list->nb_elements = 1;
    return (list);
}
