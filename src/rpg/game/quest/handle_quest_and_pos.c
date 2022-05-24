/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

void init_player_pos(all_t *a)
{
    sfIntRect rect =  (sfIntRect){a->player->skin * (160 * 3), 0, 160, 135};

    sfSprite_setTextureRect(a->player->obj->s, rect);
    a->player->obj->pos = (sfVector2f){1000, 580};
    sfSprite_setPosition(a->player->obj->s, (sfVector2f){1020, 580});
    sfSprite_setScale(a->player->obj->s, (sfVector2f){0.6, 0.6});
    sfSprite_setOrigin(a->player->obj->s, (sfVector2f){80, 67});
    init_minimap_and_location(a);
}

void init_new_game(all_t *a)
{
    sfVector2f scale = {1, 1};

    a->map.quest_todo = 0;
    a->map.map = create_map("assets/maps/small_castle_map.png",
    (sfIntRect){200, 400, 1920, 1080}, (sfVector2f){0, 0}, scale);
    a->player->obj->stat.level = 1;
    a->map.l_layer = create_map("assets/maps/last_layer.png",
    (sfIntRect){200, 400, 1920, 1080}, (sfVector2f){0, 10}, scale);
    a->map.bot_wall = create_map("assets/maps/bot_wall.png",
    (sfIntRect){200, 400, 1920, 1080}, (sfVector2f){0, 0}, scale);
    a->map.map_dim = (sfVector2u){2328, 2328};
    a->map.world = SPAWN;
    a->map.txtmap = get_txt_map("src/rpg/game/map/test.txt");
    init_player_pos(a);
}

void load_dungeon_npc_numbers(all_t *a)
{
    if (a->map.world == DUNGEON) {
        if (a->mobs[0].miniboss == false)
            a->mobs[0].minibossnb = 0;
        a->npc->npc_nb = 3;
        a->npc->index = 3;
        init_npc(a, true);
    }
    if (a->map.world == BOSS) {
        if (a->mobs[0].boss == false)
            a->mobs[0].boss = 0;
    }
}

void load_npc_numbers(all_t *a)
{
    if (a->map.world == SPAWN) {
        a->npc->index = 0;
        a->npc->npc_nb = 0;
        init_npc(a, true);
    }
    if (a->map.world == FOPSPACE) {
        a->npc->npc_nb = 3;
        a->npc->index = 3;
        init_npc(a, true);
    }
    load_dungeon_npc_numbers(a);
}

void load_player_quest_and_pos(all_t *a)
{
    char **file_arr = read_arr_file("data/players/player_data.txt");
    int line = get_data_line_in_arr(file_arr, a->main_menu->nickname);
    char **line_arr = NULL;

    if (line == -1) {
        load_npc_numbers(a);
        init_new_game(a);
        return;
    }
    load_player_pos_save(a, line_arr, line, file_arr);
    load_npc_numbers(a);
    if (a->map.world == FOPSPACE && (a->map.quest_todo == SKELETON_QUEST ||
    a->map.quest_todo == BOSS_QUEST)) {
        a->npc[0].obj[OLDIDK].quest = true;
        a->npc[0].npc_arr[FORGERON].quest = false;
    }
    sfText_setString(a->player->lvl,
    my_strcat("LEVEL : ", my_itoa(a->player->obj->stat.level)));
}