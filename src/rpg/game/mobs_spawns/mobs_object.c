/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** mobs_object
*/

#include "rpg.h"
#include "struct.h"
#include "mobs.h"

void spawn_mobs(float srate, all_t *a)
{
    sfVector2i pos = {0, 0};
    int status = 0;

    if (a->mobs->mb_nb != 0)
        handle_mobs(a);
    if (get_seconds(a->mobs->spawn_clock) > 1 && a->mobs->mb_nb <= 20) {
        for (pos.y = 0; a->map.txtmap[pos.y] && status != 1; pos.y++)
            status = check_mobs_on_map(a, &pos.x, &pos.y, srate);
        if (status == 1)
            create_mob(a, pos);
        sfClock_restart(a->mobs->spawn_clock);
    }
}

void init_mobs_name(mobs_object_t *object, int nb)
{
    if (nb == 0)
        object->name = "GHOST";
    if (nb == 1)
        object->name = "SKELETON";
    if (nb == 2)
        object->name = "GOBLIN";
    if (nb == 3)
        object->name = "DRAGON";
    if (nb == 4)
        object->name = "MAGE";
    if (nb == 5)
        object->name = "DEMON_GIRL";
}

void init_mobs_object(mobs_object_t *object, char *filepath)
{
    sfVector2u width_height = {0, 0};

    object->clock = create_clock();
    object->rectclock = create_clock();
    object->texture = create_texture(filepath, NULL);
    object->sprite = create_sprite();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->width = width_height.x;
    object->height = width_height.y;
    object->rect.left = (object->rect.left == 0) ? 0 : object->rect.left;
    object->rect.top = (object->rect.top == 0) ? 0 : object->rect.top;
    sfSprite_setTextureRect(object->sprite, object->rect);
    sfSprite_setScale(object->sprite, object->scale);
    sfSprite_setPosition(object->sprite, object->pos);
    object->status = object->status;
}