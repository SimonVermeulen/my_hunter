/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** utils function to modify/interact with elements
*/

#include "../include/my_hunter.h"

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

void display_active_nodes(display_list_t *list, sfRenderWindow *window,
    void (*draw_sprite)(sfRenderWindow *, const sfSprite *,
    const sfRenderStates *))
{
    to_display_t *current = list->head;

    while (current) {
        if (current->is_active == 1) {
            (*draw_sprite)(window, current->sprite, NULL);
        }
        current = current->next;
    }
}

void set_position(display_list_t *list, unsigned int index, sfVector2f pos)
{
    to_display_t *to_set_pos = NULL;

    to_set_pos = get_from_index(list, index);
    sfSprite_setPosition(to_set_pos->sprite, pos);
}

void move_animated_elements(display_list_t *list, game_t *game)
{
    animated_element_t *animated = NULL;
    to_display_t *current = list->head;
    sfSprite *sprite = NULL;
    int error = 0;

    for (int index = 1; current; index++) {
        if (current->animated_element) {
            sprite = current->sprite;
            animated = current->animated_element;
            move_rect(current);
            error = set_pos(current, game->window);
        }
        if (error) {
            destroy_element(list, index);
            game->hp--;
        }
        current = current->next;
    }
}

int check_impact(animated_element_t *animated, game_t *game)
{
    if (game->event.mouseButton.x < animated->pos.x + DUCK_WIDTH &&
        game->event.mouseButton.y < animated->pos.y + DUCK_HEIGHT &&
        game->event.mouseButton.x > animated->pos.x &&
        game->event.mouseButton.y > animated->pos.y) {
        return (1);
    }
    return (0);
}

void check_hitbox(game_t *game, display_list_t *list)
{
    to_display_t *current = list->head;
    int touched = 0;

    for (int index = 0; current; index++) {
        if (current->animated_element)
            touched = check_impact(current->animated_element, game);
        current = current->next;
        if (touched)
            destroy_element(list, index);
    }
}
