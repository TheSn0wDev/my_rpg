/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game
*/

#ifndef game
#define game

#include "player/player.h"
#include "map/map.h"

void init_game(all_t *a);
void init_before_game(all_t *a);
void handle_game(all_t *a);
void destroy_game(all_t *a);
void display_game(all_t *a);
void handle_game_events(all_t *a);
int get_obstacles_count(char **map);
int is_arrow(sfEvent event);

// Dialogue

void start_dialogue(all_t *a, char *txt);
void update_dialogue(all_t *a);
void draw_dialogue(all_t *a);
void init_dialogue(all_t *a);
void check_interaction(all_t *a);

//draw

void must_draw_after_player_spawn(all_t *a);
void must_draw_before_player_dungeon_boss(all_t *a);
void must_draw_before_player_fospace(all_t *a);
void must_draw_before_player_dungeon(all_t *a);
void display_npc(all_t *a);
void npc_button(all_t *a);

// inventory
void draw_inventory(all_t *a);
void init_inventory(all_t *a);

//zone changement

void handle_zone_changements(all_t *a);

#endif /* !game */
