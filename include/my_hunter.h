/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** header file for my_hunter
*/

#include <SFML/Graphics.h>
#include <time.h>

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

    #define DESC_STR    "My_hunter: the user need to left click on ducks"
    #define DESCT_STR_2 "to kill them and earn points, good luck\n"
    #define DEFAULT_W   800
    #define DEFAULT_H  600

    #define DUCK_PATH       "./ressources/img/ducks.png"
    #define BACKGROUND_PATH "./ressources/img/background.png"

    #define DUCK_HEIGHT 63
    #define DUCK_WIDTH 100
    #define DUCK_SPEED 12

    #define CHECK_ERROR_WIDTH(width) (width == 0) ? DEFAULT_W : width
    #define CHECK_ERROR_HEIGHT(height) (height == 0) ? DEFAULT_H : height

    #define GET_OFFSET_H(h) (h > DEFAULT_H) ? h - DEFAULT_H : DEFAULT_H - h;
    #define GET_OFFSET_W(w) (w > DEFAULT_W) ? w - DEFAULT_W : DEFAULT_W - w;

struct game_instance {
    sfRenderWindow *window;
    sfText *score_text;
    int frames_passed;
    sfClock *clock;
    float seconds;
    sfEvent event;
    int pause;
    int score;
    int hp;
} typedef game_t;

sfVector2f get_random_pos(time_t t, sfRenderWindow *window);

game_t *init_game(int height, int width, char *name, int hp);

void destroy_game_instance(game_t *game);

int launch_game();

/*----------------------------STRUCT FOR ELEMENTS----------------------------*/

struct animated_element {
    sfVector2f speed;
    sfVector2f pos;
    sfIntRect rect;
    int nb_frames;
    int hp;
} typedef animated_element_t;

struct to_display {
    animated_element_t *animated_element;
    struct to_display *next;
    sfTexture *texture;
    sfSprite *sprite;
    int is_active;
} typedef to_display_t;

struct to_display_list {
    to_display_t *head;
    int nb_elements;
} typedef display_list_t;

/*-----------------------------ANIMATED ELEMENT-----------------------------*/

animated_element_t *create_animated_element(sfIntRect rect,
    unsigned int nb_frames, sfVector2f speed);

animated_element_t *create_duck(sfVector2f position, sfVector2f speed, int hp);

int set_pos(to_display_t *element, game_t *game);

void move_rect(to_display_t *element);

//EVENTS;

void check_hitbox(game_t *game, display_list_t *list);

/*--------------------------------LINKED LIST--------------------------------*/

//ADD OR INIT ELEMENTS

display_list_t *init_list(animated_element_t *animated_element,
    char *path);

void add_element(animated_element_t *animated_element, display_list_t *list,
    char *path, int index);

//UTILS FOR ELEMENTS

void display_active_nodes(display_list_t *list, sfRenderWindow *window);

to_display_t *get_from_index(display_list_t *list, unsigned int index);

void move_animated_elements(display_list_t *list, game_t *game);

void set_position(display_list_t *list, unsigned int index, sfVector2f pos);

//DESTROY ELEMENTS / LIST

void destroy_element(display_list_t *list, int index);

void destroy_list(to_display_t *current);

#endif
