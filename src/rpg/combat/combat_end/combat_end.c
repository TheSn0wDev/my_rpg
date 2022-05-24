/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** combat_end.c
*/

#include "combat_end.h"

void init_combat_end(all_t *a)
{
    char *name = "assets/combat/continue_button.png";
    stat_t old_stats;

    a->text.content = my_malloc(sizeof(char *) * 1);
    level_up(a, &old_stats);
    create_button_end(name, &a->combat.button, (sfVector2f){700, 800});
    a->text.font = create_font("assets/fonts/diablo_h.ttf");
    a->text.text = create_text();
    a->text.pos = (sfVector2f){0, 50};
    a->text.content[0] = "YOU WIN!";
    a->text.pos.x = (1920 - 6.5 * 64) / 2;
    sfText_setFont(a->text.text, a->text.font);
    sfText_setString(a->text.text, a->text.content[0]);
    sfText_setCharacterSize(a->text.text, 64);
    sfText_setPosition(a->text.text, a->text.pos);
    a->player->obj->pos = a->combat.save_pos;
    handle_combat_end(a, &old_stats);
}

void next_button(all_t *a, sfVector2i mouse, sfEvent event)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->combat.button, mouse))
        sfSprite_setTextureRect(a->combat.button.s,
        (sfIntRect){0, 84, 465, 84});
    else {
        sfSprite_setTextureRect(a->combat.button.s,
        (sfIntRect){0, 0, 465, 84});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->combat.button, mouse) &&
    sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->combat.button.s,
        (sfIntRect){0, 84 * 2, 465, 84});
        pressed = true;
    }
    if (is_sprite_hovered(a->combat.button, mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->scene = GAME;
}

void analyse_combat_end_events(all_t *a)
{
    sfEvent event;
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(a->window);

    while (sfRenderWindow_pollEvent(a->window, &event)) {
        next_button(a, mousepos, event);
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

void handle_combat_end(all_t *a, stat_t *stats)
{
    int nb = 28;
    sfText **end_stats = my_malloc(sizeof(sfText *) * nb);

    init_texts(a, end_stats, stats);
    while (a->scene == COMBAT_WIN) {
        analyse_combat_end_events(a);
        sfRenderWindow_clear(a->window, sfBlack);
        sfRenderWindow_drawText(a->window, a->text.text, NULL);
        sfRenderWindow_drawSprite(a->window, a->combat.button.s, NULL);
        for (int i = 0; i < nb; i++)
            sfRenderWindow_drawText(a->window, end_stats[i], NULL);
        if (my_strcmp(a->mobs[0].combat_mob.name, "SCYTHE") == 0)
            a->mobs[0].miniboss = true;
        if (my_strcmp(a->mobs[0].combat_mob.name, "DEMON_LORD") == 0) {
            a->mobs[0].boss = true;
            a->scene = ENDGAME;
        }
        sfRenderWindow_display(a->window);
    }
}