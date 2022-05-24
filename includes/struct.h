/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdbool.h>

#ifndef STRUCT_H
#define STRUCT_H

typedef enum  quest_todo_s {
    CHIEF_QUEST,
    BLACKSMITH_QUEST,
    OLDGUY_QUEST,
    FARM_QUEST,
    SKELETON_QUEST,
    BOSS_QUEST
} quest_todo_t;

typedef enum pnj_s {
    QUESTMASTER,
    SPAWNNPC,
    FORGERON,
    OLDIDK,
    SKELETON
} pnj_t;

typedef enum scene_s {
    MENU,
    SETTINGS,
    GAME,
    COMBAT,
    COMBAT_WIN,
    GAME_OVER,
    QUIT,
    CINEMATIC,
    PAUSE,
    HOW_TO_PLAY,
    ENDGAME
} scene_t;

typedef enum world_s {
    SPAWN,
    FOPSPACE,
    DUNGEON,
    BOSS
} world_t;

typedef enum player_skin_s {
    FEATHER,
    HORSETAIL,
    SHORTHAIR,
    CLASSIC
} player_skin_t;

typedef struct stat_s {
    int level;
    int max_hp;
    int hp;
    int max_exp;
    int exp;
    int gold;
    float max_speed;
    float speed;
    int attack;
    int defense;
} stat_t;

typedef struct player_obj_s {
    stat_t stat;
    sfTexture *t;
    sfSprite *s;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfClock *clock;
    sfVector2f velocity;
} player_obj_t;

typedef struct map_obj_s {
    sfTexture *t;
    sfSprite *s;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
} map_obj_t;

typedef struct player_s {
    player_obj_t *obj;
    player_skin_t skin;
    sfClock *movement;
    sfClock *map_movement;
    bool blocked;
    sfText *lvl;
    sfText **stats;
} player_t;

typedef enum states_s {
    JUMPING,
    GROUNDED,
    LEFT,
    RIGHT,
    IDLE,
    ATTACK,
    DEFEND,
    COOL,
    DESTROY
} states_t;

typedef struct gauge_s {
    int value;
    sfTexture *back_t;
    sfSprite *back_s;
    sfTexture *t;
    sfSprite *s;
    sfVector2f pos;
    sfIntRect rect;
} gauge_t;

typedef struct icon_s {
    sfTexture *t;
    sfSprite *s;
    sfFont *font;
    sfText *text;
} icon_t;

typedef struct attack_stats_s {
    int attack;
    int defense;
    int range;
    int cool;
    int max_dist;
    int speed;
    sfVector2i offset;
    int nb_anim;
    sfTexture *t;
    sfIntRect rect;
    sfClock *clock;
    icon_t icon;
} attack_stats_t;

typedef struct attack_s {
    attack_stats_t stats;
    states_t state;
    sfVector2f pos;
    sfVector2f max_pos;
    sfSprite *s;
    sfClock *clock;
    struct attack_s *next;
} attack_t;

typedef struct enemy_s {
    attack_stats_t attacks[4];
    attack_t *my_attacks;
    states_t state;
    states_t dir_state;
    states_t combat_state;
    states_t side;
    int current_attack;
    int nb_attacks;
    int ground;
    gauge_t hp;
    sfVector2f mul;
    float x_mul;
    float y_mul;
    player_obj_t *p;
    sfClock *clock;
} enemy_t;

typedef struct menu_object_s {
    float width;
    float height;
    sfVector2f scale;
    sfVector2f pos;
    sfSprite *s;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
} menu_object_t;

typedef struct mobs_object_s {
    float width;
    float height;
    sfVector2f scale;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    sfClock *rectclock;
    int status;
    char *name;
} mobs_object_t;

typedef struct mobs_list_s
{
    mobs_object_t mobs;
    struct mobs_list_s *next;
} mobs_lists_t;

typedef struct handle_mobs_s
{
    int mb_nb;
    sfClock *spawn_clock;
    sfClock *combat_cooldown;
    sfClock *rdm_move;
    mobs_object_t mobs;
    mobs_object_t combat_mob;
    mobs_lists_t *mb_list;
    sfVector2f **pos_arr;
    bool miniboss;
    bool boss;
    int minibossnb;
    int bossnb;
} handle_mobs_t;

typedef struct map_s {
    map_obj_t *map;
    map_obj_t *l_layer;
    map_obj_t *bot_wall;
    sfVector2u map_dim;
    int world;
    char **txtmap;
    char **txtmap_clone;
    sfRectangleShape **obstacles_rect;
    sfRectangleShape *shadows;
    sfClock *clock;
    menu_object_t *tran_wall;
    bool transition;
    menu_object_t quest_ui;
    quest_todo_t quest_todo;
    sfText *quest;
    sfText *pseudo;
    sfText *location;
    map_obj_t *mini_map;
    menu_object_t xp_bar;
    sfRectangleShape *xp_progress;
} map_t;

typedef struct combat_s {
    enemy_t player;
    enemy_t enemy;
    map_obj_t map;
    menu_object_t button;
    char *enemy_name;
    sfVector2f save_pos;
    sfClock *clock;
} combat_t;

typedef struct main_menu_s {
    menu_object_t *parallax;
    menu_object_t *button;
    char *nickname;
    sfText *nick;
    bool nick_display;
    sfMusic *menu_music;
    bool pseudo_taken;
} main_menu_t;

typedef struct end_game_s {
    menu_object_t *endgame;
} end_game_t;

typedef struct text_object_s {
    sfFont *font;
    sfText *text;
    sfVector2f pos;
    float size;
    sfColor color;
    int key;
} text_object_t;

typedef struct settings_s {
    menu_object_t *interface;
    menu_object_t *keygui;
    text_object_t *keytxt;
    text_object_t *sliderstxt;
    bool changing_key;
    int status;
    bool vsync;
    bool showfps;
    bool particles;
    bool enable_sfx;
    bool enable_music;
    float music;
    float sfx;
    sfClock *fps_clock;
    sfText *fps;
} settings_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfTexture *t;
    sfSprite *s;
    char **content;
    int index;
    int nb_visible;
    sfVector2f pos;
    sfClock *clock;
} text_t;

typedef struct pause_s {
    sfRectangleShape *blacklayer;
    menu_object_t *interface;
    int status;
    bool paused;
    sfText *nickname;
} pause_t;

typedef struct cinematic_s {
    sfMusic *monolog;
    menu_object_t *obj;
    sfClock *clock;
    sfRectangleShape *trans;
    bool transition;
    sfColor color;
    int end;
    bool start_mus;
} cinematic_t;

typedef enum quest_s {
    TO_DO,
    IN_PROGRESS,
    DONE
} quest_t;

typedef struct npc_obj_s {
    float width;
    float height;
    sfVector2f scale;
    sfVector2f pos;
    sfSprite *s;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    bool quest;
    int status;
    int id;
} npc_obj_t;

typedef struct npc_s {
    npc_obj_t *obj;
    npc_obj_t *npc_arr;
    npc_obj_t *interact_button;
    int npc_nb;
    char *fp;
    int index;
    bool dialoging;
    sfText *interact_key;
    menu_object_t *dotex;
    bool ex;
    sfClock *go_back;
} npc_t;

typedef struct add_item_s {
    int fd;
    int j;
    char **inventory;
    char **data;
    char *copy;
} add_item_t;

typedef struct inv_item_s {
    float width;
    float height;
    bool equiped;
    sfVector2f scale;
    sfVector2f pos;
    sfSprite *s;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    bool drawable;
    int id;
} inv_item_t;

typedef struct inventory_s {
    menu_object_t sprite;
    inv_item_t *items;
    bool show;
    int items_size;
    char **data;
    sfRectangleShape *xp_bar;
    text_object_t stats;
} inventory_t;

typedef struct sfx_s {
    sfMusic *attack;
    sfMusic *hit;
    sfMusic *win;
    sfMusic *lose;
    sfMusic *dialogue;
    sfMusic *click;
} sfx_t;

typedef struct particle_s
{
    sfVector2f pos;
    sfVector2f size;
    bool living;
} particle_t;

typedef struct particles_s
{
    float speed;
    sfClock *clock;
    sfRectangleShape *rect;
    sfCircleShape *circle;
    sfColor color;
    int weather;
    particle_t particle[1000];
} particles_t;

typedef struct all_s {
    sfRenderWindow *window;
    scene_t scene;
    bool in_dialogue;
    particles_t particles;
    main_menu_t main_menu[1];
    settings_t settings[2];
    handle_mobs_t mobs[1];
    inventory_t inventory;
    player_t player[1];
    pause_t pause[1];
    combat_t combat;
    map_t map;
    int *key_arr;
    text_t text;
    cinematic_t cin[1];
    npc_t npc[1];
    end_game_t end[1];
    sfx_t sfx;
    sfImage *logo;
} all_t;

#endif