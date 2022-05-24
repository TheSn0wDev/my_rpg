/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** handle_parallax
*/

#include "struct.h"
#include "rpg.h"

void animate_parallax(menu_object_t *object, int coef)
{
    if (get_seconds(object->clock) >= 0.01) {
        object->rect.left += coef - 1;
        sfSprite_setTextureRect(object->s, object->rect);
        sfClock_restart(object->clock);
    }
}

void draw_parallax(all_t *a)
{
    for (int i = 0; i < 10; i++) {
        animate_parallax(&a->main_menu[0].parallax[i], i);
        sfRenderWindow_drawSprite(a->window, a->main_menu[0].parallax[i].s,
        NULL);
    }
}