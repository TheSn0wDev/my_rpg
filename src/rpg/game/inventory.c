/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game
*/

#include "rpg.h"
#include "struct.h"

int get_items_size(char *str)
{
    int r = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ':')
            r++;
    }
    return (r);
}

void init_inv_item(inv_item_t *object, char *filepath, sfVector2i eq_count)
{
    sfVector2u width_height = {0, 0};

    object->clock = create_clock();
    object->s = create_sprite();
    if (filepath != NULL) {
        object->texture = create_texture(filepath, NULL);
        sfSprite_setTexture(object->s, object->texture, sfTrue);
        object->drawable = 1;
    }
    object->width = width_height.x;
    object->height = width_height.y;
    object->rect.left = (object->rect.left == 0) ? 0 : object->rect.left;
    object->rect.top = (object->rect.top == 0) ? 0 : object->rect.top;
    object->equiped = eq_count.x;
    object->id = eq_count.y;
    sfSprite_setTextureRect(object->s, object->rect);
    sfSprite_setScale(object->s, object->scale);
    sfSprite_setPosition(object->s, object->pos);
}

inv_item_t load_item(int type, int j, sfVector2f pos, sfVector2i eq_count)
{
    inv_item_t item = {0, 0, eq_count.x, {0.8, 0.8}, get_pos(j, pos), 0, 0,
    {0, 0, 40, 40}, 0, false, eq_count.y};

    init_inv_item(&item, get_image(type), eq_count);
    if (eq_count.x == 1) {
        item.pos = get_equiped_pos(type, &item);
        sfSprite_setPosition(item.s, get_equiped_pos(type, &item));
    }
    sfSprite_setOrigin(item.s, (sfVector2f){20.0, 20.0});
    return (item);
}