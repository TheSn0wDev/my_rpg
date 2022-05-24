/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** combat_end.h
*/

#ifndef COMBAT_END_H
#define COMBAT_END_H

#include <rpg.h>

void init_game_over(all_t *a);

void handle_game_over(all_t *a);

void destroy_game_over(all_t *a);

void init_combat_end(all_t *a);

void analyse_combat_end_events(all_t *a);

void handle_combat_end(all_t *a, stat_t *stats);

void destroy_combat_end(all_t *a);

void level_up(all_t *a, stat_t *old_stats);

void create_button_end(char *image, menu_object_t *button, sfVector2f pos);

bool is_sprite_hovered(menu_object_t sprite, sfVector2i mouse);

void init_texts(all_t *a, sfText **text, stat_t *stats);

#endif /* !COMBAT_END */