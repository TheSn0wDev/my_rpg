/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init end game
*/

#include "rpg.h"
#include "struct.h"

void init_end_game(all_t *a)
{
    sfVector2f scale = {1, 1};
    menu_object_t end_npc = {0, 0, {1.8, 1.8}, {1
    , (1)}, 0, 0, {10, 5, 43, 55}, 0};

    a->end[0].endgame = my_malloc(sizeof(menu_object_t) * 5);
    init_menu_object(&end_npc, "assets/npc/oldidk.png");
    a->end[0].endgame[0] = end_npc;
    a->map.map = create_map("assets/maps/small_castle_map.png",
    (sfIntRect){200, 400, 1920, 1080}, (sfVector2f){0, 0}, scale);
    sfSprite_setPosition(a->player->obj->s, (sfVector2f){1000, 620});
    sfSprite_setPosition(a->end[0].endgame[0].s, (sfVector2f){960, 490});
    sfSprite_setTextureRect(a->player->obj->s, (sfIntRect)
    {a->player->skin * (160 * 3), 415, 160, 135});
}