/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game events
*/

#include "rpg.h"
#include "struct.h"

void move_item(int id, bool pressed, sfVector2i mvector, all_t *a)
{
    if (id != -1 && pressed && !a->inventory.items[id].equiped) {
        sfSprite_setPosition(a->inventory.items[id].s,
        (sfVector2f){mvector.x, mvector.y});
    }
}

bool is_item_hovered(inv_item_t item, sfVector2i mouse)
{
    sfVector2f offset = sfSprite_getOrigin(item.s);

    if (item.pos.x - offset.x <= mouse.x &&
    mouse.x <= (item.pos.x + item.rect.width * item.scale.x) - offset.x
    && item.pos.y - offset.y <= mouse.y &&
    mouse.y <= (item.pos.y + item.rect.height * item.scale.y) - offset.y)
        return (true);
    else
        return (false);
}

void unequip_events(all_t *a)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(a->window);
    for (int i = 0; i < a->inventory.items_size; i++) {
        if (a->inventory.items[i].equiped == false)
            continue;
        mvector = sfMouse_getPositionRenderWindow(a->window);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        is_item_hovered(a->inventory.items[i], mvector)) {
            unequip_item_in_inv(a, a->inventory.items[i].id, i);
            return;
        }
    }
}