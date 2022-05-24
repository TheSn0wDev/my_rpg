/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_game
*/

#include "rpg.h"
#include "struct.h"
#include "csfml_garbage_collector.h"

int get_obstacles_count(char **map)
{
    int count = 0;

    for (int i = 0; map[i] != 0; i++) {
        for (int j = 0; map[i][j] != 0; j++) {
            count = map[i][j] == '0' ? count + 1 : count;
        }
    }
    return (count);
}

void init_mobs(all_t *a)
{
    a->mobs[0].mb_list = my_malloc(sizeof(mobs_lists_t));
    a->mobs[0].mb_list = NULL;
    a->mobs->mb_nb = 0;
    a->mobs->spawn_clock = create_clock();
    a->mobs[0].miniboss = false;
    a->mobs[0].boss = false;
    a->mobs[0].bossnb = 0;
    a->mobs[0].minibossnb = 0;
}

void init_game(all_t *a)
{
    a->player->blocked = false;
    a->player->obj->rect =
    (sfIntRect){a->player->skin * (160 * 3), 0, 160, 135};
    sfSprite_setTextureRect(a->player->obj->s, a->player->obj->rect);
    sfSprite_setPosition(a->player->obj->s, a->player->obj->pos);
    a->player->movement = create_clock();
    a->player->map_movement = create_clock();
    a->mobs->combat_cooldown = create_clock();
    a->mobs->rdm_move = create_clock();
    a->map.shadows = create_rectangle();
    sfRectangleShape_setSize(a->map.shadows, (sfVector2f){10000, 10000});
    sfRectangleShape_setFillColor(a->map.shadows, (sfColor){0, 0, 0, 100});
    create_interaction_button_sprite(a);
    init_inventory(a);
    start_weather(a);
}