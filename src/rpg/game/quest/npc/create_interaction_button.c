/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** create_interaction_button
*/

#include "rpg.h"
#include "struct.h"

void create_interaction_button_sprite(all_t *a)
{
    sfColor color =  sfColor_fromRGBA(240, 255, 255, 255);
    npc_obj_t interact_button = {0, 0, {0.3, 0.3}, {10000, -1000}, 0, 0,
    {0, 0, 154, 151}, 0, true, TO_DO, QUESTMASTER};

    a->npc[0].interact_button = my_malloc(sizeof(npc_obj_t) * 1);
    init_npc_object(&interact_button, "assets/npc/interact_button.png");
    a->npc[0].interact_button[0] = interact_button;
    a->npc[0].interact_key = create_texts("assets/fonts/diablo_h.ttf", 40,
    (sfVector2f){10000, -1000}, color);
}