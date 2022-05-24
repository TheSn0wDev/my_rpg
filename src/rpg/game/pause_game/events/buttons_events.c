/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** buttons_events
*/

#include "struct.h"
#include "rpg.h"

void pause_resume_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->pause->interface[0], mouse))
        sfSprite_setTextureRect(a->pause->interface[0].s,
        (sfIntRect){0, 84, 465, 84});
    else {
        sfSprite_setTextureRect(a->pause->interface[0].s,
        (sfIntRect){0, 0, 465, 84});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->pause->interface[0], mouse)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->pause->interface[0].s,
        (sfIntRect){0, 84*2, 465, 84});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->pause->interface[0], mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->pause->status = a->scene;
}

void pause_returnmenu_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->pause->interface[3], mouse))
        sfSprite_setTextureRect(a->pause->interface[3].s,
        (sfIntRect){0, 84, 465, 84});
    else {
        sfSprite_setTextureRect(a->pause->interface[3].s,
        (sfIntRect){0, 0, 465, 84});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->pause->interface[3], mouse)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->pause->interface[3].s,
        (sfIntRect){0, 168, 465, 84});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->pause->interface[3], mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->pause->status = MENU;
}

void pause_settings_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->pause->interface[1], mouse))
        sfSprite_setTextureRect(a->pause->interface[1].s,
        (sfIntRect){0, 53, 325, 51});
    else {
        sfSprite_setTextureRect(a->pause->interface[1].s,
        (sfIntRect){0, 0, 325, 51});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->pause->interface[1], mouse)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->pause->interface[1].s,
        (sfIntRect){0, 104, 325, 51});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->pause->interface[1], mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->pause->status = SETTINGS;
}

void pause_quit_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->pause->interface[2], mouse))
        sfSprite_setTextureRect(a->pause->interface[2].s,
        (sfIntRect){0, 51, 320, 51});
    else {
        sfSprite_setTextureRect(a->pause->interface[2].s,
        (sfIntRect){0, 0, 320, 51});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->pause->interface[2], mouse)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->pause->interface[2].s,
        (sfIntRect){0, 102, 320, 51});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->pause->interface[2], mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->pause->status = QUIT;
}

void handle_pause_buttons(all_t *a, sfEvent event)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(a->window);

    pause_resume_button(a, event, mousepos);
    pause_settings_button(a, event, mousepos);
    pause_quit_button(a, event, mousepos);
    pause_returnmenu_button(a, event, mousepos);
}