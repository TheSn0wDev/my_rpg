/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init menu of rpg
*/

#include "rpg.h"
#include "struct.h"
#include "menu.h"

void init_nickname(all_t *a)
{
    sfColor color =  sfColor_fromRGBA(220, 118, 51, 255);

    a->main_menu->nick_display = false;
    a->main_menu->nick = create_texts("assets/fonts/diablo_h.ttf", 18,
    (sfVector2f){820, 712}, color);
    a->settings->fps = create_texts("assets/fonts/diablo_h.ttf", 24,
    (sfVector2f){1800, 10}, color);
    a->main_menu->nickname = my_malloc(sizeof(char) *  10);
    a->main_menu->nickname = memset(a->main_menu->nickname, '\0', 9);
    sfText_setString(a->main_menu->nick, "Enter your Nickname here !");
}

void init_menu(all_t *a)
{
    a->main_menu->pseudo_taken = false;
    create_menu_sprites(a);
}