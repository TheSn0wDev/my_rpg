/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** draw_npc
*/

#include "rpg.h"
#include "struct.h"

int can_draw_npc(all_t *a, int i)
{
    if (a->map.world != SPAWN && (a->npc[0].obj[i].id == QUESTMASTER ||
    a->npc[0].obj[i].id == SPAWNNPC || a->npc[0].obj[i].id == FORGERON))
        return (1);
    if ((a->map.world != FOPSPACE && (a->npc[0].obj[i].id == SKELETON ||
    a->npc[0].obj[i].id == OLDIDK))) {
        return (1);
    }
    return (0);
}

void display_npc(all_t *a)
{
    sfVector2f pos;

    for (int i = 0; i < a->npc->npc_nb; i++) {
        if (can_draw_npc(a, i) == 1)
            continue;
        pos = (sfVector2f){a->npc[0].obj[i].pos.x - a->map.map->rect.left,
        a->npc[0].obj[i].pos.y - a->map.map->rect.top};
        sfSprite_setPosition(a->npc[0].obj[i].s, pos);
        if (i != 2)
            sfRenderWindow_drawSprite(a->window, a->npc[0].obj[i].s, NULL);
    }
}

void npc_button(all_t *a)
{
    sfRenderWindow_drawSprite(a->window, a->npc->interact_button[0].s, NULL);
    sfRenderWindow_drawText(a->window, a->npc[0].interact_key, NULL);
    sfSprite_setPosition(a->npc->interact_button[0].s,
    (sfVector2f){10000, -1000});
    sfText_setPosition(a->npc[0].interact_key, (sfVector2f){10000, -1000});
    if (a->npc->ex)
        sfRenderWindow_drawSprite(a->window, a->npc->dotex[0].s, NULL);
    sfRenderWindow_drawRectangleShape(a->window, a->map.shadows, NULL);
    if (a->in_dialogue == true) {
        update_dialogue(a);
        draw_dialogue(a);
    }
}