/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init window for game
*/

#include "rpg.h"
#include "struct.h"

void init_before_menu(all_t *a)
{
    a->sfx.hit = create_music("assets/musics/canon.ogg");
    a->sfx.attack = create_music("assets/musics/swing.ogg");
    a->sfx.dialogue = create_music("assets/musics/dialogue.ogg");
    a->sfx.click = create_music("assets/musics/menu_clicks.ogg");
    a->sfx.lose = NULL;
    a->sfx.win = NULL;
    init_nickname(a);
    slider_sprites(a);
}

void init_before_game_two(all_t *a)
{
    menu_object_t start = {0, 0, {1, 1}, {0, 0}, 0, 0, {0, 0, 1920, 1080}, 0};
    menu_object_t ex = {0, 0, {0.05, 0.05}, {0, 0}, 0, 0, {0, 0, 306, 969}, 0};

    a->map.txtmap_clone = get_txt_map("src/rpg/game/map/test.txt");
    init_mobs(a);
    a->map.clock = create_clock();
    a->map.transition = false;
    a->map.tran_wall = my_malloc(sizeof(menu_object_t) * 1);
    init_menu_object(&start, "assets/cinematic/title_screen.jpg");
    a->map.tran_wall[0] = start;
    a->mobs[0].pos_arr = my_malloc(sizeof(sfVector2f*) * 25);
    a->npc->ex = false;
    a->npc->dotex = my_malloc(sizeof(menu_object_t) * 1);
    init_menu_object(&ex, "assets/npc/ex.png");
    a->npc->dotex[0] = ex;
    a->inventory.items_size = 0;
    a->inventory.data = NULL;
}

void init_before_game(all_t *a)
{
    sfVector2f scale = {1, 1};

    a->map.map = create_map("assets/maps/small_castle_map.png",
    (sfIntRect){200, 400, 1920, 1080}, (sfVector2f){0, 0}, scale);
    a->player->obj = init_player("assets/player_skins/skin_asset.png",
    (sfIntRect){a->player->skin * (160 * 3), 0, 160, 135},
    (sfVector2f){1170 - a->map.map->rect.left, 980 - a->map.map->rect.top},
    (sfVector2f){0.6, 0.6});
    a->player->obj->stat.level = 1;
    a->map.l_layer = create_map("assets/maps/last_layer.png",
    (sfIntRect){200, 400, 1920, 1080}, (sfVector2f){0, 10}, scale);
    a->map.bot_wall = create_map("assets/maps/bot_wall.png",
    (sfIntRect){200, 400, 1920, 1080}, (sfVector2f){0, 0}, scale);
    a->map.map_dim = (sfVector2u){2328, 2328};
    a->map.world = SPAWN;
    a->map.txtmap = get_txt_map("src/rpg/game/map/test.txt");
    init_before_game_two(a);
}

void init_before_settings(all_t *a)
{
    a->settings->vsync = false;
    a->settings->showfps = false;
    a->settings->particles = true;
    a->settings->enable_music = true;
    a->settings->enable_sfx = true;
    a->settings->music = 20;
    a->settings->sfx = 40;
    a->settings[0].interface = my_malloc(sizeof(menu_object_t) * 30);
}

void init_rpg(void)
{
    all_t a;
    int key_arr[9] = {'z', 'q', 's', 'd', 'e', 'a', 'a', 'e', 'r'};
    static bool once = false;

    init_rpg_two(&a);
    a.key_arr = my_malloc(sizeof(int) * (6));
    a.key_arr = key_arr;
    if (once == false) {
        a.logo = sfImage_createFromFile("assets/diabolo.jpeg");
        a.window = create_window(sfFullscreen, a.logo);
        a.pause->status = GAME;
        a.pause->paused = false;
        once = true;
    }
    init_npc(&a, false);
    handle_rpg(&a);
}