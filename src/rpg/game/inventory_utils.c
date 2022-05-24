/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game
*/

#include "rpg.h"
#include "struct.h"

char *get_image(int type)
{
    if (type == 0)
        return ("assets/inventory/items/sword.png");
    if (type == 1)
        return ("assets/inventory/items/helmet.png");
    if (type == 2)
        return ("assets/inventory/items/chestplate.png");
    if (type == 3)
        return ("assets/inventory/items/legs.png");
    if (type == 4)
        return ("assets/inventory/items/boots.png");
    return (NULL);
}

sfVector2f get_equiped_pos_s(int id, inv_item_t *item)
{
    if (id == 4) {
        drop_item_on_slot(item, (sfVector2f){1770, 680});
        return (sfVector2f){1770, 680};
    }
    return (sfVector2f){0, 0};
}

sfVector2f get_equiped_pos(int id, inv_item_t *item)
{
    if (id == 0) {
        drop_item_on_slot(item, (sfVector2f){1692, 507});
        return (sfVector2f){1692, 507};
    }
    if (id == 1) {
        drop_item_on_slot(item, (sfVector2f){1770, 430});
        return (sfVector2f){1770, 430};
    }
    if (id == 2) {
        drop_item_on_slot(item, (sfVector2f){1770, 505});
        return (sfVector2f){1770, 505};
    }
    if (id == 3) {
        drop_item_on_slot(item, (sfVector2f){1770, 614});
        return (sfVector2f){1770, 614};
    }
    return (get_equiped_pos_s(id, item));
}

sfVector2f get_pos(int j, sfVector2f pos)
{
    return (sfVector2f){(pos.x + j * 47) - 10 - (5 * j), pos.y + 492};
}