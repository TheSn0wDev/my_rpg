/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** handleègame
*/

#include "rpg.h"
#include "struct.h"

void spawn_mobs(float srate, all_t *a);

void init_after_combat(all_t *a)
{
    sfIntRect rect =  (sfIntRect){a->player->skin * (160 * 3), 0, 160, 135};
    float row = a->player->obj->pos.y + a->map.map->rect.top;
    float col = a->player->obj->pos.x + a->map.map->rect.left;
    float xp_pourcentage = ((float){a->player->obj->stat.exp} /
    (float){a->player->obj->stat.max_exp}) * 100;
    float xp_size = (235 * xp_pourcentage) / 100;

    if (a->main_menu[0].nickname[0] == '\0')
        sfSprite_setPosition(a->player->obj->s, (sfVector2f){col, row});
    sfSprite_setTextureRect(a->player->obj->s, rect);
    sfSprite_setScale(a->player->obj->s, (sfVector2f){0.6, 0.6});
    sfSprite_setOrigin(a->player->obj->s, (sfVector2f){80, 67});
    if (xp_pourcentage > 0)
        sfRectangleShape_setSize(a->inventory.xp_bar,
        (sfVector2f){(int){xp_size}, 27});
}

void handle_game(all_t *a)
{
    char *map[4] = {"assets/maps/small_castle_map.png",
    "assets/maps/fopenspace.png", "assets/maps/DUNGEON.png",
    "assets/maps/boss.png"};

    init_after_combat(a);
    if (a->main_menu[0].nickname[0] != '\0')
        load_player_quest_and_pos(a);
    reloard_minimap(a, map[a->map.world]);
    while (a->scene == GAME) {
        handle_game_events(a);
        handle_zone_changements(a);
        set_player_pos(a);
        update_weather(a);
        sfRenderWindow_clear(a->window, sfBlack);
        display_game(a);
        activate_options_settings(a);
        sfRenderWindow_display(a->window);
    }
    if (a->main_menu->nickname[0] != 0)
        save_player_stats(a, &a->player->obj->stat);
}