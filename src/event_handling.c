/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** utils function to modify/interact with elements
*/

#include "../include/my_hunter.h"
#include "../include/my.h"

int check_impact(animated_element_t *animated, game_t *game)
{
    sfMouseButtonEvent mouse = game->event.mouseButton;
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    float ratio_y = (float)(win_size.y) / DEFAULT_H;
    float ratio_x = (float)(win_size.x) / DEFAULT_W;

    if (mouse.x < animated->pos.x * ratio_x + DUCK_WIDTH &&
        mouse.y < animated->pos.y * ratio_y + DUCK_HEIGHT &&
        mouse.x > animated->pos.x * ratio_x &&
        mouse.y > animated->pos.y * ratio_y)
        return (1);
    return (0);
}

void check_hitbox(game_t *game, display_list_t *list)
{
    to_display_t *current = list->head;
    int touched = 0;

    for (int index = 0; current && !game->pause &&
        game->event.mouseButton.button == sfMouseLeft; index++) {
        if (current->animated_element)
            touched = check_impact(current->animated_element, game);
        if (touched && current->animated_element->hp) {
            game->score++;
            game->hp++;
            get_from_index(list, index)->animated_element->hp--;
            sfText_setString(game->score_text, my_itos(game->score));
        }
        current = current->next;
    }
}

void handle_key_pressed(game_t *game)
{
    if (game->event.key.code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    else if (game->event.key.code == sfKeyP)
        game->pause = (game->pause) ? 0 : 1;
}

void change_hp(display_list_t *list, game_t *game)
{
    to_display_t *hp = get_from_index(list, 1);
    sfIntRect rect = hp->animated_element->rect;

    rect.left = (game->hp * HP_WIDTH) - HP_WIDTH;
    sfSprite_setTextureRect(hp->sprite, rect);
}
