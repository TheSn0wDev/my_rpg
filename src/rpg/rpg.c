/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** rpg handling
*/

#include "rpg.h"
#include "struct.h"

void check_game(all_t *a)
{
    if (a->scene == GAME) {
        init_game(a);
        handle_game(a);
    }
    if (a->scene == COMBAT) {
        init_combat(a);
        handle_combat(a);
    }
    if (a->scene == GAME_OVER) {
        init_game_over(a);
        handle_game_over(a);
        destroy_combat(a);
    }
    if (a->scene == COMBAT_WIN) {
        init_combat_end(a);
        destroy_combat(a);
    }
}

void check_menu(all_t *a)
{
    if (a->scene == MENU) {
        init_menu(a);
        handle_menu(a);
    }
    if (a->scene == SETTINGS) {
        init_settings(a);
        handle_settings(a);
    }
    if (a->scene == HOW_TO_PLAY) {
        handle_how_to_play(a);
    }
    if (a->scene == ENDGAME) {
        handle_end_game(a);
    }
}

void handle_rpg(all_t *a)
{
    while (sfRenderWindow_isOpen(a->window)) {
        if (a->scene == CINEMATIC) {
            start_cinematic(a);
            destroy_cinematic_assets(a);
        }
        check_menu(a);
        check_game(a);
        if (a->scene == QUIT) {
            sfRenderWindow_close(a->window);
        }
    }
    save_player_stats(a, &a->player->obj->stat);
    sfRenderWindow_destroy(a->window);
    sfImage_destroy(a->logo);
}