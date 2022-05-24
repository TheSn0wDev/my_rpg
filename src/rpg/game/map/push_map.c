/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** push map to follow the player
*/

#include "rpg.h"
#include "struct.h"

int is_obstacle(all_t *a, sfKeyCode code)
{
    if (is_colliding(a, code) == 1) {
        return (1);
    }
    return (0);
}

int push_map_demi(all_t *a, sfKeyCode code)
{
    if (code == a->key_arr[2] - 97 && a->map.map->rect.top < a->map.map_dim.y -
    (1080 * (1 / a->map.map->scale.y))
    && a->player->obj->pos.y > 540 && !is_obstacle(a, code)) {
        a->map.map->rect.top += 4 / a->map.map->scale.y;
        sfSprite_setTextureRect(a->map.map->s, a->map.map->rect);
        sfSprite_setTextureRect(a->map.l_layer->s, a->map.map->rect);
        sfSprite_setTextureRect(a->map.bot_wall->s, a->map.map->rect);
        return (1);
    }
    return (0);
}

int push_map_two(all_t *a, sfKeyCode code)
{
    if (code == a->key_arr[0] - 97 && a->map.map->rect.top > 0
    && a->player->obj->pos.y < 540 && !is_obstacle(a, code)) {
        a->map.map->rect.top -= 4 / a->map.map->scale.y;
        sfSprite_setTextureRect(a->map.map->s, a->map.map->rect);
        sfSprite_setTextureRect(a->map.l_layer->s, a->map.map->rect);
        sfSprite_setTextureRect(a->map.bot_wall->s, a->map.map->rect);
        return (1);
    }
    if (push_map_demi(a, code) == 1)
        return (1);
    return (0);
}

int push_map_onedemi(all_t *a, sfKeyCode code)
{
    if (code == a->key_arr[3] - 97 && a->map.map->rect.left
    < a->map.map_dim.x - (1920 * (1 / a->map.map->scale.x))
    && a->player->obj->pos.x > 960 && !is_obstacle(a, code)) {
        a->map.map->rect.left += 5 / a->map.map->scale.x;
        sfSprite_setTextureRect(a->map.map->s, a->map.map->rect);
        sfSprite_setTextureRect(a->map.l_layer->s, a->map.map->rect);
        sfSprite_setTextureRect(a->map.bot_wall->s, a->map.map->rect);
        return (1);
    }
    return (0);
}

int push_map(all_t *a, sfKeyCode code)
{
    if (get_seconds(a->player->map_movement) < 0.01)
        return (0);
    sfClock_restart(a->player->map_movement);
    if (code == a->key_arr[1] - 97 && a->map.map->rect.left > 0
    && a->player->obj->pos.x < 960 && !is_obstacle(a, code)) {
        a->map.map->rect.left -= 5 / a->map.map->scale.x;
        sfSprite_setTextureRect(a->map.map->s, a->map.map->rect);
        sfSprite_setTextureRect(a->map.l_layer->s, a->map.map->rect);
        sfSprite_setTextureRect(a->map.bot_wall->s, a->map.map->rect);
        return (1);
    }
    if (push_map_onedemi(a, code) == 1)
        return (1);
    return (push_map_two(a, code));
}