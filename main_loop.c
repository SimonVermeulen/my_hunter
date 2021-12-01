/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** main_loop file
*/

#include "include/my_hunter.h"
#include <stdlib.h>

void display(display_list_t *list, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    display_active_nodes(list, window, &sfRenderWindow_drawSprite);
    sfRenderWindow_display(window);
}

void handle_clock_events(game_t *game, display_list_t *list, time_t t)
{
    to_display_t *current = NULL;
    animated_element_t *duck = NULL;
    sfVector2f pos;
    sfTime time;

    time = sfClock_getElapsedTime(game->clock);
    game->seconds = time.microseconds / 1000000.0;
    if (game->seconds > 0.07) {
        move_animated_elements(list, game);
        game->frames_passed++;
        sfClock_restart(game->clock);

        if (game->frames_passed % 42 == 0) {
            pos = get_random_pos(t, game->window);
            duck = create_duck(pos, (sfVector2f) {12, 0}, 1);

            add_element(duck, list, DUCK_PATH, list->nb_elements);
            set_position(list, list->nb_elements - 1, pos);
        }
    }
}

void check_events(game_t *game, display_list_t *list)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    else if (game->event.type == sfEvtMouseButtonPressed &&
        game->event.mouseButton.button == sfMouseLeft)
        check_hitbox(game, list);
}

int launch_game(void)
{
    game_t *game = init_game(DEFAULT_HEIGHT, DEFAULT_WIDTH, "Wish Hunter", 5);
    time_t t;

    display_list_t *list = init_list(NULL, BACKGROUND_PATH);
    sfRenderWindow_setFramerateLimit(game->window, 60);

    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            check_events(game, list);
        handle_clock_events(game, list, t);
        display(list, game->window);
    }

    destroy_list(list->head);
    sfRenderWindow_destroy(game->window);
    return EXIT_SUCCESS;
}
