/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** draw_spawn
*/

#include "rpg.h"
#include "struct.h"

void must_draw_after_player_spawn(all_t *a)
{
    sfRenderWindow_drawSprite(a->window, a->npc[0].obj[2].s, NULL);
    sfRenderWindow_drawSprite(a->window, a->map.l_layer->s, NULL);
    sfRenderWindow_drawSprite(a->window, a->map.bot_wall->s, NULL);
}