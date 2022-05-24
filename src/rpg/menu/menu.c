/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** menu
*/

#include "rpg.h"
#include "struct.h"
#include "./events/events.h"

void display_play_button(all_t *a)
{
    if (!a->main_menu->pseudo_taken)
        sfRenderWindow_drawSprite(a->window, a->main_menu[0].button[0].s,
        NULL);
    else
        sfRenderWindow_drawSprite(a->window, a->main_menu[0].button[6].s,
        NULL);
}

void handle_pseudo_bar(all_t *a)
{
    if (check_string_char(a->main_menu->nickname, '\0') == false)
        a->main_menu->nick_display = true;
    if (a->main_menu->nick_display == true)
        sfText_setString(a->main_menu->nick, a->main_menu->nickname);
    if (check_string_char(a->main_menu->nickname, 0) == true)
        sfText_setString(a->main_menu->nick, "Enter your Nickname here !");
}

void handle_menu(all_t *a)
{
    while (a->scene == MENU) {
        handle_menu_events(a);
        sfRenderWindow_clear(a->window, sfBlack);
        draw_parallax(a);
        for (int i = 1; i < 8; i++) {
            sfRenderWindow_drawSprite(a->window,
            a->main_menu[0].button[i].s, NULL);
        }
        display_play_button(a);
        handle_pseudo_bar(a);
        sfRenderWindow_drawText(a->window, a->main_menu->nick, NULL);
        show_skin_walking_in_menu(a);
        activate_options_settings(a);
        sfRenderWindow_display(a->window);
    }
    set_stat(a, &a->player->obj->stat);
}