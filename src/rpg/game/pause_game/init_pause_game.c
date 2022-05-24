/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** init_pause_game
*/

#include "rpg.h"
#include "struct.h"

void create_black_layer(all_t *a)
{
    sfColor color = sfColor_fromRGBA(0, 0, 0, 200);

    a->pause->blacklayer = create_rectangle();
    sfRectangleShape_setFillColor(a->pause->blacklayer, color);
    sfRectangleShape_setSize(a->pause->blacklayer,
    (sfVector2f){20000, 20000});
    sfRectangleShape_setPosition(a->pause->blacklayer,
    (sfVector2f){0, 0});
}

void create_walking_player(all_t *a)
{
    menu_object_t character = {0, 0, {1.5, 1.5},
    {865, 450}, 0, 0, {a->player->skin * (160 * 3), 0, 160, 135}, 0};

    init_menu_object(&character, "assets/player_skins/skin_asset.png");
    a->pause[0].interface[4] = character;
}

void create_pausegame_sprites_two(all_t *a)
{
    menu_object_t settings = {0, 0, {1, 1},
    {830/2, 514}, 0, 0, {0, 0, 325, 51}, 0};
    menu_object_t quit = {0, 0, {1.02, 1},
    {830/2, 594}, 0, 0, {0, 0, 325, 51}, 0};

    init_menu_object(&settings, "assets/menu/buttons/b_2.png");
    a->pause[0].interface[1] = settings;
    init_menu_object(&quit, "assets/menu/buttons/b_3.png");
    a->pause[0].interface[2] = quit;
}

void create_pausegame_sprites(all_t *a)
{
    menu_object_t start = {0, 0, {0.8, 0.8},
    {789/2, 314}, 0, 0, {0, 0, 465, 84}, 0};
    menu_object_t returnmenu = {0, 0, {0.8, 0.8},
    {789/2, 414}, 0, 0, {0, 0, 465, 84}, 0};
    sfColor color =  sfColor_fromRGBA(220, 118, 51, 255);

    a->pause[0].interface = my_malloc(sizeof(menu_object_t) * 6);
    init_menu_object(&start, "assets/menu/buttons/resumegame.png");
    a->pause[0].interface[0] = start;
    init_menu_object(&returnmenu, "assets/menu/buttons/returnmenu.png");
    a->pause[0].interface[3] = returnmenu;
    create_pausegame_sprites_two(a);
    create_walking_player(a);
    a->pause->nickname = create_texts("assets/fonts/diablo_h.ttf", 24,
    (sfVector2f){925, 420}, color);
    sfText_setString(a->pause->nickname, a->main_menu->nickname);
}