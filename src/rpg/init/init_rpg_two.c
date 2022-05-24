/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

void init_rpg_two(all_t *a)
{
    a->scene = CINEMATIC;
    a->sfx.attack = create_music("assets/musics/canon.ogg");
    init_before_settings(a);
    init_before_menu(a);
    init_dialogue(a);
    a->player->skin = FEATHER;
    init_before_game(a);
    init_before_combat(a);
    init_quest_ui(a);
}