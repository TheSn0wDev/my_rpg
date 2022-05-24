/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

bool does_pseudo_exist(all_t *a)
{
    char **arr = read_file_inv("data/players/inventory.txt");
    char **pseudo;

    if (arr == NULL)
        return (false);
    for (int i = 0; arr[i]; i++) {
        pseudo = my_str_to_word_array(arr[i], ":");
        if (my_strcmp(pseudo[0], a->main_menu->nickname) == 0)
            return (true);
    }
    return (false);
}

bool is_nickname_taken(all_t *a)
{
    if (check_string_char(a->main_menu->nickname, ' ')
    || !does_pseudo_exist(a))
        return (false);
    return (true);
}

void handle_continue_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->main_menu->button[6], mouse))
        sfSprite_setTextureRect(a->main_menu->button[6].s,
        (sfIntRect){0, 252 / 3, 465, 252 / 3});
    else {
        sfSprite_setTextureRect(a->main_menu->button[6].s,
        (sfIntRect){0, 0, 465, 252 / 3});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->main_menu->button[6], mouse)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->main_menu->button[6].s,
        (sfIntRect){0, 168, 465, 252 / 3});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->main_menu->button[6], mouse))
        if (event.type == sfEvtMouseButtonReleased)
            a->scene = GAME;
}