/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** create_enemy.c
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

int get_enemy_info(char *name, char **info)
{
    char **temp = NULL;

    for (int i = 0; info[i]; i++) {
        temp = my_str_to_word_array(info[i], " ");
        if (my_strcmp(temp[0], name) == 0) {
            return (i);
        }
    }
    return (0);
}

void scale_enemy_stats(all_t *a, enemy_t *enemy)
{
    int level = a->player->obj->stat.level;

    enemy->p->stat.attack += level * rand() % 3;
    enemy->p->stat.defense += level * rand() % 3;
    enemy->p->stat.speed += level * rand() % 2;
    enemy->p->stat.max_speed += level * rand() % 3;
    enemy->p->stat.exp += level * rand() % 5;
    enemy->p->stat.gold += level * rand() % 5;
    enemy->p->scale = (sfVector2f){5, 5};
    enemy->p->rect.left = 3 * enemy->p->rect.height;
}

void init_enemy_stats(all_t *a, enemy_t *enemy, char *name)
{
    char **info = read_arr_file("assets/combat/attacks/enemy.txt");
    int pos = get_enemy_info(name, info);
    mobs_object_t mob = a->mobs[0].combat_mob;
    char **enemy_stats = my_str_to_word_array(info[pos], " ");

    enemy->nb_attacks = my_getnbr(enemy_stats[5]);
    enemy->p->stat.attack = my_getnbr(enemy_stats[1]);
    enemy->p->stat.defense = my_getnbr(enemy_stats[2]);
    enemy->p->stat.hp = my_getnbr(enemy_stats[3]);
    enemy->p->stat.max_hp = enemy->p->stat.hp;
    enemy->p->stat.speed = my_getnbr(enemy_stats[4]);
    enemy->p->stat.max_speed = enemy->p->stat.speed;
    enemy->p->stat.exp = my_getnbr(enemy_stats[6]);
    enemy->p->stat.gold = my_getnbr(enemy_stats[7]);
    enemy->p->rect = mob.rect;
    enemy->p->s = mob.sprite;
    scale_enemy_stats(a, enemy);
    for (int i = 0; i < enemy->nb_attacks; i++)
        create_attack(&enemy->attacks[i], info[pos + i + 2], &enemy->p->stat);
}

void create_combat_enemy(all_t *a, enemy_t *enemy, char *name)
{
    enemy->p = my_malloc(sizeof(player_obj_t));
    init_enemy_stats(a, enemy, name);
    enemy->p->clock = create_clock();
    enemy->clock = create_clock();
    enemy->state = GROUNDED;
    enemy->dir_state = IDLE;
    enemy->combat_state = IDLE;
    enemy->side = RIGHT;
    enemy->current_attack = 0;
    enemy->my_attacks = NULL;
    enemy->y_mul = -1;
    enemy->x_mul = 0;
    enemy->ground = 1000 - (enemy->p->rect.height * enemy->p->scale.x);
    enemy->p->pos = (sfVector2f){100, enemy->ground};
    sfSprite_setScale(enemy->p->s, enemy->p->scale);
    sfSprite_setTextureRect(enemy->p->s, enemy->p->rect);
    sfSprite_setPosition(enemy->p->s, enemy->p->pos);
}

void create_combat_player(enemy_t *player, all_t *a)
{
    char **attacks = read_arr_file("data/players/player.txt");

    player->p = a->player->obj;
    player->state = GROUNDED;
    player->dir_state = IDLE;
    player->combat_state = IDLE;
    player->side = LEFT;
    player->current_attack = 0;
    player->my_attacks = NULL;
    create_attack(&player->attacks[0], attacks[1], &player->p->stat);
    create_attack(&player->attacks[1], attacks[2], &player->p->stat);
    player->nb_attacks = 2;
    player->y_mul = -1;
    player->x_mul = 0;
    player->clock = create_clock();
    player->p->pos = (sfVector2f){1600, 865};
    sfSprite_setOrigin(player->p->s, (sfVector2f){0, 0});
    player->p->rect = (sfIntRect){a->player->skin * (160 * 3), 135, 160, 135};
    sfSprite_setTextureRect(player->p->s, player->p->rect);
    sfSprite_setPosition(player->p->s, player->p->pos);
}