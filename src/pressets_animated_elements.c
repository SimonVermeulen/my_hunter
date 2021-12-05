/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** main_loop file
*/

#include "../include/my_hunter.h"
#include <stdlib.h>

animated_element_t *create_duck(sfVector2f position, int hp)
{
    animated_element_t *new_duck = NULL;
    sfIntRect rect = {0, 0, DUCK_WIDTH, DUCK_WIDTH};

    new_duck = malloc(sizeof(animated_element_t));
    if (!new_duck)
        return (NULL);

    new_duck->pos = position;
    new_duck->speed = (sfVector2f) {DUCK_SPEED, 0};
    new_duck->rect = rect;
    new_duck->hp = hp;

    return (new_duck);
}

animated_element_t *create_hp(void)
{
    animated_element_t *new_hp = NULL;
    sfIntRect rect = {0, 0, 50, 50};

    new_hp = malloc(sizeof(animated_element_t));
    if (!new_hp)
        return (NULL);
    
    new_hp->pos = (sfVector2f) {500, 500};
    new_hp->speed = (sfVector2f) {0, 0};
    new_hp->rect = rect;
    new_hp->hp = -1;

    return (new_hp);
}
