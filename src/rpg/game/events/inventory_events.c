/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game events
*/

#include "rpg.h"
#include "struct.h"

int get_item_id(inv_item_t *items, int items_nb, sfVector2i mvector)
{
    for (int i = 0; i < items_nb; i++) {
        if (mvector.x >= items[i].pos.x - 20
        && mvector.x <= items[i].pos.x + 20
        && mvector.y >= items[i].pos.y - 20
        && mvector.y <= items[i].pos.y + 20)
            return (i);
    }
    return (-1);
}

int is_click_on_bar(all_t *a, sfVector2i mvector)
{
    if (mvector.x >= 1480 && mvector.x <= 1920)
        if (mvector.y >= 730 && mvector.y <= 770)
            return (get_item_id(a->inventory.items,
            a->inventory.items_size, mvector));
    return (-1);
}

int drop_item(inv_item_t *item, sfVector2i mv, int id, sfVector2f og_pos)
{
    if (mv.x >= 1655 && mv.x <= 1880
    && mv.y >= 400 && mv.y <= 715 && item->drawable) {
        if (id == 0)
            drop_item_on_slot(item, (sfVector2f){1692, 507});
        if (id == 1)
            drop_item_on_slot(item, (sfVector2f){1770, 430});
        if (id == 2)
            drop_item_on_slot(item, (sfVector2f){1770, 505});
        if (id == 3)
            drop_item_on_slot(item, (sfVector2f){1770, 614});
        if (id == 4)
            drop_item_on_slot(item, (sfVector2f){1770, 680});
        return (1);
    } else
        sfSprite_setPosition(item->s, og_pos);
    return (0);
}

void drag_drop_events(sfEvent event, all_t *a)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(a->window);
    static int id = -1;
    static sfVector2f og_pos;
    static bool pressed = false;

    if (sfMouse_isButtonPressed(sfMouseLeft) && !pressed) {
        id = is_click_on_bar(a, mvector);
        if (id != -1) {
            og_pos = a->inventory.items[id].pos;
            pressed = true;
        }
    }
    move_item(id, pressed, mvector, a);
    if (id != -1 && event.type == sfEvtMouseButtonReleased) {
        if (drop_item(&a->inventory.items[id], mvector, id, og_pos))
            equip_item_in_inv(a, id);
        pressed = false;
    }
}

void inventory_events(all_t *a, sfEvent event)
{
    static bool released = true;

    if (event.type == sfEvtKeyPressed
    && event.key.code == a->key_arr[5] - 97 && released) {
        a->inventory.show = !a->inventory.show;
        released = false;
    }
    if (event.type == sfEvtKeyReleased)
        released = true;
    drag_drop_events(event, a);
    unequip_events(a);
}