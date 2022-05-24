/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player
*/

#ifndef PLAYER
#define PLAYER

#include "struct.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/JoystickIdentification.h>

void move_player(all_t *a, sfKeyCode code);
player_obj_t *init_player(char *filepath, sfIntRect rect, \
sfVector2f pos, sfVector2f scale);
void init_game_player(player_obj_t *object, sfIntRect rect, sfVector2f scale);
void change_player_rect(all_t *a, int top);
void set_player_pos(all_t *a);
int is_colliding(all_t *a, sfKeyCode code);
void make_player_walk(all_t *a, sfKeyCode code);
void actualize_player_clock(all_t *a);
void init_player_displaying_stats(player_t *player);
void update_stat(int *stat_to_modif, int to_add);
void get_equipement_stat_update(player_t *player, int id, int option);
void equip_item_in_inv(all_t *a, int id);
void unequip_item_in_inv(all_t *a, int id, int i);

#endif /* !PLAYER */