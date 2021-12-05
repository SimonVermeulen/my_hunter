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

animated_element_t *create_duck(sfVector2f position, sfVector2f speed, int hp)
{
    animated_element_t *new_duck = NULL;
    sfIntRect rect = {0, 0, 100, 63};

    new_duck = malloc(sizeof(animated_element_t));
    if (!new_duck)
        return (NULL);

    new_duck->pos = position;
    new_duck->speed = speed;
    new_duck->rect = rect;
    new_duck->hp = hp;

    return (new_duck);
}

int set_pos(to_display_t *element, game_t *game)
{
    animated_element_t *animated = element->animated_element;
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    float speed[2] = {0, 0};

    speed[0] = animated->speed.y;
    speed[1] = animated->speed.x + (game->score / 5 * 2);
    if (speed[1] > 20)
        speed[1] = 20;

    animated->pos.y += speed[0];
    animated->pos.x += speed[1];

    if (animated->pos.x <= win_size.x && animated->pos.y <= win_size.y) {
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
    } else {
        animated->rect.left = 300;
        animated->speed.y = 40;
    }
    sfSprite_setTextureRect(element->sprite, animated->rect);
}

void move_animated_elements(display_list_t *list, game_t *game)
{
    animated_element_t *animated = NULL;
    to_display_t *current = list->head;
    sfSprite *sprite = NULL;
    int error = 0;

    for (int index = 0; current; index++) {
        if (current->animated_element) {
            sprite = current->sprite;
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
