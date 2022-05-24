/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** cinematic
*/

#include "rpg.h"
#include "struct.h"

void move_sprite(all_t *a, int to_display)
{
    move_one(a, to_display);
    if (to_display == 10) {
        a->cin[0].obj[to_display].scale.x -= 0.0005;
        a->cin[0].obj[to_display].scale.y -= 0.0005;
    }
    sfSprite_setTextureRect(a->cin[0].obj[to_display].s,
    a->cin[0].obj[to_display].rect);
    sfSprite_setScale(a->cin[0].obj[to_display].s,
    a->cin[0].obj[to_display].scale);
}

void transition(all_t *a, int to_wait, int to_display)
{
    static bool bounce = false;

    if (get_seconds(a->cin[0].clock) > to_wait - 0.4 && to_display < 13
    && a->cin->transition == false && to_display != 3) {
        a->cin->transition = true;
    }
    if (bounce == false && a->cin->transition == true)
            a->cin->color.a += 5;
    else if (bounce == true && a->cin->transition == true)
            a->cin->color.a -= 5;
    if (a->cin->color.a >= 250)
        bounce = true;
    else if (a->cin->color.a <= 0) {
        bounce = false;
        a->cin->transition = false;
    }
}

void display_cinematic(all_t *a)
{
    static int to_display = 0;
    static float to_wait = 3.4;

    transition(a, to_wait, to_display);
    if (get_seconds(a->cin[0].clock) > to_wait && to_display < 13) {
        to_display++;
        sfClock_restart(a->cin[0].clock);
        to_wait = increment_to_wait(to_display);
    } else if (get_seconds(a->cin[0].clock) > to_wait && to_display == 13) {
        a->cin->end = true;
        a->cin->start_mus = true;
    }
    move_sprite(a, to_display);
    sfRenderWindow_drawSprite(a->window, a->cin[0].obj[to_display].s, NULL);
    sfRectangleShape_setFillColor(a->cin->trans, a->cin->color);
    sfRenderWindow_drawRectangleShape(a->window, a->cin->trans, NULL);
    sfRenderWindow_drawSprite(a->window, a->cin[0].obj[14].s, NULL);
}

void handle_cinematic_events(all_t *a)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->window, &event)) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeySpace && a->cin->end == true) {
            a->scene = MENU;
        }
        if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeySpace && a->cin->end == false) {
            a->cin->end = true;
            a->cin->start_mus = true;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            a->scene = QUIT;
        }
    }
}

void start_cinematic(all_t *a)
{
    create_cinematic_assets(a);
    while (a->scene == CINEMATIC) {
        handle_cinematic_events(a);
        sfRenderWindow_clear(a->window, sfBlack);
        if (a->cin->end == false) {
            display_cinematic(a);
        } else {
            display_end(a);
        }
        sfRenderWindow_display(a->window);
    }
}