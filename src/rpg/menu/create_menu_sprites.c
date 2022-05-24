/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** create_menu_sprites
*/

#include "menu.h"
#include "struct.h"
#include "rpg.h"
#include <string.h>

void create_parallax_sprites(all_t *a)
{
    menu_object_t parallax;

    a->main_menu[0].parallax = my_malloc(sizeof(menu_object_t) * 11);
    for (int i = 1; i <= 10; i++) {
        parallax = (menu_object_t){0, 0, {1, 1},
        {0, 0}, 0, 0, {0, 0, 1920, 1080}, 0};
        init_menu_object(&parallax, my_strcat("assets/menu/parallax/p_",
        my_strcat(my_itoa(i), ".png")));
        a->main_menu[0].parallax[i - 1] = parallax;
        sfTexture_setRepeated(a->main_menu[0].parallax[i - 1].texture, sfTrue);
    }
}

void create_playerselect(all_t *a)
{
    menu_object_t nextarrow = {0, 0, {0.65, 0.65},
    {1055, 656}, 0, 0, {0, 0, 62, 60}, 0};
    menu_object_t nicknamebar = {0, 0, {0.5, 0.5},
    {800, 700}, 0, 0, {0, 0, 708, 106}, 0};
    menu_object_t caracter = {0, 0, {1.5, 1.5},
    {865, 450}, 0, 0, {a->player->skin * (160 * 3), 0, 160, 135}, 0};

    a->player->skin = FEATHER;
    init_menu_object(&nicknamebar, "assets/menu/nicknamebar.png");
    a->main_menu[0].button[3] = nicknamebar;
    init_menu_object(&nextarrow, "assets/menu/nextarrow.png");
    a->main_menu[0].button[4] = nextarrow;
    init_menu_object(&caracter, "assets/player_skins/skin_asset.png");
    a->main_menu[0].button[5] = caracter;
}

void create_continue_button(all_t *a)
{
    menu_object_t start = {0, 0, {1, 1},
    {789 / 2, 414}, 0, 0, {0, 0, 358, 71}, 0};
    menu_object_t continue_game = {0, 0, {0.75, 0.85},
    {795/2, 414}, 0, 0, {0, 0, 465, 252 / 3}, 0};

    init_menu_object(&start, "assets/menu/buttons/b_1.png");
    a->main_menu[0].button[0] = start;
    init_menu_object(&continue_game, "assets/combat/continue_button.png");
    a->main_menu[0].button[6] = continue_game;
}

void create_menu_sprites(all_t *a)
{
    menu_object_t how_to_play = {0, 0, {0.73, 0.73},
    {805 / 2, 514}, 0, 0, {0, 0, 465, 84}, 0};
    menu_object_t settings = {0, 0, {1, 1},
    {820 / 2, 614}, 0, 0, {0, 0, 325, 51}, 0};
    menu_object_t quit = {0, 0, {1.02, 1},
    {820 / 2, 694}, 0, 0, {0, 0, 325, 51}, 0};

    a->main_menu[0].button = my_malloc(sizeof(menu_object_t) * 9);
    create_parallax_sprites(a);
    init_menu_object(&settings, "assets/menu/buttons/b_2.png");
    a->main_menu[0].button[1] = settings;
    init_menu_object(&quit, "assets/menu/buttons/b_3.png");
    a->main_menu[0].button[2] = quit;
    init_menu_object(&how_to_play, "assets/menu/buttons/howtoplay.png");
    a->main_menu[0].button[7] = how_to_play;
    create_playerselect(a);
    create_continue_button(a);
}