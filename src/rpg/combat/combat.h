/*
** EPITECH PROJECT, 2020
** My_screensaver
** File description:
** my_screensaver.h
*/

#ifndef RPG_H_
#define RPG_H_

#include <struct.h>
#include <rpg.h>

// Window

void analyse_combat_events(all_t *a);

float get_seconds(sfClock *clock);

// Player / Enemy

void create_combat_enemy(all_t *a, enemy_t *enemy, char *name);
void create_combat_player(enemy_t *player, all_t *a);
void update_dir_pos(enemy_t *player, enemy_t *enemy, int x, float value);
void continue_action(all_t *a, enemy_t *player, enemy_t *enemy);
void continue_player_action(all_t *a, enemy_t *player, enemy_t *enemy);
void destroy_enemy(enemy_t *enemy);
void update_enemy(all_t *a, enemy_t *enemy, int ground, int identity);
void get_next_action(all_t *a, enemy_t *enemy, enemy_t *player);

// Collisions

int are_colliding(enemy_t *player, enemy_t *enemy, int minus);
int hit_enemy(enemy_t *enemy, attack_t *attack);

// Gauge

void create_gauge(gauge_t *gauge, int value, sfVector2f pos);
void update_gauge_hp(gauge_t *gauge, enemy_t *enemy);
void draw_gauge(sfRenderWindow *window, gauge_t *gauge);

// Combat Scene

void init_sfx(all_t *a);
void init_before_combat(all_t *a);
void update_combat(all_t *a);
void update_attacks(all_t *a, enemy_t *enemy, attack_t **attacks);
void analyse_combat_events(all_t *a);
void display_combat(all_t *a);

// Essentials

char **read_arr_file(char *filepath);
float round_float(float nb, int x);
int rand_nbr(int lower, int upper);

// Manipulate Attacks

void create_attack(attack_stats_t *attack, char *info, stat_t *my_stats);
void update_attacks(all_t *a, enemy_t *enemy, attack_t **attacks);
void destroy_attacks(attack_t **attack);
void destroy_attack(attack_t **attack, int index);
void push_back_attack(attack_t **att, attack_stats_t *stats, sfVector2f pos);
void push_front_attack(attack_t **att, attack_stats_t *stats, enemy_t *player);

// Cooldowns

void update_cooldowns(all_t *a, enemy_t *enemy);
void display_cooldowns(sfRenderWindow *window, enemy_t *enemy);

void set_stat(all_t *a, stat_t *stat);

#endif /*RPG_H*/