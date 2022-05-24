/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** menu
*/

#include "rpg.h"
#include "struct.h"
#include "settings.h"
#include "./events/events.h"

void draw_videogui(all_t *a)
{
    for (int i = 6; i < 9; i++) {
        sfRenderWindow_drawSprite(a->window,
        a->settings[0].interface[i].s, NULL);
    }
    sfRenderWindow_drawSprite(a->window,
    a->settings[0].interface[0].s, NULL);
    sfRenderWindow_drawSprite(a->window,
    a->settings[0].interface[6].s, NULL);
    sfRenderWindow_drawSprite(a->window,
    a->settings[0].interface[7].s, NULL);
    sfRenderWindow_drawSprite(a->window,
    a->settings[0].interface[8].s, NULL);
}

void draw_volumegui(all_t *a)
{
    for (int i = 9; i < 11; i++) {
        sfRenderWindow_drawSprite(a->window,
        a->settings[0].interface[1].s, NULL);
        sfRenderWindow_drawSprite(a->window,
        a->settings[0].interface[i].s, NULL);
        sfRenderWindow_drawSprite(a->window,
        a->settings[0].interface[13].s, NULL);
        sfRenderWindow_drawSprite(a->window,
        a->settings[0].interface[14].s, NULL);
    }
    sfRenderWindow_drawSprite(a->window,
    a->settings[0].interface[9].s, NULL);
    sfRenderWindow_drawText(a->window,
    a->settings[1].sliderstxt[2].text, NULL);
    sfRenderWindow_drawText(a->window,
    a->settings[1].sliderstxt[1].text, NULL);

}

void draw_keybindsgui(all_t *a)
{
    sfRenderWindow_drawSprite(a->window,
    a->settings[0].interface[21].s, NULL);
    for (int i = 0; i <= 8; i++) {
        sfRenderWindow_drawSprite(a->window,
        a->settings[1].keygui[i].s, NULL);
    }
    for (int i = 0; i <= 17; i++)
        sfRenderWindow_drawText(a->window,
        a->settings[1].keytxt[i].text , NULL);

}

void handle_settings(all_t *a)
{
    while (a->scene == SETTINGS) {
        handle_settings_events(a);
        sfRenderWindow_clear(a->window, sfBlack);
        if (a->settings->status == VIDEO)
            draw_videogui(a);
        if (a->settings->status == VOLUME)
            draw_volumegui(a);
        if (a->settings->status == KEYBINDS)
            draw_keybindsgui(a);
        for (int i = 2; i <= 5; i++) {
            sfRenderWindow_drawSprite(a->window,
            a->settings[0].interface[i].s, NULL);
        }
        activate_options_settings(a);
        sfRenderWindow_display(a->window);
    }
}