/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** end_loop
*/

#include "rpg.h"
#include "struct.h"

void handle_end_game(all_t *a)
{
    init_end_game(a);
    start_dialogue(a, "assets/dialogue/end.txt");
    while (a->scene == ENDGAME) {
        handle_end_game_events(a);
        sfRenderWindow_clear(a->window, sfBlack);
        sfRenderWindow_drawSprite(a->window, a->map.map->s, NULL);
        sfRenderWindow_drawSprite(a->window, a->end[0].endgame[0].s, NULL);
        sfRenderWindow_drawSprite(a->window, a->player->obj->s, NULL);
        if (a->in_dialogue == true) {
            update_dialogue(a);
            draw_dialogue(a);
        } else
            a->scene = MENU;
        sfRenderWindow_display(a->window);
    }
    rm_from_data_files(a);
}