/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** handle_menu_events
*/

#include "struct.h"
#include "rpg.h"
#include "events.h"

bool is_sprite_hovered(menu_object_t sprite, sfVector2i mouse)
{
    if (sprite.pos.x <= mouse.x &&
    mouse.x <= sprite.pos.x + sprite.rect.width * sprite.scale.x
    && sprite.pos.y <= mouse.y &&
    mouse.y <= sprite.pos.y + sprite.rect.height * sprite.scale.y)
        return (true);
    else
        return (false);
}

void menu_start_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->main_menu->button[0], mouse))
        sfSprite_setTextureRect(a->main_menu->button[0].s,
        (sfIntRect){0, 71, 358, 71});
    else {
        sfSprite_setTextureRect(a->main_menu->button[0].s,
        (sfIntRect){0, 0, 358, 71});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->main_menu->button[0], mouse)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->main_menu->button[0].s,
        (sfIntRect){0, 145, 358, 71});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->main_menu->button[0], mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->scene = GAME;
}

void menu_settings_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->main_menu->button[1], mouse))
        sfSprite_setTextureRect(a->main_menu->button[1].s,
        (sfIntRect){0, 53, 325, 51});
    else {
        sfSprite_setTextureRect(a->main_menu->button[1].s,
        (sfIntRect){0, 0, 325, 51});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->main_menu->button[1], mouse)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->main_menu->button[1].s,
        (sfIntRect){0, 104, 325, 51});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->main_menu->button[1], mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->scene = SETTINGS;
}

void menu_quit_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->main_menu->button[2], mouse))
        sfSprite_setTextureRect(a->main_menu->button[2].s,
        (sfIntRect){0, 51, 320, 51});
    else {
        sfSprite_setTextureRect(a->main_menu->button[2].s,
        (sfIntRect){0, 0, 320, 51});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->main_menu->button[2], mouse)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->main_menu->button[2].s,
        (sfIntRect){0, 102, 320, 51});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->main_menu->button[2], mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->scene = QUIT;
}

void handle_menu_buttons(all_t *a, sfEvent event)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(a->window);

    if (!a->main_menu->pseudo_taken)
        menu_start_button(a, event, mousepos);
    else
        handle_continue_button(a, event, mousepos);
    menu_settings_button(a, event, mousepos);
    menu_quit_button(a, event, mousepos);
    menu_howtoplay_button(a, event, mousepos);
    arrow_button(a, event, mousepos);
    nickname_bar_event(a, event, mousepos);
}