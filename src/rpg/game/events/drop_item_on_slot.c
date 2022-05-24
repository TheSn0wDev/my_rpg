/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

int get_id_from_equiped(sfVector2i mvector)
{
    if (mvector.x >= 1761 && mvector.x <= 1781
    && mvector.y >= 419 && 444)
        return (1);
    if (mvector.x >= 1758 && mvector.x <= 1782
    && mvector.y >= 490 && 516)
        return (2);
    if (mvector.x >= 1761 && mvector.x <= 1781
    && mvector.y >= 600 && 628)
        return (3);
    if (mvector.x >= 1761 && mvector.x <= 666
    && mvector.y >= 1783 && 695)
        return (4);
    return (0);
}

void drop_item_on_slot(inv_item_t *item, sfVector2f pos)
{
    sfSprite_setPosition(item->s, pos);
    item->pos = pos;
}