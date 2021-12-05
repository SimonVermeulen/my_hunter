/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** utils funcs for animated_elements
*/

#include "../include/my_hunter.h"
#include <stdlib.h>

animated_element_t *create_animated_element(sfIntRect rect,
    unsigned int nb_frames, sfVector2f speed)
{
    animated_element_t *new_element = NULL;
    sfVector2f position = {0, 0};

    new_element = malloc(sizeof(animated_element_t));
    if (!new_element)
        return (NULL);

    new_element->pos = position;
    new_element->speed = speed;
    new_element->rect = rect;
    new_element->hp = -1;

    return (new_element);
}

int set_pos(to_display_t *element, game_t *game)
{
    animated_element_t *animated = element->animated_element;
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    float speed[2] = {0, 0};
    float ratio_x = (float)(win_size.x) / DEFAULT_W;
    float ratio_y = (float)(win_size.y) / DEFAULT_H;

    speed[0] = animated->speed.y;
    speed[1] = animated->speed.x + (game->score / 5 * 4);
    if (speed[1] > MAX_SPEED)
        speed[1] = MAX_SPEED;

    animated->pos.y += speed[0];
    animated->pos.x += speed[1];
    if (animated->pos.x * ratio_x <= win_size.x &&
        animated->pos.y * ratio_y <= win_size.y) {
        sfSprite_setPosition(element->sprite, animated->pos);
        return (0);
    }
    return (1);
}

void move_rect(to_display_t *element)
{
    animated_element_t *animated = element->animated_element;

    if (animated->hp > 0) {
        animated->rect.left += animated->rect.width;
        if (animated->rect.left >= 200)
            animated->rect.left = 0;
    } else if (!animated->hp) {
        animated->rect.left = 300;
        animated->speed.y = 60;
    }
    sfSprite_setTextureRect(element->sprite, animated->rect);
}

void move_animated_elements(display_list_t *list, game_t *game)
{
    animated_element_t *animated = NULL;
    to_display_t *current = list->head;
    int error = 0;

    for (int index = 0; current; index++) {
        if (current->animated_element) {
            animated = current->animated_element;
            move_rect(current);
            error = set_pos(current, game);
        }
        if (error) {
            current = current->next;
            destroy_element(list, index);
            game->hp--;
        }
        current = (error) ? current : current->next;
    }
}
