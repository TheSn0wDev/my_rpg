/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** gauge.c
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

void create_gauge(gauge_t *gauge, int value, sfVector2f pos)
{
    sfVector2u dim;

    gauge->pos = pos;
    gauge->back_t = create_texture("assets/combat/back_hp.png", NULL);
    gauge->back_s = create_sprite();
    gauge->t = create_texture("assets/combat/front_hp.png", NULL);
    gauge->s = create_sprite();
    gauge->value = value;
    sfSprite_setPosition(gauge->back_s, gauge->pos);
    sfSprite_setTexture(gauge->back_s, gauge->back_t, sfTrue);
    gauge->pos.x += 4;
    gauge->pos.y += 4;
    sfSprite_setPosition(gauge->s, gauge->pos);
    sfSprite_setTexture(gauge->s, gauge->t, sfTrue);
    dim = sfTexture_getSize(gauge->t);
    gauge->rect = (sfIntRect){0, 0, dim.x, dim.y};
    sfSprite_setTextureRect(gauge->s, gauge->rect);
}

void update_gauge_hp(gauge_t *gauge, enemy_t *enemy)
{
    sfVector2u dim = sfTexture_getSize(gauge->t);
    int hp_lost = enemy->p->stat.max_hp - enemy->p->stat.hp;
    sfVector2f new_pos = gauge->pos;

    gauge->value = enemy->p->stat.hp;
    gauge->rect.left = dim.x * hp_lost / enemy->p->stat.max_hp;
    new_pos.x += gauge->rect.left;
    gauge->rect.width = dim.x - gauge->rect.left;
    sfSprite_setTextureRect(gauge->s, gauge->rect);
    sfSprite_setPosition(gauge->s, new_pos);
}

void draw_gauge(sfRenderWindow *window, gauge_t *gauge)
{
    sfRenderWindow_drawSprite(window, gauge->back_s, NULL);
    sfRenderWindow_drawSprite(window, gauge->s, NULL);
}