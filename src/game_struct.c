/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** structure containing usefull functions for game_struct
*/

#include "../include/my_hunter.h"
#include "../include/my.h"
#include <stdlib.h>

sfRenderWindow *init_window(sfRenderWindow *window, int height, int width,
    char *name)
{
    sfVideoMode mode;

    mode.height = CHECK_ERROR_HEIGHT(height);
    mode.width = CHECK_ERROR_WIDTH(width);
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
}

sfVector2f get_random_pos(time_t t, sfRenderWindow *window)
{
    sfVector2u win_size = sfRenderWindow_getSize(window);
    sfVector2f position = {-DUCK_WIDTH, 0};
    unsigned int test = win_size.y - DEFAULT_H;
    int random_y = 0;

    srand((unsigned) time(&t));
    random_y = rand() % (DEFAULT_H - DUCK_HEIGHT);
    position.y = (float) random_y;

    return (position);
}

game_t *init_game(int height, int width, char *name, int hp)
{
    game_t *game_instance = NULL;
    sfRenderWindow *window;

    game_instance = malloc(sizeof(game_t));
    if (!game_instance)
        return (NULL);
    game_instance->window = init_window(window, height, width, name);
    game_instance->clock = sfClock_create();
    game_instance->frames_passed = 0;
    game_instance->seconds = 0;
    game_instance->score = 0;
    game_instance->pause = 0;
    game_instance->event;
    game_instance->hp = hp;
}

void destroy_game_instance(game_t *game)
{
    sfClock_destroy(game->clock);
    sfText_destroy(game->score_text);
    sfRenderWindow_destroy(game->window);
}
