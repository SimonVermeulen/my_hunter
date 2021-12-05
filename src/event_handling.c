/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** utils function to modify/interact with elements
*/

#include "../include/my_hunter.h"

int check_impact(animated_element_t *animated, game_t *game)
{
    sfMouseButtonEvent mouse = game->event.mouseButton;
    sfVector2u win_size = sfRenderWindow_getSize(game->window);

    if (mouse.x < animated->pos.x + DUCK_WIDTH &&
        mouse.y < animated->pos.y + DUCK_HEIGHT &&
        mouse.x > animated->pos.x &&
        mouse.y > animated->pos.y)
        return (1);
    return (0);
}

void check_hitbox(game_t *game, display_list_t *list)
{
    to_display_t *current = list->head;
    int touched = 0;

    for (int index = 0; current &&
        game->event.mouseButton.button == sfMouseLeft; index++) {
        if (current->animated_element)
            touched = check_impact(current->animated_element, game);
        if (touched && current->animated_element->hp) {
            get_from_index(list, index)->animated_element->hp--;
            game->hp++;
            game->score++;
        }
        current = current->next;
    }
}
