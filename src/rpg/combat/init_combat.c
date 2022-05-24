/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_game
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

void apply_stats(stat_t *stat, char **player)
{
    if (player == NULL || stat == NULL)
        return;
    stat->level = my_getnbr(player[1]);
    stat->attack = my_getnbr(player[2]);
    stat->defense = my_getnbr(player[3]);
    stat->hp = my_getnbr(player[4]);
    stat->max_hp = my_getnbr(player[5]);
    stat->speed = my_getnbr(player[6]);
    stat->max_speed = stat->speed;
    stat->exp = my_getnbr(player[7]);
    stat->max_exp = my_getnbr(player[8]);
}

void set_stat(all_t *a, stat_t *stat)
{
    char **info = read_arr_file("data/players/player.txt");
    char **player = NULL;
    bool player_found = false;

    for (int i = 4; info[i] && player_found == false; i++) {
        player = my_str_to_word_array(info[i], " ");
        if (my_strcmp(player[0], a->main_menu->nickname) == 0)
            player_found = true;
    }
    if (a->main_menu->nickname[0] == 0 || player_found == false)
        player = my_str_to_word_array(info[4], " ");
    apply_stats(stat, player);
}

void create_combat_map(char *img, sfVector2f pos, map_obj_t *map)
{
    map->t = create_texture(img, NULL);
    map->s = create_sprite();
    map->pos = pos;
    sfSprite_setTexture(map->s, map->t, sfTrue);
    sfSprite_setPosition(map->s, map->pos);
}

void init_before_combat(all_t *a)
{
    char *back = "assets/combat/desert_back.png";

    set_stat(a, &a->player->obj->stat);
    a->combat.clock = create_clock();
    a->combat.player.ground = 865;
    a->combat.enemy_name = "DEFAULT";
    create_combat_map(back, (sfVector2f){0, 0}, &a->combat.map);
}

void init_combat(all_t *a)
{
    sfVector2f e_hp_pos = {100, 100};
    sfVector2f p_hp_pos = {1100, 100};

    a->combat.save_pos = a->player->obj->pos;
    a->combat.enemy_name = a->mobs[0].combat_mob.name;
    sfSprite_setScale(a->player->obj->s, (sfVector2f){1, 1});
    create_combat_enemy(a, &a->combat.enemy, a->combat.enemy_name);
    create_combat_player(&a->combat.player, a);
    create_gauge(&a->combat.player.hp, a->combat.player.p->stat.hp, p_hp_pos);
    create_gauge(&a->combat.enemy.hp, a->combat.enemy.p->stat.hp, e_hp_pos);
}