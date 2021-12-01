/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** utils funcs for animated_elements
*/

#include "./include/my_hunter.h"
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

int set_pos(to_display_t *element, sfRenderWindow *window)
{
    animated_element_t *animated = element->animated_element;
    sfVector2u win_size = sfRenderWindow_getSize(window);
    float speed[2] = {0, 0};

    speed[0] = animated->speed.x;
    speed[1] = animated->speed.y;

    animated->pos.x += speed[0];
    animated->pos.y += speed[1];
    if (animated->pos.x <= win_size.x || animated->pos.y <= win_size.y) {
        sfSprite_setPosition(element->sprite, animated->pos);
        return (0);
    }
    return (1);
}

void move_rect(to_display_t *element)
{
    animated_element_t *animated = element->animated_element;

    animated->rect.left += animated->rect.width;
    if (animated->rect.left >= 200)
        animated->rect.left = 0;
    sfSprite_setTextureRect(element->sprite, animated->rect);
}
