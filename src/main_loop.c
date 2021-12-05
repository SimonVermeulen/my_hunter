/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** main_loop file
*/

#include "../include/my_hunter.h"
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

void display(display_list_t *list, game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, list->head->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    display_active_nodes(list, game->window);
    sfRenderWindow_display(game->window);
}

void handle_clock_events(game_t *game, display_list_t *list, time_t t)
{
    to_display_t *current = NULL;
    animated_element_t *duck = NULL;
    sfVector2f pos;
    sfTime time;

    time = sfClock_getElapsedTime(game->clock);
    game->seconds = time.microseconds / 1000000.0;
    if (game->seconds > 0.07 && !game->pause) {
        move_animated_elements(list, game);
        game->frames_passed++;
        sfClock_restart(game->clock);
        if (game->frames_passed % 12 == 0) {
            pos = get_random_pos(t, game->window);
            duck = create_duck(pos, 1);

            add_element(duck, list, DUCK_PATH, list->nb_elements);
            set_position(list, list->nb_elements - 1, pos);
        }
    }
}

void check_events(game_t *game, display_list_t *list)
{
    switch (game->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(game->window);
            break;
        case sfEvtMouseButtonPressed:
            check_hitbox(game, list);
            break;
        case sfEvtLostFocus:
            game->pause = 1;
            break;
        case sfEvtGainedFocus:
            game->pause = 0;
            break;
        case sfEvtKeyPressed:
            handle_key_pressed(game);
            break;
    }
}

void print_end_message(game_t *game)
{
    if (game->hp == 0)
        my_printf("You lost!\n");
    else
        my_printf("Thanks for playing!\n");
    my_printf("Your final score was: %d\n", game->score);
}

int launch_game(void)
{
    game_t *game = init_game(DEFAULT_H, DEFAULT_W, "Wish Hunter", 5);
    display_list_t *list = init_list(NULL, BACKGROUND_PATH);
    time_t t;

    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window) && game->hp) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            check_events(game, list);
        handle_clock_events(game, list, t);
        display(list, game);
        game->hp = (game->hp > 5) ? 5 : game->hp;
    }
    print_end_message(game);
    destroy_list(list->head);
    destroy_game_instance(game);
    return EXIT_SUCCESS;
}
