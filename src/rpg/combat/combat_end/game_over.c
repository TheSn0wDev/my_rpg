/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** game_over.c
*/

#include "combat_end.h"

void init_game_over(all_t *a)
{
    char *name = "assets/combat/restart_button.png";

    a->text.content = my_malloc(sizeof(char *) * 1);
    create_button_end(name, &a->combat.button, (sfVector2f){700, 700});
    sfSprite_setPosition(a->combat.button.s, a->combat.button.pos);
    a->text.font = create_font("assets/fonts/diablo_h.ttf");
    a->text.text = create_text();
    a->text.pos = (sfVector2f){0, 390};
    a->text.content[0] = "GAME OVER";
    a->text.pos.x = (1920 - 7.5 * 128) / 2;
    sfText_setFont(a->text.text, a->text.font);
    sfText_setString(a->text.text, a->text.content[0]);
    sfText_setCharacterSize(a->text.text, 128);
    sfText_setPosition(a->text.text, a->text.pos);
    a->player->obj->pos = a->combat.save_pos;
    init_before_game(a);
    init_before_combat(a);
}

void restart_button(all_t *a)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(a->window);

    if (is_sprite_hovered(a->combat.button, mousepos) == true) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            a->combat.button.rect.top = a->combat.button.rect.height;
            a->scene = GAME;
        } else
            a->combat.button.rect.top = a->combat.button.rect.height * 2;
    } else {
        a->combat.button.rect.top = 0;
    }
    sfSprite_setTextureRect(a->combat.button.s, a->combat.button.rect);
}

void analyse_game_over_events(all_t *a)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->window, &event)) {
        restart_button(a);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            a->scene = QUIT;
            sfRenderWindow_close(a->window);
        }
        if (event.type == sfEvtClosed) {
            a->scene = QUIT;
            sfRenderWindow_close(a->window);
        }
    }
}

void handle_game_over(all_t *a)
{
    while (a->scene == GAME_OVER) {
        analyse_game_over_events(a);
        sfRenderWindow_clear(a->window, sfBlack);
        sfRenderWindow_drawSprite(a->window, a->combat.button.s, NULL);
        sfRenderWindow_drawText(a->window, a->text.text, NULL);
        sfRenderWindow_display(a->window);
    }
    rm_from_data_files(a);
}