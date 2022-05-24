/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

void reload_map(all_t *a, char *mappath, char *txtpath)
{
    a->map.transition = true;
    a->map.map = create_map(mappath,
    (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){0, 0}, (sfVector2f){1, 1});
    a->map.txtmap = get_txt_map(txtpath);
    a->map.txtmap_clone = get_txt_map(txtpath);
    init_npc(a, true);
    sfSprite_setTextureRect(a->map.map->s, a->map.map->rect);
    sfSprite_setTextureRect(a->map.l_layer->s,
    (sfIntRect){2900, 2900, a->map.map->rect.width, a->map.map->rect.height});
    sfSprite_setTextureRect(a->map.bot_wall->s, a->map.map->rect);
    init_mobs(a);
}

void reloard_map_player_pos(all_t *a, sfIntRect pos)
{
    a->player->obj->pos = (sfVector2f){pos.width, pos.height};
    a->map.map->rect.left = pos.left;
    a->map.map->rect.top = pos.top;
    sfSprite_setPosition(a->player->obj->s, a->player->obj->pos);
    sfSprite_setTextureRect(a->map.map->s, a->map.map->rect);
}