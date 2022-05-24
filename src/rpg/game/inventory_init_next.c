/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game
*/

#include "rpg.h"
#include "struct.h"

inv_item_t *load_inv(char *inventory, char **data, all_t *a)
{
    inv_item_t *items = my_malloc(sizeof(*items) *
    get_items_size(inventory) + 1);

    a->inventory.items_size = get_items_size(inventory) / 2;
    for (int j = 1, count = 0; data[j] && data[j + 1]; j += 2, count++) {
        items[count] = load_item(my_getnbr(data[j]), j / 2 + 1,
        a->inventory.sprite.pos, (sfVector2i){my_getnbr(data[j + 1]), count});
    }
    return (items);
}