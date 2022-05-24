/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** how_to_play.c
*/

#include "rpg.h"
#include "struct.h"

void menu_howtoplay_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->main_menu->button[7], mouse))
        sfSprite_setTextureRect(a->main_menu->button[7].s,
        (sfIntRect){0, 84, 465, 84});
    else {
        sfSprite_setTextureRect(a->main_menu->button[7].s,
        (sfIntRect){0, 0, 465, 84});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->main_menu->button[7], mouse)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->main_menu->button[7].s,
        (sfIntRect){0, 168, 465, 84});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->main_menu->button[7], mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->scene = HOW_TO_PLAY;
}

void howtoplay_return_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->main_menu->button[8], mouse))
        sfSprite_setTextureRect(a->main_menu->button[8].s,
        (sfIntRect){0, 84, 465, 84});
    else {
        sfSprite_setTextureRect(a->main_menu->button[8].s,
        (sfIntRect){0, 0, 465, 84});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->main_menu->button[8], mouse)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->main_menu->button[8].s,
        (sfIntRect){0, 168, 465, 84});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->main_menu->button[8], mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->scene = MENU;
}

void analyse_how_to_play_events(all_t *a)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(a->window);
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->window, &event)) {
        howtoplay_return_button(a, event, mouse);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            a->scene = MENU;
        }
        if (event.type == sfEvtClosed) {
            a->scene = QUIT;
            sfRenderWindow_close(a->window);
        }
    }
}

void handle_how_to_play(all_t *a)
{
    sfRenderWindow *window = a->window;
    sfTexture *texture = create_texture("assets/menu/how_to_play.png", NULL);
    sfSprite *sprite = create_sprite();
    menu_object_t returnmenu = {0, 0, {0.8, 0.8},
    {950, 920}, 0, 0, {0, 0, 465, 84}, 0};

    init_menu_object(&returnmenu, "assets/menu/buttons/returnmenu.png");
    a->main_menu[0].button[8] = returnmenu;
    sfSprite_setPosition(sprite, (sfVector2f){175, 0});
    sfSprite_setScale(sprite, (sfVector2f){1.2, 1.2});
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (a->scene == HOW_TO_PLAY) {
        analyse_how_to_play_events(a);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, a->main_menu[0].button[8].s, NULL);
        sfRenderWindow_display(window);
    }
}
