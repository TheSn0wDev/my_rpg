/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** level_up.c
*/

#include "combat_end.h"

void level_up_stats(all_t * a)
{
    int plus = rand_nbr(0, 1);

    a->player->obj->stat.max_speed += plus;
    a->player->obj->stat.speed = a->player->obj->stat.max_speed;
    plus = rand_nbr(1, 3);
    a->player->obj->stat.attack += plus;
    plus = rand_nbr(1, 3);
    a->player->obj->stat.defense += plus;
    plus = rand_nbr(5, 10);
    a->player->obj->stat.max_hp += plus;
    a->player->obj->stat.hp = a->player->obj->stat.max_hp;
    sfText_setString(a->player->lvl,
    my_strcat("LEVEL :", my_itoa(a->player->obj->stat.level)));
}

void level_up(all_t *a, stat_t *old_stats)
{
    *old_stats = a->player->obj->stat;
    a->player->obj->stat.exp += a->combat.enemy.p->stat.exp;
    a->player->obj->stat.gold += a->combat.enemy.p->stat.gold;
    if (a->player->obj->stat.exp < a->player->obj->stat.max_exp)
        return;
    a->player->obj->stat.exp -= a->player->obj->stat.max_exp;
    a->player->obj->stat.max_exp += a->player->obj->stat.max_exp;
    a->player->obj->stat.level += 1;
    level_up_stats(a);
}

void create_button_end(char *image, menu_object_t *button, sfVector2f pos)
{
    sfVector2u dim = {0, 0};

    button->scale.x = 0.7;
    button->scale.y = 0.7;
    button->s = create_sprite();
    button->texture = create_texture(image, NULL);
    dim = sfTexture_getSize(button->texture);
    button->rect = (sfIntRect){0, 0, dim.x, dim.y / 3};
    button->pos = pos;
    sfSprite_setTexture(button->s, button->texture, sfTrue);
    sfSprite_setTextureRect(button->s, button->rect);
    sfSprite_setPosition(button->s, button->pos);
}