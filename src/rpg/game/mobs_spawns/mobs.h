/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** mobs
*/

#ifndef MOBS_H_
#define MOBS_H_

#include "struct.h"

void create_special_mob_one(all_t *a);
void create_special_mob_two(all_t *a);

sfVector2i get_player_case(all_t *a);

void int_list_push_front(mobs_lists_t **list, mobs_object_t mobs);
void pop_front(mobs_lists_t **list);
void int_list_push_back(mobs_lists_t **list, mobs_object_t mobs);
void int_list_destroy(mobs_lists_t **list);
void int_list_pop_back(mobs_lists_t **list);
void printlist(mobs_lists_t *list);
void mobs_movements(all_t *a, mobs_object_t *mob);
int chase_player(all_t *a, mobs_object_t *mob, sfVector2f p_pos);
void change_mob_rect(mobs_object_t *mob, int left);
void init_mobs_object(mobs_object_t *object, char *filepath);
void init_mobs_name(mobs_object_t *object, int nb);
void spawn_mobs(float srate, all_t *a);
void create_mob(all_t *a, sfVector2i pos);
int check_maps_mobs_spawns(all_t *a, int y, int x, int srate);
int check_mobs_on_map(all_t *a, int *xc, int *yc, int srate);
bool check_for_colision(all_t *a, mobs_object_t mobs);
void handle_mobs(all_t *a);
void change_dir_animation(mobs_object_t *mob, sfVector2f p_pos);
void draw_mobs(all_t *a);
int random_monster_movements(all_t *a, mobs_object_t *mob);
int mb_colide(all_t *a, mobs_object_t *mob, sfVector2i coods);
void init_mobs(all_t *a);

#endif /* !MOBS_H_ */