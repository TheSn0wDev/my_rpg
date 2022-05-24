/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

void init_xp_bar(all_t *a)
{
    sfColor color = sfColor_fromRGBA(51, 102, 29, 255);

    a->inventory.xp_bar = create_rectangle();
    sfRectangleShape_setSize(a->inventory.xp_bar, (sfVector2f){10, 27});
    sfRectangleShape_setFillColor(a->inventory.xp_bar, color);
    sfRectangleShape_setPosition(a->inventory.xp_bar, (sfVector2f){785, 1020});
}