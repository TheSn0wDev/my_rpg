/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** menu
*/

#include "struct.h"

void init_menu(all_t *a);
void handle_menu(all_t *a);
void draw_parallax(all_t *a);
void destroy_menu(all_t *a);
void create_menu_sprites(all_t *a);
void init_menu_object(menu_object_t *object, char *filepath);
void show_skin_walking_in_menu(all_t *a);
void init_nickname(all_t *a);
void handle_how_to_play(all_t *a);
void menu_howtoplay_button(all_t *a, sfEvent event, sfVector2i mouse);