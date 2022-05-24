/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** rpg headers
*/

#ifndef RPG_H
#define RPG_H

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/JoystickIdentification.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
#include "garbage_collector.h"
#include "csfml_garbage_collector.h"
#include "../lib/my/my.h"
#include "../src/render_window/window.h"
#include "../src/rpg/init/init.h"
#include "../src/error/error.h"
#include "../src/output/print_help.h"
#include "../src/rpg/menu/menu.h"
#include "../src/rpg/game/game.h"
#include "../src/rpg/combat/combat.h"
#include "../src/rpg/combat/combat_end/combat_end.h"
#include "../src/rpg/game/mobs_spawns/mobs.h"
#include "../src/rpg/game/quest/npc/npc.h"
#include "../src/rpg/game/quest/quest.h"
#include "../src/rpg/game/game.h"
#include "../src/rpg/settings/settings.h"
#include "../src/rpg/game/end_game/endgame.h"

void handle_rpg(all_t *a);

//Main Combat Functions

void init_combat(all_t *a);
void handle_combat(all_t *a);
void destroy_combat(all_t *a);

// Particles

void init_particles(particles_t *particles, sfColor color);
void init_particle(particle_t *particle, sfVector2f pos, int type);
void add_particles(particles_t *particles, int particle_num, int type);
void update_particle(particles_t *particles, particle_t *particle);
void display_particles(all_t *a, particles_t *particles);
void start_weather(all_t *a);
void update_weather(all_t *a);
void display_weather(all_t *a);

//Main game Functions

void init_game(all_t *a);
void handle_game(all_t *a);
void destroy_game(all_t *a);

void handle_settings(all_t *a);
void init_settings(all_t *a);

void get_fps(all_t *a);
void spawn_mobs(float srate, all_t *a);
int rand_nbr(int lower, int upper);
void activate_options_settings(all_t *a);
void init_text_object(text_object_t *t, char *f, char *string);
sfText *create_texts(const char *f, float size, sfVector2f pos, sfColor color);
void slider_sprites(all_t *a);
void set_music_volumes(all_t *a, float volume);
void set_sfx_volumes(all_t *a, float volume);
void start_cinematic(all_t *a);
void destroy_cinematic_assets(all_t *a);
void create_cinematic_assets(all_t *a);
void move_one(all_t *a, int to_display);
float increment_to_wait(int to_display);
void destroy_cinematic_assets(all_t *a);
void display_end(all_t *a);
int get_maze_height(char **maze);
int get_maze_width(char **maze);
void handle_zone_changements(all_t *a);
int can_read_case(all_t *a, int casex, int casey);
void make_transition_between_maps(all_t *a);
char *my_memset(char *str, char c, int size);
void move_minimap(all_t *a, sfVector2f dir);
char **read_file_inv(char *filepath);
char *get_image(int type);
sfVector2f get_pos(int j, sfVector2f pos);
sfVector2f get_equiped_pos(int id, inv_item_t *item);
void add_item(int item, int n, all_t *a);
inv_item_t *load_items(all_t *a);
void play_sfx(all_t *a, sfMusic *sfx);
void save_player_stats(all_t *a, stat_t *stat);
void drop_item_on_slot(inv_item_t *item, sfVector2f pos);
int get_id_from_equiped(sfVector2i mvector);
void init_inv_item(inv_item_t *object, char *filepath, sfVector2i eq_count);
void init_player_inv(char *nickname, all_t *a);
int get_items_size(char *str);
inv_item_t load_item(int type, int j, sfVector2f pos, sfVector2i eq_count);
inv_item_t *load_inv(char *inventory, char **data, all_t *a);
void upload_item_in_inventory_file(all_t *a, int type);
void init_xp_bar(all_t *a);
void unequip_events(all_t *a);
void handle_continue_button(all_t *a, sfEvent event, sfVector2i mouse);
int get_file_bytes_nb(char *filepath);
void move_item(int id, bool pressed, sfVector2i mvector, all_t *a);
bool is_nickname_taken(all_t *a);
bool check_string_char(char *str, char c);
void init_rpg_two(all_t *a);
void init_before_settings(all_t *a);
void init_before_game(all_t *a);
void init_before_game_two(all_t *a);
void init_before_menu(all_t *a);
void load_player_quest_and_pos(all_t *a);
void write_player_quest_and_pos(all_t *a);
void write_player_data_in_file(int fd, all_t *a);
void write_default_data_in_file(int fd, all_t *a);
void write_new_data_in_file(int fd, all_t *a);
void load_default_player(all_t *a);
int get_data_line_in_arr(char **arr, char *data);
void load_player_pos_save(all_t *a, char **line_arr, int lin, char ** file_arr);
void init_minimap_and_location(all_t *a);
void rm_from_data_files(all_t *a);
void write_data_in_file(int line, char **file_arr, all_t *a);
void handle_end_game_events(all_t *a);
void init_end_game(all_t *a);

#endif